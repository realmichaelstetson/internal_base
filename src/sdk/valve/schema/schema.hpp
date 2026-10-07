#pragma once

#include <memory>
#include <unordered_map>
#include <type_traits>
#include <cstdint>

#include "../interfaces/interfaces.hpp"
#include "../../includes/hash.hpp"

std::uint32_t schema_get_offset(const char* module_name, const char* class_name, const char* key_name);
std::uint32_t schema_get_offset(const char* class_name, const char* key_name);

void schema_verify_offset(const char* module_name, const char* class_name, const char* key_name, std::ptrdiff_t expected);
void schema_verify_known_offsets();

#define SCHEMA_VERIFY(module, cls, field, expected) \
    schema_verify_offset(module, cls, field, expected)

#define SCHEMA(varName, type, className, keyName) \
	type& varName() { \
		static const std::uint32_t offset = schema_get_offset(className, keyName); \
		return *reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + offset); \
	}

#define SCHEMA_IN_MODULE(varName, type, moduleName, className, keyName) \
	type& varName() { \
		static const std::uint32_t offset = schema_get_offset(moduleName, className, keyName); \
		return *reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + offset); \
	}

#define SCHEMA_ARRAY(varName, type, className, keyName) \
	type* varName() { \
		static const std::uint32_t offset = schema_get_offset(className, keyName); \
		return reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + offset); \
	}

#define SCHEMA_ARRAY_IN_MODULE(varName, type, moduleName, className, keyName) \
	type* varName() { \
		static const std::uint32_t offset = schema_get_offset(moduleName, className, keyName); \
		return reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + offset); \
	}

#define SCHEMA_WITH_OFFSET(varName, type, className, keyName, offset2) \
	type& varName() { \
		static const std::uint32_t offset = schema_get_offset(className, keyName); \
		return *reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + (offset + offset2)); \
	}

#define SCHEMA_WITH_OFFSET_IN_MODULE(varName, type, moduleName, className, keyName, offset2) \
	type& varName() { \
		static const std::uint32_t offset = schema_get_offset(moduleName, className, keyName); \
		return *reinterpret_cast<type*>(reinterpret_cast<unsigned __int64>(this) + (offset + offset2)); \
	}

#define OFFSET(type, name, offset) \
    __forceinline std::add_lvalue_reference_t<type> name() const { \
        return *reinterpret_cast<type*>(reinterpret_cast<std::uintptr_t>(this) + offset); \
    }
