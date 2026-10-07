#include "../../core/main.hpp"
#include "glow.hpp"
#include "../../hooks/hooks.hpp"
#include "../../sdk/valve/classes/c_cs_player_pawn.hpp"

void glow::update() {

}

enum class glow_type {
    none,
    enemy_player,
    weapon_drop,
    bomb
};

static bool contains_text(const char* text, const char* needle) {
    return text && needle && strstr(text, needle) != nullptr;
}

static bool is_ragdoll_entity(c_entity_instance* entity, const char* designer_name) {
    if (contains_text(designer_name, "ragdoll") || contains_text(designer_name, "Ragdoll"))
        return true;

    const char* class_name = nullptr;
    __try {
        class_name = entity ? entity->get_class_name() : nullptr;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return contains_text(designer_name, "ragdoll") || contains_text(designer_name, "Ragdoll") ||
        contains_text(class_name, "ragdoll") || contains_text(class_name, "Ragdoll");
}

static bool is_grenade_projectile(c_entity_instance* entity, const char* designer_name) {
    if (contains_text(designer_name, "_projectile"))
        return true;

    const char* class_name = nullptr;
    __try {
        class_name = entity ? entity->get_class_name() : nullptr;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return contains_text(designer_name, "_projectile") || contains_text(class_name, "Projectile");
}

static c_base_entity* get_base_entity_safe(int index) {
    if (!g_interfaces || !g_interfaces->m_entity_system)
        return nullptr;

    __try {
        return g_interfaces->m_entity_system->get_base_entity(index);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return nullptr;
    }
}

static uint16_t get_weapon_definition_index(c_base_player_weapon* weapon) {
    if (!weapon)
        return 0;

    __try {
        if (auto* attr_mgr = weapon->m_attribute_manager()) {
            if (auto* item = attr_mgr->m_item())
                return item->m_definition_index();
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {}

    return 0;
}

static bool is_planted_c4_entity(c_entity_instance* entity, const char* designer_name) {
    if (designer_name && strcmp(designer_name, "planted_c4") == 0)
        return true;

    __try {
        const char* class_name = entity ? entity->get_class_name() : nullptr;
        return class_name && strcmp(class_name, "C_PlantedC4") == 0;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool is_c4_weapon(c_base_player_weapon* weapon, c_entity_instance* entity, const char* designer_name) {
    (void)designer_name;
    constexpr uint16_t c4_definition_index = 49;
    if (get_weapon_definition_index(weapon) == c4_definition_index)
        return true;

    __try {
        const char* class_name = entity ? entity->get_class_name() : nullptr;
        return class_name && strcmp(class_name, "C_C4") == 0;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool is_grenade_weapon_class(c_base_player_weapon* weapon) {
    __try {
        const char* class_name = weapon ? reinterpret_cast<c_base_entity*>(weapon)->get_class_name() : nullptr;
        if (!class_name || contains_text(class_name, "Projectile"))
            return false;
        return contains_text(class_name, "Flashbang") || contains_text(class_name, "HEGrenade") ||
            contains_text(class_name, "SmokeGrenade") || contains_text(class_name, "Molotov") ||
            contains_text(class_name, "Decoy") || contains_text(class_name, "Incendiary");
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
}

static bool is_grenade_weapon(c_base_player_weapon* weapon, const char* designer_name) {
    switch (get_weapon_definition_index(weapon)) {
    case WEAPON_FLASHBANG:
    case WEAPON_HEGRENADE:
    case WEAPON_SMOKE:
    case WEAPON_MOLOTOV:
    case WEAPON_DECOY:
    case WEAPON_INCDENDIARY:
        return true;
    default:
        break;
    }

    return contains_text(designer_name, "flashbang") || contains_text(designer_name, "hegrenade") ||
        contains_text(designer_name, "smokegrenade") || contains_text(designer_name, "molotov") ||
        contains_text(designer_name, "decoy") || contains_text(designer_name, "incgrenade") ||
        contains_text(designer_name, "incendiary") || is_grenade_weapon_class(weapon);
}

static bool is_weapon_in_player_inventory(c_base_player_weapon* weapon) {
    if (!weapon || !g_interfaces || !g_interfaces->m_entity_system)
        return false;

    __try {
        if (g_ctx && g_ctx->m_local_pawn) {
            auto* local_pawn = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
            if (local_pawn->get_active_weapon() == weapon)
                return true;

            if (auto* weapon_services = local_pawn->m_weapon_services()) {
                auto& weapons = weapon_services->my_weapons();
                if (weapons.m_elements && weapons.m_size > 0 && weapons.m_size <= 64) {
                    for (unsigned int j = 0; j < weapons.m_size; ++j) {
                        const auto weapon_handle = weapons.m_elements[j];
                        if (!weapon_handle.is_valid())
                            continue;

                        if (get_base_entity_safe(weapon_handle.get_entry_index()) == weapon)
                            return true;
                    }
                }
            }
        }

        for (int i = 1; i <= 64; ++i) {
            auto* entity = get_base_entity_safe(i);
            if (!entity || !entity->is_player_controller())
                continue;

            auto* controller = reinterpret_cast<c_cs_player_controller*>(entity);
            const auto pawn_handle = controller->m_pawn();
            if (!pawn_handle.is_valid())
                continue;

            auto* pawn = reinterpret_cast<c_cs_player_pawn*>(get_base_entity_safe(pawn_handle.get_entry_index()));
            if (!pawn)
                continue;

            if (pawn->get_active_weapon() == weapon)
                return true;

            auto* weapon_services = pawn->m_weapon_services();
            if (!weapon_services)
                continue;

            auto& weapons = weapon_services->my_weapons();
            if (!weapons.m_elements || weapons.m_size == 0 || weapons.m_size > 64)
                continue;

            for (unsigned int j = 0; j < weapons.m_size; ++j) {
                const auto weapon_handle = weapons.m_elements[j];
                if (!weapon_handle.is_valid())
                    continue;

                if (get_base_entity_safe(weapon_handle.get_entry_index()) == weapon)
                    return true;
            }
        }
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return false;
}

static bool is_dropped_weapon(c_base_player_weapon* weapon, const char* designer_name) {
    if (!weapon)
        return false;
    (void)designer_name;

    if (is_weapon_in_player_inventory(weapon))
        return false;

    __try {
        const auto owner_handle = weapon->m_owner_entity();
        if (owner_handle.is_valid())
            return false;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }

    return true;
}

static glow_type get_glow_type(void* entity_ptr) {
    if (!g_cfg || !entity_ptr)
        return glow_type::none;

    if (!g_ctx || !g_ctx->m_local_pawn)
        return glow_type::none;

    __try {
        auto* entity = reinterpret_cast<c_entity_instance*>(entity_ptr);
        if (!entity)
            return glow_type::none;

        auto* identity = entity->m_entity();
        if (!identity)
            return glow_type::none;

        const char* designer_name = entity->get_designer_name();
        if (!designer_name)
            return glow_type::none;

        if (is_planted_c4_entity(entity, designer_name)) {
            constexpr uintptr_t m_bBombTicking = 0x1160;
            const bool is_ticking = *reinterpret_cast<bool*>(reinterpret_cast<uintptr_t>(entity_ptr) + m_bBombTicking);
            if (is_ticking && g_cfg->visuals.m_bomb_esp && (g_cfg->visuals.m_bomb_esp_type & (1 << 4)))
                return glow_type::bomb;
            return glow_type::none;
        }

        auto* possible_weapon = reinterpret_cast<c_base_player_weapon*>(entity_ptr);
        if (is_c4_weapon(possible_weapon, entity, designer_name)) {
            auto* weapon = possible_weapon;
            if (is_dropped_weapon(weapon, designer_name) && !is_weapon_in_player_inventory(weapon) &&
                g_cfg->visuals.m_bomb_esp && (g_cfg->visuals.m_bomb_esp_type & (1 << 4)))
                return glow_type::bomb;
            return glow_type::none;
        }
        if (strcmp(designer_name, "weapon_c4") == 0)
            return glow_type::none;

        if ((strstr(designer_name, "flashbang") != nullptr || strstr(designer_name, "hegrenade") != nullptr ||
            strstr(designer_name, "smokegrenade") != nullptr || strstr(designer_name, "decoy") != nullptr ||
            strstr(designer_name, "molotov") != nullptr || strstr(designer_name, "incendiary") != nullptr ||
            strstr(designer_name, "incgrenade") != nullptr) && is_grenade_projectile(entity, designer_name))
            return glow_type::none;

        if (strstr(designer_name, "weapon_") != nullptr || is_grenade_weapon(possible_weapon, designer_name)) {
            auto* weapon = possible_weapon;
            if (!weapon)
                return glow_type::none;

            if (!is_dropped_weapon(weapon, designer_name))
                return glow_type::none;

            if (g_cfg->visuals.m_weapon_drops && (g_cfg->visuals.m_weapon_drops_type & (1 << 4)))
                return glow_type::weapon_drop;
            return glow_type::none;
        }

        if (!g_cfg->visuals.m_glow)
            return glow_type::none;

        auto* local = reinterpret_cast<c_cs_player_pawn*>(g_ctx->m_local_pawn);
        auto* pawn = reinterpret_cast<c_cs_player_pawn*>(entity_ptr);
        if (!local || !pawn)
            return glow_type::none;

        if (is_ragdoll_entity(entity, designer_name) || pawn->m_health() <= 0)
            return glow_type::none;

        int local_team = local->m_team_num();
        int pawn_team = pawn->m_team_num();

        if (pawn_team != 2 && pawn_team != 3)
            return glow_type::none;

        if (local_team == 0 || pawn_team == 0 || pawn_team == local_team)
            return glow_type::none;

        return glow_type::enemy_player;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return glow_type::none;
    }
}

bool __fastcall hooks::glow_should_glow::hk_should_glow(void* glow_property) {
    auto original = m_should_glow.get_original<decltype(&hk_should_glow)>();
    if (!original)
        return false;

    if (!glow_property || !g_cfg)
        return original(glow_property);

    void* entity_ptr = nullptr;
    __try {
        entity_ptr = reinterpret_cast<void*>(
            *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(glow_property) + 0x18)
        );
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return original(glow_property);
    }

    glow_type type = get_glow_type(entity_ptr);
    if (type == glow_type::none)
        return original(glow_property);

    return true;
}

void __fastcall hooks::glow_apply_glow::hk_apply_glow(void* glow_property, void* glow_object) {
    auto original = m_apply_glow.get_original<decltype(&hk_apply_glow)>();
    if (!original)
        return;

    original(glow_property, glow_object);

    if (!glow_property || !glow_object || !g_cfg)
        return;

    void* entity_ptr = nullptr;
    __try {
        entity_ptr = reinterpret_cast<void*>(
            *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(glow_property) + 0x18)
        );
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return;
    }

    glow_type type = get_glow_type(entity_ptr);
    if (type == glow_type::none)
        return;

    __try {
        ImVec4 color;
        switch (type) {
            case glow_type::enemy_player:
                color = g_cfg->visuals.m_glow_color;
                break;
            case glow_type::weapon_drop:
                color = g_cfg->visuals.m_weapon_drops_color;
                break;
            case glow_type::bomb:
                color = g_cfg->visuals.m_bomb_esp_color;
                break;
            default:
                return;
        }

        float* glow_rgba = reinterpret_cast<float*>(glow_object);
        glow_rgba[0] = color.x;
        glow_rgba[1] = color.y;
        glow_rgba[2] = color.z;
        glow_rgba[3] = color.w;
    } __except (EXCEPTION_EXECUTE_HANDLER) {}
}
