#include "../../../core/main.hpp"

using schema_key_value_map_t = std::unordered_map<unsigned long long, std::uint32_t>;
using schema_table_map_t = std::unordered_map<unsigned long long, schema_key_value_map_t>;

namespace {
constexpr const char* schema_modules[] = {
    "client.dll",
    "animationsystem.dll",
    "engine2.dll",
    "schemasystem.dll"
};

std::uint64_t make_cache_key(const char* module_name, const char* class_name) {
    const std::uint64_t module_key = module_name ? fnv1a::hash_64(module_name) : 0;
    const std::uint64_t class_key = fnv1a::hash_64(class_name);

    return module_key ^ (class_key + 0x9e3779b97f4a7c15ULL + (module_key << 6) + (module_key >> 2));
}

bool cache_schema_fields_for_class(schema_table_map_t& table_map, const char* module_name, const char* class_name) {
    c_schema_type_scope* type_scope = g_interfaces->m_schema_system->find_type_scope_for_module(module_name);
    if (!type_scope)
        return false;

    c_schema_class_info* class_info = type_scope->find_declared_class(class_name);
    if (!class_info)
        return false;

    const std::uint16_t fields_size = class_info->get_fields_size();
    c_schema_class_field* fields = class_info->get_fields();
    if (!fields)
        return false;

    auto& key_value_map = table_map[make_cache_key(module_name, class_name)];
    for (std::uint16_t i = 0; i < fields_size; ++i) {
        c_schema_class_field& field = fields[i];
        if (!field.m_name)
            continue;

        key_value_map.emplace(fnv1a::hash_64(field.m_name), static_cast<std::uint32_t>(field.m_offset));
    }

    return true;
}

std::uint32_t find_cached_offset(schema_table_map_t& table_map, const char* module_name, const char* class_name, const char* key_name) {
    const std::uint64_t cache_key = make_cache_key(module_name, class_name);
    const std::uint64_t key_name_key = fnv1a::hash_64(key_name);

    const auto& it = table_map.find(cache_key);
    if (it == table_map.cend()) {
        if (cache_schema_fields_for_class(table_map, module_name, class_name))
            return find_cached_offset(table_map, module_name, class_name, key_name);

        table_map.emplace(cache_key, schema_key_value_map_t{});
        return 0;
    }

    const schema_key_value_map_t& key_value_map = it->second;
    const auto& offset_it = key_value_map.find(key_name_key);
    if (offset_it == key_value_map.cend())
        return 0;

    return offset_it->second;
}
}

std::uint32_t schema_get_offset(const char* module_name, const char* class_name, const char* key_name) {
    static schema_table_map_t schema_table_map;

    if (!g_interfaces || !g_interfaces->m_schema_system || !module_name || !class_name || !key_name) {
        LOG_ERROR("[Schema] invalid lookup %s->%s", class_name ? class_name : "<null>", key_name ? key_name : "<null>");
        return 0;
    }

    const std::uint32_t offset = find_cached_offset(schema_table_map, module_name, class_name, key_name);
    if (!offset)
        LOG_ERROR("[Schema] couldn't find %s!%s->%s", module_name, class_name, key_name);

    return offset;
}

void schema_verify_offset(const char* module_name, const char* class_name, const char* key_name, std::ptrdiff_t expected) {
    const std::uint32_t actual = schema_get_offset(module_name, class_name, key_name);
    if (actual && static_cast<std::ptrdiff_t>(actual) != expected)
        LOG_ERROR("[Schema] OFFSET MISMATCH %s!%s->%s: expected 0x%llX, schema says 0x%X", module_name, class_name, key_name, expected, actual);
}

void schema_verify_known_offsets() {
    schema_verify_offset("client.dll", "CSkeletonInstance", "m_modelState", 0x140);
    schema_verify_offset("client.dll", "C_CSPlayerPawn", "m_ArmorValue", 0x1C9C);
}

std::uint32_t schema_get_offset(const char* class_name, const char* key_name) {
    static schema_table_map_t schema_table_map;

    if (!g_interfaces || !g_interfaces->m_schema_system || !class_name || !key_name) {
        LOG_ERROR("[Schema] invalid lookup %s->%s", class_name ? class_name : "<null>", key_name ? key_name : "<null>");
        return 0;
    }

    for (const char* module_name : schema_modules) {
        const std::uint32_t offset = find_cached_offset(schema_table_map, module_name, class_name, key_name);
        if (offset)
            return offset;
    }

    LOG_ERROR("[Schema] couldn't find %s->%s", class_name, key_name);
    return 0;
}
