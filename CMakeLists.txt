cmake_minimum_required(VERSION 3.10)
project(OOP_indie_studio_2019)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

add_executable(bomberman
        sources/main.cpp
        sources/core/global.cpp
        sources/core/Core.cpp
        sources/map/Map.cpp
        sources/map/LoadMap.cpp
        sources/menu/splashScreen/Splash.cpp
        sources/menu/splashScreen/ProgressBar.cpp
        sources/menu/splashScreen/loadCore.cpp
        sources/menu/mainMenu/Menu.cpp
        sources/menu/mainMenu/options/Controls.cpp
        sources/menu/mainMenu/options/GameSettings.cpp
        sources/menu/mainMenu/options/Sounds.cpp
        sources/menu/mainMenu/Select.cpp
        sources/menu/mainMenu/Intro.cpp
        sources/menu/mainMenu/Credits.cpp
        sources/menu/mainMenu/Help.cpp
        sources/menu/mainMenu/Load.cpp
        sources/menu/inGameMenu/gameOptions/GameControls.cpp
        sources/menu/inGameMenu/gameOptions/GameSounds.cpp
        sources/menu/inGameMenu/Score.cpp
        sources/menu/inGameMenu/Pause.cpp
        sources/menu/inGameMenu/Save.cpp
        sources/menu/inGameMenu/Game.cpp
        sources/input/MyEventReceiver.cpp
        sources/input/Input.cpp
        sources/characters/Character.cpp
        sources/music/Music.cpp
        sources/travel/CircleCameraTravel.cpp
        sources/travel/StraightCameraTravel.cpp
        sources/travel/CameraTravelManager.cpp
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
        sources/bomb/BombStack.cpp
        sources/bomb/Bomber.cpp
        sources/bomb/AnimExplo.cpp
        sources/saveAndLoad/saveAndLoad.cpp
        )

include_directories(includes
        includes/map
        includes/core/
        includes/menu/
        includes/menu/splashScreen/
        includes/menu/mainMenu/
        includes/menu/mainMenu/options/
        includes/menu/inGameMenu/
        includes/menu/inGameMenu/gameOptions/
        includes/characters/
        includes/bomb/
        includes/music/
        includes/travel/
        includes/input/
        includes/powerUps/
        includes/game/
        includes/saveAndLoad/
        includes/splash/
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
if (MSVC)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/irrKlang.lib)
ELSE (MSVC)
    target_link_libraries(bomberman ${CMAKE_MODULE_PATH}/irrKlang/libIrrKlang.so)
ENDIF(MSVC)
#########################################

######## Boost integration ############
find_package(Boost 1.69.0 COMPONENTS thread chrono REQUIRED)
if (Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(bomberman ${Boost_LIBRARIES})
endif (Boost_FOUND)
#########################################
