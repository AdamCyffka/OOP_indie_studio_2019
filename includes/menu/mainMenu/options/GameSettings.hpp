/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Videos
*/

#ifndef VIDEOS_HPP_
#define VIDEOS_HPP_

#include <iostream>
#include <map>
#include <irrlicht.h>
#include "Character.hpp"
#include "IMenu.hpp"

class GameSettings : public IMenu {
    public:
        explicit GameSettings(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~GameSettings() = default;

        void loadButtons();
        void loadTextures();

        std::vector<Character *> getPreviews();
        std::map<std::string, irr::gui::IGUIButton *> getButtons();
        std::map<std::string, irr::gui::IGUIImage *> getImages();
        std::map<std::string, irr::gui::IGUICheckBox *> getCheckBox();

		int getFirePower() const;
		void setFirePower(int firePower);
		int getBombAmount() const;
		void setBombAmount(int bombAmount);
		int getSpeed() const;
		void setSpeed(int speed);
		bool isWallPass() const;
		void setWallPass(bool wallPass);
		bool isBombPass() const;
		void setBombPass(bool bombPass);

    private:
        int _firePower;
        int _bombAmount;
        int _speed;
        bool _wallPass;
        bool _bombPass;

		irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::map<std::string, irr::gui::IGUIImage *> _images;
        std::map<std::string, irr::video::ITexture *> _textures;
        std::map<std::string, irr::gui::IGUIButton *> _buttons;
        std::map<std::string, irr::gui::IGUICheckBox *> _checkBox;
};

#endif /* !VIDEOS_HPP_ */