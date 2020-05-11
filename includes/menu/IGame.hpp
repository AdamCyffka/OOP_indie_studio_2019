/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <irrlicht.h>

enum button {
    GUI_ID_NEW_BUTTON,
    GUI_ID_LOAD_BUTTON,
    GUI_ID_OPTIONS_BUTTON,
    GUI_ID_QUIT_BUTTON,
    GUI_ID_CREDITS_BUTTON,
    GUI_ID_RESUME_BUTTON,
    GUI_ID_RETURN_MENU_BUTTON,
    GUI_ID_RETURN_SELECT_PLAY,
    GUI_ID_PLAY_SELECT,
    GUI_ID_OPTION_RETURN,
    GUI_ID_OPTION_MUTE,
    GUI_ID_OPTION_SCROLL,
    GUI_ID_PAUSE_SAVE,
};

class IGame {
    public:
        virtual ~IGame() = default;

        virtual void loadButtons() = 0;
        virtual void loadTextures() = 0;
};

#endif /* !IGAME_HPP_ */