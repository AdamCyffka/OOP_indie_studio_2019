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

class Core {
    public:
        Core();
	    ~Core() = default;
	    int run();

        enum gameState {
            mainSplashScreen,
            mainMenu,
            mainGame,
            mainOptions,
            mainPause,
            mainSelect,
        };

        void menuCase();
    protected:
    private:
        Menu *_menu;
        gameState _state;
        irr::IrrlichtDevice *_window;
};

#endif /* !CORE_HPP_ */