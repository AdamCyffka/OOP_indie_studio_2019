/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Splash header file
*/

#ifndef SPLASH_HPP
#define SPLASH_HPP

#include <iostream>
#include <map>
#include "IMenu.hpp"
#include "Character.hpp"
#include "ProgressBar.hpp"

class Splash : public IMenu {
	public:
		explicit Splash(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
		~Splash() = default;

		void loadButtons();
		void loadTextures();
		void run();
        std::vector<Character *> getPreviews();
		std::map<std::string, irr::gui::IGUIButton *> getButtons();
		std::map<std::string, irr::gui::IGUIImage *> getImages();
		ProgressBar *getBar();
		void setBar(ProgressBar *bar);

	private:
		ProgressBar *_bar;
		irr::gui::IGUIEnvironment *_env;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_smgr;

		std::map<std::string, irr::gui::IGUIImage *> _images;
		std::map<std::string, irr::video::ITexture *> _textures;
		std::map<std::string, irr::gui::IGUIButton *> _buttons;
};

#endif