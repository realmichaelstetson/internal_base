#include "../../core/main.hpp"
#include "diagnostics.hpp"
#pragma warning(push)
#pragma warning(disable: 4459) // json.hpp uses locals named 's' that shadow the global State s
#include "../includes/json.hpp"
#pragma warning(pop)
#include "../../sdk/interfaces_sdk.hpp"
#include <algorithm>
#include <filesystem>
#include <fstream>

namespace diagnostics {

namespace {
constexpr std::size_t k_max_logs = 256;

std::filesystem::path get_module_directory()
{
    char buffer[MAX_PATH]{};
    HMODULE module_handle = nullptr;
    if (!GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                            reinterpret_cast<LPCSTR>(&get_module_directory),
                            &module_handle)) {
        return {};
    }

    const DWORD length = GetModuleFileNameA(module_handle, buffer, MAX_PATH);
    if (length == 0 || length >= MAX_PATH)
        return {};

    return std::filesystem::path(buffer).parent_path();
}

std::filesystem::path find_manifest_path()
{
    const auto module_dir = get_module_directory();
    const auto current_dir = std::filesystem::current_path();
    const auto source_dir = std::filesystem::path(__FILE__).parent_path();

    const std::filesystem::path candidates[] = {
        module_dir / "include" / "manifest.json",
        module_dir.parent_path() / "include" / "manifest.json",
        module_dir.parent_path().parent_path() / "include" / "manifest.json",
        current_dir / "include" / "manifest.json",
        source_dir.parent_path().parent_path() / "include" / "manifest.json"
    };

    for (const auto& candidate : candidates) {
        std::error_code ec;
        if (!candidate.empty() && std::filesystem::exists(candidate, ec) && !ec)
            return candidate;
    }

    return {};
}

severity from_logger_level(int level) {
    switch (level) {
    case 1: return severity::success;
    case 2: return severity::warning;
    case 3: return severity::error;
    case 4: return severity::trace;
    default: return severity::info;
    }
}
}

void runtime_diagnostics::initialize() {
    m_compatibility.sdk_build = static_cast<int>(cs2::ifaces::CS2_BUILD);
    load_manifest();
}

void runtime_diagnostics::begin_step(const char* name, bool required) {
    if (!name)
        return;

    init_step_state step;
    step.name = name;
    step.required = required;
    step.started = true;
    m_init_steps.push_back(step);
    m_step_start_times[name] = std::chrono::steady_clock::now();
}

void runtime_diagnostics::finish_step(const char* name, bool success, const std::string& detail) {
    if (!name)
        return;

    for (auto it = m_init_steps.rbegin(); it != m_init_steps.rend(); ++it) {
        if (it->name != name)
            continue;

        it->finished = true;
        it->success = success;
        it->detail = detail;

        const auto start_it = m_step_start_times.find(name);
        if (start_it != m_step_start_times.end()) {
            it->duration_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start_it->second).count();
            m_step_start_times.erase(start_it);
        }
        return;
    }
}

const char* runtime_diagnostics::current_step_name() const {
    if (m_init_steps.empty())
        return "";
    return m_init_steps.back().name.c_str();
}

void runtime_diagnostics::mark_module(const char* name, bool available, bool) {
    if (name)
        m_modules[name] = available;
}

void runtime_diagnostics::mark_interface(const char* name, bool available, bool) {
    if (name)
        m_interfaces[name] = available;
}

void runtime_diagnostics::mark_hook(const char* name, bool installed, bool) {
    if (name)
        m_hooks[name] = installed;
}

std::string runtime_diagnostics::make_key(const char* left, const char* right) {
    std::string key = left ? left : "";
    key += "!";
    key += right ? right : "";
    return key;
}

void runtime_diagnostics::mark_signature(const char* module_name, const char* name, bool available, bool) {
    if (module_name && name)
        m_signatures[make_key(module_name, name)] = available;
}

void runtime_diagnostics::record_log(severity level, const char* category, const char* file, int line, const char* message) {
    log_entry entry;
    entry.level = level;
    entry.category = category ? category : "general";
    entry.file = file ? file : "";
    entry.line = line;
    entry.message = message ? message : "";
    GetLocalTime(&entry.time);
    m_logs.push_back(std::move(entry));
    trim_logs();
}

void runtime_diagnostics::trim_logs() {
    if (m_logs.size() <= k_max_logs)
        return;
    m_logs.erase(m_logs.begin(), m_logs.begin() + (m_logs.size() - k_max_logs));
}

void runtime_diagnostics::load_manifest() {
    m_compatibility.manifest_present = false;
    m_compatibility.manifest_build_known = false;
    m_compatibility.build_match = false;
    m_compatibility.manifest_generated_at.clear();
    m_compatibility.manifest_path.clear();
    m_compatibility.note.clear();

    const auto manifest_path = find_manifest_path();
    m_compatibility.manifest_path = manifest_path.empty() ? "" : manifest_path.string();
    std::ifstream file(manifest_path);
    if (!file.is_open()) {
        m_compatibility.note = "manifest missing";
        return;
    }

    nlohmann::json manifest;
    try {
        file >> manifest;
    }
    catch (...) {
        m_compatibility.note = "manifest parse failed";
        return;
    }

    m_compatibility.manifest_present = true;
    if (manifest.contains("generated_at") && manifest["generated_at"].is_string())
        m_compatibility.manifest_generated_at = manifest["generated_at"].get<std::string>();

    if (manifest.contains("build_number") && manifest["build_number"].is_number_integer()) {
        m_compatibility.manifest_build_known = true;
        m_compatibility.manifest_build = manifest["build_number"].get<int>();
    }

    if (m_compatibility.manifest_build_known) {
        m_compatibility.build_match = m_compatibility.manifest_build == m_compatibility.sdk_build;
        m_compatibility.note = m_compatibility.build_match ? "manifest build matches sdk" : "manifest build mismatch";
    } else {
        m_compatibility.note = "manifest build missing";
    }
}

void runtime_diagnostics::set_sdk_build(int build) {
    m_compatibility.sdk_build = build;
    if (m_compatibility.manifest_build_known)
        m_compatibility.build_match = m_compatibility.manifest_build == build;
}

void runtime_diagnostics::define_feature(const char* name) {
    if (!name)
        return;
    auto& feature = m_features[name];
    feature.name = name;
}

void runtime_diagnostics::set_feature_dependency(const char* feature_name, const char* kind, const char* dependency_name, bool required, bool satisfied) {
    if (!feature_name || !kind || !dependency_name)
        return;

    auto& feature = m_features[feature_name];
    feature.name = feature_name;

    auto it = std::find_if(feature.dependencies.begin(), feature.dependencies.end(), [&](const dependency_state& dep) {
        return dep.kind == kind && dep.name == dependency_name;
    });

    if (it == feature.dependencies.end()) {
        feature.dependencies.push_back({ kind, dependency_name, required, satisfied });
    } else {
        it->required = required;
        it->satisfied = satisfied;
    }
}

void runtime_diagnostics::finalize_feature(const char* feature_name) {
    if (!feature_name)
        return;

    auto& feature = m_features[feature_name];
    feature.enabled = true;
    feature.blocked = false;
    feature.block_reason.clear();

    for (const auto& dep : feature.dependencies) {
        if (dep.required && !dep.satisfied) {
            feature.enabled = false;
            feature.blocked = true;
            feature.block_reason = dep.kind + ": " + dep.name;
            break;
        }
    }
}

bool runtime_diagnostics::is_feature_available(const char* feature_name) const {
    if (!feature_name)
        return false;
    const auto it = m_features.find(feature_name);
    return it != m_features.end() && it->second.enabled && !it->second.blocked;
}

void runtime_diagnostics::set_signature_verification_totals(int total, int resolved, int missing, int required_missing) {
    m_signature_verification.total = total;
    m_signature_verification.resolved = resolved;
    m_signature_verification.missing = missing;
    m_signature_verification.required_missing = required_missing;
    m_signature_verification.complete = true;
}

void record_log_from_logger(const char* file, int line, int message_level, const char* category, const char* message) {
    if (!g_diagnostics)
        return;
    g_diagnostics->record_log(from_logger_level(message_level), category, file, line, message);
}

}
