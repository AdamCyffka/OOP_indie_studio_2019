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
	_textures["false"] = _driver->getTexture("resources/images/buttons/plus.png");
	if (_textures.find("plus") == _textures.end() || !_textures["plus"])
		throw LoadingException("could not load texture : resources/images/buttons/plus.png");
	_textures["true"] = _driver->getTexture("resources/images/buttons/plus.png");
	if (_textures.find("plus") == _textures.end() || !_textures["plus"])
		throw LoadingException("could not load texture : resources/images/buttons/plus.png");
    _textures["GameSettings"] = _driver->getTexture("resources/images/buttons/videos.png");
    if (_textures.find("GameSettings") == _textures.end() || !_textures["GameSettings"])
        throw LoadingException("could not load texture : resources/images/buttons/videos.png");
    _textures["controls"] = _driver->getTexture("resources/images/buttons/controls.png");
    if (_textures.find("controls") == _textures.end() || !_textures["controls"])
        throw LoadingException("could not load texture : resources/images/buttons/controls.png");
	_textures["sounds"] = _driver->getTexture("resources/images/buttons/sounds.png");
	if (_textures.find("sounds") == _textures.end() || !_textures["sounds"])
		throw LoadingException("could not load texture : resources/images/buttons/sounds.png");
	_textures["firePower"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("firePower") == _textures.end() || !_textures["firePower"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
	_textures["bombAmount"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("bombAmount") == _textures.end() || !_textures["bombAmount"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
	_textures["speed"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("speed") == _textures.end() || !_textures["speed"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
	_textures["wallPass"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("wallPass") == _textures.end() || !_textures["wallPass"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
	_textures["bombPass"] = _driver->getTexture("resources/images/buttons/music_volume.png");
	if (_textures.find("bombPass") == _textures.end() || !_textures["bombPass"])
		throw LoadingException("could not load texture : resources/images/buttons/music_volume.png");
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
	_buttons["plusFirePower"]->setRelativePosition(irr::core::position2d<irr::s32>(1650, 500));
	_buttons["minusFirePower"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_FIRE_POWER, L"");
	if (_buttons.find("minusFirePower") == _buttons.end() || !_buttons["minusFirePower"])
		throw LoadingException("could not add button : minusFirePower");
	_buttons["minusFirePower"]->setImage(_textures["minus"]);
	_buttons["minusFirePower"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 500));

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
	_buttons["plusBombAmount"]->setRelativePosition(irr::core::position2d<irr::s32>(1650, 400));
	_buttons["minusBombAmount"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_BOMB_AMOUNT, L"");
	if (_buttons.find("minusBombAmount") == _buttons.end() || !_buttons["minusBombAmount"])
		throw LoadingException("could not add button : minusBombAmount");
	_buttons["minusBombAmount"]->setImage(_textures["minus"]);
	_buttons["minusBombAmount"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 400));

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
	_buttons["plusSpeed"]->setRelativePosition(irr::core::position2d<irr::s32>(1650, 300));
	_buttons["minusSpeed"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_MINUS_SPEED, L"");
	if (_buttons.find("minusSpeed") == _buttons.end() || !_buttons["minusSpeed"])
		throw LoadingException("could not add button : minusSpeed");
	_buttons["minusSpeed"]->setImage(_textures["minus"]);
	_buttons["minusSpeed"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 300));

	//wallpass
	_images["wallPass"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("wallPass") == _images.end() || !_images["wallPass"])
		throw LoadingException("could not add image : wallPass");
	_images["wallPass"]->setImage(_textures["wallPass"]);
	_images["wallPass"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 600));

	_buttons["wallPassFalse"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_WALLPASS, L"");
	if (_buttons.find("wallPassFalse") == _buttons.end() || !_buttons["wallPassFalse"])
		throw LoadingException("could not add button : wallPassFalse");
	_buttons["wallPassFalse"]->setImage(_textures["false"]);
	_buttons["wallPassFalse"]->setRelativePosition(irr::core::position2d<irr::s32>(1650, 600));
	_buttons["wallPassTrue"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_WALLPASS, L"");
	if (_buttons.find("wallPassTrue") == _buttons.end() || !_buttons["wallPassTrue"])
		throw LoadingException("could not add button : wallPassTrue");
	_buttons["wallPassTrue"]->setImage(_textures["true"]);
	_buttons["wallPassTrue"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 600));

	//bombPass
	_images["bombPass"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 215, 47));
	if (_images.find("bombPass") == _images.end() || !_images["bombPass"])
		throw LoadingException("could not add image : bombPass");
	_images["bombPass"]->setImage(_textures["bombPass"]);
	_images["bombPass"]->setRelativePosition(irr::core::position2d<irr::s32>(1200, 700));

	_buttons["bombPassFalse"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_BOMBPASS, L"");
	if (_buttons.find("bombPassFalse") == _buttons.end() || !_buttons["bombPassFalse"])
		throw LoadingException("could not add button : bombPassFalse");
	_buttons["bombPassFalse"]->setImage(_textures["false"]);
	_buttons["bombPassFalse"]->setRelativePosition(irr::core::position2d<irr::s32>(1650, 700));
	_buttons["bombPassTrue"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_GAMESETTINGS_BOMBPASS, L"");
	if (_buttons.find("bombPassTrue") == _buttons.end() || !_buttons["bombPassTrue"])
		throw LoadingException("could not add button : bombPassTrue");
	_buttons["bombPassTrue"]->setImage(_textures["true"]);
	_buttons["bombPassTrue"]->setRelativePosition(irr::core::position2d<irr::s32>(1450, 700));
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
}

bool GameSettings::isWallPass() const
{
	return _wallPass;
}

void GameSettings::setWallPass(bool wallPass)
{
	_wallPass = wallPass;
}

bool GameSettings::isBombPass() const
{
	return _bombPass;
}

void GameSettings::setBombPass(bool bombPass)
{
	_bombPass = bombPass;
}
