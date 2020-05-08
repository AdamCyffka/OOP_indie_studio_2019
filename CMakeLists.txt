cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

message(${CMAKE_SOURCE_DIR})
find_package(Irrlicht REQUIRED)
#find_package(Boost 1.69 REQUIRED /* COMPOSANTS REQUIS ICI*/) A DECOMMENTER SI VOUS UTILISEZ LA LIB BOOST (n'oubliez pas d'insérer les composants)

link_libraries(${Irrlicht_LIBRARIES})

include_directories(includes)
include_directories(includes/core/)
include_directories(includes/intro/)
include_directories(includes/map/)
include_directories(includes/menu/)
include_directories(includes/characters/)
include_directories("${Irrlicht_INCLUDE_DIRS}")

add_executable(bomberman
        sources/main.cpp
        sources/core/Core.cpp
        sources/menu/Menu.cpp
        sources/map/map.cpp
        sources/map/LoadMap.cpp
        sources/characters/Character.cpp)
