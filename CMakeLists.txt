cmake_minimum_required(VERSION 3.17)
project(SimpleRPG)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ()
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif ()

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SimpleRPG
        src/main.cpp src/Player.cpp src/Player.h src/Terrain.cpp src/Terrain.h src/Chunk.cpp src/Chunk.h src/Camera.cpp src/Camera.h src/Constants.h src/Mouse.cpp src/Mouse.h src/RandomNumberGenerator.cpp src/RandomNumberGenerator.h)
target_link_libraries(SimpleRPG sfml-graphics sfml-audio)