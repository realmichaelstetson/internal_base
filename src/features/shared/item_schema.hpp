#pragma once

#include "../../core/main.hpp"
#include "../../sdk/valve/classes/game_enums.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../../sdk/valve/interfaces/vtables/i_econ_item_system.hpp"
#include <vector>
#include <string>
#include <unordered_map>

struct item_info_t {
	uint16_t definition_index;
	std::string name;
	std::string group;
	const char* model_path;
	int rarity = -1;
};

struct paint_kit_info_t {
	int id;
	std::string name;
	int rarity;
};

class c_item_schema {
public:
	std::vector<item_info_t> knives;
	std::vector<item_info_t> gloves;
	std::vector<item_info_t> weapons;
	std::vector<item_info_t> t_agents;
	std::vector<item_info_t> ct_agents;
	const char* default_t_agent_model = nullptr;
	const char* default_ct_agent_model = nullptr;

	std::vector<paint_kit_info_t> all_paint_kits;

	std::unordered_map<uint16_t, std::vector<paint_kit_info_t>> item_paint_kits;
	std::unordered_map<uint16_t, std::vector<const char*>> item_paint_kit_names;

	std::vector<const char*> knife_names_cstr;
	std::vector<const char*> glove_names_cstr;
	std::vector<const char*> weapon_names_cstr;
	std::vector<const char*> t_agent_names_cstr;
	std::vector<const char*> ct_agent_names_cstr;

	void initialize();
	bool is_initialized() const { return m_initialized; }

	void ensure_paint_kits_for_item(uint16_t def_index);

	const std::vector<const char*>& get_paint_kit_names_for_item(uint16_t def_index) {
		ensure_paint_kits_for_item(def_index);
		auto it = item_paint_kit_names.find(def_index);
		return it != item_paint_kit_names.end() ? it->second : empty_names;
	}

	int get_paint_kit_id_for_item(uint16_t def_index, int index) {
		ensure_paint_kits_for_item(def_index);
		auto it = item_paint_kits.find(def_index);
		if (it != item_paint_kits.end() && index >= 0 && index < (int)it->second.size())
			return it->second[index].id;
		return 0;
	}

private:
	bool m_initialized = false;
	std::vector<const char*> empty_names = { "Default" };
	c_utl_map<int, c_econ_item_definition*>* m_items = nullptr;
	c_utl_map<int, c_paint_kit*>* m_paint_kit_map = nullptr;
	bool is_paint_kit_for_item(const char* simple_weapon_name, c_paint_kit* paint_kit);
	void build_paint_kits_for_item(uint16_t def_index);
};

inline const auto g_item_schema = std::make_unique<c_item_schema>();

class c_hud {
public:
	static std::uintptr_t find_hud_element(const char* name);
	static void clear_hud_weapon_icon(std::uintptr_t hud_weapons, std::int32_t index, std::int64_t unk = 0);

	static void clear_hud_weapon_icons();

	static void clear_hud_weapon_icon_for(class c_base_entity* weapon);
};
