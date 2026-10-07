#include "../../core/main.hpp"
#include "removals.hpp"
#include "../../config.hpp"
#include "../../sdk/valve/classes/c_view_setup.hpp"
#include "../../sdk/valve/interfaces/vtables/i_csgo_input.hpp"

#include <cstdint>
#include <cstring>
#include <mutex>
#include "../../sdk/valve/schema/schema.hpp"

namespace removals {
    namespace {
        constexpr int k_remove_flash = 1 << 0;
        constexpr int k_remove_players = 1 << 1;
        constexpr int k_remove_particles = 1 << 2;
        constexpr int k_remove_world = 1 << 3;
        constexpr int k_remove_hud = 1 << 4;
        constexpr int k_remove_viewmodel = 1 << 5;
        constexpr int k_remove_post_processing = 1 << 6;
        constexpr int k_remove_scope = 1 << 7;
        constexpr int k_remove_smoke = 1 << 8;
        struct flash_offsets_t {
            std::uint32_t bang_time = 0;
            std::uint32_t screenshot_alpha = 0;
            std::uint32_t overlay_alpha = 0;
            std::uint32_t build_up = 0;
            std::uint32_t dsp_cleared = 0;
            std::uint32_t screenshot_grabbed = 0;
            std::uint32_t max_alpha = 0;
            std::uint32_t duration = 0;

            bool valid() const { return bang_time != 0; }
        };

        static const flash_offsets_t& flash_offsets() {
            static flash_offsets_t o;
            static bool init = false;
            if (!init) {
                o.bang_time = schema_get_offset("C_CSPlayerPawnBase", "m_flFlashBangTime");
                o.screenshot_alpha = schema_get_offset("C_CSPlayerPawnBase", "m_flFlashScreenshotAlpha");
                o.overlay_alpha = schema_get_offset("C_CSPlayerPawnBase", "m_flFlashOverlayAlpha");
                o.build_up = schema_get_offset("C_CSPlayerPawnBase", "m_bFlashBuildUp");
o.dsp_cleared = schema_get_offset("C_CSPlayerPawnBase", "m_bFlashDspHasBeenCleared");
o.screenshot_grabbed = schema_get_offset("C_CSPlayerPawnBase", "m_bFlashScreenshotHasBeenGrabbed");
                o.max_alpha = schema_get_offset("C_CSPlayerPawnBase", "m_flFlashMaxAlpha");
                o.duration = schema_get_offset("C_CSPlayerPawnBase", "m_flFlashDuration");
                init = true;
            }
            return o;
        }

        struct flash_backup_t {
            bool active = false;
            float bang_time = 0.0f;
            float screenshot_alpha = 0.0f;
            float overlay_alpha = 0.0f;
            float max_alpha = 0.0f;
            float duration = 0.0f;
            bool build_up = false;
            bool dsp_cleared = false;
            bool screenshot_grabbed = false;
        } g_flash_backup;

        union cvar_value_t {
            bool b_value;
            float fl_value;
            int i_value;
            const char* sz_value;
        };

        struct convar_t {
            const char* name;
            cvar_value_t* default_value;
            std::uint8_t pad_0010[0x10];
            const char* description;
            std::uint32_t type;
            std::uint32_t registered;
            std::uint32_t flags;
            std::uint8_t pad_0034[0x24];
            cvar_value_t value;
        };

        template <typename T>
        T& field(void* base, std::uintptr_t offset) {
            return *reinterpret_cast<T*>(reinterpret_cast<std::uintptr_t>(base) + offset);
        }

        void* engine_cvar() {
            static void* cvar = []() -> void* {
                HMODULE tier0 = GetModuleHandleA("tier0.dll");
                if (!tier0)
                    return nullptr;

                using create_interface_t = void* (*)(const char*, int*);
                auto create_interface = reinterpret_cast<create_interface_t>(GetProcAddress(tier0, "CreateInterface"));
                if (!create_interface)
                    return nullptr;

                return create_interface("VEngineCvar007", nullptr);
            }();

            return cvar;
        }

        convar_t* find_cvar(const char* name) {
            if (!name)
                return nullptr;

            using get_first_iterator_t = void(__fastcall*)(void*, std::uint64_t*);
            using get_next_iterator_t = void(__fastcall*)(void*, std::uint64_t*, std::uint64_t);
            using find_by_index_t = convar_t* (__fastcall*)(void*, std::uint64_t);

            static auto get_first_iterator = reinterpret_cast<get_first_iterator_t>(
                g_opcodes->scan("tier0.dll", "48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 48 8B F2 48 8D B9")
            );
            static auto get_next_iterator = reinterpret_cast<get_next_iterator_t>(
                g_opcodes->scan("tier0.dll", "40 53 55 56 41 56 41 57 48 83 EC ? 49 8B D8 48 8D B1 ? ? ? ? 4C 8B F2 48 8B E9 FF 15 ? ? ? ? 8B D0 39 46 ? 75 ? 66 FF 46 ? EB ? 8B 06 90 85 C0 75 ? B9 ? ? ? ? F0 0F B1 0E 75 ? 66 C7 46 ? ? ? 89 56 ? EB ? 48 8B CE E8 ? ? ? ? 41 BF ? ? ? ? 48 89 7C 24 ? 4C 89 6C 24 ? 66 41 3B DF 74 ? 41 BD ? ? ? ? 66 44 85 6D")
            );
            static auto find_by_index = reinterpret_cast<find_by_index_t>(
                g_opcodes->scan("tier0.dll", "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B DA 48 8D B9 ? ? ? ? 48 8B F1 FF 15 ? ? ? ? 8B D0 39 47 ? 75 ? 66 FF 47 ? EB ? 8B 07 90 85 C0 75 ? B9 ? ? ? ? F0 0F B1 0F 75 ? 66 C7 47 ? ? ? 89 57 ? EB ? 48 8B CF E8 ? ? ? ? BA")
            );

            auto* cvar = engine_cvar();
            if (!cvar || !get_first_iterator || !get_next_iterator || !find_by_index)
                return nullptr;

            std::uint64_t index = 0;
            get_first_iterator(cvar, &index);

            while (index != 0xFFFFFFFFull) {
                auto* var = find_by_index(cvar, index);
                if (var && var->name && std::strcmp(var->name, name) == 0)
                    return var;

                get_next_iterator(cvar, &index, index);
            }

            return nullptr;
        }

        void set_cvar_bool(const char* name, bool value) {
            static convar_t* r_drawparticles = nullptr;
            static convar_t* r_drawworld = nullptr;
            static convar_t* cl_draw_only_deathnotices = nullptr;
            static convar_t* r_drawcsplayers = nullptr;
            static convar_t* r_drawviewmodel = nullptr;
            static convar_t* r_csgo_postprocess_enable = nullptr;
            static convar_t* mat_fullbright = nullptr;
            static std::mutex s_cvar_mtx;

            convar_t** target = nullptr;
            if (std::strcmp(name, "r_drawparticles") == 0)
                target = &r_drawparticles;
            else if (std::strcmp(name, "r_drawworld") == 0)
                target = &r_drawworld;
            else if (std::strcmp(name, "cl_draw_only_deathnotices") == 0)
                target = &cl_draw_only_deathnotices;
            else if (std::strcmp(name, "r_drawcsplayers") == 0)
                target = &r_drawcsplayers;
            else if (std::strcmp(name, "r_drawviewmodel") == 0)
                target = &r_drawviewmodel;
            else if (std::strcmp(name, "r_csgo_postprocess_enable") == 0)
                target = &r_csgo_postprocess_enable;
            else if (std::strcmp(name, "mat_fullbright") == 0)
                target = &mat_fullbright;

            if (!target)
                return;

            {
                std::lock_guard<std::mutex> lk(s_cvar_mtx);
                if (!*target)
                    *target = find_cvar(name);
            }

            if (!*target)
                return;

            (*target)->value.b_value = value;
        }

        void apply_cvar_removals() {
            const int effects = g_cfg->removals.m_effects;

            set_cvar_bool("r_drawparticles", (effects & k_remove_particles) == 0);
            set_cvar_bool("r_drawworld", (effects & k_remove_world) == 0);
            set_cvar_bool("cl_draw_only_deathnotices", (effects & k_remove_hud) != 0);
            set_cvar_bool("r_drawcsplayers", (effects & k_remove_players) == 0);
            set_cvar_bool("r_drawviewmodel", (effects & k_remove_viewmodel) == 0);
            set_cvar_bool("r_csgo_postprocess_enable", (effects & k_remove_post_processing) == 0);
        }

        void apply_fullbright() {
            set_cvar_bool("mat_fullbright", g_cfg->removals.m_fullbright);
        }

        void restore_flash(void* local_pawn) {
            if (!g_flash_backup.active)
                return;

            const auto& o = flash_offsets();
            if (!o.valid())
                return;

            field<float>(local_pawn, o.bang_time) = g_flash_backup.bang_time;
            field<float>(local_pawn, o.screenshot_alpha) = g_flash_backup.screenshot_alpha;
            field<float>(local_pawn, o.overlay_alpha) = g_flash_backup.overlay_alpha;
            field<float>(local_pawn, o.max_alpha) = g_flash_backup.max_alpha;
            field<float>(local_pawn, o.duration) = g_flash_backup.duration;
            field<bool>(local_pawn, o.build_up) = g_flash_backup.build_up;
            field<bool>(local_pawn, o.dsp_cleared) = g_flash_backup.dsp_cleared;
            field<bool>(local_pawn, o.screenshot_grabbed) = g_flash_backup.screenshot_grabbed;
            g_flash_backup.active = false;
        }

        void apply_flash_removal(void* local_pawn) {
            const auto& o = flash_offsets();
            if (!o.valid())
                return;

            if (!g_cfg->removals.m_flash) {
                restore_flash(local_pawn);
                return;
            }

            const float bang_time = field<float>(local_pawn, o.bang_time);
            const float screenshot_alpha = field<float>(local_pawn, o.screenshot_alpha);
            const float overlay_alpha = field<float>(local_pawn, o.overlay_alpha);
            const float max_alpha = field<float>(local_pawn, o.max_alpha);
            const float duration = field<float>(local_pawn, o.duration);
            const bool flash_active = bang_time > 0.0f || screenshot_alpha > 0.0f ||
                                      overlay_alpha > 0.0f || max_alpha > 0.0f || duration > 0.0f;

            if (flash_active) {
                g_flash_backup.active = true;
                g_flash_backup.bang_time = bang_time;
                g_flash_backup.screenshot_alpha = screenshot_alpha;
                g_flash_backup.overlay_alpha = overlay_alpha;
                g_flash_backup.max_alpha = max_alpha > 0.0f ? max_alpha : 255.0f;
                g_flash_backup.duration = duration;
                g_flash_backup.build_up = field<bool>(local_pawn, o.build_up);
                g_flash_backup.dsp_cleared = field<bool>(local_pawn, o.dsp_cleared);
                g_flash_backup.screenshot_grabbed = field<bool>(local_pawn, o.screenshot_grabbed);
            }

            field<float>(local_pawn, o.bang_time) = 0.0f;
            field<float>(local_pawn, o.screenshot_alpha) = 0.0f;
            field<float>(local_pawn, o.overlay_alpha) = 0.0f;
            field<float>(local_pawn, o.max_alpha) = 0.0f;
            field<float>(local_pawn, o.duration) = 0.0f;
            field<bool>(local_pawn, o.build_up) = false;
            field<bool>(local_pawn, o.dsp_cleared) = true;
            field<bool>(local_pawn, o.screenshot_grabbed) = true;
        }
    }

    void run() {
        if (!g_cfg || !g_ctx || !g_ctx->m_local_pawn)
            return;

        __try {
            auto* local_pawn = g_ctx->m_local_pawn;
            apply_flash_removal(local_pawn);
            apply_cvar_removals();
            apply_fullbright();
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {
        }
    }

    void override_view(c_view_setup* view_setup) {
        if (!view_setup)
            return;

        if (g_cfg && g_cfg->misc.m_remove_visual_recoil && g_ctx && g_ctx->m_local_pawn && g_interfaces && g_interfaces->m_csgo_input)
            view_setup->m_view_angle = g_interfaces->m_csgo_input->get_view_angles();
    }
}
