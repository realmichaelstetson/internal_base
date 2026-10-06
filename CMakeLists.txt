cmake_minimum_required(VERSION 3.20)
project(cs2_internal LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "CS2 is 64-bit only - configure with an x64 toolchain")
endif()

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/ext/imgui)
set(MINHOOK_DIR ${CMAKE_SOURCE_DIR}/ext/minhook)

add_library(cs2_internal SHARED
    src/dllmain.cpp
    src/core/hooks.cpp
    src/features/bhop.cpp
    src/features/chams.cpp
    src/sdk/entities.cpp
    src/sdk/material.cpp
    src/sdk/pattern.cpp
    src/ui/menu.cpp

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/backends/imgui_impl_dx11.cpp
    ${IMGUI_DIR}/backends/imgui_impl_win32.cpp

    ${MINHOOK_DIR}/src/buffer.c
    ${MINHOOK_DIR}/src/hook.c
    ${MINHOOK_DIR}/src/trampoline.c
    ${MINHOOK_DIR}/src/hde/hde64.c
)

target_include_directories(cs2_internal PRIVATE ${IMGUI_DIR} ${MINHOOK_DIR}/include)
target_compile_definitions(cs2_internal PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX)
target_link_libraries(cs2_internal PRIVATE d3d11 dxgi d3dcompiler dwmapi)

if(MSVC)
    target_compile_options(cs2_internal PRIVATE /MP /W3)
    set_property(TARGET cs2_internal PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    target_link_options(cs2_internal PRIVATE -static)
endif()
