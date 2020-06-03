/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Videos
*/

#include "Videos.hpp"
#include "LoadingException.hpp"

Videos::Videos(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Videos::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    if (_textures.find("back") == _textures.end() || !_textures["back"])
        throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
    if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
        throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
    _textures["videos"] = _driver->getTexture("resources/images/buttons/videos.png");
    if (_textures.find("videos") == _textures.end() || !_textures["videos"])
        throw LoadingException("could not load texture : resources/images/buttons/videos.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
    _textures["fullscreen"] = _driver->getTexture("resources/images/buttons/fullscreen.png");
    if (_textures.find("fullscreen") == _textures.end() || !_textures["fullscreen"])
        throw LoadingException("could not load texture : resources/images/buttons/fullscreen.png");
    _textures["vsync"] = _driver->getTexture("resources/images/buttons/vsync.png");
    if (_textures.find("vsync") == _textures.end() || !_textures["vsync"])
        throw LoadingException("could not load texture : resources/images/buttons/vsync.png");
}

void Videos::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
        throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));

    _buttons["sounds"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SOUNDS_BUTTON, L"");
    if (_buttons.find("sounds") == _buttons.end() || !_buttons["sounds"])
        throw LoadingException("could not add button : sounds");
    _buttons["sounds"]->setImage(_textures["sounds"]);
    _buttons["sounds"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 400));

    _buttons["controls"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_CONTROLS_BUTTON, L"");
    if (_buttons.find("controls") == _buttons.end() || !_buttons["controls"])
        throw LoadingException("could not add button : controls");
    _buttons["controls"]->setImage(_textures["controls"]);
    _buttons["controls"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 500));

    _buttons["videos"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_VIDEOS_BUTTON, L"");
    if (_buttons.find("videos") == _buttons.end() || !_buttons["videos"])
        throw LoadingException("could not add button : videos");
    _buttons["videos"]->setImage(_textures["videos"]);
    _buttons["videos"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 600));

    // irr::core::dimension2d<u32> dim(1920, 1080);
    // _checkBox["fullScreen"] = _env->addCheckBox(false, irr::core::rect<s32>(dim.Width - 320, 150, dim.Width - 300, 166), nullptr, -1, L"");
    // _images["fullScreen"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
    // if (_images.find("fullScreen") == _images.end() || !_images["fullScreen"])
    //     throw LoadingException("could not add image : fullScreen");
    // _images["fullScreen"]->setImage(_textures["fullScreen"]);
    // _images["fullScreen"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 900));

    // _checkBox["vsync"] = _env->addCheckBox(false, irr::core::rect<s32>(dim.Width - 600, 20, dim.Width - 300, 1000), nullptr, -1, L"");
    // _images["vsync"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
    // if (_images.find("vsync") == _images.end() || !_images["vsync"])
    //     throw LoadingException("could not add image : vsync");
    // _images["vsync"]->setImage(_textures["vsync"]);
    // _images["vsync"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 1000));
}

std::vector<Character *> Videos::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Videos::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Videos::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Videos::getCheckBox()
{
    return _checkBox;
}