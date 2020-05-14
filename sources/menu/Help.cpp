/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Help
*/

#include "Help.hpp"

Help::Help(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Help::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    _textures["help"] = _driver->getTexture("resources/images/buttons/credits_us.png");
}
void Help::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));

    _images["help"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1333, 272));
    _images["help"]->setImage(_textures["help"]);
    _images["help"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 10));
}

std::map<std::string, irr::gui::IGUIButton *> Help::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Help::getImages()
{
    return _images;
}