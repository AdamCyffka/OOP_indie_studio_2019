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
    _textures["menuNewButton"] = _driver->getTexture("resources/images/buttons/new.png");
    _textures["menuLoadButton"] = _driver->getTexture("resources/images/buttons/load.png");
    _textures["menuOptionsButton"] = _driver->getTexture("resources/images/buttons/options.png");
    _textures["menuCreditsButton"] = _driver->getTexture("resources/images/buttons/credits.png");
    _textures["menuExitButton"] = _driver->getTexture("resources/images/buttons/leave.png");
    _textures["menuExitPressedButton"] = _driver->getTexture("resources/images/buttons/back.png");
}

void Menu::loadButtons()
{
    _buttons["menuNew"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_NEW_BUTTON, L"");
    _buttons["menuNew"]->setImage(_textures["menuNewButton"]);
    _buttons["menuNew"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 450));

    _buttons["menuLoad"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LOAD_BUTTON, L"");
    _buttons["menuLoad"]->setImage(_textures["menuLoadButton"]);
    _buttons["menuLoad"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 550));

    _buttons["menuOptions"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTIONS_BUTTON, L"");
    _buttons["menuOptions"]->setImage(_textures["menuOptionsButton"]);
    _buttons["menuOptions"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 550));

    _buttons["menuCredits"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_CREDITS_BUTTON, L"");
    _buttons["menuCredits"]->setImage(_textures["menuCreditsButton"]);
    _buttons["menuCredits"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 450));

    _buttons["menuExit"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"");
    _buttons["menuExit"]->setImage(_textures["menuExitButton"]);
    _buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800)); // WIN_WIDTH / 2 - 107.5
}

std::map<std::string, irr::gui::IGUIButton *> Menu::getButtons()
{
    return _buttons;
}