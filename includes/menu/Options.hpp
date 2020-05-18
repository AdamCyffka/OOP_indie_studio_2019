/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Options
*/

#ifndef OPTIONS_HPP_
#define OPTIONS_HPP_

#include <iostream>
#include <map>
#include <irrlicht.h>
#include "Character.hpp"
#include "IGame.hpp"

class Options : public IGame {
    public:
        explicit Options(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Options() = default;

        void loadButtons();
        void loadTextures();
        void run();
        std::vector<Character *> getPreviews();
        std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUIImage *> getImages();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::map<std::string, irr::gui::IGUIImage *> _images;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif /* !OPTIONS_HPP_ */