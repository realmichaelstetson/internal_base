#pragma once

#include <Windows.h>
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace diagnostics {

enum class severity {
    info,
    success,
    warning,
    error,
    trace
};

struct log_entry {
    severity level = severity::info;
    std::string category;
    std::string message;
    std::string file;
    int line = 0;
    SYSTEMTIME time{};
};

struct init_step_state {
    std::string name;
    bool required = true;
    bool started = false;
    bool finished = false;
    bool success = false;
    std::string detail;
    long long duration_ms = 0;
};

struct dependency_state {
    std::string kind;
    std::string name;
    bool required = true;
    bool satisfied = false;
};

struct feature_state {
    std::string name;
    bool enabled = false;
    bool blocked = false;
    std::string block_reason;
    std::vector<dependency_state> dependencies;
};

struct build_compatibility_state {
    int sdk_build = 0;
    int manifest_build = 0;
    bool manifest_present = false;
    bool manifest_build_known = false;
    bool build_match = false;
    std::string manifest_generated_at;
    std::string manifest_path;
    std::string note;
};

struct signature_verification_state {
    int total = 0;
    int resolved = 0;
    int missing = 0;
    int required_missing = 0;
    bool complete = false;
};

class runtime_diagnostics {
public:
    void initialize();

    void begin_step(const char* name, bool required = true);
    void finish_step(const char* name, bool success, const std::string& detail = {});
    const char* current_step_name() const;

    void mark_module(const char* name, bool available, bool required);
    void mark_interface(const char* name, bool available, bool required);
    void mark_hook(const char* name, bool installed, bool required);
    void mark_signature(const char* module_name, const char* name, bool available, bool required);

    void record_log(severity level, const char* category, const char* file, int line, const char* message);

    void load_manifest();
    void set_sdk_build(int build);

    void define_feature(const char* name);
    void set_feature_dependency(const char* feature_name, const char* kind, const char* dependency_name, bool required, bool satisfied);
    void finalize_feature(const char* feature_name);
    bool is_feature_available(const char* feature_name) const;

    const std::vector<log_entry>& logs() const { return m_logs; }
    const std::vector<init_step_state>& init_steps() const { return m_init_steps; }
    const std::unordered_map<std::string, bool>& modules() const { return m_modules; }
    const std::unordered_map<std::string, bool>& interfaces() const { return m_interfaces; }
    const std::unordered_map<std::string, bool>& hooks() const { return m_hooks; }
    const std::unordered_map<std::string, bool>& signatures() const { return m_signatures; }
    const std::unordered_map<std::string, feature_state>& features() const { return m_features; }
    const build_compatibility_state& compatibility() const { return m_compatibility; }
    const signature_verification_state& signature_verification() const { return m_signature_verification; }

    void set_signature_verification_totals(int total, int resolved, int missing, int required_missing);

private:
    void trim_logs();
    static std::string make_key(const char* left, const char* right);

    std::vector<log_entry> m_logs;
    std::vector<init_step_state> m_init_steps;
    std::unordered_map<std::string, bool> m_modules;
    std::unordered_map<std::string, bool> m_interfaces;
    std::unordered_map<std::string, bool> m_hooks;
    std::unordered_map<std::string, bool> m_signatures;
    std::unordered_map<std::string, std::chrono::steady_clock::time_point> m_step_start_times;
    std::unordered_map<std::string, feature_state> m_features;
    build_compatibility_state m_compatibility;
    signature_verification_state m_signature_verification;
};

inline const auto g_diagnostics = std::make_unique<runtime_diagnostics>();

void record_log_from_logger(const char* file, int line, int message_level, const char* category, const char* message);

}
