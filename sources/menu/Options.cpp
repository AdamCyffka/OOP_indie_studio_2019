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
    _textures["generalVolume"] = _driver->getTexture("resources/images/buttons/general_volume.png");
    _textures["musicVolume"] = _driver->getTexture("resources/images/buttons/music_volume.png");
    _textures["sfxVolume"] = _driver->getTexture("resources/images/buttons/sfx_volume.png");
}

void Options::loadButtons()
{
    _buttons["retour"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["retour"]->setImage(_textures["retour"]);
    _buttons["retour"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 500));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_MUSIC_BUTTON, L"");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 500));
    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_MUSIC_BUTTON, L"");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));
    _images["musicVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_MUSIC_IMAGE);
    _images["musicVolume"]->setImage(_textures["musicVolume"]);
    _images["musicVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 500));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_GENERAL_BUTTON, L"");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 400));
    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_GENERAL_BUTTON, L"");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 400));
    _images["generalVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_GENERAL_IMAGE);
    _images["generalVolume"]->setImage(_textures["generalVolume"]);
    _images["generalVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 400));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_SFX_BUTTON, L"");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 600));
    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_SFX_BUTTON, L"");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 600));
    _images["sfxVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_SFX_IMAGE);
    _images["sfxVolume"]->setImage(_textures["sfxVolume"]);
    _images["sfxVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 600));
}
