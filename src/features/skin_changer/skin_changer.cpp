#include "skin_changer.hpp"
#include "../model_changer/model_changer.hpp"
#include "../shared/econ_item_attribute_manager.hpp"
#include "../shared/item_schema.hpp"
#include "../../sdk/valve/interfaces/interfaces.hpp"
#include "../../sdk/valve/schema/schema.hpp"
#include "../../sdk/valve/interfaces/vtables/i_econ_item_system.hpp"

namespace {
	constexpr int k_skin_reapply_frames = 8;
}

c_base_entity* c_skin_changer::get_hud_weapon(c_base_entity* weapon, c_cs_player_pawn* local_pawn) {
	if (!valid_ptr(weapon) || !valid_ptr(local_pawn))
		return nullptr;

	__try {
		auto arms_handle = local_pawn->m_hud_model_arms();
		if (!arms_handle.is_valid())
			return nullptr;

		auto* hud_arms = reinterpret_cast<c_base_entity*>(
			g_interfaces->m_entity_system->get_base_entity(arms_handle.get_entry_index())
		);
		if (!valid_ptr(hud_arms))
			return nullptr;

		auto* arms_node = hud_arms->m_scene_node();
		if (!valid_ptr(arms_node))
			return nullptr;

		for (auto* vm = arms_node->m_child(); valid_ptr(vm); vm = vm->m_next_sibling()) {
			auto* vm_owner = vm->m_owner();
			if (!valid_ptr(vm_owner))
				continue;

			auto* vm_entity = reinterpret_cast<c_base_entity*>(vm_owner);
			auto owner_handle = vm_entity->m_owner_entity();
			if (!owner_handle.is_valid())
				continue;

			if (g_interfaces->m_entity_system->get_base_entity(owner_handle.get_entry_index()) == weapon)
				return vm_entity;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {

		return nullptr;
	}
	return nullptr;
}

void c_skin_changer::apply_skin(c_econ_entity* weapon, c_econ_item_view* item, int paint_kit_id, float wear, int seed, const char* custom_name, c_cs_player_pawn* local_pawn, uint16_t def_index) {
	(void)def_index;
	if (!valid_ptr(weapon) || !valid_ptr(item) || paint_kit_id <= 0)
		return;

	__try {
		econ_item_attribute_manager::remove(item);
		econ_item_attribute_manager::create(item, paint_kit_id, wear, seed);

		c_paint_kit* desired_paint_kit = nullptr;
		if (auto* item_system = g_interfaces->m_source2_client->get_econ_item_system())
			if (auto* item_schema = item_system->get_econ_item_schema())
				desired_paint_kit = item_schema->get_paint_kits().find_by_key(paint_kit_id);

		item->m_item_id_high() = 0xFFFFFFFF;
		item->m_item_id_low() = 0xFFFFFFFF;
		item->m_restore_custom_material_after_precache() = true;
		item->m_initialized() = true;
		item->m_initialized_tags() = false;
		weapon->m_paint_kit() = paint_kit_id;
		weapon->m_wear() = wear;
		weapon->m_seed() = seed;
		weapon->m_attributes_initialized() = true;
		weapon->m_original_owner_xuid_low() = 0;
		weapon->m_original_owner_xuid_high() = 0;
		item->m_entity_quality() = QUALITY_UNUSUAL;

		if (custom_name && custom_name[0] != '\0')
			strcpy_s(item->m_custom_name(), 161, custom_name);

		bool uses_old_model = desired_paint_kit ? desired_paint_kit->uses_old_model() : false;

		uint64_t mesh_mask = uses_old_model ? 2 : 1;

		if (auto* scene_node = weapon->m_scene_node())
			scene_node->set_mesh_group_mask(mesh_mask);

		if (auto* hud_weapon = get_hud_weapon(weapon, local_pawn))
			if (auto* hud_node = hud_weapon->m_scene_node())
				hud_node->set_mesh_group_mask(mesh_mask);

		weapon->apply_econ_customization(true);
		weapon->update_skin(true);
		weapon->regenerate_weapon_skin(true);
		if (auto* hud_weapon = reinterpret_cast<c_econ_entity*>(get_hud_weapon(weapon, local_pawn))) {
			hud_weapon->apply_econ_customization(true);
			hud_weapon->update_skin(true);
			hud_weapon->regenerate_weapon_skin(true);
		}
		weapon->update_weapon_data();
		item->m_name_description_ptr() = 0;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {

		return;
	}
}

void c_skin_changer::initialize() {
	if (m_initialized)
		return;

	if (!g_item_schema->is_initialized())
		g_item_schema->initialize();

	m_initialized = g_item_schema->is_initialized();
}

void c_skin_changer::request_update() {
	should_update = true;
	m_weapon_update_frames.clear();
	m_knife_update_frames = k_skin_reapply_frames;
	m_agent_update_frames = k_skin_reapply_frames;
	round_start_delay_frames = 0;

	m_last_knife = 0;
	m_last_knife_paint_kit_id = 0;
	m_last_knife_wear = 0.0001f;
	m_last_knife_seed = 0;
}

void c_skin_changer::process_weapon(c_econ_entity* weapon, c_econ_item_view* item, c_cs_player_pawn* local_pawn, bool force_update) {
	if (!valid_ptr(weapon) || !valid_ptr(item) || !valid_ptr(local_pawn))
		return;

	uint16_t def_index = item->m_definition_index();
	int config_index = c_config::skin_changer_t::get_config_index(def_index);
	if (config_index == 0)
		return;

	auto& skin = g_cfg->skin_changer.weapon_skins[config_index];
	if (skin.paint_kit == 0 && !skin.paint_color)
		return;

	int paint_kit_id = 0;
	if (skin.paint_kit > 0) {
		paint_kit_id = g_item_schema->get_paint_kit_id_for_item(def_index, skin.paint_kit);
		if (paint_kit_id == 0)
			return;
	}

	const int current_paint_kit = weapon->m_paint_kit();
	const bool state_changed = current_paint_kit != paint_kit_id
	                        || weapon->m_wear() != skin.wear
	                        || weapon->m_seed() != skin.seed
	                        || item->m_item_id_high() != 0xFFFFFFFF
	                        || item->m_item_id_low() != 0xFFFFFFFF
	                        || !weapon->m_attributes_initialized()
	                        || !item->m_initialized();

	auto& update_frames = m_weapon_update_frames[reinterpret_cast<std::uintptr_t>(weapon)];
	const bool paint_color_only = paint_kit_id == 0 && skin.paint_color;
	if (force_update || state_changed || paint_color_only)
		update_frames = k_skin_reapply_frames;

	if (update_frames <= 0)
		return;

	if (paint_kit_id > 0) {
		apply_skin(weapon, item, paint_kit_id, skin.wear, skin.seed, skin.custom_name, local_pawn, def_index);
	} else if (skin.paint_color) {
		weapon->apply_econ_customization(true);
		weapon->update_skin(true);
		weapon->regenerate_weapon_skin(true);
		if (auto* hud_weapon = reinterpret_cast<c_econ_entity*>(get_hud_weapon(weapon, local_pawn))) {
			hud_weapon->apply_econ_customization(true);
			hud_weapon->update_skin(true);
			hud_weapon->regenerate_weapon_skin(true);
		}
	}

	if (state_changed || force_update)
		c_hud::clear_hud_weapon_icon_for(weapon);
	update_frames--;
}

void c_skin_changer::process_knife(c_econ_entity* weapon, c_econ_item_view* item, c_cs_player_pawn* local_pawn, bool force_update) {
	if (!valid_ptr(weapon) || !valid_ptr(item) || !valid_ptr(local_pawn))
		return;

	if (g_cfg->knife_changer.m_knife < 0)
		return;
	if (!g_item_schema->is_initialized()
		|| g_cfg->knife_changer.m_knife >= (int)g_item_schema->knives.size())
		return;

	const uint16_t def_index      = item->m_definition_index();
	const uint16_t selected_knife = g_item_schema->knives[g_cfg->knife_changer.m_knife].definition_index;
	if (selected_knife == 0)
		return;

	int paint_kit_id = g_item_schema->get_paint_kit_id_for_item(selected_knife, g_cfg->knife_changer.m_paint_kit);
	bool config_changed = (m_last_knife != selected_knife) ||
	                      (m_last_knife_paint_kit_id != paint_kit_id) ||
	                      (m_last_knife_wear != g_cfg->knife_changer.m_wear) ||
	                      (m_last_knife_seed != g_cfg->knife_changer.m_seed);

	const bool state_changed = def_index != selected_knife
	                        || weapon->m_paint_kit() != paint_kit_id
	                        || weapon->m_wear() != g_cfg->knife_changer.m_wear
	                        || weapon->m_seed() != g_cfg->knife_changer.m_seed
	                        || item->m_item_id_high() != 0xFFFFFFFF
	                        || item->m_item_id_low() != 0xFFFFFFFF
	                        || !weapon->m_attributes_initialized()
	                        || !item->m_initialized();

	if (config_changed || force_update || state_changed)
		m_knife_update_frames = k_skin_reapply_frames;

	if (m_knife_update_frames <= 0)
		return;

	__try {
		item->m_definition_index() = selected_knife;
		item->m_entity_quality() = QUALITY_UNUSUAL;
		item->m_item_id_high() = 0xFFFFFFFF;
		item->m_item_id_low() = 0xFFFFFFFF;
		item->m_restore_custom_material_after_precache() = true;
		item->m_initialized() = true;
		item->m_initialized_tags() = false;
		weapon->m_attributes_initialized() = true;
		weapon->m_original_owner_xuid_low() = 0;
		weapon->m_original_owner_xuid_high() = 0;

		if (const char* model_path = g_item_schema->knives[g_cfg->knife_changer.m_knife].model_path) {
			weapon->set_model(model_path);
			if (auto* hud_weapon = get_hud_weapon(weapon, local_pawn))
				hud_weapon->set_model(model_path);
		}

		econ_item_attribute_manager::remove(item);
		if (paint_kit_id > 0)
			econ_item_attribute_manager::create(item, paint_kit_id, g_cfg->knife_changer.m_wear, g_cfg->knife_changer.m_seed);
		weapon->m_paint_kit() = paint_kit_id;
		weapon->m_wear() = g_cfg->knife_changer.m_wear;
		weapon->m_seed() = g_cfg->knife_changer.m_seed;

		bool uses_old_model = false;
		if (paint_kit_id > 0) {
			if (auto* item_system = g_interfaces->m_source2_client->get_econ_item_system())
				if (auto* item_schema = item_system->get_econ_item_schema())
					if (auto* desired_paint_kit = item_schema->get_paint_kits().find_by_key(paint_kit_id)) {
						uses_old_model = desired_paint_kit->uses_old_model();
					}
		}

		uint64_t mesh_mask = uses_old_model ? 2 : 1;
		if (auto* scene_node = weapon->m_scene_node())
			scene_node->set_mesh_group_mask(mesh_mask);
		if (auto* hud_weapon = get_hud_weapon(weapon, local_pawn))
			if (auto* hud_node = hud_weapon->m_scene_node())
				hud_node->set_mesh_group_mask(mesh_mask);

		if (g_cfg->knife_changer.m_custom_name[0] != '\0')
			strcpy_s(item->m_custom_name(), 161, g_cfg->knife_changer.m_custom_name);
		else
			item->m_custom_name()[0] = '\0';

		weapon->update_subclass(selected_knife);
		weapon->update_skin(true);
		weapon->update_weapon_data();
		item->m_name_description_ptr() = 0;

		m_last_knife = selected_knife;
		m_last_knife_paint_kit_id = paint_kit_id;
		m_last_knife_wear = g_cfg->knife_changer.m_wear;
		m_last_knife_seed = g_cfg->knife_changer.m_seed;
		m_knife_update_frames--;
		if (config_changed || state_changed || force_update)
			c_hud::clear_hud_weapon_icon_for(weapon);
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {

		m_knife_update_frames = 0;
		return;
	}
}

void c_skin_changer::process_agent(c_cs_player_pawn* local_pawn, bool force_update) {
	if (!valid_ptr(local_pawn) || !g_cfg->agent_changer.m_enabled || !g_item_schema->is_initialized())
		return;

	const int team = local_pawn->m_team_num();
	const bool is_t = team == 2;
	const bool is_ct = team == 3;
	if (!is_t && !is_ct)
		return;

	const auto& agents = is_t ? g_item_schema->t_agents : g_item_schema->ct_agents;
	const int selected = is_t ? g_cfg->agent_changer.m_selected_t_agent : g_cfg->agent_changer.m_selected_ct_agent;
	if (selected <= 0 || selected >= (int)agents.size()) {
		const char* default_model = is_t ? g_item_schema->default_t_agent_model : g_item_schema->default_ct_agent_model;
		if (!default_model) {
			m_last_agent = 0;
			return;
		}

		if (force_update || m_last_agent != 0)
			m_agent_update_frames = k_skin_reapply_frames;

		if (m_agent_update_frames <= 0)
			return;

		__try {
			if (auto* identity = local_pawn->m_entity())
				if (!identity->is_safe_to_modify())
					return;

			local_pawn->set_model(default_model);
			m_last_agent = 0;
			m_agent_update_frames--;
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			m_agent_update_frames = 0;
		}
		return;
	}

	const auto& agent = agents[selected];
	if (agent.definition_index == 0 || !agent.model_path)
		return;

	const bool config_changed = m_last_agent != agent.definition_index;
	if (force_update || config_changed)
		m_agent_update_frames = k_skin_reapply_frames;

	if (m_agent_update_frames <= 0)
		return;

	__try {
		if (auto* identity = local_pawn->m_entity())
			if (!identity->is_safe_to_modify())
				return;

		local_pawn->set_model(agent.model_path);

		m_last_agent = agent.definition_index;
		m_agent_update_frames--;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		m_agent_update_frames = 0;
	}
}

bool c_skin_changer::process_model(c_cs_player_pawn* local_pawn, bool force_update) {
	if (!valid_ptr(local_pawn) || !g_cfg->model_changer.m_enabled)
		return false;

	g_model_changer->initialize();

	const char* model_path = g_model_changer->selected_model_path();
	if (!model_path || !model_path[0]) {
		// "[ off ]" -- restore the default team model. If agent changer is
		// enabled it will take over next frame; otherwise do it right now.
		m_last_model_path.clear();
		m_last_agent = 0;
		m_agent_update_frames = k_skin_reapply_frames;

		if (!g_cfg->agent_changer.m_enabled) {
			const int team = local_pawn->m_team_num();
			const char* default_model = team == 2 ? g_item_schema->default_t_agent_model
			                     : team == 3 ? g_item_schema->default_ct_agent_model
			                     : nullptr;
			if (default_model) {
				__try {
					local_pawn->set_model(default_model);
					if (auto arms_handle = local_pawn->m_hud_model_arms(); arms_handle.is_valid())
						if (auto* arms = reinterpret_cast<c_base_entity*>(
								g_interfaces->m_entity_system->get_base_entity(arms_handle.get_entry_index())))
							if (valid_ptr(arms))
								arms->set_model(default_model);
				}
				__except (EXCEPTION_EXECUTE_HANDLER) {
				}
			}
		}

		return false;
	}

	const bool config_changed = m_last_model_path != model_path;
	if (force_update || config_changed)
		m_agent_update_frames = k_skin_reapply_frames;

	if (m_agent_update_frames <= 0)
		return true;

	__try {
		if (auto* identity = local_pawn->m_entity())
			if (!identity->is_safe_to_modify())
				return true;

		g_model_changer->precache(model_path);
		local_pawn->set_model(model_path);

		// The first-person viewmodel arms are a separate entity (m_hHudModelArms)
		// that otherwise keeps the default agent gloves/arms -- leaving two sets of
		// hands (default gloves in the viewmodel, the custom model's arms clipping
		// in from the world model). Point the arms entity at the same custom model
		// so the viewmodel hands match. The engine attaches the arms to the weapon's
		// hand bones, so only the forearms/hands render.
		if (auto arms_handle = local_pawn->m_hud_model_arms(); arms_handle.is_valid()) {
			if (auto* arms = reinterpret_cast<c_base_entity*>(
					g_interfaces->m_entity_system->get_base_entity(arms_handle.get_entry_index())))
				if (valid_ptr(arms))
					arms->set_model(model_path);
		}

		m_last_model_path = model_path;
		m_last_agent = 0; // force the agent changer to reapply if we later yield
		m_agent_update_frames--;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		m_agent_update_frames = 0;
	}
	return true;
}

void c_skin_changer::run(int stage) {
	if (stage != 7)
		return;

	const bool skin_enabled  = g_cfg->skin_changer.m_enabled;
	const bool knife_enabled = g_cfg->knife_changer.m_enabled;
	const bool agent_enabled = g_cfg->agent_changer.m_enabled;
	const bool model_enabled = g_cfg->model_changer.m_enabled;
	if (!skin_enabled && !knife_enabled && !agent_enabled && !model_enabled) {
		should_update = false;
		return;
	}

	if (round_start_delay_frames > 0) {
		round_start_delay_frames--;
		return;
	}

	__try {
		if (!g_ctx->m_local_pawn)
			return;

		auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
		if (!valid_ptr(local_pawn))
			return;

		int health = 0;
		__try {
			health = local_pawn->m_health();
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return;
		}

		if (health <= 0)
			return;

		auto* identity = local_pawn->m_entity();
		if (!identity || !identity->is_valid())
			return;

		if (local_pawn->m_is_buy_menu_open())
			should_update = true;

	const auto current_pawn = reinterpret_cast<std::uintptr_t>(local_pawn);
	const int current_team = local_pawn->m_team_num();
	if (current_pawn != m_last_pawn || (m_last_team != 0 && current_team != m_last_team)) {
		should_update = true;
		m_last_pawn = current_pawn;
		m_last_team = current_team;
		m_last_agent = 0;
		m_weapon_update_frames.clear();
		m_knife_update_frames = k_skin_reapply_frames;
		m_agent_update_frames = k_skin_reapply_frames;
	}
	else if (m_last_team == 0) {
		m_last_team = current_team;
	}

	const float current_spawn_time = local_pawn->m_last_spawn_time_index();
	if (current_spawn_time != m_last_spawn_time) {
		should_update = true;
		m_last_spawn_time = current_spawn_time;
		m_weapon_update_frames.clear();
		m_last_agent = 0;
		m_agent_update_frames = k_skin_reapply_frames;
	}

	bool model_handled = false;
	if (model_enabled)
		model_handled = process_model(local_pawn, should_update);
	if (agent_enabled && !model_handled)
		process_agent(local_pawn, should_update);

	auto* weapon_service = local_pawn->m_weapon_services();
	if (!valid_ptr(weapon_service))
		return;

	auto& my_weapons   = weapon_service->my_weapons();

	if (!valid_ptr(&my_weapons) || my_weapons.m_size == 0 || my_weapons.m_size > 64)
		return;

	auto* entity_system = g_interfaces->m_entity_system;
	if (!valid_ptr(entity_system))
		return;

	uint16_t active_def_index = 0;
	m_current_weapon_def_index = 0;
	if (auto* active = local_pawn->get_active_weapon()) {
		if (auto* attr_mgr = active->m_attribute_manager()) {
			if (auto* item = attr_mgr->m_item()) {
				active_def_index = item->m_definition_index();
				m_current_weapon_def_index = active_def_index;
			}
		}
	}

	const bool force_update = should_update;
	bool keep_update_pending = false;

	__try {
		for (unsigned int i = 0; i < my_weapons.m_size; i++) {

			if (i >= 64) break;

			auto* weapon = reinterpret_cast<c_econ_entity*>(
				entity_system->get_base_entity(my_weapons.m_elements[i].get_entry_index())
			);
			if (!valid_ptr(weapon))
				continue;

				auto* item_identity = weapon->m_entity();
			if (!item_identity || !item_identity->is_valid())
				continue;
			if (!item_identity->is_safe_to_modify()) {
				if (force_update)
					keep_update_pending = true;
				continue;
			}

			auto* attr_mgr = weapon->m_attribute_manager();
			if (!valid_ptr(attr_mgr))
				continue;

			auto* item = attr_mgr->m_item();
			if (!valid_ptr(item))
				continue;

			const uint16_t def_index = item->m_definition_index();
			const bool is_knife = (def_index == WEAPON_KNIFE || def_index == WEAPON_KNIFE_T
			                   || (def_index >= 500 && def_index <= 526));

			const int wi = c_config::skin_changer_t::get_config_index(def_index);
			const bool has_paint_color = wi > 0 && g_cfg->skin_changer.weapon_skins[wi].paint_color;

			if (is_knife && knife_enabled)
				process_knife(weapon, item, local_pawn, force_update);
			else if (!is_knife && (skin_enabled || has_paint_color))
				process_weapon(weapon, item, local_pawn, force_update);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {

		should_update = false;
		return;
	}

	should_update = keep_update_pending;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {

		should_update = false;
		round_start_delay_frames = 0;
	}
}
