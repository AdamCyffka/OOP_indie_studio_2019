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

        void menuCase();
        void pauseCase();
        void gameCase();
        void selectCase();
        void optionsCase();
        void creditsCase();
    protected:
    private:
        Menu *_menu;
        LoadMap *_loadmap;
        gameState_e _state;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !CORE_HPP_ */