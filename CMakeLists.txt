cmake_minimum_required(VERSION 3.10)

project(DroneSwarmSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    src/Boid.cpp 
    src/DataLogger.cpp 
    src/Engine.cpp 
    src/Swarm.cpp 
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System)