#include "../../../core/main.hpp"

void* get_entity_by_index(int index) {
	if (!g_interfaces || !g_interfaces->m_entity_system)
		return nullptr;
	return g_interfaces->m_entity_system->get_base_entity(index);
}

#define CHECK(name, arg) \
	if ((arg) == nullptr) { \
		LOG_ERROR(xorstr_("[-] Failed to get: %s"), name); \
		MessageBoxA(NULL, name, "Failed to initialize", MB_OK | MB_ICONERROR); \
		return false; \
	}

bool c_interfaces::initialize()
{
	m_csgo_input = *reinterpret_cast<i_csgo_input**>(SIG("CSGOInput_ptr"));
	diagnostics::g_diagnostics->mark_interface("CCSGOInput", m_csgo_input != nullptr, true);
	CHECK(xorstr_("CCSGOInput"), m_csgo_input);

	auto entity_system_address = SIG("EntitySystem");
	CHECK(xorstr_("Entity System signature"), entity_system_address);

	m_entity_system = *reinterpret_cast<i_entity_system**>(entity_system_address);
	diagnostics::g_diagnostics->mark_interface("EntitySystem", m_entity_system != nullptr, true);
	CHECK(xorstr_("Entity System"), m_entity_system);

	m_schema_system = get_interface<i_schema_system>(&g_modules->m_modules.schemasystem_dll, xorstr_("SchemaSystem_001"));
	diagnostics::g_diagnostics->mark_interface("SchemaSystem_001", m_schema_system != nullptr, true);
	CHECK(xorstr_("Schema System"), m_schema_system);

	m_input_system = get_interface(&g_modules->m_modules.input_system, xorstr_("InputSystemVersion001"));
	diagnostics::g_diagnostics->mark_interface("InputSystemVersion001", m_input_system != nullptr, true);
	CHECK(xorstr_("Input System"), m_input_system);

	m_source2_client = get_interface<c_source2_client>(&g_modules->m_modules.client_dll, xorstr_("Source2Client002"));
	diagnostics::g_diagnostics->mark_interface("Source2Client002", m_source2_client != nullptr, true);
	CHECK(xorstr_("Source2Client"), m_source2_client);

	m_file_system = get_interface<i_file_system>(&g_modules->m_modules.filesystem_stdio, xorstr_("VFileSystem017"));
	diagnostics::g_diagnostics->mark_interface("VFileSystem017", m_file_system != nullptr, true);
	CHECK(xorstr_("FileSystem"), m_file_system);

	m_scene_system = get_interface<c_scene_system>(&g_modules->m_modules.scenesystem_dll, xorstr_("SceneSystem_002"));
	diagnostics::g_diagnostics->mark_interface("SceneSystem_002", m_scene_system != nullptr, true);

	m_engine = get_interface(&g_modules->m_modules.engine2_dll, xorstr_("Source2EngineToClient001"));
	diagnostics::g_diagnostics->mark_interface("Source2EngineToClient001", m_engine != nullptr, false);

	return true;
}
