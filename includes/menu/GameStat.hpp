/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameStat
*/

#ifndef GAMESTAT_HPP_
#define GAMESTAT_HPP_

#include <irrlicht.h>

enum button {
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_LOAD_BUTTON = 102,
    GUI_ID_OPTIONS_BUTTON = 103,
    GUI_ID_RESUME_BUTTON = 104,
    GUI_ID_RETURN_MENU_BUTTON = 105,
    GUI_ID_RETURN_SELECT_PLAY = 121,
    GUI_ID_PLAY_SELECT = 122,
    GUI_ID_NEW_BUTTON = 123,
    GUI_ID_OPTION_RETURN = 124,
    GUI_ID_OPTION_MUTE = 125,
    GUI_ID_OPTION_SCROLL = 126,
    GUI_ID_PAUSE_SAVE = 127,
};

class GameStat {
    public:
        virtual ~GameStat() = default;
        virtual void run(irr::IrrlichtDevice *window) = 0;

        virtual void loadButtons(irr::IrrlichtDevice *window) = 0;
        virtual void loadTextures(irr::IrrlichtDevice *window) = 0;
};

#endif /* !GAMESTAT_HPP_ */