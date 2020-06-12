/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameControls
*/

#include "GameControls.hpp"
#include "LoadingException.hpp"

GameControls::GameControls(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void GameControls::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    if (_textures.find("back") == _textures.end() || !_textures["back"])
        throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
    if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
        throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
    _textures["control_keyboard"] = _driver->getTexture("resources/images/buttons/keyboard_control.png");
	if (_textures.find("control_keyboard") == _textures.end() || !_textures["control_keyboard"])
		throw LoadingException("could not load texture : resources/images/buttons/keyboard_control.png");
    _textures["control_controller"] = _driver->getTexture("resources/images/buttons/controller_control.png");
	if (_textures.find("control_controller") == _textures.end() || !_textures["control_controller"])
		throw LoadingException("could not load texture : resources/images/buttons/controller_control.png");
    _textures["p1"] = _driver->getTexture("resources/images/buttons/p1.png");
	if (_textures.find("p1") == _textures.end() || !_textures["p1"])
		throw LoadingException("could not load texture : resources/images/buttons/p1.png");
    _textures["p2"] = _driver->getTexture("resources/images/buttons/p2_2.png");
	if (_textures.find("p2") == _textures.end() || !_textures["p2"])
		throw LoadingException("could not load texture : resources/images/buttons/p2_2.png");
    _textures["p3"] = _driver->getTexture("resources/images/buttons/p3.png");
	if (_textures.find("p3") == _textures.end() || !_textures["p3"])
		throw LoadingException("could not load texture : resources/images/buttons/p3.png");
    _textures["p4"] = _driver->getTexture("resources/images/buttons/p4.png");
	if (_textures.find("p4") == _textures.end() || !_textures["p4"])
        throw LoadingException("could not load texture : resources/images/buttons/p4.png");
}

void GameControls::loadButtons()
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

    _images["p1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p1") == _images.end() || !_images["p1"])
		throw LoadingException("could not add image : p1");
    _images["p1"]->setImage(_textures["p1"]);
    _images["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 340));

    _images["p2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p2") == _images.end() || !_images["p2"])
		throw LoadingException("could not add image : p2");
    _images["p2"]->setImage(_textures["p2"]);
    _images["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 440));

    _images["p3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p3") == _images.end() || !_images["p3"])
		throw LoadingException("could not add image : p3");
    _images["p3"]->setImage(_textures["p3"]);
    _images["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 540));

    _images["p4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p4") == _images.end() || !_images["p4"])
		throw LoadingException("could not add image : p4");
    _images["p4"]->setImage(_textures["p4"]);
    _images["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1300, 640));

    _images["control_keyboard"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 200, 401));
	if (_images.find("control_keyboard") == _images.end() || !_images["control_keyboard"])
		throw LoadingException("could not add image : control_keyboard");
    _images["control_keyboard"]->setImage(_textures["control_keyboard"]);
    _images["control_keyboard"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 320));

    _images["control_controller"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 199, 82));
	if (_images.find("control_controller") == _images.end() || !_images["control_controller"])
		throw LoadingException("could not add image : control_controller");
    _images["control_controller"]->setImage(_textures["control_controller"]);
    _images["control_controller"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 230));
}

std::vector<Character *> GameControls::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> GameControls::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> GameControls::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> GameControls::getCheckBox()
{
    return _checkBox;
}