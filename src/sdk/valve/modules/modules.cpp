#include "../../../core/main.hpp"

#define REQUIRE(field, name) \
	field = c_dll(xorstr_(name)); \
	log_module(name, field); \
	diagnostics::g_diagnostics->mark_module(name, field.get() != 0, true); \
	if (!field.get()) { \
		LOG_ERROR(xorstr_("[-] missing %s"), name); \
		MessageBoxA(NULL, name, "Missing module", MB_OK | MB_ICONERROR); \
		return false; \
	}

static void log_module(const char* name, const c_dll& dll) {
	if (dll.get())
		DBG_INFO("[modules] %-22s base %p size 0x%zX", name, reinterpret_cast<void*>(dll.get()), dll.get_size());
	else
		DBG_ERR("[modules] %-22s NOT LOADED", name);
}

bool c_modules::modules_t::initialize() {
	REQUIRE(client_dll,       "client.dll");
	REQUIRE(engine2_dll,      "engine2.dll");
	REQUIRE(input_system,     "inputsystem.dll");
	REQUIRE(schemasystem_dll, "schemasystem.dll");
	REQUIRE(filesystem_stdio, "filesystem_stdio.dll");

	localize_dll = c_dll(xorstr_("localize.dll"));
	log_module("localize.dll", localize_dll);
	diagnostics::g_diagnostics->mark_module("localize.dll", localize_dll.get() != 0, false);
	if (!localize_dll.get())
		LOG_ERROR(xorstr_("[-] localize.dll missing - names will use raw tokens"));

	scenesystem_dll = c_dll(xorstr_("scenesystem.dll"));
	log_module("scenesystem.dll", scenesystem_dll);
	diagnostics::g_diagnostics->mark_module("scenesystem.dll", scenesystem_dll.get() != 0, false);

	materialsystem2_dll = c_dll(xorstr_("materialsystem2.dll"));
	log_module("materialsystem2.dll", materialsystem2_dll);
	diagnostics::g_diagnostics->mark_module("materialsystem2.dll", materialsystem2_dll.get() != 0, false);

	return true;
}
