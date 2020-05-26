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
#include "IEntity.hpp"
#include "Character.hpp"
#include "IMenu.hpp"

class Select : public IMenu {
    public:
        Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Select() = default;
        void run();

        // Getter
		std::map<std::string, irr::gui::IGUIImage *> getImages();
		std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::video::ITexture *> getTextures();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();
        std::vector<Character *> getPreviews();
        std::vector<std::vector<std::vector<std::string>>> getSelectRole();
        std::vector<std::vector<int>> getNbRole(); 

        // Loader
        void loadButtons();
        void loadTextures();
        Character *getPreview(int preview) const;
        irr::video::ITexture *getRole(int role);
        void spawnEntities();
        void incSkin(int skin);
        void changeRole(int role);

		const std::vector<EntityType::EntityType> &getEntityTypes();
        void switchSkin(int pos);
        int getNextAvailableSkin();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::vector<int> _pos;
        std::vector<bool> _playersIA;
		std::map<std::string, irr::gui::IGUIImage *> _images;
		std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
        std::vector<Character *> _previews;
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