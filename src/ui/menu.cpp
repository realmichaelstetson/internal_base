#include "menu.h"

#include <imgui.h>
#include <Windows.h>

#include "../core/config.h"
#include "../sdk/globals.h"

namespace
{
	struct KeyOption
	{
		const char* name;
		int vk;
	};

	constexpr KeyOption bhopKeys[ ] = {
		{ "Space", VK_SPACE },
		{ "Mouse 4", VK_XBUTTON1 },
		{ "Mouse 5", VK_XBUTTON2 },
		{ "Left Alt", VK_LMENU },
		{ "C", 'C' },
	};

	void applyStyle( )
	{
		static bool done = false;
		if ( done )
			return;
		done = true;

		ImGuiStyle& style = ImGui::GetStyle( );
		ImGui::StyleColorsDark( &style );
		style.WindowRounding = 6.f;
		style.FrameRounding = 4.f;
		style.GrabRounding = 4.f;
		style.WindowTitleAlign = { 0.5f, 0.5f };

		ImVec4* colors = style.Colors;
		const ImVec4 accent = { 0.55f, 0.35f, 0.95f, 1.f };
		colors[ ImGuiCol_TitleBgActive ] = accent;
		colors[ ImGuiCol_CheckMark ] = accent;
		colors[ ImGuiCol_SliderGrab ] = accent;
		colors[ ImGuiCol_SliderGrabActive ] = { 0.65f, 0.45f, 1.f, 1.f };
		colors[ ImGuiCol_Button ] = { 0.30f, 0.20f, 0.55f, 1.f };
		colors[ ImGuiCol_ButtonHovered ] = accent;
		colors[ ImGuiCol_Tab ] = { 0.20f, 0.14f, 0.35f, 1.f };
		colors[ ImGuiCol_TabSelected ] = accent;
		colors[ ImGuiCol_TabHovered ] = { 0.65f, 0.45f, 1.f, 1.f };
	}

	void movementTab( )
	{
		bool enabled = config::bhop::enabled;
		if ( ImGui::Checkbox( "Bunnyhop", &enabled ) )
			config::bhop::enabled = enabled;

		ImGui::BeginDisabled( !enabled );

		int current = 0;
		for ( int i = 0; i < IM_ARRAYSIZE( bhopKeys ); ++i )
			if ( bhopKeys[ i ].vk == config::bhop::key )
				current = i;

		if ( ImGui::BeginCombo( "Key", bhopKeys[ current ].name ) )
		{
			for ( int i = 0; i < IM_ARRAYSIZE( bhopKeys ); ++i )
				if ( ImGui::Selectable( bhopKeys[ i ].name, i == current ) )
					config::bhop::key = bhopKeys[ i ].vk;
			ImGui::EndCombo( );
		}

		int delay = config::bhop::releaseDelay;
		if ( ImGui::SliderInt( "Release delay (ms)", &delay, 1, 20 ) )
			config::bhop::releaseDelay = delay;

		ImGui::EndDisabled( );
	}

	void miscTab( )
	{
		ImGui::TextDisabled( "INSERT - toggle menu" );
		ImGui::TextDisabled( "END    - unload" );
		ImGui::Spacing( );

		if ( ImGui::Button( "Unload", { -1.f, 0.f } ) )
			globals::running = false;
	}
}

void menu::render( )
{
	if ( !globals::menuOpen )
		return;

	applyStyle( );

	ImGui::SetNextWindowSize( { 420.f, 260.f }, ImGuiCond_Once );
	if ( ImGui::Begin( "cs2 internal", nullptr, ImGuiWindowFlags_NoCollapse ) )
	{
		if ( ImGui::BeginTabBar( "tabs" ) )
		{
			if ( ImGui::BeginTabItem( "Movement" ) )
			{
				movementTab( );
				ImGui::EndTabItem( );
			}
			if ( ImGui::BeginTabItem( "Misc" ) )
			{
				miscTab( );
				ImGui::EndTabItem( );
			}
			ImGui::EndTabBar( );
		}
	}
	ImGui::End( );
}
