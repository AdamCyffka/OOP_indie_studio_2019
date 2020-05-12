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
    GUI_ID_OPTION_RETURN,
    GUI_ID_OPTION_PLUS_MUSIC_BUTTON,
    GUI_ID_OPTION_MINUS_MUSIC_BUTTON,
    GUI_ID_OPTION_PLUS_GENERAL_BUTTON,
    GUI_ID_OPTION_MINUS_GENERAL_BUTTON,
    GUI_ID_OPTION_PLUS_SFX_BUTTON,
    GUI_ID_OPTION_MINUS_SFX_BUTTON,
    GUI_ID_OPTION_MUSIC_IMAGE,
    GUI_ID_OPTION_SFX_IMAGE,
    GUI_ID_OPTION_GENERAL_IMAGE,
    GUI_ID_RESUME_BUTTON_BUTTON,
};

class IGame {
    public:
        virtual ~IGame() = default;

        virtual void loadButtons() = 0;
        virtual void loadTextures() = 0;
};

#endif /* !IGAME_HPP_ */