/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include <iostream>
#include <chrono>
#include <thread>
#include "ProgressBar.hpp"
#include "MyEventReceiver.hpp"
#include "Core.hpp"
#include "Character.hpp"
#include "Select.hpp"
#include "Credits.hpp"
#include "Help.hpp"
#include "Pause.hpp"
#include "Intro.hpp"

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
	_isInitialized = false;
	_initStep = 0;
	_intro = nullptr;
    _loadmap = nullptr;
	_credits = nullptr;
	_pause = nullptr;
	_help = nullptr;
	_splash = nullptr;
    _menu = nullptr;
    _options = nullptr;
    _select = nullptr;
    _music = nullptr;
}

Select *Core::getSelect()
{
	return _select;
}

Core::layerState Core::getState()
{
	return _lState;
}

Music *Core::getMusicEngine()
{
	return _music;
}

void Core::setState(Core::layerState state)
{
	_lState = state;
}

void Core::introCase()
{
	hideLayers();
	showLayer(_intro);
}

void Core::menuCase()
{
	hideLayers();
	showLayer(_menu);
}

void Core::selectCase()
{
	_select->run();
	hideLayers();
	showLayer(_select);
}

void Core::pauseCase()
{
	hideLayers();
	showLayer(_pause);
}

void Core::optionsCase()
{
	hideLayers();
	showLayer(_options);
}

void Core::creditsCase()
{
	hideLayers();
	showLayer(_credits);
}

void Core::helpCase()
{
	hideLayers();
	showLayer(_help);
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
		_splash->setBar(new ProgressBar(_env, _driver, irr::core::rect<irr::s32>(300, 800, 1620, 830)));
		_splash->getBar()->setPosition(irr::core::rect<irr::s32>(30, 700, 600, 600));
		_splash->getBar()->addBorder(2);

		_splash->getBar()->setProgress(11);
	} else if (_initStep == 1) {
		if (!_loadmap)
			_loadmap = new LoadMap(_env, _driver, _smgr);
		_splash->getBar()->setProgress(22);
	} else if (_initStep == 2) {
		if (!_intro)
			_intro = new Intro(_env, _driver, _smgr);
		_splash->getBar()->setProgress(33);
	} else if (_initStep == 3) {
		if (!_menu)
			_menu = new Menu(_env, _driver, _smgr);
		_splash->getBar()->setProgress(44);
	} else if (_initStep == 4) {
		if (!_options)
			_options = new Options(_env, _driver, _smgr);
		_splash->getBar()->setProgress(55);
	} else if (_initStep == 5) {
		if (!_select)
			_select = new Select(_env, _driver, _smgr);
		_splash->getBar()->setProgress(66);
	} else if (_initStep == 6) {
		if (!_help)
			_help = new Help(_env, _driver, _smgr);
		_splash->getBar()->setProgress(77);
	} else if (_initStep == 7) {
		if (!_credits)
			_credits = new Credits(_env, _driver, _smgr);
		_splash->getBar()->setProgress(88);
	} else if (_initStep == 8) {
		if (!_music)
			_music = new Music();
		_splash->getBar()->setProgress(95);
	// } else if (_initStep == 9) {
	// 	if (!_pause)
	// 		_pause = new Pause();
	// 	_splash->getBar()->setProgress(100);
	} else {
		_isInitialized = true;
		if (_loadmap)
			_loadmap->run();
		_splash->getBar()->setVisible(false);
		_lState = menuIntro;
	}
	_initStep++;
	hideLayers();
}

int Core::run()
{
	irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNodeMaya(); // addCameraSceneNodeMaya
	camera->setFarValue(42000);

	irr::gui::IGUISkin* skin = _env->getSkin();
    irr::gui::IGUIFont* font = _env->getFont("resources/fonts/font.bmp");
    if (font)
        skin->setFont(font);
    skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_MENU);

	core::stringw str = L"Irrlicht Engine [";
	str += _driver->getName();
	str += L"] FPS: ";
	str += (s32)_driver->getFPS();
	_window->setWindowCaption(str.c_str());
	irr::gui::IGUIStaticText *fpsText = _env->addStaticText(str.c_str(), irr::core::rect<s32>(0, 0, 600, 28));

	while (_window->run() && _driver) {
		_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		drawScene();

		str = L"Irrlicht Engine [";
		str += _driver->getName();
		str += L"] FPS: ";
		str += (s32)_driver->getFPS();
		_window->setWindowCaption(str.c_str());
		fpsText->setText(str.c_str());

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
		case menuSplash:
			splashCase();
			break;
		case menuIntro:
			introCase();
			break;
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

void Core::hideLayers()
{
	if (_menu) {
		for (auto &it : _menu->getButtons())
			it.second->setVisible(false);
		for (auto &it : _menu->getImages())
			it.second->setVisible(false);
	}
	if (_intro) {
		for (auto &it : _intro->getButtons())
			it.second->setVisible(false);
		for (auto &it : _intro->getImages())
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
		for (auto &it : _select->getPreviews())
			it->setVisibility(false);
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
	if (_pause) {
		for (auto &it : _pause->getButtons())
			it.second->setVisible(false);
		for (auto &it : _pause->getImages())
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

