/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Pause
*/

#ifndef PAUSE_HPP_
#define PAUSE_HPP_

#include <map>
#include <string>
#include "IGame.hpp"

class Pause : public IGame {
    public:
        explicit Pause(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Pause() = default;
        void loadButtons();
        void loadTextures();

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


#endif /* !PAUSE_HPP_ */