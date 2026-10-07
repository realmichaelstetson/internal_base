#pragma once

#include "../../core/main.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"
#include "../shared/item_schema.hpp"
#include <unordered_map>

class c_skin_changer {
public:
	void run(int stage);
	void initialize();
	void request_update();

	bool should_update = false;
	uint16_t m_current_weapon_def_index = 0;
	bool is_initialized() const { return m_initialized; }

	int round_start_delay_frames = 0;

private:
	bool m_initialized = false;
	uint16_t m_last_knife = 0;
	int m_last_knife_paint_kit_id = 0;
	float m_last_knife_wear = 0.0001f;
	int m_last_knife_seed = 0;
	int m_knife_update_frames = 0;
	float m_last_spawn_time = 0.0f;
	int m_last_team = 0;
	uint16_t m_last_agent = 0;
	int m_agent_update_frames = 0;
	std::string m_last_model_path;
	std::uintptr_t m_last_pawn = 0;
	std::unordered_map<std::uintptr_t, int> m_weapon_update_frames;

	c_base_entity* get_hud_weapon(c_base_entity* weapon, c_cs_player_pawn* local_pawn);
	void apply_skin(c_econ_entity* weapon, c_econ_item_view* item, int paint_kit_id, float wear, int seed, const char* custom_name, c_cs_player_pawn* local_pawn, uint16_t def_index = 0);
	void process_agent(c_cs_player_pawn* local_pawn, bool force_update);
	// Applies a custom .vmdl model to the local pawn (precache + set_model).
	// Returns true when the model changer is active and owns the pawn model this
	// frame, so the caller skips the agent changer (they both drive set_model).
	bool process_model(c_cs_player_pawn* local_pawn, bool force_update);
	void process_weapon(c_econ_entity* weapon, c_econ_item_view* item, c_cs_player_pawn* local_pawn, bool force_update);
	void process_knife(c_econ_entity* weapon, c_econ_item_view* item, c_cs_player_pawn* local_pawn, bool force_update);
};

inline const auto g_skin_changer = std::make_unique<c_skin_changer>();
