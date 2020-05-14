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

class Help;
class Credits;
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
			menuHelp,
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
        void helpCase();
        void creditsCase();

        layerState getState();
        Select *getSelect();

        void setState(layerState state);
    private:
		void drawScene();
		void drawLayer();
        Menu *_menu;
        Options *_options;
        LoadMap *_loadmap;
        Select *_select;
        Credits *_credits;
        Help *_help;
        layerState _lState;
        gameState _gState;
        MyEventReceiver *_receiver;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !CORE_HPP_ */