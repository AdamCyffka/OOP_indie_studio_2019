/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Pause
*/

#include "Pause.hpp"

Pause::Pause(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Pause::loadTextures()
{
    _textures["resume"] = _driver->getTexture("resources/images/buttons/resume.png");
    _textures["save"] = _driver->getTexture("resources/images/buttons/save.png");
    _textures["options"] = _driver->getTexture("resources/images/buttons/options.png");
    _textures["bachToMenu"] = _driver->getTexture("resources/images/buttons/back.png");
    _textures["backToDesktop"] = _driver->getTexture("resources/images/buttons/leave.png");
}

void Pause::loadButtons()
{
    _buttons["resume"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RESUME_BUTTON, L"");
    _buttons["resume"]->setImage(_textures["resume"]);
    _buttons["resume"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 200));

    _buttons["save"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SAVE_BUTTON, L"");
    _buttons["save"]->setImage(_textures["save"]);
    _buttons["save"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 400));

    _buttons["options"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTIONS_BUTTON, L"");
    _buttons["options"]->setImage(_textures["options"]);
    _buttons["options"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 300));

    _buttons["bachToMenu"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["bachToMenu"]->setImage(_textures["bachToMenu"]);
    _buttons["bachToMenu"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 500));

    _buttons["backToDesktop"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"");
    _buttons["backToDesktop"]->setImage(_textures["backToDesktop"]);
    _buttons["backToDesktop"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 600));
}

void Pause::run()
{}

std::map<std::string, irr::gui::IGUIButton *> Pause::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Pause::getImages()
{
    return _images;
}