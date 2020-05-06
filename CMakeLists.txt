cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

message(${CMAKE_SOURCE_DIR})
find_package(Irrlicht REQUIRED)
#find_package(Boost 1.69 REQUIRED /* COMPOSANTS REQUIS ICI*/) A DECOMMENTER SI VOUS UTILISEZ LA LIB BOOST (n'oubliez pas d'insérer les composants)

link_libraries(${Irrlicht_LIBRARIES})

include_directories(includes)
include_directories(includes/map)
include_directories(${Irrlicht_INCLUDE_DIRS})
#include_directories(${Boost_INCLUDE_DIRS}) A DECOMMENTER SI VOUS UTILISEZ LA LIB BOOST

add_executable(bomberman
        sources/main.cpp
        sources/map/map.cpp)