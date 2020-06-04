/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameSounds
*/

#include "GameSounds.hpp"
#include "LoadingException.hpp"

GameSounds::GameSounds(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void GameSounds::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    if (_textures.find("back") == _textures.end() || !_textures["back"])
        throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["plus"] = _driver->getTexture("resources/images/buttons/plus.png");
    if (_textures.find("plus") == _textures.end() || !_textures["plus"])
        throw LoadingException("could not load texture : resources/images/buttons/plus.png");
    _textures["minus"] = _driver->getTexture("resources/images/buttons/minus.png");
    if (_textures.find("minus") == _textures.end() || !_textures["minus"])
        throw LoadingException("could not load texture : resources/images/buttons/minus.png");
    _textures["generalVolume"] = _driver->getTexture("resources/images/buttons/general_volume.png");
    if (_textures.find("generalVolume") == _textures.end() || !_textures["generalVolume"])
        throw LoadingException("could not load texture : resources/images/buttons/general_volume.png");
    _textures["musicVolume"] = _driver->getTexture("resources/images/buttons/music_volume.png");
    if (_textures.find("musicVolume") == _textures.end() || !_textures["musicVolume"])
        throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
    _textures["sfxVolume"] = _driver->getTexture("resources/images/buttons/sfx_volume.png");
    if (_textures.find("sfxVolume") == _textures.end() || !_textures["sfxVolume"])
        throw LoadingException("could not load texture : resources/images/buttons/sfx_volume.png");
    _textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
    if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
        throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
}

void GameSounds::loadButtons()
{
    _buttons["sounds"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_SOUNDS, L"");
    if (_buttons.find("sounds") == _buttons.end() || !_buttons["sounds"])
        throw LoadingException("could not add button : sounds");
    _buttons["sounds"]->setImage(_textures["sounds"]);
    _buttons["sounds"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 450));

    _buttons["controls"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_CONTROLS, L"");
    if (_buttons.find("controls") == _buttons.end() || !_buttons["controls"])
        throw LoadingException("could not add button : controls");
    _buttons["controls"]->setImage(_textures["controls"]);
    _buttons["controls"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 550));

    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_RETURN, L"");
    if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
        throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_MUSIC_BUTTON, L"");
    if (_buttons.find("plus") == _buttons.end() || !_buttons["plus"])
        throw LoadingException("could not add button : plus");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 500));
    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_MUSIC_BUTTON, L"");
    if (_buttons.find("minus") == _buttons.end() || !_buttons["minus"])
        throw LoadingException("could not add button : minus");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));
    _images["musicVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
    if (_images.find("musicVolume") == _images.end() || !_images["musicVolume"])
        throw LoadingException("could not add image : musicVolume");
    _images["musicVolume"]->setImage(_textures["musicVolume"]);
    _images["musicVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 500));

    _buttons["plus2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_GENERAL_BUTTON, L"");
    if (_buttons.find("plus2") == _buttons.end() || !_buttons["plus2"])
        throw LoadingException("could not add button : plus2");
    _buttons["plus2"]->setImage(_textures["plus"]);
    _buttons["plus2"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 400));
    _buttons["minus2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_GENERAL_BUTTON, L"");
    if (_buttons.find("minus2") == _buttons.end() || !_buttons["minus2"])
        throw LoadingException("could not add button : minus2");
    _buttons["minus2"]->setImage(_textures["minus"]);
    _buttons["minus2"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 400));
    _images["generalVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
    if (_images.find("generalVolume") == _images.end() || !_images["generalVolume"])
        throw LoadingException("could not add image : generalVolume");
    _images["generalVolume"]->setImage(_textures["generalVolume"]);
    _images["generalVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 400));

    _buttons["plus3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_SFX_BUTTON, L"");
    if (_buttons.find("plus3") == _buttons.end() || !_buttons["plus3"])
        throw LoadingException("could not add button : plus3");
    _buttons["plus3"]->setImage(_textures["plus"]);
    _buttons["plus3"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 600));
    _buttons["minus3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_SFX_BUTTON, L"");
    if (_buttons.find("minus3") == _buttons.end() || !_buttons["minus3"])
        throw LoadingException("could not add button : minus3");
    _buttons["minus3"]->setImage(_textures["minus"]);
    _buttons["minus3"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 600));
    _images["sfxVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
    if (_images.find("sfxVolume") == _images.end() || !_images["sfxVolume"])
        throw LoadingException("could not add image : sfxVolume");
    _images["sfxVolume"]->setImage(_textures["sfxVolume"]);
    _images["sfxVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 600));
}

std::vector<Character *> GameSounds::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> GameSounds::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> GameSounds::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> GameSounds::getCheckBox()
{
    return _checkBox;
}