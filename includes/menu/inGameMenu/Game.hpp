/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <map>
#include <string>
#include "Character.hpp"
#include "IMenu.hpp"
#include "IEntity.hpp"

class Game : public IMenu {
    public:
        explicit Game(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::vector<Character *> previews);
        ~Game() = default;

        void loadButtons();
        void loadTextures();
        void loadImages();
        void run(int count, std::vector<IEntity *> entities);
        void printUpLeft();
        void printUpRight();
        void printDownLeft();
        void printDownRight();

        std::vector<Character *> getPreviews();
        std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUIImage *> getImages();
        std::map<std::string, irr::gui::IGUIImage *> getTempImages();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        std::vector<Character *> _previews;

        std::map<std::string, irr::gui::IGUIImage *> _images;
        std::map<std::string, irr::gui::IGUIImage *> _tempImages;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
};

#endif /* !GAME_HPP_ */