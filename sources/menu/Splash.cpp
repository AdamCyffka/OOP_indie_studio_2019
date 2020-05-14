/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Splash
*/

#include "Splash.hpp"

Splash::Splash(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
	_driver = driver;
	_env = env;
	_smgr = smgr;

	loadTextures();
	loadButtons();
}

void Splash::loadTextures()
{
	_textures["background"] = _driver->getTexture("resources/images/splash/splash.png");
}

void Splash::loadButtons()
{
	_images["background"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, GUI_ID_OPTION_MUSIC_IMAGE);
	_images["background"]->setImage(_textures["background"]);
	_images["background"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
}

std::map<std::string, irr::gui::IGUIButton *> Splash::getButtons()
{
	return _buttons;
}