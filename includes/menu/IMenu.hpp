/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IMenu
*/

#ifndef IMENU_HPP_
#define IMENU_HPP_

#include <irrlicht.h>

class IMenu {
    public:
        enum button {
            GUI_ID_NEW_BUTTON,
            GUI_ID_LOAD_BUTTON,
            GUI_ID_SOUNDS_BUTTON,
            GUI_ID_VIDEOS_BUTTON,
            GUI_ID_CONTROLS_BUTTON,
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
            GUI_ID_INTRO_BUTTON,
            GUI_ID_SKIN_1,
            GUI_ID_SKIN_2,
            GUI_ID_SKIN_3,
            GUI_ID_SKIN_4,
            GUI_ID_X_1,
            GUI_ID_X_2,
            GUI_ID_X_3,
            GUI_ID_X_4,
            GUI_ID_SAVE_SLOT_1,
            GUI_ID_SAVE_SLOT_2,
            GUI_ID_SAVE_SLOT_3,
            GUI_ID_SAVE_SLOT_4,
            GUI_ID_LOAD_SLOT_1,
            GUI_ID_LOAD_SLOT_2,
            GUI_ID_LOAD_SLOT_3,
            GUI_ID_LOAD_SLOT_4,
            GUI_ID_SAVE_BACKTOPAUSE,
            GUI_ID_PAUSE_RETURN,
            GUI_ID_PAUSE_SOUNDS,
            GUI_ID_PAUSE_CONTROLS,
            GUI_ID_PAUSE_MENU,
        };

        virtual ~IMenu() = default;

        virtual void loadButtons() = 0;
        virtual void loadTextures() = 0;
};

#endif /* !IMENU_HPP_ */