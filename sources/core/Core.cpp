/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <typeinfo>
#include "Core.hpp"
#include "CoreException.hpp"
#include "ProgressBar.hpp"
#include "MyEventReceiver.hpp"
#include "Character.hpp"
#include "Select.hpp"
#include "Score.hpp"
#include "Credits.hpp"
#include "Help.hpp"
#include "Pause.hpp"
#include "Intro.hpp"
#include "Save.hpp"
#include "Load.hpp"
#include "Game.hpp"
#include "GameOptions.hpp"

Core::Core() : _fullscreen(FULLSCREEN)
{
	_window = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(1920, 1080),
        16, getFullscreen(), false);
	if (!_window) {
		std::cerr << "Couldn't open a window" << std::endl;
		return;
	}
	//_window->setWindowCaption(L"Super Bomberman Bros");
	_smgr = _window->getSceneManager();
	_camera = _smgr->addCameraSceneNode();
	_camera->setFarValue(42000);
	_cameraTravelManager = new CameraTravelManager(_camera, _smgr);
	_receiver = new MyEventReceiver(_window, *this, _cameraTravelManager);
	_window->setEventReceiver(_receiver);
	_env = _window->getGUIEnvironment();
	_driver = _window->getVideoDriver();
	_lState = menuSplash;
	_gState = menu;
	_lGState = gameGame;
	_isInitialized = false;
	_initStep = 0;
	_intro = nullptr;
	_loadmap = nullptr;
	_credits = nullptr;
	_help = nullptr;
	_splash = nullptr;
	_menu = nullptr;
	_options = nullptr;
	_save = nullptr;
	_load = nullptr;
    _select = nullptr;
	_score = nullptr;
    _music = nullptr;
    _inputs = nullptr;
    _gameCore = nullptr;
	_pause = nullptr;
	_game = nullptr;
	_gameOptions = nullptr;

	// irr::core::dimension2d<u32> dim(1920, 1080);
  	// _env->addCheckBox(getFullscreen(), irr::core::rect<s32>(dim.Width - 600, 20, dim.Width - 300, 80), nullptr, -1, L"Fullscreen");
}

void Core::start()
{
    restartDevice(_fullscreen);
}

void Core::restartDevice(bool fullscreen)
{
	if (_window) {
		_window->closeDevice();
		_window->run();
		_window->drop();
	}
    _window = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(1920, 1080),
        16, fullscreen, false);
	if (!_window)
		throw CoreException("Error : Window could not be loaded");
	_smgr = _window->getSceneManager();
	if (!_smgr)
		throw CoreException("Error : Scene manager could not be loaded");
	_env = _window->getGUIEnvironment();
	if (!_env)
		throw CoreException("Error : GUI environment could not be loaded");
	_driver = _window->getVideoDriver();
	if (!_driver)
		throw CoreException("Error : Driver could not be loaded");
	_camera = _smgr->addCameraSceneNodeMaya();
	if (!_camera)
		throw CoreException("Error : Camera could not be loaded");
	_camera->setFarValue(42000);
	_cameraTravelManager = new CameraTravelManager(_camera, _smgr);
	_receiver = new MyEventReceiver(_window, *this, _cameraTravelManager);
	_window->setEventReceiver(_receiver);
	_lState = menuSplash;
	_gState = menu;
	_lGState = gameGame;
	_isInitialized = false;
	_initStep = 0;
	_intro = nullptr;
	_loadmap = nullptr;
	_credits = nullptr;
	_help = nullptr;
	_splash = nullptr;
	_menu = nullptr;
	_options = nullptr;
	_save = nullptr;
	_load = nullptr;
    _select = nullptr;
	_score = nullptr;
    _music = nullptr;
    _inputs = nullptr;
    _gameCore = nullptr;
	_pause = nullptr;
	_game = nullptr;
	_gameOptions = nullptr;
}

void Core::changeFullscreen()
{
    _fullscreen = !_fullscreen;
}

bool Core::getFullscreen() const
{
    return _fullscreen;
}

Select *Core::getSelect()
{
	return _select;
}

Score *Core::getScore()
{
	return _score;
}

GameCore *Core::getGame()
{
	return _gameCore;
}

Map *Core::getMap()
{
	return _loadmap->getMap();
}

Core::layerMenuState Core::getLState()
{
	return _lState;
}

Core::layerGameState Core::getLGState()
{
	return _lGState;
}

Core::gameState Core::getGState()
{
	return _gState;
}

Music *Core::getMusicEngine()
{
	return _music;
}

Intro *Core::getIntro()
{
	return _intro;
}

Input *Core::getInput()
{
	return _inputs;
}

LoadMap *Core::getLoadMap()
{
	return _loadmap;
}

CameraTravelManager *Core::getCameraTravelManager()
{
	return _cameraTravelManager;
}

void Core::setLState(Core::layerMenuState state)
{
	_lState = state;
}

void Core::setLGState(Core::layerGameState state)
{
	_lGState = state;
}

void Core::setGState(Core::gameState state)
{
	_gState = state;
}

void Core::introCase()
{
	if (_receiver->IsKeyDown(irr::KEY_RSHIFT)) {
		getMusicEngine()->stop("resources/music/intro.mp3", false);
		getMusicEngine()->add2D("resources/music/menu.mp3", false, false, true, irrklang::ESM_AUTO_DETECT);
		_cameraTravelManager->doTravel(CameraTravelManager::travel::introToMenu);
		setLState(Core::menuMain);
	}
	hideMenuLayers();
	showMenuLayer(_intro);
}

void Core::menuCase()
{
	hideMenuLayers();
	showMenuLayer(_menu);
}

void Core::selectCase()
{
	_select->run();
	hideMenuLayers();
	showMenuLayer(_select);
}

void Core::scoreCase()
{
	hideMenuLayers();
	showMenuLayer(_score);
}

void Core::optionsCase()
{
	hideMenuLayers();
	showMenuLayer(_options);
}

void Core::creditsCase()
{
	hideMenuLayers();
	showMenuLayer(_credits);
}

void Core::helpCase()
{
	hideMenuLayers();
	showMenuLayer(_help);
}

void Core::saveCase()
{
	hideGameLayers();
	showGameLayer(_save);
}

void Core::loadCase()
{
	hideMenuLayers();
	showMenuLayer(_load);
}

void Core::gameOptionsCase()
{
	hideGameLayers();
	showGameLayer(_gameOptions);
}

void Core::splashCase()
{
	if (!_splash)
		_splash = new Splash(_env, _driver, _smgr);
	if (!_isInitialized) {
		init();
	}
	showMenuLayer(_splash);
}

void Core::gameCase()
{
	if (!_gameCore->isInit())
		_gameCore->init(_select->getPreviews(), _inputs->getPlayerInput(), _select->getEntityTypes());
	_game->run();
	_gameCore->run();
	hideGameLayers();
	showGameLayer(_game);
}

void Core::pauseCase()
{
	hideGameLayers();
	showGameLayer(_pause);
}

void Core::init()
{
	if (_initStep == 0)
	{
		_splash->setBar(new ProgressBar(_env, _driver, irr::core::rect<irr::s32>(300, 800, 1620, 830)));
		_splash->getBar()->setPosition(irr::core::rect<irr::s32>(30, 700, 600, 600));
		_splash->getBar()->addBorder(2);
		_splash->getBar()->setProgress(5);
	}
	else if (_initStep == 1)
	{
		if (!_music)
			_music = new Music();
//		_music->getEngine()->setSoundVolume(0.0f); __MUSIC__
		_splash->getBar()->setProgress(7);
	}
	else if (_initStep == 2)
	{
		if (!_loadmap)
			_loadmap = new LoadMap(_env, _driver, _smgr);
		_splash->getBar()->setProgress(10);
	}
	else if (_initStep == 3)
	{
		if (!_intro)
			_intro = new Intro(_env, _driver, _smgr);
		_splash->getBar()->setProgress(20);
	}
	else if (_initStep == 4)
	{
		if (!_menu)
			_menu = new Menu(_env, _driver, _smgr);
		_splash->getBar()->setProgress(30);
	}
	else if (_initStep == 5)
	{
		if (!_options)
			_options = new Options(_env, _driver, _smgr);
		_splash->getBar()->setProgress(40);
	}
	else if (_initStep == 6)
	{
		if (!_select)
			_select = new Select(_env, _driver, _smgr);
		_splash->getBar()->setProgress(50);
	} else if (_initStep == 7) {
		if (!_score && _select)
			_score = new Score(_env, _driver, _smgr, _select->getPreviews());
		_splash->getBar()->setProgress(50);
	} else if (_initStep == 8) {
		if (!_help)
			_help = new Help(_env, _driver, _smgr);
		_splash->getBar()->setProgress(60);
	} else if (_initStep == 9) {
		if (!_credits)
			_credits = new Credits(_env, _driver, _smgr);
		_splash->getBar()->setProgress(70);
	} else if (_initStep == 10) {
		if (!_save)
			_save = new Save(_env, _driver, _smgr);
		_splash->getBar()->setProgress(80);
	} else if (_initStep == 11) {
		if (!_inputs)
			_inputs = new Input();
		_splash->getBar()->setProgress(90);
	} else if (_initStep == 12) {
		if (!_load)
			_load = new Load(_env, _driver, _smgr);
		_splash->getBar()->setProgress(95);
	} else if (_initStep == 13) {
		if (!_select)
			throw CoreException("Select hasn't been initialized, cannot get characters previews");
		if (!_gameCore)
			_gameCore = new GameCore(this);
		_splash->getBar()->setProgress(97);
	} else if (_initStep == 14) {
		if (!_pause)
			_pause = new Pause(_env, _driver, _smgr);
		_splash->getBar()->setProgress(100);
	} else if (_initStep == 15) {
		if (!_game && _select)
			_game = new Game(_env, _driver, _smgr, _select->getPreviews());
		_splash->getBar()->setProgress(100);
	} else if (_initStep == 16) {
		if (!_gameOptions)
			_gameOptions = new GameOptions(_env, _driver, _smgr);
		_splash->getBar()->setProgress(100);
	} else {
		_isInitialized = true;
		if (_loadmap)
			_loadmap->run();
		_splash->getBar()->setVisible(false);
		_lState = menuIntro;
		_cameraTravelManager->doTravel(CameraTravelManager::travel::intro);
		_music->add2D("resources/music/intro.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
	}
	_initStep++;
	hideMenuLayers();
	hideGameLayers();
}

int Core::run()
{
	irr::gui::IGUISkin *skin = _env->getSkin();
	irr::gui::IGUIFont *font = _env->getFont("resources/fonts/font.bmp");
	if (font)
		skin->setFont(font);
	skin->setFont(_env->getBuiltInFont(), irr::gui::EGDF_MENU);

	video::ITexture *images = _driver->getTexture("resources/images/cursor.png");
	_driver->makeColorKeyTexture(images, core::position2d<s32>(0,0));

	while (_window->run() && _driver) {
		_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		drawScene();

		core::vector3df cameraPosition = _camera->getPosition();
		core::vector3df cameraTargetPosition = _camera->getTarget();
		core::stringw cameraPositionStr = L"CAMERA POSITION [";
		cameraPositionStr += cameraPosition.X;
		cameraPositionStr += L" ";
		cameraPositionStr += cameraPosition.Y;
		cameraPositionStr += L" ";
		cameraPositionStr += cameraPosition.Z;
		cameraPositionStr += L"] CAMERA TARGET POSITION [";
		cameraPositionStr += cameraTargetPosition.X;
		cameraPositionStr += L" ";
		cameraPositionStr += cameraTargetPosition.Y;
		cameraPositionStr += L" ";
		cameraPositionStr += cameraTargetPosition.Z;
		cameraPositionStr += L"]";
		_window->setWindowCaption(cameraPositionStr.c_str());

		_smgr->drawAll();
		_env->drawAll();

		//draw cursor
		_window->getCursorControl()->setVisible(false);
		irr::core::position2d<int> mousePosition = _window->getCursorControl()->getPosition();
		_driver->draw2DImage(images, irr::core::position2d<s32>(mousePosition.X, mousePosition.Y), core::rect<s32>(0, 0, 28, 26), 0,
            video::SColor(255, 255, 255, 255), true);

		_driver->endScene();
	}
	_window->drop();
	return 0;
}

void Core::drawScene()
{
	switch (_gState) {
		case menu:
			hideGameLayers();
			drawMenuLayer();
			break;
		case game:
			hideMenuLayers();
			drawGameLayer();
			break;
	}
}

void Core::drawGameLayer()
{
	switch (_lGState) {
		case gamePause:
			pauseCase();
			break;
		case gameGame:
			gameCase();
			break;
		case gameOptions:
			gameOptionsCase();
			break;
		case gameSave:
			saveCase();
			break;
	}
}

void Core::drawMenuLayer()
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
		case menuCredits:
			creditsCase();
			break;
		case menuHelp:
			helpCase();
			break;
		case menuSelect:
			selectCase();
			break;
		case menuScore:
			scoreCase();
			break;
		case menuLoad:
			loadCase();
			break;
	}
}

void Core::hideGameLayers()
{
	if (_pause) {
		for (auto &it : _pause->getButtons())
			it.second->setVisible(false);
		for (auto &it : _pause->getImages())
			it.second->setVisible(false);
	}
	if (_game) {
		for (auto &it : _game->getButtons())
			it.second->setVisible(false);
		for (auto &it : _game->getImages())
			it.second->setVisible(false);
	}
	if (_save)
		for (auto &it : _save->getButtons())
			it.second->setVisible(false);
	if (_gameOptions) {
		for (auto &it : _gameOptions->getButtons())
			it.second->setVisible(false);
		for (auto &it : _gameOptions->getImages())
			it.second->setVisible(false);
		for (auto &it : _gameOptions->getCheckBox())
			it.second->setVisible(false);
	}
}

void Core::hideMenuLayers()
{
	if (_menu)
	{
		for (auto &it : _menu->getButtons())
			it.second->setVisible(false);
		for (auto &it : _menu->getImages())
			it.second->setVisible(false);
	}
	if (_intro)
	{
		for (auto &it : _intro->getButtons())
			it.second->setVisible(false);
		for (auto &it : _intro->getImages())
			it.second->setVisible(false);
	}
	if (_options)
	{
		for (auto &it : _options->getButtons())
			it.second->setVisible(false);
		for (auto &it : _options->getImages())
			it.second->setVisible(false);
		for (auto &it : _options->getCheckBox())
			it.second->setVisible(false);
	}
	if (_splash)
	{
		for (auto &it : _splash->getButtons())
			it.second->setVisible(false);
		for (auto &it : _splash->getImages())
			it.second->setVisible(false);
	}
	if (_select)
	{
		for (auto &it : _select->getButtons())
			it.second->setVisible(false);
		for (auto &it : _select->getImages())
			it.second->setVisible(false);
		if (_gState != game)
			for (auto &it : _select->getPreviews())
				it->setVisibility(false);
	}
	if (_score) {
		for (auto &it : _score->getButtons())
			it.second->setVisible(false);
		for (auto &it : _score->getImages())
			it.second->setVisible(false);
		if (_gState != game)
			for (auto &it : _score->getPreviews())
				it->setVisibility(false);
	}
	if (_credits) {
		for (auto &it : _credits->getButtons())
			it.second->setVisible(false);
		for (auto &it : _credits->getImages())
			it.second->setVisible(false);
	}
	if (_help)
	{
		for (auto &it : _help->getButtons())
			it.second->setVisible(false);
		for (auto &it : _help->getImages())
			it.second->setVisible(false);
	}
	if (_load)
		for (auto &it : _load->getButtons())
			it.second->setVisible(false);
}

template <typename T>
void Core::showMenuLayer(T *layer)
{
	for (auto &it : layer->getButtons())
		it.second->setVisible(true);
	for (auto &it : layer->getImages())
		it.second->setVisible(true);
	for (auto &it : layer->getCheckBox())
		it.second->setVisible(true);
	for (auto &it : layer->getPreviews())
		it->setVisibility(true);
}

template <typename T>
void Core::showGameLayer(T *layer)
{
	for (auto &it : layer->getButtons())
		it.second->setVisible(true);
	for (auto &it : layer->getImages())
		it.second->setVisible(true);
	for (auto &it : layer->getCheckBox())
		it.second->setVisible(true);
}