#pragma once

#include <Windows.h>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <memory>

class c_dll {
	HMODULE m_dll;
	std::size_t m_size;
	char m_name[256];
public:
	c_dll() : m_dll(nullptr), m_size(0), m_name{} { }
	c_dll(const char* name) : m_dll(GetModuleHandleA(name)), m_size(0), m_name{} {
		if (name)
			strcpy_s(m_name, name);

		if (!m_dll)
			return;

		auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(m_dll);
		auto nt_header = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uintptr_t>(m_dll) + dos_header->e_lfanew);
		m_size = nt_header->OptionalHeader.SizeOfImage;
	}

	std::uintptr_t get() const {
		return reinterpret_cast<uintptr_t>(m_dll);
	}

	std::size_t get_size() const {
		return m_size;
	}

	const char* get_name() const {
		return m_name[0] ? m_name : nullptr;
	}

	bool valid() const {
		return m_dll != nullptr;
	}
};

class c_modules {
private:
	struct modules_t {
		c_dll client_dll{};
		c_dll engine2_dll{};
		c_dll input_system{};
		c_dll schemasystem_dll{};
		c_dll filesystem_stdio{};
		c_dll localize_dll{};
		c_dll scenesystem_dll{};
		c_dll materialsystem2_dll{};

		bool initialize();
	};

public:
	modules_t m_modules{};
};

inline const auto g_modules = std::make_unique<c_modules>();
