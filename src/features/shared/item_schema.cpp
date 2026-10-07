#include "item_schema.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/interfaces/vtables/i_localize.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include <algorithm>
#include <cctype>
#include <unordered_set>

static std::string normalized_sort_name(std::string value) {
	std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
		return (char)std::tolower(c);
	});
	return value;
}

static int weapon_group_rank(const std::string& group) {
	if (group.find("Pistol") != std::string::npos)
		return 0;
	if (group.find("Rifle") != std::string::npos)
		return 1;
	if (group.find("SMG") != std::string::npos || group.find("SubMachinegun") != std::string::npos)
		return 2;
	if (group.find("Sniper") != std::string::npos)
		return 3;
	if (group.find("Shotgun") != std::string::npos)
		return 4;
	if (group.find("Machine") != std::string::npos)
		return 5;
	return 6;
}

static bool is_t_agent_model(const char* model_path) {
	if (!model_path)
		return false;

	std::string value = normalized_sort_name(model_path);
	if (value.find("ctm_") != std::string::npos)
		return false;
	return value.find("/tm_") != std::string::npos || value.find("\\tm_") != std::string::npos
		|| value.find("tm_") != std::string::npos;
}

static bool is_ct_agent_model(const char* model_path) {
	if (!model_path)
		return false;

	std::string value = normalized_sort_name(model_path);
	return value.find("/ctm_") != std::string::npos || value.find("\\ctm_") != std::string::npos
		|| value.find("ctm_") != std::string::npos;
}

static bool is_default_agent_name(const std::string& name) {
	const std::string value = normalized_sort_name(name);
	return value.find("default") != std::string::npos && value.find("agent") != std::string::npos;
}

static const char* paint_kit_phase_suffix(const char* name) {
	if (!name)
		return "";

	std::string value = normalized_sort_name(name);
	if (value.find("emerald") != std::string::npos)
		return " (emerald)";
	if (value.find("ruby") != std::string::npos)
		return " (ruby)";
	if (value.find("sapphire") != std::string::npos)
		return " (sapphire)";
	if (value.find("blackpearl") != std::string::npos || value.find("black_pearl") != std::string::npos)
		return " (black pearl)";
	if (value.find("phase1") != std::string::npos || value.find("phase_1") != std::string::npos)
		return " (phase 1)";
	if (value.find("phase2") != std::string::npos || value.find("phase_2") != std::string::npos)
		return " (phase 2)";
	if (value.find("phase3") != std::string::npos || value.find("phase_3") != std::string::npos)
		return " (phase 3)";
	if (value.find("phase4") != std::string::npos || value.find("phase_4") != std::string::npos)
		return " (phase 4)";

	return "";
}

bool c_item_schema::is_paint_kit_for_item(const char* simple_weapon_name, c_paint_kit* paint_kit) {
	if (!simple_weapon_name || !paint_kit || !paint_kit->m_name)
		return false;

	std::string path = "panorama/images/econ/default_generated/" +
		std::string(simple_weapon_name) + "_" +
		paint_kit->m_name + "_light_png.vtex_c";

	return g_interfaces->m_file_system->exists(path.c_str(), "GAME");
}

void c_item_schema::build_paint_kits_for_item(uint16_t def_index) {
	if (!m_items || !m_paint_kit_map)
		return;

	c_econ_item_definition* item_def = nullptr;
	const int items_n = m_items->count();
	for (int i = 0; i < items_n; i++) {
		auto& node = m_items->element(i);
		if (node.m_value && node.m_value->m_definition_index == def_index) {
			item_def = node.m_value;
			break;
		}
	}

	if (!item_def)
		return;

	const char* simple_name = item_def->get_item_name();
	if (!simple_name || simple_name[0] == '\0')
		return;

	item_paint_kits[def_index].push_back({ 0, "default", -1 });

	const int kits_n = m_paint_kit_map->count();
	for (int i = 0; i < kits_n; i++) {
		auto& node = m_paint_kit_map->element(i);
		if (!node.m_value)
			continue;

		c_paint_kit* kit = node.m_value;
		if (!kit->m_name || kit->m_id <= 0)
			continue;

		if (is_paint_kit_for_item(simple_name, kit)) {

			const char* display = localize::find_safe(kit->m_description_tag);
			if (!display || !*display)
				display = kit->m_name;

			std::string display_name = display;
			std::transform(display_name.begin(), display_name.end(), display_name.begin(),
			               [](unsigned char c) { return (char)std::tolower(c); });
			const char* suffix = paint_kit_phase_suffix(kit->m_name);
			if (suffix[0] != '\0' && display_name.find('(') == std::string::npos)
				display_name += suffix;

			item_paint_kits[def_index].push_back({ kit->m_id, display_name, kit->m_rarity });
		}
	}

	auto& kits = item_paint_kits[def_index];
	std::stable_sort(kits.begin(), kits.end(), [](const paint_kit_info_t& a, const paint_kit_info_t& b) {
		if (a.id == 0)
			return true;
		if (b.id == 0)
			return false;
		if (a.rarity != b.rarity)
			return a.rarity > b.rarity;
		return normalized_sort_name(a.name) < normalized_sort_name(b.name);
	});
}

void c_item_schema::ensure_paint_kits_for_item(uint16_t def_index) {
	if (!m_initialized || item_paint_kits.find(def_index) != item_paint_kits.end())
		return;

	build_paint_kits_for_item(def_index);

	auto& kits = item_paint_kits[def_index];
	auto& names = item_paint_kit_names[def_index];
	names.reserve(kits.size());
	for (auto& kit : kits)
		names.push_back(kit.name.c_str());
}

void c_item_schema::initialize() {
	if (m_initialized)
		return;

	auto* item_system = g_interfaces->m_source2_client->get_econ_item_system();
	if (!item_system)
		return;

	auto* item_schema = item_system->get_econ_item_schema();
	if (!item_schema)
		return;

	auto& items = item_schema->get_sorted_item_definition_map();
	auto& paint_kit_map = item_schema->get_paint_kits();

	m_items = &items;
	m_paint_kit_map = &paint_kit_map;

	t_agents.push_back({ 0, "default", "agent", nullptr });
	ct_agents.push_back({ 0, "default", "agent", nullptr });
	std::unordered_set<uint16_t> t_agent_defs;
	std::unordered_set<uint16_t> ct_agent_defs;
	std::unordered_set<std::string> t_agent_names = { "default" };
	std::unordered_set<std::string> ct_agent_names = { "default" };

	auto add_agent = [](std::vector<item_info_t>& out,
	                    std::unordered_set<uint16_t>& defs,
	                    std::unordered_set<std::string>& names,
	                    const item_info_t& item) {
		if (item.definition_index == 0 || !item.model_path || is_default_agent_name(item.name))
			return;

		const std::string key = normalized_sort_name(item.name);
		if (defs.find(item.definition_index) != defs.end() || names.find(key) != names.end())
			return;

		defs.insert(item.definition_index);
		names.insert(key);
		out.push_back(item);
	};

	const int items_n = items.count();
	for (int i = 0; i < items_n; i++) {
		auto& node = items.element(i);
		if (!node.m_value || !node.m_value->m_item_type_name)
			continue;

		c_econ_item_definition* item_def = node.m_value;

		std::string item_name;
		if (item_def->m_item_base_name && item_def->m_item_base_name[0] != '\0') {
			const char* localized = localize::find_safe(item_def->m_item_base_name);
			item_name = (localized && *localized) ? localized : item_def->m_item_base_name;
		} else {
			item_name = "Item " + std::to_string(item_def->m_definition_index);
		}

		const char* model_path = item_def->get_model_name();

		if (item_def->is_knife(false)) {
			std::transform(item_name.begin(), item_name.end(), item_name.begin(),
			               [](unsigned char c) { return (char)std::tolower(c); });
			knives.push_back({ item_def->m_definition_index, item_name, "knife", model_path });
		}
		else if (item_def->is_glove(false)) {
			std::transform(item_name.begin(), item_name.end(), item_name.begin(),
			               [](unsigned char c) { return (char)std::tolower(c); });
			gloves.push_back({ item_def->m_definition_index, item_name, "glove", model_path });
		}
		else if (item_def->is_agent()) {
			std::transform(item_name.begin(), item_name.end(), item_name.begin(),
			               [](unsigned char c) { return (char)std::tolower(c); });
			if (is_ct_agent_model(model_path)) {
				if (is_default_agent_name(item_name)) {
					if (!default_ct_agent_model)
						default_ct_agent_model = model_path;
				}
				else {
					add_agent(ct_agents, ct_agent_defs, ct_agent_names, { item_def->m_definition_index, item_name, "agent", model_path, item_def->m_item_rarity });
				}
			}
			else if (is_t_agent_model(model_path)) {
				if (is_default_agent_name(item_name)) {
					if (!default_t_agent_model)
						default_t_agent_model = model_path;
				}
				else {
					add_agent(t_agents, t_agent_defs, t_agent_names, { item_def->m_definition_index, item_name, "agent", model_path, item_def->m_item_rarity });
				}
			}
		}
		else {
			const char* type_name = item_def->m_item_type_name;
			bool is_weapon = strstr(type_name, "Pistol") || strstr(type_name, "Rifle") ||
			                 strstr(type_name, "SMG") || strstr(type_name, "Sniper") ||
			                 strstr(type_name, "Shotgun") || strstr(type_name, "Machine") ||
			                 strstr(type_name, "SubMachinegun") ||
			                 item_def->m_definition_index == WEAPON_TASER;

			if (is_weapon && item_def->m_definition_index > 0 && item_def->m_definition_index <= 70)
				weapons.push_back({ item_def->m_definition_index, item_name, type_name ? type_name : "", model_path });
		}
	}

	std::sort(knives.begin(), knives.end(), [](const item_info_t& a, const item_info_t& b) {
		return normalized_sort_name(a.name) < normalized_sort_name(b.name);
	});
	std::sort(gloves.begin(), gloves.end(), [](const item_info_t& a, const item_info_t& b) {
		return normalized_sort_name(a.name) < normalized_sort_name(b.name);
	});
	std::sort(weapons.begin(), weapons.end(), [](const item_info_t& a, const item_info_t& b) {
		const int ar = weapon_group_rank(a.group);
		const int br = weapon_group_rank(b.group);
		if (ar != br)
			return ar < br;
		return normalized_sort_name(a.name) < normalized_sort_name(b.name);
	});
	auto agent_sort = [](const item_info_t& a, const item_info_t& b) {
		if (a.definition_index == 0)
			return true;
		if (b.definition_index == 0)
			return false;
		if (a.rarity != b.rarity)
			return a.rarity > b.rarity;
		return normalized_sort_name(a.name) < normalized_sort_name(b.name);
	};
	std::sort(t_agents.begin(), t_agents.end(), agent_sort);
	std::sort(ct_agents.begin(), ct_agents.end(), agent_sort);

	for (auto& knife : knives)
		knife_names_cstr.push_back(knife.name.c_str());
	for (auto& glove : gloves)
		glove_names_cstr.push_back(glove.name.c_str());
	for (auto& weapon : weapons)
		weapon_names_cstr.push_back(weapon.name.c_str());
	for (auto& agent : t_agents)
		t_agent_names_cstr.push_back(agent.name.c_str());
	for (auto& agent : ct_agents)
		ct_agent_names_cstr.push_back(agent.name.c_str());

	m_initialized = true;
	LOG_INFO(xorstr_("[item_schema] %d knives, %d gloves, %d weapons, %d t agents, %d ct agents"),
		(int)knives.size() - 1, (int)gloves.size() - 1, (int)weapons.size(),
		(int)t_agents.size() - 1, (int)ct_agents.size() - 1);
}

std::uintptr_t c_hud::find_hud_element(const char* name) {

	using fn_t = std::uintptr_t(__fastcall*)(const char*);
	static auto fn = reinterpret_cast<fn_t>(
		SIG("FindHudElement")
	);
	return fn ? fn(name) : 0;
}

void c_hud::clear_hud_weapon_icon(std::uintptr_t hud_weapons, std::int32_t index, std::int64_t unk) {
	static auto fn = reinterpret_cast<std::int64_t(__fastcall*)(std::uintptr_t, std::int32_t, std::int64_t)>(
		SIG("ClearHUDWeaponIcon")
	);
	if (!fn)
		return;

	fn(hud_weapons, index, unk);
}

struct hud_weapon_panel_t {
	std::uintptr_t base  = 0;
	std::uintptr_t data  = 0;
	std::int32_t   count = 0;
};

static bool resolve_weapon_panel(hud_weapon_panel_t& out) {
	const auto hud = c_hud::find_hud_element("HudWeaponSelection");
	if (!valid_ptr(hud))
		return false;

	out.base  = hud - 0x98;
	out.data  = *reinterpret_cast<std::uintptr_t*>(out.base + 0x58);
	out.count = *reinterpret_cast<std::int32_t*>  (out.base + 0x50);
	return valid_ptr(out.data) && out.count > 0 && out.count <= 64;
}

void c_hud::clear_hud_weapon_icons() {
	__try {
		hud_weapon_panel_t panel;
		if (!resolve_weapon_panel(panel))
			return;
		for (std::int32_t i = panel.count - 1; i >= 0; --i)
			clear_hud_weapon_icon(panel.base, i, 0);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}
}

void c_hud::clear_hud_weapon_icon_for(c_base_entity* weapon) {
	if (!valid_ptr(weapon))
		return;
	__try {
		hud_weapon_panel_t panel;
		if (!resolve_weapon_panel(panel))
			return;

		auto* es = g_interfaces->m_entity_system;
		for (std::int32_t i = panel.count - 1; i >= 0; --i) {
			const auto handle = *reinterpret_cast<std::int32_t*>(panel.data + 72 * i + 0x38);
			if (handle < 0)
				continue;
			if (es->get_base_entity(handle & 0x7FFF) == weapon) {
				clear_hud_weapon_icon(panel.base, i, 0);
				return;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}
}
