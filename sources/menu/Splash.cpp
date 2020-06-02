/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Splash
*/

#include "Splash.hpp"
#include "LoadingException.hpp"

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
	_textures["background"] = _driver->getTexture("resources/images/splash/background.png");
	if (_textures.find("background") == _textures.end() || !_textures["background"])
		throw LoadingException("could not load texture : resources/images/splash/background.png");
	_textures["title"] = _driver->getTexture("resources/images/splash/title.png");
	if (_textures.find("title") == _textures.end() || !_textures["title"])
		throw LoadingException("could not load texture : resources/images/splash/title.png");
}

void Splash::loadButtons()
{
	_images["background"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1920, 1080));
	if (_images.find("background") == _images.end() || !_images["background"])
		throw LoadingException("could not add image : background");
	_images["background"]->setImage(_textures["background"]);
	_images["background"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
	_images["title"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1920, 1080));
	if (_images.find("title") == _images.end() || !_images["title"])
		throw LoadingException("could not add image : title");
	_images["title"]->setImage(_textures["title"]);
	_images["title"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 100));
}

std::vector<Character *> Splash::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Splash::getButtons()
{
	return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Splash::getImages()
{
	return _images;
}

ProgressBar *Splash::getBar()
{
	return _bar;
}

void Splash::setBar(ProgressBar *bar)
{
	_bar = bar;
}

std::map<std::string, irr::gui::IGUICheckBox *> Splash::getCheckBox()
{
  return _checkBox;
}