/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include <irrlicht.h>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include "Character.hpp"
#include "Music.hpp"
#include "IMenu.hpp"

class Score : public IMenu {
    public:
        Score(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr,  std::vector<Character *> previews, Music *music);
        ~Score() = default;

        // Getter
		std::map<std::string, irr::gui::IGUIImage *> getImages();
		std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();
        std::vector<Character *> getPreviews();

        void updateRanking(std::vector<std::pair<int, int>> ranking);
        void spawnEntities();
        void loadButtons();
        void loadTextures();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        Music *_music;

		std::map<std::string, irr::gui::IGUIImage *> _images;
		std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
        std::vector<Character *> _previews;

        std::vector<int> _ranking;
};

#endif /* !SCORE_HPP_ */
