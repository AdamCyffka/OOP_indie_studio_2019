/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"
#include "Character.hpp"
#include "Select.hpp"
#include "MyEventReceiver.hpp"
#include "Credits.hpp"
#include "Help.hpp"
#include "Pause.hpp"

Core::Core()
{
	_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
	if (!_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
	//_window->setWindowCaption(L"Super Bomberman Bros");
	_receiver = new MyEventReceiver(_window, *this);
	_window->setEventReceiver(_receiver);
    _env = _window->getGUIEnvironment();
    _driver = _window->getVideoDriver();
    _smgr = _window->getSceneManager();
    _lState = menuMain;
    _gState = menu;
	_select = nullptr;
    _loadmap = nullptr;
	_credits = nullptr;
	_pause = nullptr;
	_help = nullptr;
    _menu = nullptr;
    _options = nullptr;
    _select = nullptr;
}

Select *Core::getSelect()
{
    return _select;
}

Core::layerState Core::getState()
{
    return _lState;
}

void Core::setState(Core::layerState state)
{
    _lState = state;
}

void Core::menuCase()
{
    if (!_menu)
        _menu = new Menu(_env, _driver, _smgr);
	if (_select)
        for (auto &it : _select->getButtons())
            it.second->setVisible(false);
    if (_options) {
        for (auto &it : _options->getButtons())
            it.second->setVisible(false);
		for (auto &it : _options->getImages())
            it.second->setVisible(false);
	}
	if (_credits) {
        for (auto &it : _credits->getButtons())
            it.second->setVisible(false);
		for (auto &it : _credits->getImages())
            it.second->setVisible(false);
	}
	if (_help) {
        for (auto &it : _help->getButtons())
            it.second->setVisible(false);
		for (auto &it : _help->getImages())
            it.second->setVisible(false);
	}
    for (auto &it : _menu->getButtons())
        it.second->setVisible(true);
}

void Core::selectCase()
{
    if (!_select)
        _select = new Select(_env, _driver, _smgr);
	for (auto &it : _menu->getButtons())
        it.second->setVisible(false);
    for (auto &it : _select->getButtons())
        it.second->setVisible(true);
}

void Core::pauseCase()
{
	if (!_pause)
        _pause = new Pause(_env, _driver, _smgr);
}

void Core::optionsCase()
{
    if (!_options)
        _options = new Options(_env, _driver, _smgr);
    for (auto &it : _menu->getButtons())
        it.second->setVisible(false);
    for (auto &it : _options->getButtons())
        it.second->setVisible(true);
	for (auto &it : _options->getImages())
            it.second->setVisible(true);
}

void Core::creditsCase()
{
	if (!_credits)
        _credits = new Credits(_env, _driver, _smgr);
	for (auto &it : _menu->getButtons())
        it.second->setVisible(false);
	for (auto &it : _credits->getButtons())
        it.second->setVisible(true);
	for (auto &it : _credits->getImages())
            it.second->setVisible(true);
}

void Core::helpCase()
{
	if (!_help)
        _help = new Help(_env, _driver, _smgr);
	for (auto &it : _menu->getButtons())
        it.second->setVisible(false);
	for (auto &it : _help->getButtons())
        it.second->setVisible(true);
	for (auto &it : _help->getImages())
            it.second->setVisible(true);
}

int Core::run()
{
	if (!_loadmap)
		_loadmap = new LoadMap(_env, _driver, _smgr);
	_loadmap->run();

	// POSITION CAMERA PAS TOUCHER
	irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNodeMaya(); // addCameraSceneNodeMaya
	camera->setFarValue(42000);
	camera->setPosition(irr::core::vector3df(-94.354813, 44.179367, 294.335876));
	camera->setTarget(irr::core::vector3df(-70.055885, 21.188717, 232.846115));
	irr::core::vector3df posCam = camera->getPosition();
	irr::core::vector3df targetCam = camera->getTarget();
	core::stringw titre = L"POS : X = ";
	titre += posCam.X;
	titre += " Y = ";
	titre += posCam.Y;
	titre += " Z = ";
	titre += posCam.Z;
	titre += " TARGET: X = ";
	titre += targetCam.X;
	titre += " Y = ";
	titre += targetCam.Y;
	titre += " Z = ";
	titre += targetCam.Z;
	_window->setWindowCaption(titre.c_str());

	while (_window->run() && _driver) {
		_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		drawScene();
		irr::core::vector3df posCam = camera->getPosition();
		irr::core::vector3df targetCam = camera->getTarget();
		titre = L"POS : X = ";
		titre += posCam.X;
		titre += " Y = ";
		titre += posCam.Y;
		titre += " Z = ";
		titre += posCam.Z;

		titre += "\nTARGET: X = ";
		titre += targetCam.X;
		titre += " Y = ";
		titre += targetCam.Y;
		titre += " Z = ";
		titre += targetCam.Z;
		_window->setWindowCaption(titre.c_str());
	    _smgr->drawAll();
        _env->drawAll();
	    _driver->endScene();
    }

    _window->drop();
    return 0;
}

void Core::drawScene()
{
	switch (_gState) {
		case menu:
			drawLayer();
		case game:
			break;
	}
}

void Core::drawLayer()
{
	switch (_lState) {
		case menuMain:
			menuCase();
			break;
		case menuOptions:
			optionsCase();
			break;
		case menuPause:
			pauseCase();
			break;
		case menuCredits:
			creditsCase();
			break;
		case menuHelp:
			helpCase();
			break;
		case menuSelect:
			selectCase();
			break;
	}
}
