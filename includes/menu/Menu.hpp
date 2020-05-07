/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <map>
#include <irrlicht.h>
#include "GameStat.hpp"

class Menu : public GameStat {
    public:
        explicit Menu(irr::IrrlichtDevice *window);
        ~Menu() override = default;
        void run(irr::IrrlichtDevice *window) override;

        std::map<std::string, irr::gui::IGUIButton *> getButtons();

        void loadButtons(irr::IrrlichtDevice *window) override;
        void loadTextures(irr::IrrlichtDevice *window) override;
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::gui::IGUIFont *_font;
        irr::gui::IGUISkin *_skin;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif /* !MENU_HPP_ */