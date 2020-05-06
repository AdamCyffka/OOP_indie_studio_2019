/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"

Menu::Menu(irr::IrrlichtDevice *window)
{
    _driver = window->getVideoDriver();
    _env = window->getGUIEnvironment();
    loadTextures(window);
    loadButtons(window);
}

void Menu::loadTextures(irr::IrrlichtDevice *window)
{
    _textures["menuBackground"] = _driver->getTexture("resources/images/menu/background.jpg");
    _textures["menuExitButton"] = _driver->getTexture("resources/images/buttons/leave.png");
}

void Menu::loadButtons(irr::IrrlichtDevice *window)
{
    _buttons["menuExit"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"test");
    
    _buttons["menuExit"]->setImage(_textures["menuExitButton"]);
    _buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
}

std::map<std::string, irr::gui::IGUIButton *> Menu::getButtons()
{
    return _buttons;
}

void Menu::run(irr::IrrlichtDevice *window)
{
    _driver->draw2DImage(_textures["menuBackground"], irr::core::position2d<irr::s32>(0, 0),
            irr::core::rect<irr::s32>(0, 0, 1920, 1080), nullptr, irr::video::SColor(255, 255, 255, 255), true);
}