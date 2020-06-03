/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Controls
*/

#include "Controls.hpp"
#include "LoadingException.hpp"

Controls::Controls(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Controls::loadTextures()
{
}

void Controls::loadButtons()
{
}

std::vector<Character *> Controls::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Controls::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Controls::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Controls::getCheckBox()
{
    return _checkBox;
}