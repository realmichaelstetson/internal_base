#include "chams.h"

#include <Windows.h>
#include <cmath>
#include <cstdint>
#include <string>

#include <imgui.h>

#include "../core/config.h"
#include "../sdk/entities.h"
#include "../sdk/material.h"
#include "../sdk/memory.h"
#include "../sdk/offsets.h"

using namespace config::chams;

namespace
{
	// One entry of the array passed to the draw function (scenesystem.dll)
	struct SceneData
	{
		char pad0[ 0x18 ];
		uintptr_t sceneObject;
		void* material;
		void* material2;
		char pad1[ 0x20 ];
		uint8_t r, g, b, a;
		char pad2[ 0x14 ];
	};
	static_assert( sizeof( SceneData ) == 0x68 );

	constexpr const char* KV3_HEADER = "<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->\n";
	constexpr const char* IGNORE_Z = "F_DISABLE_Z_BUFFERING = 1\nF_DISABLE_Z_PREPASS = 1\nF_DISABLE_Z_WRITE = 1\n";

	// {Z} is replaced with the ignore-z flags for the through-walls variant
	constexpr const char* materialBodies[ MaterialCount - 1 ] = {
		// Flat
		R"({
			shader = "csgo_unlitgeneric.vfx"
			{Z}
			F_PAINT_VERTEX_COLORS = 1
			F_TRANSLUCENT = 1
			F_BLEND_MODE = 1
			g_vColorTint = [1, 1, 1, 1]
			TextureAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tAmbientOcclusion = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tTintMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
		})",
		// Textured (lit, keeps shading)
		R"({
			shader = "csgo_character.vfx"
			{Z}
			F_BLEND_MODE = 1
			g_vColorTint = [1.0, 1.0, 1.0, 1.0]
			g_bFogEnabled = 0
			g_flMetalness = 0.000
			g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
			g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_79a2e0d0.vtex"
			g_tNormal = resource:"materials/default/default_normal_tga_1b833b2a.vtex"
			g_tMetalness = resource:"materials/default/default_metal_tga_8fbc2820.vtex"
		})",
		// Metallic
		R"({
			shader = "csgo_character.vfx"
			{Z}
			F_BLEND_MODE = 1
			g_vColorTint = [1.0, 1.0, 1.0, 1.0]
			g_bFogEnabled = 0
			g_flMetalness = 1.000
			g_tColor = resource:"materials/dev/primary_white_color_tga_21186c76.vtex"
			g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_79a2e0d0.vtex"
			g_tNormal = resource:"materials/default/default_normal_tga_1b833b2a.vtex"
			g_tMetalness = resource:"materials/default/default_metal_tga_8fbc2820.vtex"
		})",
		// Glow (fresnel rim)
		R"({
			shader = "csgo_effects.vfx"
			{Z}
			F_ADDITIVE_BLEND = 1
			F_BLEND_MODE = 1
			F_TRANSLUCENT = 1
			g_flOpacityScale = 0.45
			g_flFresnelExponent = 0.75
			g_flFresnelFalloff = 1.0
			g_flFresnelMax = 0.0
			g_flFresnelMin = 1.0
			g_flToolsVisCubemapReflectionRoughness = 1.0
			g_flBeginMixingRoughness = 1.0
			g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tMask1 = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tMask2 = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tMask3 = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tSceneDepth = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_vColorTint = [1.0, 1.0, 1.0, 0]
		})",
		// Illuminate (self-illum)
		R"({
			shader = "csgo_complex.vfx"
			{Z}
			F_SELF_ILLUM = 1
			F_PAINT_VERTEX_COLORS = 1
			F_TRANSLUCENT = 1
			g_vColorTint = [1.0, 1.0, 1.0, 1.0]
			g_flSelfIllumScale = [3.0, 3.0, 3.0, 3.0]
			g_flSelfIllumBrightness = [3.0, 3.0, 3.0, 3.0]
			g_vSelfIllumTint = [10.0, 10.0, 10.0, 10.0]
			g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tSelfIllumMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			TextureAmbientOcclusion = resource:"materials/debug/particleerror.vtex"
			g_tAmbientOcclusion = resource:"materials/debug/particleerror.vtex"
		})",
		// Ghost (additive flat)
		R"({
			shader = "csgo_unlitgeneric.vfx"
			{Z}
			F_PAINT_VERTEX_COLORS = 1
			F_TRANSLUCENT = 1
			F_ADDITIVE_BLEND = 1
			F_BLEND_MODE = 1
			g_vColorTint = [1, 1, 1, 1]
			g_tColor = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tNormal = resource:"materials/default/default_mask_tga_fde710a5.vtex"
			g_tTintMask = resource:"materials/default/default_mask_tga_fde710a5.vtex"
		})",
	};

	// [material][0 = visible, 1 = through walls] -> resource binding
	void* bindings[ MaterialCount - 1 ][ 2 ]{ };
	bool initialized = false;
	const char* statusText = "Not initialized";

	std::string buildMaterial( const char* body, bool ignoreZ )
	{
		std::string out = KV3_HEADER;
		out += body;
		out.replace( out.find( "{Z}" ), 3, ignoreZ ? IGNORE_Z : "" );
		return out;
	}

	void* getMaterial( int type, bool ignoreZ )
	{
		if ( type < 0 || type >= Original )
			return nullptr;
		void* binding = bindings[ type ][ ignoreZ ? 1 : 0 ];
		return binding ? *static_cast< void** >( binding ) : nullptr;
	}

	const Group* groupFor( const SceneData& data )
	{
		uint32_t owner = 0xFFFFFFFF;
		if ( !memory::read( data.sceneObject + offsets::manual::sceneObjectOwner, owner ) || owner == 0xFFFFFFFF )
			return nullptr;

		switch ( entities::categoryOf( owner ) )
		{
		case entities::Category::Enemy: return &groups[ Enemies ];
		case entities::Category::Teammate: return &groups[ Teammates ];
		case entities::Category::Local: return &groups[ LocalPlayer ];
		default: break;
		}

		// not a player - maybe something a player owns (weapon / viewmodel)
		const uintptr_t entity = entities::get( owner );
		uint32_t ownerOfOwner = 0xFFFFFFFF;
		if ( !entity || !memory::read( entity + offsets::m_hOwnerEntity, ownerOfOwner ) || ownerOfOwner == 0xFFFFFFFF )
			return nullptr;

		switch ( entities::categoryOf( ownerOfOwner ) )
		{
		case entities::Category::Local: return &groups[ Viewmodel ];
		case entities::Category::Enemy:
		case entities::Category::Teammate: return &groups[ Weapons ];
		default: return nullptr;
		}
	}

	bool anyLayer( const Group& group )
	{
		return group.visible.enabled || group.hidden.enabled || group.overlay.enabled;
	}

	void applyColor( SceneData& data, const Layer& layer )
	{
		const float time = static_cast< float >( GetTickCount64( ) ) / 1000.f;

		float r = layer.color[ 0 ], g = layer.color[ 1 ], b = layer.color[ 2 ], a = layer.color[ 3 ];
		if ( layer.rainbow )
			ImGui::ColorConvertHSVtoRGB( std::fmod( time * 0.15f, 1.f ), 0.7f, 1.f, r, g, b );
		if ( layer.pulse )
			a *= 0.35f + 0.65f * ( 0.5f + 0.5f * std::sin( time * 4.f ) );

		data.r = static_cast< uint8_t >( r * 255.f );
		data.g = static_cast< uint8_t >( g * 255.f );
		data.b = static_cast< uint8_t >( b * 255.f );
		data.a = static_cast< uint8_t >( a * 255.f );
	}

	// Sets material + colour for a layer. Returns false if the layer can't be drawn.
	bool applyLayer( SceneData& data, const Layer& layer, bool ignoreZ )
	{
		if ( layer.material == Original )
		{
			if ( ignoreZ ) // original game material can't render through walls
				return false;
			applyColor( data, layer );
			return true;
		}

		void* material = getMaterial( layer.material, ignoreZ );
		if ( !material )
			return false;

		data.material = material;
		data.material2 = material;
		applyColor( data, layer );
		return true;
	}
}

bool features::chams::init( )
{
	if ( !material::init( ) )
	{
		statusText = "CreateMaterial / LoadKV3 not found (outdated signature)";
		return false;
	}

	static const char* names[ MaterialCount - 1 ] = { "flat", "textured", "metallic", "glow", "illuminate", "ghost" };
	for ( int i = 0; i < Original; ++i )
	{
		for ( int z = 0; z < 2; ++z )
		{
			const std::string name = std::string( "materials/dev/cs2internal_" ) + names[ i ] + ( z ? "_xqz.vmat" : ".vmat" );
			bindings[ i ][ z ] = material::create( name.c_str( ), buildMaterial( materialBodies[ i ], z ).c_str( ) );
		}
	}

	initialized = true;
	statusText = "Ready";
	return true;
}

bool features::chams::ready( )
{
	return initialized;
}

const char* features::chams::status( )
{
	return statusText;
}

void* features::chams::onDrawObject( DrawObjectFn original, void* desc, void* renderContext, void* sceneData, int count, void* sceneView, void* sceneLayer, void* unk )
{
	if ( !initialized || !enabled || !sceneData || count <= 0 )
		return original( desc, renderContext, sceneData, count, sceneView, sceneLayer, unk );

	auto entries = static_cast< SceneData* >( sceneData );
	void* result = nullptr;

	// Draw untouched entries in batches and every chammed entry on its own, so each one can get several passes.
	int runStart = 0;
	for ( int i = 0; i < count; ++i )
	{
		const Group* group = groupFor( entries[ i ] );
		if ( !group || !anyLayer( *group ) )
			continue;

		if ( i > runStart )
			result = original( desc, renderContext, entries + runStart, i - runStart, sceneView, sceneLayer, unk );
		runStart = i + 1;

		SceneData& data = entries[ i ];
		const SceneData backup = data;
		auto draw = [ & ] { result = original( desc, renderContext, &data, 1, sceneView, sceneLayer, unk ); };

		// 1. through walls
		if ( group->hidden.enabled && applyLayer( data, group->hidden, true ) )
			draw( );

		// 2. visible model (or the normal model if the visible layer is off)
		data = backup;
		if ( group->visible.enabled )
			applyLayer( data, group->visible, false );
		draw( );

		// 3. overlay on top
		if ( group->overlay.enabled && applyLayer( data, group->overlay, group->overlayThroughWalls ) )
			draw( );

		data = backup;
	}

	if ( runStart < count )
		result = original( desc, renderContext, entries + runStart, count - runStart, sceneView, sceneLayer, unk );

	return result;
}
