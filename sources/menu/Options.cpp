/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Options
*/

#include "Options.hpp"
#include "LoadingException.hpp"

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
	if (_textures.find("retour") != _textures.end() && !_textures["retour"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["plus"] = _driver->getTexture("resources/images/buttons/plus.png");
	if (_textures.find("plus") != _textures.end() && !_textures["plus"])
		throw LoadingException("could not load texture : resources/images/buttons/plus.png");
    _textures["minus"] = _driver->getTexture("resources/images/buttons/minus.png");
	if (_textures.find("minus") != _textures.end() && !_textures["minus"])
		throw LoadingException("could not load texture : resources/images/buttons/minus.png");
    _textures["generalVolume"] = _driver->getTexture("resources/images/buttons/general_volume.png");
	if (_textures.find("generalVolume") != _textures.end() && !_textures["generalVolume"])
		throw LoadingException("could not load texture : resources/images/buttons/general_volume.png");
    _textures["musicVolume"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("musicVolume") != _textures.end() && !_textures["musicVolume"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
    _textures["sfxVolume"] = _driver->getTexture("resources/images/buttons/sfx_volume.png");
	if (_textures.find("sfxVolume") != _textures.end() && !_textures["sfxVolume"])
		throw LoadingException("could not load texture : resources/images/buttons/sfx_volume.png");
}

void Options::loadButtons()
{
    _buttons["retour"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("retour") != _buttons.end() && !_buttons["retour"])
		throw LoadingException("could not add button : retour");
    _buttons["retour"]->setImage(_textures["retour"]);
    _buttons["retour"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 500));

    _buttons["plus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_MUSIC_BUTTON, L"");
	if (_buttons.find("plus") != _buttons.end() && !_buttons["plus"])
		throw LoadingException("could not add button : plus");
    _buttons["plus"]->setImage(_textures["plus"]);
    _buttons["plus"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 500));
    _buttons["minus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_MUSIC_BUTTON, L"");
	if (_buttons.find("minus") != _buttons.end() && !_buttons["minus"])
		throw LoadingException("could not add button : minus");
    _buttons["minus"]->setImage(_textures["minus"]);
    _buttons["minus"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));
    _images["musicVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("musicVolume") != _images.end() && !_images["musicVolume"])
		throw LoadingException("could not add image : musicVolume");
    _images["musicVolume"]->setImage(_textures["musicVolume"]);
    _images["musicVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 500));

    _buttons["plus2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_GENERAL_BUTTON, L"");
	if (_buttons.find("plus2") != _buttons.end() && !_buttons["plus2"])
		throw LoadingException("could not add button : plus2");
    _buttons["plus2"]->setImage(_textures["plus"]);
    _buttons["plus2"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 400));
    _buttons["minus2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_GENERAL_BUTTON, L"");
	if (_buttons.find("minus2") != _buttons.end() && !_buttons["minus2"])
		throw LoadingException("could not add button : minus2");
    _buttons["minus2"]->setImage(_textures["minus"]);
    _buttons["minus2"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 400));
    _images["generalVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("generalVolume") != _images.end() && !_images["generalVolume"])
		throw LoadingException("could not add image : generalVolume");
    _images["generalVolume"]->setImage(_textures["generalVolume"]);
    _images["generalVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 400));

    _buttons["plus3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_PLUS_SFX_BUTTON, L"");
	if (_buttons.find("plus3") != _buttons.end() && !_buttons["plus3"])
		throw LoadingException("could not add button : plus3");
    _buttons["plus3"]->setImage(_textures["plus"]);
    _buttons["plus3"]->setRelativePosition(irr::core::position2d<irr::s32>(1550, 600));
    _buttons["minus3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_OPTION_MINUS_SFX_BUTTON, L"");
	if (_buttons.find("minus3") != _buttons.end() && !_buttons["minus3"])
		throw LoadingException("could not add button : minus3");
    _buttons["minus3"]->setImage(_textures["minus"]);
    _buttons["minus3"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 600));
    _images["sfxVolume"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("sfxVolume") != _images.end() && !_images["sfxVolume"])
		throw LoadingException("could not add image : sfxVolume");
    _images["sfxVolume"]->setImage(_textures["sfxVolume"]);
    _images["sfxVolume"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 600));

    irr::core::dimension2d<u32> dim(1920, 1080);
    _checkBox["fullScreen"] = _env->addCheckBox(false, irr::core::rect<s32>(dim.Width - 600, 20, dim.Width - 300, 80), nullptr, -1, L"Fullscreen");
}

std::vector<Character *> Options::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Options::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Options::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Options::getCheckBox()
{
    return _checkBox;
}