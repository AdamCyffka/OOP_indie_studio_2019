cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(Irrlicht REQUIRED)

link_libraries(${Irrlicht_LIBRARIES})

include_directories(include)
include_directories("${Irrlicht_INCLUDE_DIRS}")

add_executable(bomberman
        src/main.cpp)