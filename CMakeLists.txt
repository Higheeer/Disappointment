cmake_minimum_required(VERSION 3.17)
project(Disappointment)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif ()
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 ")
endif ()

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Disappointment
        src/main.cpp
        src/Player.cpp src/Player.h
        src/Utilities/Constants.h
        src/Utilities/RandomNumberGenerator.cpp src/Utilities/RandomNumberGenerator.h
        src/Game.cpp src/Game.h
        src/Weapons/Weapon.h src/Weapons/Rifle.cpp src/Weapons/Rifle.h src/Weapons/Bullet.cpp src/Weapons/Bullet.h
        src/Enemy.cpp src/Enemy.h
        src/HUD.cpp src/HUD.h src/EnemySupervisor.cpp src/EnemySupervisor.h)
target_link_libraries(Disappointment sfml-graphics sfml-audio)
