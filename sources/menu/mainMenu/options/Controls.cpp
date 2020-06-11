/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Controls
*/

#include "Controls.hpp"
#include "LoadingException.hpp"

Controls::Controls(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Controls::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    if (_textures.find("back") == _textures.end() || !_textures["back"])
        throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
    if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
        throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
	_textures["GameSettings"] = _driver->getTexture("resources/images/buttons/game_settings.png");
	if (_textures.find("GameSettings") == _textures.end() || !_textures["GameSettings"])
		throw LoadingException("could not load texture : resources/images/buttons/game_settings.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
    _textures["keyboard"] = _driver->getTexture("resources/images/buttons/keyboard.png");
	if (_textures.find("keyboard") == _textures.end() || !_textures["keyboard"])
		throw LoadingException("could not load texture : resources/images/buttons/keyboard.png");
    _textures["keyboard_grey"] = _driver->getTexture("resources/images/buttons/keyboard2.png");
	if (_textures.find("keyboard_grey") == _textures.end() || !_textures["keyboard_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/keyboard2.png");
    _textures["controller"] = _driver->getTexture("resources/images/buttons/controller.png");
	if (_textures.find("controller") == _textures.end() || !_textures["controller"])
		throw LoadingException("could not load texture : resources/images/buttons/controller.png");
    _textures["controller_grey"] = _driver->getTexture("resources/images/buttons/controller2.png");
	if (_textures.find("controller_grey") == _textures.end() || !_textures["controller_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/controller2.png");
    _textures["x"] = _driver->getTexture("resources/images/buttons/switch.png");
	if (_textures.find("x") == _textures.end() || !_textures["x"])
		throw LoadingException("could not load texture : resources/images/buttons/switch.png");
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
    _textures["control_keyboard"] = _driver->getTexture("resources/images/buttons/keyboard_control.png");
	if (_textures.find("control_keyboard") == _textures.end() || !_textures["control_keyboard"])
		throw LoadingException("could not load texture : resources/images/buttons/keyboard_control.png");
    _textures["control_controller"] = _driver->getTexture("resources/images/buttons/controller_control.png");
	if (_textures.find("control_controller") == _textures.end() || !_textures["control_controller"])
		throw LoadingException("could not load texture : resources/images/buttons/controller_control.png");
}

void Controls::loadButtons()
{
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

	_buttons["GameSettings"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_GAMESETTINGS_BUTTON, L"");
	if (_buttons.find("GameSettings") == _buttons.end() || !_buttons["GameSettings"])
		throw LoadingException("could not add button : GameSettings");
	_buttons["GameSettings"]->setImage(_textures["GameSettings"]);
	_buttons["GameSettings"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 600));

    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
        throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));

    _images["keyboard1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("keyboard1") == _images.end() || !_images["keyboard1"])
		throw LoadingException("could not add image : keyboard1");
    _images["keyboard1"]->setImage(_textures["keyboard"]);
    _images["keyboard1"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 350));

    _images["keyboard2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("keyboard2") == _images.end() || !_images["keyboard2"])
		throw LoadingException("could not add image : keyboard2");
    _images["keyboard2"]->setImage(_textures["keyboard"]);
    _images["keyboard2"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 450));

    _images["keyboard3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("keyboard3") == _images.end() || !_images["keyboard3"])
		throw LoadingException("could not add image : keyboard3");
    _images["keyboard3"]->setImage(_textures["keyboard"]);
    _images["keyboard3"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 550));

    _images["keyboard4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("keyboard4") == _images.end() || !_images["keyboard4"])
		throw LoadingException("could not add image : keyboard4");
    _images["keyboard4"]->setImage(_textures["keyboard"]);
    _images["keyboard4"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 650));

    _images["controller1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("controller1") == _images.end() || !_images["controller1"])
		throw LoadingException("could not add image : controller1");
    _images["controller1"]->setImage(_textures["controller"]);
    _images["controller1"]->setRelativePosition(irr::core::position2d<irr::s32>(1320, 350));

    _images["controller2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("controller2") == _images.end() || !_images["controller2"])
		throw LoadingException("could not add image : controller2");
    _images["controller2"]->setImage(_textures["controller"]);
    _images["controller2"]->setRelativePosition(irr::core::position2d<irr::s32>(1320, 450));

    _images["controller3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("controller3") == _images.end() || !_images["controller3"])
		throw LoadingException("could not add image : controller3");
    _images["controller3"]->setImage(_textures["controller"]);
    _images["controller3"]->setRelativePosition(irr::core::position2d<irr::s32>(1320, 550));

    _images["controller4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("controller4") == _images.end() || !_images["controller4"])
		throw LoadingException("could not add image : controller4");
    _images["controller4"]->setImage(_textures["controller"]);
    _images["controller4"]->setRelativePosition(irr::core::position2d<irr::s32>(1320, 650));

    _buttons["x1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_CONTROLS_SWITCH_1, L"");
	if (_buttons.find("x1") == _buttons.end() || !_buttons["x1"])
		throw LoadingException("could not add button : x1");
    _buttons["x1"]->setImage(_textures["x"]);
    _buttons["x1"]->setRelativePosition(irr::core::position2d<irr::s32>(1392, 360));

    _buttons["x2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_CONTROLS_SWITCH_2, L"");
	if (_buttons.find("x2") == _buttons.end() || !_buttons["x2"])
		throw LoadingException("could not add button : x2");
    _buttons["x2"]->setImage(_textures["x"]);
    _buttons["x2"]->setRelativePosition(irr::core::position2d<irr::s32>(1392, 460));

    _buttons["x3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_CONTROLS_SWITCH_3, L"");
	if (_buttons.find("x3") == _buttons.end() || !_buttons["x3"])
		throw LoadingException("could not add button : x3");
    _buttons["x3"]->setImage(_textures["x"]);
    _buttons["x3"]->setRelativePosition(irr::core::position2d<irr::s32>(1392, 560));

    _buttons["x4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_CONTROLS_SWITCH_4, L"");
	if (_buttons.find("x4") == _buttons.end() || !_buttons["x4"])
		throw LoadingException("could not add button : x4");
    _buttons["x4"]->setImage(_textures["x"]);
    _buttons["x4"]->setRelativePosition(irr::core::position2d<irr::s32>(1392, 660));

    _images["p1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p1") == _images.end() || !_images["p1"])
		throw LoadingException("could not add image : p1");
    _images["p1"]->setImage(_textures["p1"]);
    _images["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(1220, 340));

    _images["p2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p2") == _images.end() || !_images["p2"])
		throw LoadingException("could not add image : p2");
    _images["p2"]->setImage(_textures["p2"]);
    _images["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(1220, 440));

    _images["p3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p3") == _images.end() || !_images["p3"])
		throw LoadingException("could not add image : p3");
    _images["p3"]->setImage(_textures["p3"]);
    _images["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1220, 540));

    _images["p4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 67, 67));
	if (_images.find("p4") == _images.end() || !_images["p4"])
		throw LoadingException("could not add image : p4");
    _images["p4"]->setImage(_textures["p4"]);
    _images["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1220, 640));

    _images["control_keyboard"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 200, 401));
	if (_images.find("control_keyboard") == _images.end() || !_images["control_keyboard"])
		throw LoadingException("could not add image : control_keyboard");
    _images["control_keyboard"]->setImage(_textures["control_keyboard"]);
    _images["control_keyboard"]->setRelativePosition(irr::core::position2d<irr::s32>(1520, 320));

    _images["control_controller"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 199, 82));
	if (_images.find("control_controller") == _images.end() || !_images["control_controller"])
		throw LoadingException("could not add image : control_controller");
    _images["control_controller"]->setImage(_textures["control_controller"]);
    _images["control_controller"]->setRelativePosition(irr::core::position2d<irr::s32>(1310, 230));
}

void Controls::changeOption(int role)
{
    if (_nbRole[role][0] == 0) {
        _nbRole[role][0] = 1;
        _nbRole[role][1] = 0;
    } else {
        _nbRole[role][0] = 0;
        _nbRole[role][1] = 1;
    }
}

void Controls::run()
{
    _images["keyboard1"]->setImage(_textures[_selectRole[0][0][_nbRole[0][0]]]);
    _images["controller1"]->setImage(_textures[_selectRole[0][1][_nbRole[0][1]]]);
    _images["keyboard2"]->setImage(_textures[_selectRole[0][0][_nbRole[1][0]]]);
    _images["controller2"]->setImage(_textures[_selectRole[0][1][_nbRole[1][1]]]);
    _images["keyboard3"]->setImage(_textures[_selectRole[0][0][_nbRole[2][0]]]);
    _images["controller3"]->setImage(_textures[_selectRole[0][1][_nbRole[2][1]]]);
    _images["keyboard4"]->setImage(_textures[_selectRole[0][0][_nbRole[3][0]]]);
    _images["controller4"]->setImage(_textures[_selectRole[0][1][_nbRole[3][1]]]);
}

const std::vector<EntityType::ControlType> &Controls::getEntityType()
{
	_controlType.clear();

	for (auto it : _nbRole) {
		if (*it.begin() == 1)
			_controlType.push_back(EntityType::ControlType::Keyboard);
		else
			_controlType.push_back(EntityType::ControlType::Controller);
	}
	return _controlType;
}

std::vector<Character *> Controls::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Controls::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Controls::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Controls::getCheckBox()
{
    return _checkBox;
}