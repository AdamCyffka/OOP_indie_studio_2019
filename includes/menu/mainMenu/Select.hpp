/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Select
*/

#ifndef SELECT_HPP_
#define SELECT_HPP_

#include <irrlicht.h>
#include <string>
#include <vector>
#include "IMenu.hpp"
#include "IEntity.hpp"
#include "Music.hpp"
#include "Character.hpp"

class Select : public IMenu {
    public:
        Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Select() = default;
        void run();
        void loadButtons();
        void loadTextures();
        void spawnEntities();
        void incSkin(int skin);
        void changeRole(int role);
        int getNextAvailableSkin(size_t start = 0);

        // Getter
		std::map<std::string, irr::gui::IGUIImage *> getImages();
		std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();
        std::vector<Character *> getPreviews();
		const std::vector<EntityType::EntityType> &getEntityTypes();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

		std::map<std::string, irr::gui::IGUIImage *> _images;
		std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
        std::vector<Character *> _previews;
        std::vector<int> _pos;
		std::vector<EntityType::EntityType> _entitiesTypes;
        std::vector<std::pair<std::string, int>> _selectTab;
        std::vector<std::vector<std::vector<std::string>>> _selectRole = {{{"p", "p_grey"}, {"ia", "ia_grey"}}};
        std::vector<std::vector<int>> _nbRole {
            {0, 1},
            {1, 0},
            {1, 0},
            {1, 0}
        };

};

#endif /* !SELECT_HPP_ */