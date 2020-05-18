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
#include "IGame.hpp"

class Intro : public IGame {
	public:
		explicit Intro(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
		~Intro() = default;

		void loadButtons();
		void loadTextures();
		void run();
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
#endif /* !INTRO_HPP_ */
