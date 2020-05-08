/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Menu::loadTextures()
{
    _textures["menuExitButton"] = _driver->getTexture("resources/images/buttons/leave.png");
}

void Menu::loadButtons()
{
    _buttons["menuExit"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"");
    
    _buttons["menuExit"]->setImage(_textures["menuExitButton"]);
    _buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
}

void Menu::run()
{
}