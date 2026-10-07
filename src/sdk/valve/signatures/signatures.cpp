#include "../../../core/main.hpp"

namespace {
using namespace std::string_view_literals;

constexpr signature_entry_t entries[] = {
	{ "CalculateWorldSpaceBones", "client.dll", "48 89 4C 24 ? 55 53 56 57 41 54 41 55 41 56 41 57 B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 48 8D 6C 24 ? 48 8B 81"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CreateMove", "client.dll", "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40 18"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSkeletonInstance::SetMeshGroupMask", "client.dll", "40 53 48 83 EC 20 4C 8B 02 48 8B D9"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetModel", "client.dll", "40 53 48 83 EC ? 48 8B D9 4C 8B C2 48 8B 0D ? ? ? ? 48 8D 54 24"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetHitboxSet", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 8B DA 48 8B F9 E8 ? ? ? ? 48 8B F0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CEconItemView::ConstructPaintKit", "client.dll", "48 89 5C 24 ? 56 48 83 EC ? 48 8B 01 FF 50 18"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ApplyEconCustomization", "client.dll", "48 89 5C 24 08 57 48 83 EC 20 8B FA 48 8B D9 E8 ? ? ? ? 48 8B CB E8 ? ? ? ? 48 85 C0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdateSubClass", "client.dll", "4C 8B DC 53 48 81 EC ? ? ? ? 48 8B 41 10"sv, signature_resolve_kind::raw, 0, 0 },
	{ "PointerToGetSpreadFunction", "client.dll", "48 63 91 ? ? ? ? 48 8B 81 ? ? ? ? 85 D2 78 ? 48 83 FA 02 73 ? F3 0F 10 84 90 ? ? ? ? C3 F3 0F 10 80 ? ? ? ? C3 CC CC CC CC CC 40 53"sv, signature_resolve_kind::raw, 0, 0 },
	{ "PointerToGetInaccuracyFunction", "client.dll", "48 89 5C 24 10 55 56 57 48 81 EC ? ? ? ? 44 0F 29 84 24 80 00 00 00"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CBaseModelEntity::SetBodyGroup", "client.dll", "E8 ? ? ? ? EB 0C 48 8B CF E8 ? ? ? ? EB"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "GetBonePositionByName", "client.dll", "40 53 48 83 EC ? 48 8B 89 30 03 00 00 48 8B DA 48 8B 01 FF 50 68"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetBonePosition", "client.dll", "48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 4D 8B F1"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CGlowProperty_OnGlowTypeChanged", "client.dll", "48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 F3 0F 10 41 4C"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ManageGlowSceneObjectPointer", "client.dll", "E8 ? ? ? ? 48 8B 4F ? 0F 28 7C"sv, signature_resolve_kind::riprel, 1, 0 },
	{ "SetSceneObjectAttributeFloat4", "client.dll", "E8 ? ? ? ? F3 0F 10 47 6C 4C 8D 44 24 30 0F C6 C0 00 BA 00 51 8B B0 0F 11 44 24 30 48 8B CB 66 0F"sv, signature_resolve_kind::riprel, 1, 0 },
	{ "GetEntityByIndex", "client.dll", "4C 8D 49 ? 81 FA"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetViewAngles", "client.dll", "4C 8B C1 85 D2 74 08 48 8D 05 ? ? ? ? C3"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetViewAngle", "client.dll", "85 D2 75 ? 48 63 81"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetControllerCmd", "client.dll", "40 53 48 83 EC ? 8B DA E8 ? ? ? ? 4C 8B C0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetEntityIndexFromController", "client.dll", "E8 ? ? ? ? 8B 8D 08 02 00 00 8D 51 FF 83 F9"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "SetupCmd", "client.dll", "48 83 EC ? E8 ? ? ? ? 8B 80 10 59 00 00 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "AutoMakeUserCmd", "client.dll", "E8 ? ? ? ? 48 89 44 24 ? 48 8D 4D F0 48 8D 05 ? ? ? ? 44"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "CCSGOInput::ProcessInput", "client.dll", "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40 18"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FindHudElement", "client.dll", "40 53 48 83 EC 20 48 8B 05 ? ? ? ? 48 8B D9 48 85 C0 74 ? 48 89 5C 24 38"sv, signature_resolve_kind::raw, 0, 0 },
	{ "ClearHUDWeaponIcon", "client.dll", "E8 ? ? ? ? 8B F8 C6 84 24 ? ? ? ? ?"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "RegenerateWeaponSkin", "client.dll", "40 55 53 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44"sv, signature_resolve_kind::raw, 0, 0 },
	{ "RegenerateWeaponSkins", "client.dll", "48 83 EC ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 10"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FrameStageNotify", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 57 48 83 EC ? 48 8B F9 33 ED"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FireEventClientSide", "client.dll", "40 53 41 54 41 56 48 83 EC ? 4C 8B F2 48 8D 99"sv, signature_resolve_kind::raw, 0, 0 },
	{ "LevelInit", "client.dll", "40 55 56 41 56 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetName", "client.dll", "8B 41 14 0F BA E0 1E 73 05 48 8D 41 18 C3"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetString", "client.dll", "48 83 EC 38 8B 02 48 83 C1 58 89 44 24 20 8B 42 04 89 44 24 24 48 8B 42 08 48 8D 54 24 20 48 89 44 24 28 E8 ? ? ? ? 48 83 C4 38 C3 CC CC CC 33 C9"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::SetString", "client.dll", "48 83 EC 38 8B 02 48 83 C1 58 89 44 24 20 41 B1 1A"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent::GetPlayerController", "client.dll", "48 83 EC 38 8B 02 4C 8D 44 24 20"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSGOInput_ptr", "client.dll", "48 8B 0D ? ? ? ? 4C 8D 47 14"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "EntitySystem", "client.dll", "48 8B 1D ? ? ? ? 48 89 1D ? ? ? ?"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "view_matrix_ptr", "client.dll", "48 8D 0D ? ? ? ? 48 C1 E0 06"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "GetViewModelOffsets", "client.dll", "40 55 53 56 41 56 41 57 48 8B EC 48 83 EC 20 4D 8B F8 4C 8B F2 48 8B F1 E8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GetWorldFovResolver", "client.dll", "40 53 48 83 EC 50 48 8B D9 E8 ? ? ? ? 48 85 C0 74 ? 48 8B C8 48 83 C4 50 5B E9"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GlowManagerShouldGlow", "client.dll", "E8 ? ? ? ? 45 33 F6 84 C0 0F 84 ? ? ? ? 48"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "GlowManagerApplyGlow", "client.dll", "E8 ? ? ? ? F3 0F 10 BE 38 0E 00 00 48 8B CF"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "C_EconEntity_BuildLegacyWeaponSkinMaterial", "client.dll", "40 55 53 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44"sv, signature_resolve_kind::raw, 0, 0 },
	{ "C_EconEntity_BuildModernWeaponSkinMaterial", "client.dll", "48 85 C9 0F 84 ? ? 00 00 48 8B C4 48 89 50 10 48 89 48 08 55 41 55 41 56 41 57 48 8D A8 ? ? FF FF"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CUtlVector_CompositeMaterialInput_AddToTail", "client.dll", "48 89 6C 24 18 48 89 7C 24 20 41 56 48 83 EC 20 48 63 29 4C 8B F2 48 8B F9 3B 69 10 0F 85 ? ? ? ? F7 41 14 00 00 00 40 0F 85 ? ? ? ? 8B"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CompositeMaterialInputLooseVariable_AddToTail", "client.dll", "E8 ? ? ? ? 0F 28 B4 24 E0 02 00 00 4C 39 A5"sv, signature_resolve_kind::rel32, 1, 0 },
	{ "SceneSystem_ptr", "scenesystem.dll", "4C 8D 05 ? ? ? ? 48 63 C6"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "DrawObject_legacy", "scenesystem.dll", "48 8B C4 48 89 50 10 48 89 48 08 53 56"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSceneAnimatableObject::GeneratePrimitives", "scenesystem.dll", "48 8B C4 48 89 58 20 4C 89 40 18 48 89 50 10"sv, signature_resolve_kind::raw, 0, 0 },
	{ "CSceneSystem_RenderViewLayer_Dispatch", "scenesystem.dll", "48 8B C4 48 89 48 08 55 53 56 57 41 54 41 55 41 56 41 57 48 8D A8"sv, signature_resolve_kind::raw, 0, 0 },

	{ "TraceShape", "client.dll", "48 89 54 24 10 48 89 4C 24 08 55 53 56 57 41 54 41 56 41 57 48 8D AC 24 ? ? ? ? B8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceInitFilter", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 0F B6 41 ? 33 FF 24"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceInitData", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8D 79 ? 33 F6 C7 47"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TracePlayerBBox", "client.dll", "48 89 74 24 18 55 57 41 54 41 55 41 56 48 8D AC 24"sv, signature_resolve_kind::raw, 0, 0 },
	{ "TraceGetInfo", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B E9 0F 29 74 24 ? 48 8B CA 49 8B F9"sv, signature_resolve_kind::raw, 0, 0 },
	{ "OverrideView", "client.dll", "40 53 57 48 83 EC 58 48 8B FA E8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "GameEvent_GetInt64", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B 01 41 8B F0"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SendMessageClient", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 56 41 57 48 8D AC 24 ? ? ? ? B8 ? ? ? ? E8 ? ? ? ? 48 2B E0 45 33 FF 41"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdateSkyBox", "client.dll", "48 89 5C 24 ? 57 48 83 EC ? 48 8B F9 E8 ? ? ? ? 48 8B 47"sv, signature_resolve_kind::raw, 0, 0 },
	{ "UpdatePostProcessing", "client.dll", "48 85 D2 0F 84 ? ? ? ? 48 89 5C 24 ? 57 48 83 EC ? 80 3A 00 48 8B DA 48 8B F9 0F 84 ? ? ? ? 48 8D 15 ? ? ? ? C7"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawAggregateSceneObject", "scenesystem.dll", "48 8B C4 4C 89 40 18 48 89 50 10 55 53 41 57"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawLightScene", "scenesystem.dll", "48 89 54 24 10 55 57 41 56 48 83 EC 50"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawAggregateSceneObjectArray", "scenesystem.dll", "48 8B C4 48 89 50 ? 48 89 48 ? 55 53 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawSkyboxArray", "scenesystem.dll", "45 85 C9 0F 8E ? ? ? ? 4C 8B DC 55 41 56 49 8D AB 58 FC FF FF 48 81 EC 98 04 00 00"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DrawScope", "client.dll", "48 8B C4 53 57 48 83 EC ? 48 8B FA"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SmokeVolumeDrawArray", "client.dll", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC ? 48 8B 9C 24 ? ? ? ? 4D 8B F8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "FirstPersonLegs", "client.dll", "4C 8B DC 55 53 56 57 41 57 49 8D AB"sv, signature_resolve_kind::raw, 0, 0 },

	{ "GetGameParticleManager", "client.dll", "48 8B 0D ? ? ? ? 41 B8 ? ? ? ? F3 0F 11 74 24 ? 48 C7 44 24 ? ? ? ? ?"sv, signature_resolve_kind::riprel, 3, 0 },
	{ "CreateParticle", "client.dll", "4C 8B DC 53 48 81 EC ? ? ? ? F2 0F 10 05"sv, signature_resolve_kind::raw, 0, 0 },
	{ "SetParticleSettings", "client.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? F3 0F 10 1D ? ? ? ? 41 8B F8 8B DA 4C 8D 05"sv, signature_resolve_kind::raw, 0, 0 },
	{ "DestroyParticle", "client.dll", "83 FA ? 0F 84 ? ? ? ? 41 54"sv, signature_resolve_kind::raw, 0, 0 },

	{ "CreateMaterial", "materialsystem2.dll", "48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 48 89 7C 24 20 41 56 48 81 EC 10 01 00 00 48 8B 05 ? ? ? ? 4C 8B F2"sv, signature_resolve_kind::raw, 0, 0 },
	{ "KV3_SetType", "client.dll", "40 53 48 83 EC 30 80 FA 06 0F B6 C2 41 B9 16 00 00 00 48 8B D9 44 0F 45 C8"sv, signature_resolve_kind::raw, 0, 0 },
	{ "QueueForceSubtickMove", "client.dll", "48 83 EC 28 8B 0D ? ? ? ? 65 48 8B 04 25 58 00 00 00 BA 68 00 00 00 48 8B 04 C8 8B 04 02 39 05 ? ? ? ? 0F 8F 82"sv, signature_resolve_kind::raw, 0, 0 },
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
	dbg::t_stage = entry.name;
	std::uint8_t* address = g_opcodes->scan(entry.module_name, entry.pattern.data());
	if (!address) {
		LOG_ERROR("[signatures] couldn't find %s!%s (%s)", entry.module_name, entry.name, entry.pattern.data());
		return nullptr;
	}

	if (entry.resolve == signature_resolve_kind::raw) {
		DBG_INFO("[sig] %s!%s -> %s", entry.module_name, entry.name, dbg::addr(address + entry.extra_offset).s);
		return address + entry.extra_offset;
	}

	auto* resolved = resolve_relative(address, entry.rel_offset, entry.extra_offset);
	if (!resolved)
		LOG_ERROR("[signatures] couldn't resolve %s!%s", entry.module_name, entry.name);
	else
		DBG_INFO("[sig] %s!%s -> %s (match at %s)", entry.module_name, entry.name, dbg::addr(resolved).s, dbg::addr(address).s);

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
