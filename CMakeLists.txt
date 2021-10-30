cmake_minimum_required(VERSION 3.20)
project(KURSACH)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(${PROJECT_NAME} STATIC include/character.hpp sources/character.cpp include/enemy.hpp sources/enemy.cpp include/battle.hpp sources/battle.cpp sources/battle_graphics.cpp include/battle_graphics.hpp)

add_executable(demo demo/main.cpp sources/battle_graphics.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        )

target_link_libraries(
        demo
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

