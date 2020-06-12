/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Help
*/

#include "Help.hpp"
#include "LoadingException.hpp"

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
	if (_textures.find("back") == _textures.end() || !_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["help"] = _driver->getTexture("resources/images/help.png");
	if (_textures.find("help") == _textures.end() || !_textures["help"])
		throw LoadingException("could not load texture : resources/images/help.png");
}

void Help::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 950));

    _images["help"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1920, 900));
	if (_images.find("help") == _images.end() || !_images["help"])
		throw LoadingException("could not add image : help");
    _images["help"]->setImage(_textures["help"]);
    _images["help"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
}

std::vector<Character *> Help::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Help::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Help::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Help::getCheckBox()
{
    return _checkBox;
}