/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <map>
#include <string>
#include "IMenu.hpp"
#include "Character.hpp"

class Save : public IMenu {
    public:
        explicit Save(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Save() = default;

        void loadButtons();
        void loadTextures();
        void run();
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

#endif /* !SAVE_HPP_ */