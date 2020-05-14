/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include <iostream>
#include "menu/ProgressBar.hpp"
#include "Core.hpp"
#include "Character.hpp"
#include "Select.hpp"
#include "MyEventReceiver.hpp"

#include <chrono>
#include <thread>

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
	_lState = menuSplash;
	_gState = menu;
	_select = nullptr;
	_loadmap = nullptr;
	_menu = nullptr;
	_options = nullptr;
	_select = nullptr;
	_isInitialized = false;
	_initStep = 0;
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
	hideLayers();
	showLayer(_menu);
}

void Core::selectCase()
{
	hideLayers();
	showLayer(_select);
}

void Core::pauseCase()
{
}

void Core::optionsCase()
{
	hideLayers();
	showLayer(_options);
}

void Core::creditsCase()
{
}

void Core::splashCase()
{
	if (!_splash)
		_splash = new Splash(_env, _driver, _smgr);
	if (!_isInitialized)
		init();
	showLayer(_splash);
}

void Core::init()
{
	if (_initStep == 0) {
		_splash->setBar(new ProgressBar(_env, _driver, core::rect<irr::s32>(300, 800, 1620, 830)));
		_splash->getBar()->setPosition(core::rect<irr::s32>(30, 700, 600, 600));
		_splash->getBar()->addBorder(2);
		_splash->getBar()->setProgress(20);
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} else if (_initStep == 1) {
		if (!_loadmap)
			_loadmap = new LoadMap(_env, _driver, _smgr);
		_splash->getBar()->setProgress(40);
//		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	} else if (_initStep == 2) {
		if (!_menu)
			_menu = new Menu(_env, _driver, _smgr);
		_splash->getBar()->setProgress(60);
//		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	} else if (_initStep == 3) {
		if (!_options)
			_options = new Options(_env, _driver, _smgr);
		_splash->getBar()->setProgress(80);
//		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	} else if (_initStep == 4) {
		if (!_select)
			_select = new Select(_env, _driver, _smgr);
		_splash->getBar()->setProgress(100);
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	} else {
		_isInitialized = true;
		if (_loadmap) {
			_loadmap->run();
		}
		_splash->getBar()->setVisible(false);
		_lState = menuMain;
	}
	_initStep++;
	hideLayers();
}

int Core::run()
{
	// POSITION CAMERA PAS TOUCHER
	irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNode(); // addCameraSceneNodeMaya
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
		break;
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
	case menuSelect:
		selectCase();
		break;
	case menuSplash:
		splashCase();
		break;
	}
}

void Core::hideLayers()
{
	if (_menu) {
		for (auto &it : _menu->getButtons())
			it.second->setVisible(false);
		for (auto &it : _menu->getImages())
			it.second->setVisible(false);
	}
	if (_options) {
		for (auto &it : _options->getButtons())
			it.second->setVisible(false);
		for (auto &it : _options->getImages())
			it.second->setVisible(false);
	}
	if (_splash) {
		for (auto &it : _splash->getButtons())
			it.second->setVisible(false);
		for (auto &it : _splash->getImages())
			it.second->setVisible(false);
	}
	if (_select) {
		for (auto &it : _select->getButtons())
			it.second->setVisible(false);
		for (auto &it : _select->getImages())
			it.second->setVisible(false);
	}
}

template<typename T>
void Core::showLayer(T *layer)
{
	for (auto &it : layer->getButtons())
		it.second->setVisible(true);
	for (auto &it : layer->getImages())
		it.second->setVisible(true);
}
