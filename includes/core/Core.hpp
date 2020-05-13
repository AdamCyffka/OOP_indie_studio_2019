/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <irrlicht.h>
#include "MyEventReceiver.hpp"
#include "Menu.hpp"
#include "Options.hpp"
#include "LoadMap.hpp"

class Core {
    public:
        Core();
	    ~Core() = default;
	    int run();
        void switchScenes();

        enum gameState_e {
            mainMenu,
            mainOptions,
            mainPause,
            mainCredits,
            mainSelect,
        };

        enum layerState {
			menuMain,
			menuOptions,
			menuPause,
			menuCredits,
			menuSelect
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
        void creditsCase();
    private:
		void drawScene();
		void drawLayer();
        Menu *_menu;
        Options *_options;
        LoadMap *_loadmap;
        gameState_e _state;
        layerState _lState;
        gameState _gState;
        //MyEventReceiver *_receiver;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !CORE_HPP_ */