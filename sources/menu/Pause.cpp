/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Pause
*/

#include "Pause.hpp"
#include "LoadingException.hpp"

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
	if (_textures.find("resume") != _textures.end() && !_textures["resume"])
		throw LoadingException("could not load texture : resources/images/buttons/resume.png");
    _textures["save"] = _driver->getTexture("resources/images/buttons/save.png");
	if (_textures.find("save") != _textures.end() && !_textures["save"])
		throw LoadingException("could not load texture : resources/images/buttons/save.png");
    _textures["options"] = _driver->getTexture("resources/images/buttons/options.png");
	if (_textures.find("options") != _textures.end() && !_textures["options"])
		throw LoadingException("could not load texture : resources/images/buttons/options.png");
    _textures["backToMenu"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("backToMenu") != _textures.end() && !_textures["backToMenu"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["backToDesktop"] = _driver->getTexture("resources/images/buttons/leave.png");
	if (_textures.find("backToDesktop") != _textures.end() && !_textures["backToDesktop"])
		throw LoadingException("could not load texture : resources/images/buttons/leave.png");
}

void Pause::loadButtons()
{
    _buttons["resume"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_RESUME_BUTTON, L"");
	if (_buttons.find("resume") != _buttons.end() && !_buttons["resume"])
		throw LoadingException("could not add button : resume");
    _buttons["resume"]->setImage(_textures["resume"]);
    _buttons["resume"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 200));

    _buttons["save"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SAVE_BUTTON, L"");
	if (_buttons.find("save") != _buttons.end() && !_buttons["save"])
		throw LoadingException("could not add button : save");
    _buttons["save"]->setImage(_textures["save"]);
    _buttons["save"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 400));

    _buttons["options"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_OPTIONS, L"");
	if (_buttons.find("options") != _buttons.end() && !_buttons["options"])
		throw LoadingException("could not add button : options");
    _buttons["options"]->setImage(_textures["options"]);
    _buttons["options"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 300));

    _buttons["backToMenu"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_PAUSE_MENU, L"");
	if (_buttons.find("backToMenu") != _buttons.end() && !_buttons["backToMenu"])
		throw LoadingException("could not add button : back");
    _buttons["backToMenu"]->setImage(_textures["backToMenu"]);
    _buttons["backToMenu"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 500));

    _buttons["backToDesktop"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"");
	if (_buttons.find("backToDesktop") != _buttons.end() && !_buttons["backToDesktop"])
		throw LoadingException("could not add button : backToDesktop");
    _buttons["backToDesktop"]->setImage(_textures["backToDesktop"]);
    _buttons["backToDesktop"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 600));
}

std::vector<Character *> Pause::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Pause::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Pause::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Pause::getCheckBox()
{
    return _checkBox;
}