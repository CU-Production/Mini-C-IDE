cmake_minimum_required(VERSION 3.25)
project(MiniCIDE)

set(CMAKE_CXX_STANDARD 17)

if (POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif ()

configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/config_app.h.cmake ${CMAKE_BINARY_DIR}/config_app.h)

# libtcc
add_subdirectory(3rd_party/tinycc)
target_include_directories(libtcc INTERFACE 3rd_party/tinycc)

add_executable(tinycc-ide
        src/main.cpp
        src/editor.cpp
        src/editor.h
        3rd_party/tinyfiledialogs/tinyfiledialogs.c
        3rd_party/imgui/imgui.cpp
        3rd_party/imgui/imgui_draw.cpp
        3rd_party/imgui/imgui_tables.cpp
        3rd_party/imgui/imgui_widgets.cpp)
target_include_directories(tinycc-ide PRIVATE
        ${CMAKE_BINARY_DIR}
        3rd_party/imgui
        3rd_party/ImGuiColorTextEdit
        3rd_party/sokol
        3rd_party/zep/include
        3rd_party/tinyfiledialogs)
target_link_libraries(tinycc-ide PRIVATE
        libtcc)
target_compile_definitions(tinycc-ide PRIVATE
        ZEP_FEATURE_CPP_FILE_SYSTEM
        ZEP_SINGLE_HEADER=1)
add_custom_command(
        TARGET tinycc-ide POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/hello.c ${CMAKE_CURRENT_BINARY_DIR}/hello.c
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/libtccbin" "${CMAKE_CURRENT_BINARY_DIR}"
)
