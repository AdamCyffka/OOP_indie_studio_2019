/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Menu
*/

#include "Menu.hpp"
#include "LoadingException.hpp"

Menu::Menu(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Menu::loadTextures()
{
    _textures["menuNewButton"] = _driver->getTexture("resources/images/buttons/new.png");
	if (_textures.find("menuNewButton") != _textures.end() && !_textures["menuNewButton"])
		throw LoadingException("could not load texture : resources/images/buttons/new.png");
    _textures["menuLoadButton"] = _driver->getTexture("resources/images/buttons/load.png");
	if (_textures.find("menuLoadButton") != _textures.end() && !_textures["menuLoadButton"])
		throw LoadingException("could not load texture : resources/images/buttons/load.png");
    _textures["menuOptionsButton"] = _driver->getTexture("resources/images/buttons/options.png");
	if (_textures.find("menuOptionsButton") != _textures.end() && !_textures["menuOptionsButton"])
		throw LoadingException("could not load texture : resources/images/buttons/options.png");
    _textures["menuCreditsButton"] = _driver->getTexture("resources/images/buttons/credits.png");
	if (_textures.find("menuCreditsButton") != _textures.end() && !_textures["menuCreditsButton"])
		throw LoadingException("could not load texture : resources/images/buttons/credits.png");
    _textures["menuExitButton"] = _driver->getTexture("resources/images/buttons/leave.png");
	if (_textures.find("menuExitButton") != _textures.end() && !_textures["menuExitButton"])
		throw LoadingException("could not load texture : resources/images/buttons/leave.png");
    _textures["menuExitPressedButton"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("menuExitPressedButton") != _textures.end() && !_textures["menuExitPressedButton"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["menuHelpButton"] = _driver->getTexture("resources/images/buttons/help.png");
	if (_textures.find("menuHelpButton") != _textures.end() && !_textures["menuHelpButton"])
		throw LoadingException("could not load texture : resources/images/buttons/help.png");
}

void Menu::loadButtons()
{
    _buttons["menuNew"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_NEW_BUTTON, L"");
	if (_buttons.find("menuNew") != _buttons.end() && !_buttons["menuNew"])
		throw LoadingException("could not add button : menuNew");
    _buttons["menuNew"]->setImage(_textures["menuNewButton"]);
    _buttons["menuNew"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 450));

    _buttons["menuLoad"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_LOAD_BUTTON, L"");
	if (_buttons.find("menuLoad") != _buttons.end() && !_buttons["menuLoad"])
		throw LoadingException("could not add button : menuLoad");
    _buttons["menuLoad"]->setImage(_textures["menuLoadButton"]);
    _buttons["menuLoad"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 550));

    _buttons["menuOptions"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTIONS_BUTTON, L"");
	if (_buttons.find("menuOptions") != _buttons.end() && !_buttons["menuOptions"])
		throw LoadingException("could not add button : menuOptions");
    _buttons["menuOptions"]->setImage(_textures["menuOptionsButton"]);
    _buttons["menuOptions"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 550));

    _buttons["menuCredits"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_CREDITS_BUTTON, L"");
	if (_buttons.find("menuCredits") != _buttons.end() && !_buttons["menuCredits"])
		throw LoadingException("could not add button : menuCredits");
    _buttons["menuCredits"]->setImage(_textures["menuCreditsButton"]);
    _buttons["menuCredits"]->setRelativePosition(irr::core::position2d<irr::s32>(1680, 945));

    _buttons["menuExit"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_QUIT_BUTTON, L"");
	if (_buttons.find("menuExit") != _buttons.end() && !_buttons["menuExit"])
		throw LoadingException("could not add button : menuExit");
    _buttons["menuExit"]->setImage(_textures["menuExitButton"]);
    _buttons["menuExit"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));

    _buttons["menuHelpButton"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_HELP_BUTTON, L"");
	if (_buttons.find("menuHelpButton") != _buttons.end() && !_buttons["menuHelpButton"])
		throw LoadingException("could not add button : menuHelpButton");
    _buttons["menuHelpButton"]->setImage(_textures["menuHelpButton"]);
    _buttons["menuHelpButton"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 450));
}

void Menu::run()
{}

std::vector<Character *> Menu::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Menu::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Menu::getImages()
{
	return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Menu::getCheckBox()
{
  return _checkBox;
}