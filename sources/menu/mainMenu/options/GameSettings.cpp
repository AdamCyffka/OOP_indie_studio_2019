/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameSettings
*/

#include "GameSettings.hpp"
#include "LoadingException.hpp"

GameSettings::GameSettings(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    _firePower = 1;
    _bombAmount = 1;
    _speed = 2;
    _wallPass = false;
    _bombPass = false;

    loadTextures();
    loadButtons();
}

void GameSettings::loadTextures()
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
	_textures["false"] = _driver->getTexture("resources/images/buttons/box_uncheck.png");
	if (_textures.find("false") == _textures.end() || !_textures["false"])
		throw LoadingException("could not load texture : resources/images/buttons/box_uncheck.png");
	_textures["true"] = _driver->getTexture("resources/images/buttons/box_check.png");
	if (_textures.find("true") == _textures.end() || !_textures["true"])
		throw LoadingException("could not load texture : resources/images/buttons/box_check.png");
    _textures["GameSettings"] = _driver->getTexture("resources/images/buttons/game_settings.png");
    if (_textures.find("GameSettings") == _textures.end() || !_textures["GameSettings"])
        throw LoadingException("could not load texture : resources/images/buttons/game_settings.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
	_textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
	if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
		throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
	_textures["firePower"] = _driver->getTexture("resources/images/buttons/fire_power.png");
	if (_textures.find("firePower") == _textures.end() || !_textures["firePower"])
		throw LoadingException("could not load texture : resources/images/buttons/fire_power.png");
	_textures["bombAmount"] = _driver->getTexture("resources/images/buttons/bomb_amount.png");
	if (_textures.find("bombAmount") == _textures.end() || !_textures["bombAmount"])
		throw LoadingException("could not load texture : resources/images/buttons/bomb_amount.png");
	_textures["speed"] = _driver->getTexture("resources/images/buttons/speed.png");
	if (_textures.find("speed") == _textures.end() || !_textures["speed"])
		throw LoadingException("could not load texture : resources/images/buttons/speed.png");
	_textures["wallPass"] = _driver->getTexture("resources/images/buttons/wall_pass.png");
	if (_textures.find("wallPass") == _textures.end() || !_textures["wallPass"])
		throw LoadingException("could not load texture : resources/images/buttons/wall_pass.png");
	_textures["bombPass"] = _driver->getTexture("resources/images/buttons/bomb_pass.png");
	if (_textures.find("bombPass") == _textures.end() || !_textures["bombPass"])
		throw LoadingException("could not load texture : resources/images/buttons/bomb_pass.png");
	_textures["value1"] = _driver->getTexture("resources/images/buttons/1.png");
	if (_textures.find("value1") == _textures.end() || !_textures["value1"])
		throw LoadingException("could not load texture : resources/images/buttons/1.png");
	_textures["value2"] = _driver->getTexture("resources/images/buttons/2.png");
	if (_textures.find("value2") == _textures.end() || !_textures["value2"])
		throw LoadingException("could not load texture : resources/images/buttons/2.png");
	_textures["value3"] = _driver->getTexture("resources/images/buttons/3.png");
	if (_textures.find("value3") == _textures.end() || !_textures["value3"])
		throw LoadingException("could not load texture : resources/images/buttons/3.png");
	_textures["value4"] = _driver->getTexture("resources/images/buttons/4.png");
	if (_textures.find("value4") == _textures.end() || !_textures["value4"])
		throw LoadingException("could not load texture : resources/images/buttons/4.png");
	_textures["value5"] = _driver->getTexture("resources/images/buttons/5.png");
	if (_textures.find("value5") == _textures.end() || !_textures["value5"])
		throw LoadingException("could not load texture : resources/images/buttons/5.png");
}

void GameSettings::loadButtons()
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

    _buttons["GameSettings"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_GAMESETTINGS_BUTTON, L"");
    if (_buttons.find("GameSettings") == _buttons.end() || !_buttons["GameSettings"])
        throw LoadingException("could not add button : GameSettings");
    _buttons["GameSettings"]->setImage(_textures["GameSettings"]);
    _buttons["GameSettings"]->setRelativePosition(irr::core::position2d<irr::s32>(400, 600));

    //firepower
	_images["firePower"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("firePower") == _images.end() || !_images["firePower"])
		throw LoadingException("could not add image : firePower");
	_images["firePower"]->setImage(_textures["firePower"]);
	_images["firePower"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 500));

    _buttons["plusFirePower"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_PLUS_FIRE_POWER, L"");
	if (_buttons.find("plusFirePower") == _buttons.end() || !_buttons["plusFirePower"])
		throw LoadingException("could not add button : plusFirePower");
	_buttons["plusFirePower"]->setImage(_textures["plus"]);
	_buttons["plusFirePower"]->setRelativePosition(irr::core::position2d<irr::s32>(1570, 500));
	_buttons["minusFirePower"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_FIRE_POWER, L"");
	if (_buttons.find("minusFirePower") == _buttons.end() || !_buttons["minusFirePower"])
		throw LoadingException("could not add button : minusFirePower");
	_buttons["minusFirePower"]->setImage(_textures["minus"]);
	_buttons["minusFirePower"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));
	_buttons["firePowerValue"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, -1, L"");
	if (_buttons.find("firePowerValue") == _buttons.end() || !_buttons["firePowerValue"])
		throw LoadingException("could not add button : firePowerValue");
	_buttons["firePowerValue"]->setImage(_textures["value1"]);
	_buttons["firePowerValue"]->setRelativePosition(irr::core::position2d<irr::s32>(1510, 500));

	//bombamount
	_images["bombAmount"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("bombAmount") == _images.end() || !_images["bombAmount"])
		throw LoadingException("could not add image : bombAmount");
	_images["bombAmount"]->setImage(_textures["bombAmount"]);
	_images["bombAmount"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 400));

	_buttons["plusBombAmount"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_PLUS_BOMB_AMOUNT, L"");
	if (_buttons.find("plusBombAmount") == _buttons.end() || !_buttons["plusBombAmount"])
		throw LoadingException("could not add button : plusBombAmount");
	_buttons["plusBombAmount"]->setImage(_textures["plus"]);
	_buttons["plusBombAmount"]->setRelativePosition(irr::core::position2d<irr::s32>(1570, 400));
	_buttons["minusBombAmount"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_BOMB_AMOUNT, L"");
	if (_buttons.find("minusBombAmount") == _buttons.end() || !_buttons["minusBombAmount"])
		throw LoadingException("could not add button : minusBombAmount");
	_buttons["minusBombAmount"]->setImage(_textures["minus"]);
	_buttons["minusBombAmount"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 400));
	_buttons["bombAmountValue"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, -1, L"");
	if (_buttons.find("bombAmountValue") == _buttons.end() || !_buttons["bombAmountValue"])
		throw LoadingException("could not add button : bombAmountValue");
	_buttons["bombAmountValue"]->setImage(_textures["value1"]);
	_buttons["bombAmountValue"]->setRelativePosition(irr::core::position2d<irr::s32>(1510, 400));

	//speed
	_images["speed"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("speed") == _images.end() || !_images["speed"])
		throw LoadingException("could not add image : speed");
	_images["speed"]->setImage(_textures["speed"]);
	_images["speed"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 300));

	_buttons["plusSpeed"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_PLUS_SPEED, L"");
	if (_buttons.find("plusSpeed") == _buttons.end() || !_buttons["plusSpeed"])
		throw LoadingException("could not add button : plusSpeed");
	_buttons["plusSpeed"]->setImage(_textures["plus"]);
	_buttons["plusSpeed"]->setRelativePosition(irr::core::position2d<irr::s32>(1570, 300));
	_buttons["minusSpeed"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_SPEED, L"");
	if (_buttons.find("minusSpeed") == _buttons.end() || !_buttons["minusSpeed"])
		throw LoadingException("could not add button : minusSpeed");
	_buttons["minusSpeed"]->setImage(_textures["minus"]);
	_buttons["minusSpeed"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 300));
	_buttons["speedValue"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, -1, L"");
	if (_buttons.find("speedValue") == _buttons.end() || !_buttons["speedValue"])
		throw LoadingException("could not add button : speedValue");
	_buttons["speedValue"]->setImage(_textures["value2"]);
	_buttons["speedValue"]->setRelativePosition(irr::core::position2d<irr::s32>(1510, 300));

	//wallpass
	_images["wallPass"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("wallPass") == _images.end() || !_images["wallPass"])
		throw LoadingException("could not add image : wallPass");
	_images["wallPass"]->setImage(_textures["wallPass"]);
	_images["wallPass"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 600));

	_buttons["wallPassStatus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_WALLPASS, L"");
	if (_buttons.find("wallPassStatus") == _buttons.end() || !_buttons["wallPassStatus"])
		throw LoadingException("could not add button : wallPassStatus");
	_buttons["wallPassStatus"]->setImage(_textures["false"]);
	_buttons["wallPassStatus"]->setRelativePosition(irr::core::position2d<irr::s32>(1510, 600));

	//bombPass
	_images["bombPass"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("bombPass") == _images.end() || !_images["bombPass"])
		throw LoadingException("could not add image : bombPass");
	_images["bombPass"]->setImage(_textures["bombPass"]);
	_images["bombPass"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 700));

	_buttons["bombPassStatus"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_BOMBPASS, L"");
	if (_buttons.find("bombPassStatus") == _buttons.end() || !_buttons["bombPassStatus"])
		throw LoadingException("could not add button : bombPassStatus");
	_buttons["bombPassStatus"]->setImage(_textures["false"]);
	_buttons["bombPassStatus"]->setRelativePosition(irr::core::position2d<irr::s32>(1510, 700));
}

std::vector<Character *> GameSettings::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> GameSettings::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> GameSettings::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> GameSettings::getCheckBox()
{
    return _checkBox;
}

int GameSettings::getFirePower() const
{
	return _firePower;
}

void GameSettings::setFirePower(int firePower)
{
	_firePower += firePower;
	if (_firePower > 5)
		_firePower = 5;
	if (_firePower < 1)
		_firePower = 1;
	switch (_firePower)
	{
		case 1:
			_buttons["firePowerValue"]->setImage(_textures["value1"]);
			break;
		case 2:
			_buttons["firePowerValue"]->setImage(_textures["value2"]);
			break;
		case 3:
			_buttons["firePowerValue"]->setImage(_textures["value3"]);
			break;
		case 4:
			_buttons["firePowerValue"]->setImage(_textures["value4"]);
			break;
		case 5:
			_buttons["firePowerValue"]->setImage(_textures["value5"]);
			break;
		default:
			break;
	}
}

int GameSettings::getBombAmount() const
{
	return _bombAmount;
}

void GameSettings::setBombAmount(int bombAmount)
{
	_bombAmount += bombAmount;
	if (_bombAmount > 4)
		_bombAmount = 4;
	if (_bombAmount < 1)
		_bombAmount = 1;
	switch (_bombAmount)
	{
		case 1:
			_buttons["bombAmountValue"]->setImage(_textures["value1"]);
			break;
		case 2:
			_buttons["bombAmountValue"]->setImage(_textures["value2"]);
			break;
		case 3:
			_buttons["bombAmountValue"]->setImage(_textures["value3"]);
			break;
		case 4:
			_buttons["bombAmountValue"]->setImage(_textures["value4"]);
			break;
		default:
			break;
	}
}

int GameSettings::getSpeed() const
{
	return _speed;
}

void GameSettings::setSpeed(int speed)
{
	_speed += speed;
	if (_speed > 5)
		_speed = 5;
	if (_speed < 1)
		_speed = 1;
	switch (_speed)
	{
		case 1:
			_buttons["speedValue"]->setImage(_textures["value1"]);
			break;
		case 2:
			_buttons["speedValue"]->setImage(_textures["value2"]);
			break;
		case 3:
			_buttons["speedValue"]->setImage(_textures["value3"]);
			break;
		case 4:
			_buttons["speedValue"]->setImage(_textures["value4"]);
			break;
		case 5:
			_buttons["speedValue"]->setImage(_textures["value5"]);
			break;
		default:
			break;
	}
}

bool GameSettings::isWallPass() const
{
	return _wallPass;
}

void GameSettings::setWallPass(bool wallPass)
{
	_wallPass = wallPass;
	if (_wallPass)
		_buttons["wallPassStatus"]->setImage(_textures["true"]);
	else
		_buttons["wallPassStatus"]->setImage(_textures["false"]);
}

bool GameSettings::isBombPass() const
{
	return _bombPass;
}

void GameSettings::setBombPass(bool bombPass)
{
	_bombPass = bombPass;
	if (_bombPass)
		_buttons["bombPassStatus"]->setImage(_textures["true"]);
	else
		_buttons["bombPassStatus"]->setImage(_textures["false"]);
}
