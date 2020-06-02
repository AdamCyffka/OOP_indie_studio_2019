/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Help
*/

#include "Credits.hpp"
#include "LoadingException.hpp"

Credits::Credits(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Credits::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("back") == _textures.end() || !_textures["back"])
		throw LoadingException("could not load texture : resources/images/splash/back.png");
    _textures["credits"] = _driver->getTexture("resources/images/buttons/credits_us.png");
	if (_textures.find("credits") == _textures.end() || !_textures["credits"])
		throw LoadingException("could not load texture : resources/images/splash/credits_us.png");
}

void Credits::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
    _images["credits"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 1333, 272));
	if (_images.find("credits") == _images.end() || !_images["credits"])
		throw LoadingException("could not add image : credits");
    _images["credits"]->setImage(_textures["credits"]);
    _images["credits"]->setRelativePosition(irr::core::position2d<irr::s32>(300, 10));
}

std::vector<Character *> Credits::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Credits::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Credits::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Credits::getCheckBox()
{
    return _checkBox;
}