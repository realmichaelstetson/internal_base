#pragma once

#include <cstdint>
#include <memory>
#include <string_view>
#include <unordered_map>

enum class signature_resolve_kind {
	raw,
	rel32,
	riprel
};

struct signature_entry_t {
	const char* name;
	const char* module_name;
	std::string_view pattern;
	signature_resolve_kind resolve;
	int rel_offset;
	int extra_offset;
};

class c_signatures {
public:
	std::uint8_t* get(const char* name);
	std::uint8_t* get(const char* module_name, const char* name);
	void verify_all();

private:
	std::uint8_t* resolve(const signature_entry_t& entry);
	std::unordered_map<std::uint64_t, std::uint8_t*> m_cache;
};

inline const auto g_signatures = std::make_unique<c_signatures>();

#define SIG(name) g_signatures->get(name)
#define SIG_MODULE(module_name, name) g_signatures->get(module_name, name)
