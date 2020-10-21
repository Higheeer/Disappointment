cmake_minimum_required(VERSION 3.17)
project(SimpleRPG)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SimpleRPG
        src/main.cpp src/Player.cpp src/Player.h src/Keyboard.cpp src/Keyboard.h src/Terrain.cpp src/Terrain.h src/Chunk.cpp src/Chunk.h)
target_link_libraries(SimpleRPG sfml-graphics sfml-audio)