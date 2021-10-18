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

add_executable(KURSACH demo/main.cpp include/character.hpp)
target_link_libraries(KURSACH
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

