/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Select
*/

#ifndef SELECT_HPP_
#define SELECT_HPP_

#include <irrlicht.h>
#include <map>
#include <string>
#include <vector>
#include "Character.hpp"
#include "IGame.hpp"

class Select {
    public:
        Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Select() = default;

        // Getter
        std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::video::ITexture *> getTextures();
        std::vector<std::vector<std::vector<std::string>>> getSelectRole();
        std::vector<std::vector<int>> getNbRole(); 

        // Loader
        void loadButtons();
        void loadTextures();
        Character *getPreview(int preview) const;
        irr::video::ITexture *getRole(int role);
        void incSkin(int skin);
        void changeRole(int role);

        void switchSkin(int pos);
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::vector<int> _pos;
        std::vector<bool> _playersIA;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::vector<std::pair<std::string, bool>> selectTab;
        std::vector<Character *> _previews;
        std::vector<std::vector<std::vector<std::string>>> selectRole = {{{"p", "p_grey"}, {"ia", "ia_grey"}}};
        int nbSkin[4] = {0, 1, 2, 3};
        std::vector<std::vector<int>> nbRole {
            {0, 1},
            {1, 0},
            {1, 0},
            {1, 0}
        };

};

#endif /* !SELECT_HPP_ */