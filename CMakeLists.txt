cmake_minimum_required(VERSION 3.10)

project(DroneSwarmSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DroneSwarm 
    src/main.cpp 
    src/Boid.cpp 
    src/DataLogger.cpp 
    src/Engine.cpp 
    src/Swarm.cpp 
)

target_include_directories(DroneSwarm PUBLIC include)