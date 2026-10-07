#include "../../../core/main.hpp"

namespace {
using namespace std::string_view_literals;

constexpr signature_entry_t entries[] = {
	{ "CalculateWorldSpaceBones", "client.dll", "48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 48 8D 6C 24 60"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CreateMove", "client.dll", "48 8B C4 4C 89 40 18 48 89 48 08 55 53 41 54 41"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSkeletonInstance::SetMeshGroupMask", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8D 99 40"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetModel", "client.dll", "40 53 48 83 EC ? 48 8B D9 4C 8B C2 48 8B 0D ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetHitboxSet", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 8B DA 48 8B F9 E8 ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CEconItemView::ConstructPaintKit", "client.dll", "48 89 5C 24 ? 56 48 83 EC ? 48 8B 01 FF 50 18"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ApplyEconCustomization", "client.dll", "48 89 5C 24 ? 57 48 83 EC ? 8B FA 48 8B D9 E8 ? ? ? ? 48 8B CB E8 ? ? ? ? 48 85 C0 74 4E"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdateSubClass", "client.dll", "4C 8B DC 53 48 81 EC ? ? ? ? 48 8B 41 10 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "PointerToGetSpreadFunction", "client.dll", "48 83 EC ? 48 63 91 D8 17 00 00 48 8B 81 88 03"sv, signature_resolve_kind::raw, 0, 0 },
	{ "PointerToGetInaccuracyFunction", "client.dll", "48 89 5C 24 ? 55 56 57 48 81 EC ? ? ? ? 44"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CBaseModelEntity::SetBodyGroup", "client.dll", "E8 ? ? ? ? EB 0C 48 8B CF E8 ? ? ? ? EB"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "GetBonePositionByName", "client.dll", "40 53 48 83 EC ? 48 8B 89 30 03 00 00 48 8B DA 48 8B 01 FF 50 68"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetBonePosition", "client.dll", "48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 4D 8B F1"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CGlowProperty_OnGlowTypeChanged", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B D9 F3"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ManageGlowSceneObjectPointer", "client.dll", "E8 ? ? ? ? 48 8B 4F 28 0F 28 7C 24 60 0F 28"sv, signature_resolve_kind::riprel, 1, 0 },
	{ "SetSceneObjectAttributeFloat4", "client.dll", "48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 66 0F 6E CA 49 8B F0 66 0F 70 C9 00 8B EA 48 8B F9 45 33 C9 48 8B C1 66 66 0F 1F 84 00 ? ? ? ? 66 0F 6F C1 4C 8D 15"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetEntityByIndex", "client.dll", "4C 8D 49 10 81 FA FE 7F 00 00 77 47 8B CA C1 F9"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetViewAngles", "client.dll", "4C 8B C1 85 D2 74 08 48 8D 05 ? ? ? ? C3 8B"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetViewAngle", "client.dll", "85 D2 75 3D ? ? ? ? 0B 00 00 F2 41 0F 10 00"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetControllerCmd", "client.dll", "40 53 48 83 EC ? 8B DA E8 ? ? ? ? 4C 8B C0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetEntityIndexFromController", "client.dll", "E8 ? ? ? ? 8B 8D 08 02 00 00 8D 51 FF 83 F9"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "SetupCmd", "client.dll", "48 83 EC ? E8 ? ? ? ? 8B 80 10 59 00 00 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "AutoMakeUserCmd", "client.dll", "E8 ? ? ? ? 48 89 44 24 ? 48 8D 4D F0 48 8D 05 ? ? ? ? 44"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "CCSGOInput::ProcessInput", "client.dll", "48 8B C4 4C 89 40 18 48 89 48 08 55 53 41 54 41"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FindHudElement", "client.dll", "40 53 48 83 EC ? 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 79"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ClearHUDWeaponIcon", "client.dll", "E8 ? ? ? ? 8B F8 C6 84 24 B8 00 00 00 01 41"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "RegenerateWeaponSkin", "client.dll", "40 55 53 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44"sv, signature_resolve_kind::raw, 0, 0 },
	{ "RegenerateWeaponSkins", "client.dll", "48 83 EC ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 10"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FrameStageNotify", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 57 48 83 EC ? 48 8B F9 33"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FireEventClientSide", "client.dll", "40 53 41 54 41 56 48 83 EC ? 4C 8B F2 48 8D 99"sv, signature_resolve_kind::raw, 0, 0 },
	{ "LevelInit", "client.dll", "48 89 74 24 ? 57 48 83 EC ? 48 8B 0D ? ? ? ? 48 8B FA"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetName", "client.dll", "8B 41 14 0F BA E0 1E 73 05 ? ? ? ? C3 A9 FF"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetString", "client.dll", "48 83 EC ? 8B 02 48 83 C1 58 89 44 24 20 8B 42 04 89 44 24 24 48 8B 42 08 48 8D 54 24 20 48 89 44 24 ? E8 ? ? ? ? 48 83 C4 38 C3 CC CC CC 33"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::SetString", "client.dll", "48 83 EC ? 8B 02 48 83 C1 58 89 44 24 20 41 B1 1A"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetPlayerController", "client.dll", "48 83 EC ? 8B 02 4C 8D 44 24 20 89 44 24 20 8B"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSGOInput_ptr", "client.dll", "48 8B 0D ? ? ? ? 8B 10 E8 ? ? ? ? 45 32"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "EntitySystem", "client.dll", "48 8B 0D ? ? ? ? 48 89 7C 24 ? 8B FA C1 EB"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "view_matrix_ptr", "client.dll", "48 8D 0D ? ? ? ? 48 89 44 24 ? 48 89 4C 24 ? 4C 8D 0D ? ? ? ? 48 8B 0D ? ? ? ? 4C 8D 05 ? ? ? ? 49"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "GetViewModelOffsets", "client.dll", "40 55 53 56 41 56 41 57 48 8B EC 48 83 EC ? 4D"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetWorldFovResolver", "client.dll", "40 53 48 83 EC ? 48 8B D9 E8 ? ? ? ? 48 85 C0 74 0D ? ? ? ? 83"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GlowManagerShouldGlow", "client.dll", "E8 ? ? ? ? 45 33 F6 84 C0 0F 84 ? ? ? ? 48"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "GlowManagerApplyGlow", "client.dll", "E8 ? ? ? ? F3 0F 10 BE 38 0E 00 00 48 8B CF"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "C_EconEntity_BuildLegacyWeaponSkinMaterial", "client.dll", "40 55 53 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44"sv, signature_resolve_kind::raw, 0, 0 },
	{ "C_EconEntity_BuildModernWeaponSkinMaterial", "client.dll", "48 85 C9 0F 84 ? ? ? ? 48 8B C4 48 89 50 10"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CUtlVector_CompositeMaterialInput_AddToTail", "client.dll", "41 B9 88 02 00 00 8B 57 14 81 E2 FF FF FF 3F 8D 71"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CompositeMaterialInputLooseVariable_AddToTail", "client.dll", "E8 ? ? ? ? 0F 28 B4 24 E0 02 00 00 4C 39 A5"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "SceneSystem_ptr", "scenesystem.dll", "48 8D 05 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8D 0D ? ? ? ? E9 ? ? ? ? CC"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "DrawObject_legacy", "scenesystem.dll", "48 8B C4 53 57 41 54 48 81 EC ? ? ? ? 49 63"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSceneAnimatableObject::GeneratePrimitives", "scenesystem.dll", "48 8B C4 4C 89 48 20 4C 89 40 18 48 89 50 10 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D A8 B8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSceneSystem_RenderViewLayer_Dispatch", "scenesystem.dll", "48 8B C4 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D A8"sv, signature_resolve_kind::raw, 0, 0 },

	{ "TraceShape", "client.dll", "48 89 54 24 ? 48 89 4C 24 ? 55 53 56 57 41 56 41 57 48 8D AC 24 ? ? ? ? B8 ? ? ? ? E8 ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceInitFilter", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 39 33 FF 24"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceInitData", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8D 79 08 33"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TracePlayerBBox", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? F2 0F 10 02"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceGetInfo", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B E9 ? ? ? ? 70"sv, signature_resolve_kind::raw, 0, 0 },
	{ "OverrideView", "client.dll", "40 57 48 83 EC ? 48 8B FA E8 ? ? ? ? BA FF"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent_GetInt64", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 01 41 8B F0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SendMessageClient", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 56 41 57 48 8D AC 24 ? ? ? ? B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 45 33 FF 41"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdateSkyBox", "client.dll", "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 E8 ? ? ? ? 48 8B 47"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdatePostProcessing", "client.dll", "48 85 D2 0F 84 ? ? ? ? 48 89 5C 24 ? 57 48 83 EC ? 80 3A 00 48 8B DA 48 8B F9 0F 84 ? ? ? ? 48 8D 15 ? ? ? ? C7"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawAggregateSceneObject", "scenesystem.dll", "48 8B C4 4C 89 40 18 48 89 50 10 55 53 41 57 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawLightScene", "scenesystem.dll", "48 89 54 24 ? 55 57 41 56 48 83 EC ? 48 8B FA"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawAggregateSceneObjectArray", "scenesystem.dll", "48 8B C4 48 89 50 10 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D A8 D8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawSkyboxArray", "scenesystem.dll", "45 85 C9 0F 8E ? ? ? ? 4C 8B DC 55 41 56 49"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawScope", "client.dll", "48 8B C4 53 57 48 83 EC ? 48 8B FA 44 0F 29 40"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SmokeVolumeDrawArray", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 9C 24 88 00 00 00 4D"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FirstPersonLegs", "client.dll", "40 55 53 56 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? F2"sv, signature_resolve_kind::raw, 0, 0 },

	{ "GetGameParticleManager", "client.dll", "48 8B 05 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 89 5C 24 ? 57 B8 ? ? ? ? E8 ? ? ? ? 48"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "CreateParticle", "client.dll", "4C 8B DC 53 48 81 EC ? ? ? ? F2 0F 10 05 ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetParticleSettings", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? F3 0F 10 1D ? ? ? ? 41 8B F8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DestroyParticle", "client.dll", "83 FA FF 0F 84 ? ? ? ? 41 54 41 56 41 57 48 83 EC ? 48 89 5C 24 ? 45"sv, signature_resolve_kind::raw, 0, 0 },

	{ "CreateMaterial", "materialsystem2.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "KV3_SetType", "tier0.dll", "40 53 48 83 EC ? 80 FA 06 0F B6 C2 41 B9 16 00"sv, signature_resolve_kind::raw, 0, 0 },
	{ "QueueForceSubtickMove", "client.dll", "48 89 5C 24 ? 57 48 83 EC ? 33 DB 48 8B F9 48 85 C9 75 ? B9 ? ? ? ? E8 ? ? ? ? 48 85 C0 74 ? 45 33 C0 33 D2 48 8B C8 E8 ? ? ? ? 48 8B D8 48 8B C3 48 8B 5C 24 ? 48 83 C4 ? 5F C3"sv, signature_resolve_kind::raw, 0, 0 },
};

bool is_required_signature(const char* name)
{
	return std::strcmp(name, "EntitySystem") == 0
		|| std::strcmp(name, "FrameStageNotify") == 0
		|| std::strcmp(name, "FireEventClientSide") == 0
		|| std::strcmp(name, "LevelInit") == 0
		|| std::strcmp(name, "GameEvent::GetName") == 0
		|| std::strcmp(name, "GameEvent::GetString") == 0
		|| std::strcmp(name, "GameEvent::SetString") == 0
		|| std::strcmp(name, "GameEvent::GetPlayerController") == 0;
}

std::uint64_t make_key(const char* module_name, const char* name)
{
	const std::uint64_t module_key = fnv1a::hash_64(module_name);
	const std::uint64_t name_key = fnv1a::hash_64(name);

	return module_key ^ (name_key + 0x9e3779b97f4a7c15ULL + (module_key << 6) + (module_key >> 2));
}

std::uint8_t* resolve_relative(std::uint8_t* address, int rel_offset, int extra_offset)
{
	if (!address)
		return nullptr;

	const std::int32_t displacement = *reinterpret_cast<std::int32_t*>(address + rel_offset);
	return address + rel_offset + sizeof(std::int32_t) + displacement + extra_offset;
}
}

std::uint8_t* c_signatures::get(const char* name)
{
	for (const auto& entry : entries) {
		if (fnv1a::hash_64(entry.name) == fnv1a::hash_64(name))
			return get(entry.module_name, name);
	}

	LOG_ERROR("[signatures] unknown signature: %s", name);
	return nullptr;
}

std::uint8_t* c_signatures::get(const char* module_name, const char* name)
{
	const std::uint64_t cache_key = make_key(module_name, name);
	const auto cached = m_cache.find(cache_key);
	if (cached != m_cache.end())
		return cached->second;

	for (const auto& entry : entries) {
		if (fnv1a::hash_64(entry.module_name) != fnv1a::hash_64(module_name)
			|| fnv1a::hash_64(entry.name) != fnv1a::hash_64(name))
			continue;

	std::uint8_t* resolved = resolve(entry);
	m_cache.emplace(cache_key, resolved);
	diagnostics::g_diagnostics->mark_signature(module_name, name, resolved != nullptr, is_required_signature(name));
	return resolved;
}

	LOG_ERROR("[signatures] unknown signature: %s!%s", module_name, name);
	return nullptr;
}

std::uint8_t* c_signatures::resolve(const signature_entry_t& entry)
{
	std::uint8_t* address = g_opcodes->scan(entry.module_name, entry.pattern.data());
	if (!address) {
		LOG_ERROR("[signatures] couldn't find %s!%s (%s)", entry.module_name, entry.name, entry.pattern.data());
		return nullptr;
	}

	if (entry.resolve == signature_resolve_kind::raw)
		return address + entry.extra_offset;

	auto* resolved = resolve_relative(address, entry.rel_offset, entry.extra_offset);
	if (!resolved)
		LOG_ERROR("[signatures] couldn't resolve %s!%s", entry.module_name, entry.name);

	return resolved;
}

void c_signatures::verify_all()
{
	int resolved = 0;
	int missing = 0;
	int required_missing = 0;

	for (const auto& entry : entries) {
		const auto* address = get(entry.module_name, entry.name);
		if (address) {
			++resolved;
		} else {
			++missing;
			LOG_ERROR("[-] missing signature: %s!%s", entry.module_name, entry.name);
			if (is_required_signature(entry.name))
				++required_missing;
		}
	}

	diagnostics::g_diagnostics->set_signature_verification_totals(
		static_cast<int>(std::size(entries)),
		resolved,
		missing,
		required_missing);
}
