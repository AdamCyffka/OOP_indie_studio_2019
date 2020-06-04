/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameControls
*/

#ifndef GAMECONTROLS_HPP_
#define GAMECONTROLS_HPP_

#include <iostream>
#include <map>
#include <irrlicht.h>
#include "Character.hpp"
#include "IMenu.hpp"

class GameControls : public IMenu {
    public:
        explicit GameControls(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~GameControls() = default;

        void loadButtons();
        void loadTextures();

        std::vector<Character *> getPreviews();
        std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUIImage *> getImages();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::map<std::string, irr::gui::IGUIImage *> _images;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
};

#endif /* !GAMECONTROLS_HPP_ */