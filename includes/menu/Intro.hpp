/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Intro
*/

#ifndef INTRO_HPP_
#define INTRO_HPP_

#include <iostream>
#include <map>
#include "IMenu.hpp"
#include "Music.hpp"
#include "Character.hpp"
#include "Core.hpp"

class Intro : public IMenu {
	public:
		explicit Intro(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);

		void loadButtons();
		void loadTextures();
		void run();
		void init();
        std::vector<Character *> getPreviews();
		std::map<std::string, irr::gui::IGUIButton *> getButtons();
		std::map<std::string, irr::gui::IGUIImage *> getImages();
	private:
		irr::gui::IGUIEnvironment *_env;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_smgr;
		Core *_core;

		std::map<std::string, irr::gui::IGUIImage *> _images;
		std::map<std::string, irr::video::ITexture *> _textures;
		std::map<std::string, irr::gui::IGUIButton *> _buttons;
};
#endif /* !INTRO_HPP_ */
