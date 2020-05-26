/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <irrlicht.h>
#include "CameraTravelManager.hpp"
#include "Menu.hpp"
#include "Score.hpp"
#include "Select.hpp"
#include "Options.hpp"
#include "LoadMap.hpp"
#include "Splash.hpp"
#include "Music.hpp"
#include "GameCore.hpp"

class Game;
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
			menuOptions,
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
		};

        enum gameState {
        	menu,
        	game
        };

        void pauseCase();
        void gameCase();

        void introCase();
        void menuCase();
        void selectCase();
        void scoreCase();
        void optionsCase();
        void helpCase();
        void creditsCase();
        void splashCase();
        void saveCase();
        void loadCase();

        layerMenuState getLState();
        layerGameState getLGState();
		gameState getGState();
        Select *getSelect();
        Score *getScore();
		GameCore *getGame();
        LoadMap *getLoadMap();
		Map *getMap();
		Music *getMusicEngine();
        Intro *getIntro();
        CameraTravelManager *getCameraTravelManager();

        void setLState(layerMenuState state);
        void setLGState(layerGameState state);
        void setGState(gameState state);

		void hideLayers();

    private:
		void init();
		template<typename T> void showLayer(T *layer);
		void drawScene();
		void drawMenuLayer();
        void drawGameLayer();
        Intro *_intro;
        Menu *_menu;
        Options *_options;
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
        layerMenuState _lState;
        layerGameState _lGState;
        gameState _gState;
        MyEventReceiver *_receiver;
        CameraTravelManager *_cameraTravelManager;

        bool _isInitialized;
        unsigned int _initStep;

        irr::SIrrlichtCreationParameters _deviceParam;
        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        irr::scene::ICameraSceneNode *_camera;
};

#endif /* !CORE_HPP_ */