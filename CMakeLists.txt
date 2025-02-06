cmake_minimum_required(VERSION 3.30)
project(Red)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)
add_executable(Red main.cpp
        Engine/Core/Game.cpp
        Engine/Core/Game.h
        Engine/Core/StateMachine.cpp
        Engine/Core/GameState.cpp
        Engine/Core/AssetManager.cpp
        Engine/Core/InputManager.cpp
        Game/States/GameState_MainMenu.cpp
        Game/States/GameState_Splash.cpp
        Engine/UI/Button.cpp
        Engine/UI/Menu_Scale.cpp
        Game/States/GameState_Gameplay.cpp
        Game/Gameplay/Bullet.cpp
        Game/Agents/Player.cpp
        Engine/Helpers/Utilities.cpp
        Engine/Core/Agent.cpp
        Game/Gameplay/FloorCanvas.cpp
        Game/Gameplay/FloorCanvas.h
        Game/Gameplay/Splatter.cpp
        Game/Gameplay/Splatter.h
        Game/States/GameState_LevelSelect.cpp
        Game/States/GameState_LevelSelect.h
        Engine/Helpers/ErrorLogging.cpp
        Engine/Helpers/ErrorLogging.h)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "Box2D/*.cpp")
include_directories(${CMAKE_SOURCE_DIR})
include_directories(/opt/homebrew/Cellar/sfml/3.0.0/include/SFML)

find_package(Box2D REQUIRED)
find_package(SFML 3.0 COMPONENTS System Window Graphics Audio REQUIRED)
include_directories(/opt/homebrew/Cellar/sfml/3.0.0/include/SFML)
target_link_libraries(Red SFML::System SFML::Window SFML::Graphics SFML::Audio)

