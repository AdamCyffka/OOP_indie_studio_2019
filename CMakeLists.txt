cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(bomberman
        sources/main.cpp
        sources/core/global.cpp
        sources/core/Core.cpp
        sources/map/Map.cpp
        sources/map/LoadMap.cpp
        sources/menu/gameOptions/GameControls.cpp
        sources/menu/gameOptions/GameSounds.cpp
        sources/menu/Menu.cpp
        sources/menu/options/Controls.cpp
        sources/menu/options/Videos.cpp
        sources/menu/options/Sounds.cpp
        sources/menu/Splash.cpp
        sources/menu/Select.cpp
        sources/menu/Intro.cpp
        sources/menu/Credits.cpp
        sources/menu/Score.cpp
        sources/menu/Help.cpp
        sources/menu/Pause.cpp
        sources/menu/MyEventReceiver.cpp
        sources/menu/ProgressBar.cpp
        sources/menu/Save.cpp
        sources/menu/Game.cpp
        sources/menu/Load.cpp
        sources/characters/Character.cpp
        sources/music/Music.cpp
        sources/travel/CircleCameraTravel.cpp
        sources/travel/StraightCameraTravel.cpp
        sources/travel/CameraTravelManager.cpp
        sources/input/Input.cpp
        sources/game/hitbox.cpp
        sources/game/Player.cpp
        sources/game/AI.cpp
        sources/game/GameCore.cpp
        sources/powerUps/BombDown.cpp
        sources/powerUps/BombFull.cpp
        sources/powerUps/BombPass.cpp
        sources/powerUps/BombUp.cpp
        sources/powerUps/FireDown.cpp
        sources/powerUps/FireFull.cpp
        sources/powerUps/FireUp.cpp
        sources/powerUps/SpeedDown.cpp
        sources/powerUps/SpeedUp.cpp
        sources/powerUps/WallPass.cpp
        sources/bomb/Bomb.cpp
        sources/bomb/AnimExplo.cpp
        sources/saveAndLoad/saveAndLoad.cpp
        )

include_directories(includes
        includes/map
        includes/core/
        includes/menu/
        includes/menu/options/
        includes/menu/gameOptions/
        includes/characters/
        includes/bomb/
        includes/music/
        includes/travel/
        includes/input/
        includes/powerUps/
        includes/game/
        includes/saveAndLoad/
        )

set_target_properties(bomberman PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${EXECUTABLE_OUTPUT_PATH}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EXECUTABLE_OUTPUT_PATH}
        )

######### Irrlicht integration #########
set(Irrlicht_DIR "${CMAKE_MODULE_PATH}/irrLicht")
find_package(Irrlicht REQUIRED)
if (Irrlicht_FOUND)
    target_link_libraries(bomberman ${Irrlicht_LIBRARIES})
    include_directories(${Irrlicht_INCLUDE_DIRS})
endif (Irrlicht_FOUND)
#########################################

######### Irrklang integration ##########
set(Irrklang_DIR "${CMAKE_MODULE_PATH}/irrKlang")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
include_directories(${Irrklang_DIR}/include)
target_link_libraries(bomberman ${CMAKE_THREAD_LIBS_INIT})
#########################################

######## Boost integration ############
find_package(Boost 1.69.0 COMPONENTS thread chrono REQUIRED)
if (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(bomberman ${Boost_LIBRARIES})
endif (Boost_FOUND)
#########################################

######## Components integration #########
if (MSVC)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/irrKlang.lib)
ELSE (MSVC)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/libIrrKlang.so)
ENDIF(MSVC)
#########################################
