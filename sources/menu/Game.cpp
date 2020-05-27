/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

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
}

void Game::loadButtons()
{
}

void Game::run()
{}

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