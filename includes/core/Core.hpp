/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define FULLSCREEN true

#include <irrlicht.h>
#include "CameraTravelManager.hpp"
#include "Menu.hpp"
#include "Score.hpp"
#include "Game.hpp"
#include "Select.hpp"
#include "LoadMap.hpp"
#include "Splash.hpp"
#include "Music.hpp"
#include "GameCore.hpp"
#include "Sounds.hpp"
#include "Videos.hpp"
#include "Controls.hpp"
#include "GameControls.hpp"
#include "GameSounds.hpp"

class Load;
class Save;
class Intro;
class Help;
class Credits;
class Pause;
class MyEventReceiver;
class GameCore;

class Core {
    public:
        Core();
	    ~Core() = default;
	    int run();

        enum layerMenuState {
            menuIntro,
			menuMain,
			menuSounds,
            menuVideos,
            menuControls,
			menuSplash,
			menuHelp,
            menuCredits,
			menuSelect,
            menuScore,
            menuSave,
            menuLoad,
		};

        enum layerGameState {
            gamePause,
            gameGame,
            gameSounds,
            gameControls,
            gameSave,
		};

        enum gameState {
        	menu,
        	game
        };

        void pauseCase();
        void gameCase();
        void gameSoundsCase();
        void gameControlsCase();
        void introCase();
        void menuCase();
        void selectCase();
        void scoreCase();
        void soundsCase();
        void controlsCase();
        void videosCase();
        void helpCase();
        void creditsCase();
        void splashCase();
        void saveCase();
        void loadCase();

        void changeFullscreen();
        void start();
        void restartDevice(bool fullscreen);

        bool getFullscreen() const;
        layerMenuState getLState();
        layerGameState getLGState();
		gameState getGState();
        Select *getSelect();
        Controls *getControls();
        Score *getScore();
		GameCore *getGameCore();
        Game *getGame();
        LoadMap *getLoadMap();
		Map *getMap();
		Music *getMusicEngine();
        Intro *getIntro();
		Input *getInput();
        CameraTravelManager *getCameraTravelManager();
        irr::scene::ISceneManager *getSmgr();
        irr::video::IVideoDriver *getDriver();

        void setLState(layerMenuState state);
        void setLGState(layerGameState state);
        void setGState(gameState state);

        void hideGameLayers();
		void hideMenuLayers();

    private:
		void init();
		template<typename T> void showMenuLayer(T *layer);
        template<typename T> void showGameLayer(T *layer);
		void drawScene();
		void drawMenuLayer();
        void drawGameLayer();
        Intro *_intro;
        Menu *_menu;
        Controls *_controls;
        Videos *_videos;
        Sounds *_sounds;
        Splash *_splash;
        LoadMap *_loadmap;
        Select *_select;
        Credits *_credits;
        Help *_help;
        Save *_save;
        Load *_load;
        Music *_music;
        Score *_score;
        Input *_inputs;
        GameCore *_gameCore;
        Pause *_pause;
        Game *_game;
        GameControls *_gameControls;
        GameSounds *_gameSounds;
        layerMenuState _lState;
        layerGameState _lGState;
        gameState _gState;
        MyEventReceiver *_receiver;
        CameraTravelManager *_cameraTravelManager;

        int _height;
        int _width;
        bool _fullscreen;
        bool _isInitialized;
        unsigned int _initStep;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        irr::scene::ICameraSceneNode *_camera;
};

#endif /* !CORE_HPP_ */