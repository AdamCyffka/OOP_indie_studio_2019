/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include "Character.hpp"
#include "Game.hpp"
#include "LoadingException.hpp"

Game::Game(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Game::loadTextures()
{
    _textures["Mario"] = _driver->getTexture("resources/images/characters/MK8_Icon_Mario.png");
	if (_textures.find("Mario") != _textures.end() && !_textures["Mario"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Mario.png");
}

void Game::loadButtons()
{
    _images["Mario"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
    if (_images.find("Mario") != _images.end() && !_images["Mario"])
        throw LoadingException("could not add image : Mario");
    _images["Mario"]->setImage(_textures["Mario"]);
    _images["Mario"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
}

void Game::run()
{
    
}

std::vector<Character *> Game::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Game::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Game::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Game::getCheckBox()
{
    return _checkBox;
}