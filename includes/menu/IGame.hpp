/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <irrlicht.h>


class IGame {
    public:
        enum button {
            GUI_ID_NEW_BUTTON,
            GUI_ID_LOAD_BUTTON,
            GUI_ID_OPTIONS_BUTTON,
            GUI_ID_QUIT_BUTTON,
            GUI_ID_HELP_BUTTON,
            GUI_ID_CREDITS_BUTTON,
            GUI_ID_OPTION_RETURN,
            GUI_ID_RESUME_BUTTON,
            GUI_ID_SAVE_BUTTON,
            GUI_ID_OPTION_PLUS_MUSIC_BUTTON,
            GUI_ID_OPTION_MINUS_MUSIC_BUTTON,
            GUI_ID_OPTION_PLUS_GENERAL_BUTTON,
            GUI_ID_OPTION_MINUS_GENERAL_BUTTON,
            GUI_ID_OPTION_PLUS_SFX_BUTTON,
            GUI_ID_OPTION_MINUS_SFX_BUTTON,
            GUI_ID_SELECT_PLAY,
            GUI_ID_SKIN_1,
            GUI_ID_SKIN_2,
            GUI_ID_SKIN_3,
            GUI_ID_SKIN_4,
            GUI_ID_IA_1,
            GUI_ID_IA_2,
            GUI_ID_IA_3,
            GUI_ID_IA_4,
            GUI_ID_P_1,
            GUI_ID_P_2,
            GUI_ID_P_3,
            GUI_ID_P_4,
            GUI_ID_X_1,
            GUI_ID_X_2,
            GUI_ID_X_3,
            GUI_ID_X_4,
        };

        virtual ~IGame() = default;

        virtual void loadButtons() = 0;
        virtual void loadTextures() = 0;
};

#endif /* !IGAME_HPP_ */