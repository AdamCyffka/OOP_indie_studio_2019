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
#include "Select.hpp"
#include "Options.hpp"
#include "LoadMap.hpp"
#include "Splash.hpp"
#include "Music.hpp"
#include "GameCore.hpp"

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

        enum layerState {
            menuIntro,
			menuMain,
			menuOptions,
			menuPause,
			menuSplash,
			menuHelp,
            menuCredits,
			menuSelect,
            menuSave,
            menuLoad
		};

        enum gameState {
        	menu,
        	game
        };

        void introCase();
        void menuCase();
        void pauseCase();
        void gameCase();
        void selectCase();
        void optionsCase();
        void helpCase();
        void creditsCase();
        void splashCase();
        void saveCase();
        void loadCase();

        layerState getLState();
		gameState getGState();
        Select *getSelect();
		GameCore *getGame();
        LoadMap *getLoadMap();
		Map *getMap();
		Music *getMusicEngine();
        Intro *getIntro();

        void setLState(layerState state);
        void setGState(gameState state);

		void hideLayers();

    private:
		void init();
		template<typename T> void showLayer(T *layer);
		void drawScene();
		void drawLayer();
        Intro *_intro;
        Menu *_menu;
        Options *_options;
        Splash *_splash;
        LoadMap *_loadmap;
        Select *_select;
        Credits *_credits;
        Help *_help;
        Pause *_pause;
        Save *_save;
        Load *_load;
        Music *_music;
        Input *_inputs;
        GameCore *_game;
        layerState _lState;
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