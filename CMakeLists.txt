cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

message(${CMAKE_SOURCE_DIR})
find_package(Irrlicht REQUIRED)

link_libraries(${Irrlicht_LIBRARIES})

include_directories(includes)
include_directories(includes/core/)
include_directories(includes/menu/)
include_directories("${Irrlicht_INCLUDE_DIRS}")

add_executable(bomberman
        sources/main.cpp
        sources/core/Core.cpp
        sources/menu/Menu.cpp
        )