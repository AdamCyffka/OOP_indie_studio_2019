/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <irrlicht.h>
#include "Menu.hpp"
#include "Select.hpp"
#include "Options.hpp"
#include "LoadMap.hpp"
#include "Splash.hpp"
#include "Music.hpp"
#include "GameCore.hpp"

class Intro;
class Help;
class Credits;
class Pause;
class MyEventReceiver;

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
			menuSelect
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

        layerState getLState();
		gameState getGState();
        Select *getSelect();
		GameCore *getGame();
		Music *getMusicEngine();

        void setLState(layerState state);
        void setGState(gameState state);
    private:
		void init();
		void hideLayers();
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
        Music *_music;
        Input *_inputs;
        GameCore *_game;
        layerState _lState;
        gameState _gState;
        MyEventReceiver *_receiver;

        bool _isInitialized;
        unsigned int _initStep;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !CORE_HPP_ */