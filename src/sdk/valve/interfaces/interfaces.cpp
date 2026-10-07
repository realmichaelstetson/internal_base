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

// logs an interface pointer and whether it looks like a real object (vtable inside a game module)
static void log_iface(const char* name, const void* ptr) {
	if (!ptr) {
		DBG_ERR("[iface] %-26s = nullptr", name);
		return;
	}
	const bool obj = dbg::looks_like_object(ptr, nullptr);
	void* vtable = dbg::readable(ptr, sizeof(void*)) ? *static_cast<void* const*>(ptr) : nullptr;
	if (obj)
		DBG_INFO("[iface] %-26s = %s vtable %s", name, dbg::addr(ptr).s, dbg::addr(vtable).s);
	else
		DBG_WARN("[iface] %-26s = %s  <-- does NOT look like an object (vtable %s), expect a crash", name, dbg::addr(ptr).s, dbg::addr(vtable).s);
}

bool c_interfaces::initialize()
{
	const HMODULE client = reinterpret_cast<HMODULE>(g_modules->m_modules.client_dll.get());

	// CSGOInput_ptr must resolve to a global that HOLDS the CCSGOInput pointer.
	// If a dump update points it at the object itself, use the object directly.
	auto* csgo_input_ref = SIG("CSGOInput_ptr");
	CHECK(xorstr_("CCSGOInput signature"), csgo_input_ref);
	void* csgo_input = dbg::readable(csgo_input_ref, sizeof(void*)) ? *reinterpret_cast<void**>(csgo_input_ref) : nullptr;
	DBG_INFO("[iface] CSGOInput_ptr global %s holds %s", dbg::addr(csgo_input_ref).s, dbg::addr(csgo_input).s);
	if (!dbg::looks_like_object(csgo_input, client) && dbg::looks_like_object(csgo_input_ref, client)) {
		DBG_WARN("[iface] CSGOInput_ptr points at the CCSGOInput object itself, using it directly");
		csgo_input = csgo_input_ref;
	}
	m_csgo_input = static_cast<i_csgo_input*>(csgo_input);
	log_iface("CCSGOInput", m_csgo_input);
	diagnostics::g_diagnostics->mark_interface("CCSGOInput", m_csgo_input != nullptr, true);
	CHECK(xorstr_("CCSGOInput"), m_csgo_input);

	auto entity_system_address = SIG("EntitySystem");
	CHECK(xorstr_("Entity System signature"), entity_system_address);
	if (!dbg::readable(entity_system_address, sizeof(void*))) {
		DBG_ERR("[iface] EntitySystem global %s is not readable", dbg::addr(entity_system_address).s);
		CHECK(xorstr_("Entity System global"), static_cast<void*>(nullptr));
	}

	m_entity_system = *reinterpret_cast<i_entity_system**>(entity_system_address);
	DBG_INFO("[iface] EntitySystem global %s holds %s", dbg::addr(entity_system_address).s, dbg::addr(m_entity_system).s);
	diagnostics::g_diagnostics->mark_interface("EntitySystem", m_entity_system != nullptr, true);
	CHECK(xorstr_("Entity System"), m_entity_system);
	log_iface("EntitySystem", m_entity_system);

	m_schema_system = get_interface<i_schema_system>(&g_modules->m_modules.schemasystem_dll, xorstr_("SchemaSystem_001"));
	log_iface("SchemaSystem_001", m_schema_system);
	diagnostics::g_diagnostics->mark_interface("SchemaSystem_001", m_schema_system != nullptr, true);
	CHECK(xorstr_("Schema System"), m_schema_system);

	m_input_system = get_interface(&g_modules->m_modules.input_system, xorstr_("InputSystemVersion001"));
	log_iface("InputSystemVersion001", m_input_system);
	diagnostics::g_diagnostics->mark_interface("InputSystemVersion001", m_input_system != nullptr, true);
	CHECK(xorstr_("Input System"), m_input_system);

	m_source2_client = get_interface<c_source2_client>(&g_modules->m_modules.client_dll, xorstr_("Source2Client002"));
	log_iface("Source2Client002", m_source2_client);
	diagnostics::g_diagnostics->mark_interface("Source2Client002", m_source2_client != nullptr, true);
	CHECK(xorstr_("Source2Client"), m_source2_client);

	m_file_system = get_interface<i_file_system>(&g_modules->m_modules.filesystem_stdio, xorstr_("VFileSystem017"));
	log_iface("VFileSystem017", m_file_system);
	diagnostics::g_diagnostics->mark_interface("VFileSystem017", m_file_system != nullptr, true);
	CHECK(xorstr_("FileSystem"), m_file_system);

	m_scene_system = get_interface<c_scene_system>(&g_modules->m_modules.scenesystem_dll, xorstr_("SceneSystem_002"));
	log_iface("SceneSystem_002", m_scene_system);
	diagnostics::g_diagnostics->mark_interface("SceneSystem_002", m_scene_system != nullptr, true);

	m_engine = get_interface(&g_modules->m_modules.engine2_dll, xorstr_("Source2EngineToClient001"));
	log_iface("Source2EngineToClient001", m_engine);
	diagnostics::g_diagnostics->mark_interface("Source2EngineToClient001", m_engine != nullptr, false);

	return true;
}
