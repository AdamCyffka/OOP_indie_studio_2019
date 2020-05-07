cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/irrLicht")
set(Irrklang_DIR "${CMAKE_MODULE_PATH}/irrKlang")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Irrlicht REQUIRED)
#find_package(Boost 1.69 REQUIRED /* COMPOSANTS REQUIS ICI*/) A DECOMMENTER SI VOUS UTILISEZ LA LIB BOOST (n'oubliez pas d'insérer les composants)

add_executable(bomberman
        sources/main.cpp
        sources/core/Core.cpp
        sources/menu/Menu.cpp
        sources/map/map.cpp
        sources/characters/Character.cpp
        )

target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
target_link_libraries(bomberman Threads::Threads)

include_directories(includes)
include_directories(includes/map)
include_directories(includes/core/)
include_directories(includes/menu/)
include_directories(includes/characters/)
include_directories(${Irrlicht_INCLUDE_DIRS})
include_directories(${Irrklang_DIR}/include)
#include_directories(${Boost_INCLUDE_DIRS}) A DECOMMENTER SI VOUS UTILISEZ LA LIB BOOST

file(COPY "${CMAKE_SOURCE_DIR}/resources"
        DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/bin")

if (MSVC)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrLicht/Irrlicht.dll"
            ${CMAKE_SOURCE_DIR}/bin)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrKlang/irrKlang.dll"
            ${CMAKE_SOURCE_DIR}/bin)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrKlang/ikpFlac.dll"
            ${CMAKE_SOURCE_DIR}/bin)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrKlang/ikpMP3.dll"
            ${CMAKE_SOURCE_DIR}/bin)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/irrKlang.lib)
ELSE (MSVC)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrKlang/ikpFlac.so"
            ${CMAKE_SOURCE_DIR}/bin)
    add_custom_command(TARGET bomberman PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${CMAKE_MODULE_PATH}/irrKlang/ikpMP3.so"
            ${CMAKE_SOURCE_DIR}/bin)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/libIrrKlang.so)
ENDIF(MSVC)