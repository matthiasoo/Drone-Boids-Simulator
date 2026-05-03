cmake_minimum_required(VERSION 3.15)
project(DroneSwarmSimulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# SFML
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "Disable SFML examples" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "Disable SFML documentation" FORCE)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
)
FetchContent_MakeAvailable(sfml)

# IMGUI
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.91.6 
)
FetchContent_GetProperties(imgui)
if(NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
endif()
set(IMGUI_DIR ${imgui_SOURCE_DIR} CACHE PATH "Path to core ImGui" FORCE)

# IMGUI-SFML
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "Don't find SFML inside ImGui-SFML" FORCE)
FetchContent_Declare(
    ImGui-SFML
    GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
    GIT_TAG master 
)
FetchContent_MakeAvailable(ImGui-SFML)

add_executable(DroneSwarmSim
    src/main.cpp
    src/Engine.cpp
    src/Swarm.cpp
    src/Boid.cpp
)

target_include_directories(DroneSwarmSim PRIVATE include)
target_link_libraries(DroneSwarmSim PRIVATE SFML::Graphics SFML::Window SFML::System ImGui-SFML::ImGui-SFML)