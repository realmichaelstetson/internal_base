#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <memory>
#pragma warning(push)
#pragma warning(disable: 4459) // json.hpp uses locals named 's' that shadow the global State s
#include "../includes/json.hpp"
#pragma warning(pop)

using json = nlohmann::json;

template <typename T>
struct config_item_t {
    T* pointer;
    std::string category;
    std::string name;
    T default_value;
};

struct config_char_array_t {
    char* pointer;
    size_t size;
    std::string category;
    std::string name;
};

class c_config_system {
public:
    void setup_values();
    void save(const std::string& name);
    void load(const std::string& name);
    void remove(const std::string& name);
    void reset();
    void refresh();

    std::vector<std::string>& get_config_files() { return m_config_files; }

    std::string m_selected_config;

private:

    void push_item(bool* pointer, const std::string& category, const std::string& name, bool default_value);
    void push_item(int* pointer, const std::string& category, const std::string& name, int default_value);
    void push_item(float* pointer, const std::string& category, const std::string& name, float default_value);
    void push_item(std::string* pointer, const std::string& category, const std::string& name, const std::string& default_value);
    void push_char_array(char* pointer, size_t size, const std::string& category, const std::string& name);

    std::vector<config_item_t<bool>> m_booleans;
    std::vector<config_item_t<int>> m_ints;
    std::vector<config_item_t<float>> m_floats;
    std::vector<config_item_t<std::string>> m_strings;
    std::vector<config_char_array_t> m_char_arrays;

    std::vector<std::string> m_config_files;

    std::string m_config_path = "C:\\celerity\\configs\\";
    bool m_values_setup = false;
};

inline const auto g_config_system = std::make_unique<c_config_system>();
