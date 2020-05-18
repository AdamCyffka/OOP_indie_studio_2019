/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Help
*/

#ifndef HELP_HPP_
#define HELP_HPP_

#include <map>
#include <string>
#include "IGame.hpp"
#include "Character.hpp"

class Help : public IGame {
    public:
        explicit Help(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Help() = default;

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

#endif /* !HELP_HPP_ */