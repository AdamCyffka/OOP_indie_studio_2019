/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Intro
*/

#include "CircleCameraTravel.hpp"
#include "Intro.hpp"
#include "LoadingException.hpp"

Intro::Intro(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Intro::loadTextures()
{
    _textures["press"] = _driver->getTexture("resources/images/buttons/press.png");
	if (_textures.find("press") != _textures.end() && !_textures["press"])
		throw LoadingException("could not load texture : resources/images/buttons/press.png");
}

void Intro::loadButtons()
{
    _buttons["press"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, IGame::GUI_ID_INTRO_BUTTON, L"");
	if (_buttons.find("press") != _buttons.end() && !_buttons["press"])
		throw LoadingException("could not add button : press");
    _buttons["press"]->setImage(_textures["press"]);
    _buttons["press"]->setRelativePosition(irr::core::position2d<irr::s32>(790, 800));
}

void Intro::run()
{}

std::vector<Character *> Intro::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Intro::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Intro::getImages()
{
    return _images;
}