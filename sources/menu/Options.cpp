/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Options
*/

#include "Options.hpp"

Options::Options(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Options::loadTextures()
{
    _textures["retour"] = _driver->getTexture("resources/images/buttons/back.png");
    _textures["plus"] = _driver->getTexture("resources/images/buttons/plus.png");
    _textures["minus"] = _driver->getTexture("resources/images/buttons/minus.png");
}

void Options::loadButtons()
{
    _buttons["retour"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["retour"]->setImage(_textures["retour"]);
    _buttons["retour"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 500));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MUTE, L"");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 500));

    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MUTE, L"");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));
}
