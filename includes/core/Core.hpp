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
			menuMain,
			menuOptions,
			menuPause,
			menuSplash,
			menuHelp,
            menuCredits,
			menuSelect,
		};

        enum gameState {
        	menu,
        	game
        };

        void menuCase();
        void pauseCase();
        void gameCase();
        void selectCase();
        void optionsCase();
        void helpCase();
        void creditsCase();
        void splashCase();
        
        layerState getState();
        Select *getSelect();

        void setState(layerState state);
    private:
		void init();
		void hideLayers();
		template<typename T>
		void showLayer(T *page);
		void drawScene();
		void drawLayer();
        Menu *_menu;
        Options *_options;
        Splash *_splash;
        LoadMap *_loadmap;
        Select *_select;
        Credits *_credits;
        Help *_help;
        Pause *_pause;
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