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
#include "Credits.hpp"
#include "Help.hpp"
#include "Pause.hpp"
#include "Intro.hpp"
#include "Save.hpp"
#include "Load.hpp"
#include "loadCore.hpp"

Core::Core()
{
	_window = irr::createDevice(irr::video::EDT_OPENGL,
        irr::core::dimension2d<irr::u32>(1920, 1080),
        16, true, false);
	if (!_window) {
		std::cerr << "Couldn't open a window" << std::endl;
		return;
	}
	_window->setWindowCaption(L"Super Bomberman Bros");
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
	_sounds = nullptr;
	_gameSettings = nullptr;
	_controls = nullptr;
	_save = nullptr;
	_load = nullptr;
    _select = nullptr;
	_score = nullptr;
    _music = nullptr;
    _inputs = nullptr;
    _gameCore = nullptr;
	_pause = nullptr;
	_game = nullptr;
	_gameSounds = nullptr;
	_gameControls = nullptr;

	setGlobalVariables(_driver, _smgr);
}

void Core::setGameSettings(GameSettings *gameSettings)
{
	_gameSettings = gameSettings;
}

GameSettings *Core::getGameSettings() const
{
	return _gameSettings;
}

Save *Core::getSave() const
{
	return _save;
}

void Core::setSave(Save *save)
{
	_save = save;
}

Load *Core::getLoad() const
{
	return _load;
}

void Core::setLoad(Load *load)
{
	_load = load;
}

Help *Core::getHelp() const
{
	return _help;
}

void Core::setHelp(Help *help)
{
	_help = help;
}

void Core::setMenu(Menu *menu)
{
	_menu = menu;
}

Menu *Core::getMenu() const
{
	return _menu;
}

Sounds *Core::getSounds() const
{
	return _sounds;
}

void Core::setSounds(Sounds *sounds)
{
	_sounds = sounds;
}

void Core::setSelect(Select *select)
{
	_select = select;
}

Select *Core::getSelect() const
{
	return _select;
}

void Core::setControls(Controls *controls)
{
	_controls = controls;
}

Controls *Core::getControls() const
{
	return _controls;
}

Credits *Core::getCredits() const
{
	return _credits;
}

void Core::setCredits(Credits *credits)
{
	_credits = credits;
}

void Core::setScore(Score *score)
{
	_score = score;
}

Score *Core::getScore() const
{
	return _score;
}

void Core::setGameCore(GameCore *gamecore)
{
	_gameCore = gamecore;
}

GameCore *Core::getGameCore() const
{
	return _gameCore;
}

void Core::setGame(Game *game)
{
	_game = game;
}

Game *Core::getGame() const
{
	return _game;
}

Map *Core::getMap() const
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

void Core::setMusicEngine(Music *music)
{
	_music = music;
}

Music *Core::getMusicEngine() const
{
	return _music;
}

Splash *Core::getSplash() const
{
	return _splash;
}

void Core::setIntro(Intro *intro)
{
	_intro = intro;
}

Intro *Core::getIntro()
{
	return _intro;
}

void Core::setInput(Input *input)
{
	_inputs = input;
}

Input *Core::getInput()
{
	return _inputs;
}

Pause *Core::getPause() const
{
	return _pause;
}

void Core::setPause(Pause *pause)
{
	_pause = pause;
}

void Core::setLoadMap(LoadMap *loadMap)
{
	_loadmap = loadMap;
}

LoadMap *Core::getLoadMap() const
{
	return _loadmap;
}

GameControls *Core::getGameControls() const
{
	return _gameControls;
}

void Core::setGameControls(GameControls *gameControls)
{
	_gameControls = gameControls;
}

GameSounds *Core::getGameSounds() const
{
	return _gameSounds;
}

void Core::setGameSounds(GameSounds *gameSounds)
{
	_gameSounds = gameSounds;
}

CameraTravelManager *Core::getCameraTravelManager()
{
	return _cameraTravelManager;
}

irr::gui::IGUIEnvironment *Core::getEnv()
{
	return _env;
}

irr::scene::ISceneManager *Core::getSmgr()
{
	return _smgr;
}

irr::video::IVideoDriver *Core::getDriver()
{
	return _driver;
}

irr::IrrlichtDevice *Core::getWindow()
{
	return _window;
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

void Core::soundsCase()
{
	hideMenuLayers();
	showMenuLayer(_sounds);
}

void Core::gameSettingsCase()
{
	hideMenuLayers();
	showMenuLayer(_gameSettings);
}

void Core::controlsCase()
{
	_controls->run();
	hideMenuLayers();
	showMenuLayer(_controls);
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

void Core::gameControlsCase()
{
	hideGameLayers();
	showGameLayer(_gameControls);
}

void Core::gameSoundsCase()
{
	hideGameLayers();
	showGameLayer(_gameSounds);
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
	if (!_gameCore->isInit()) {
		_gameCore->init(_select->getPreviews(), _select->getEntityTypes(), _controls->getEntityType());
	}
	_gameCore->run();
	_game->run(_gameCore->isWaiting(), _gameCore->getEntities());
	hideGameLayers();
	showGameLayer(_game);
}

void Core::pauseCase()
{
	hideGameLayers();
	_pause->run();
	showGameLayer(_pause);
}

void(*f[20])(Core *) = {loadSplashBar, loadMusic, loadMap, loadIntro, loadMenu, loadSounds, loadGameSettings, loadControls, loadSelect, loadScore, loadHelp, loadCredits, loadSave, loadLoad, loadInput, loadGameCore, loadPause, loadGameClass, loadGameSounds, loadGameControls};

void Core::init()
{
	if (_initStep < 20)
		f[_initStep](this);
	else
	{
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
		drawScene();

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
		case gameSounds:
			gameSoundsCase();
			break;
		case gameControls:
			gameControlsCase();
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
		case menuSounds:
			soundsCase();
			break;
		case menuControls:
			controlsCase();
			break;
		case menuGameSettings:
			gameSettingsCase();
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
		std::cout << "j'ai _game" << std::endl;
		for (auto &it : _game->getButtons())
			it.second->setVisible(false);
		for (auto &it : _game->getImages())
			it.second->setVisible(false);
		if (_lGState == layerGameState::gamePause) {
			for (auto &it : _game->getTempImages()) {
				it.second->setVisible(false);
			}
		}
	}
	if (_save)
		for (auto &it : _save->getButtons())
			it.second->setVisible(false);
	if (_gameControls) {
		for (auto &it : _gameControls->getButtons())
			it.second->setVisible(false);
		for (auto &it : _gameControls->getImages())
			it.second->setVisible(false);
		for (auto &it : _gameControls->getCheckBox())
			it.second->setVisible(false);
	}
	if (_gameSounds) {
		for (auto &it : _gameSounds->getButtons())
			it.second->setVisible(false);
		for (auto &it : _gameSounds->getImages())
			it.second->setVisible(false);
		for (auto &it : _gameSounds->getCheckBox())
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
	if (_sounds)
	{
		for (auto &it : _sounds->getButtons())
			it.second->setVisible(false);
		for (auto &it : _sounds->getImages())
			it.second->setVisible(false);
	}
	if (_gameSettings)
	{
		for (auto &it : _gameSettings->getButtons())
			it.second->setVisible(false);
		for (auto &it : _gameSettings->getImages())
			it.second->setVisible(false);
		for (auto &it : _gameSettings->getCheckBox())
			it.second->setVisible(false);
	}
	if (_controls)
	{
		for (auto &it : _controls->getButtons())
			it.second->setVisible(false);
		for (auto &it : _controls->getImages())
			it.second->setVisible(false);
		for (auto &it : _controls->getCheckBox())
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
	if (_score)
	{
		for (auto &it : _score->getButtons())
			it.second->setVisible(false);
		for (auto &it : _score->getImages())
			it.second->setVisible(false);
		if (_gState != game)
			for (auto &it : _score->getPreviews())
				it->setVisibility(false);
	}
	if (_credits)
	{
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