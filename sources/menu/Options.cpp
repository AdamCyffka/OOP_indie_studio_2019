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
    _textures["mute"] =_driver->getTexture("resources/images/buttons/sound.png");
    _textures["muted"] = _driver->getTexture("resources/images/buttons/soundoff.png");
}

void Options::loadButtons()
{
    _buttons["retour"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["retour"]->setImage(_textures["retour"]);
    _buttons["retour"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 500));

    _buttons["mute"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MUTE, L"");
    _buttons["mute"]->setImage(_textures["mute"]);
    _buttons["mute"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 500));

    _scrollbars["volume"] = _env->addScrollBar(true, irr::core::rect<irr::s32>(10, 265, 300, 300), nullptr, GUI_ID_OPTION_SCROLL);
    _scrollbars["volume"]->setMax(100);
    _scrollbars["volume"]->setPos(100);
    _scrollbars["volume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 505));
}