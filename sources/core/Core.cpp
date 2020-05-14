/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#include <iostream>
#include "Core.hpp"
#include "Character.hpp"

Core::Core()
{
	_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080));
	if (!_window) {
		std::cerr << "Couldn't open a window" << std::endl;
		return;
	}
	_window->setWindowCaption(L"Super Bomberman Bros");
	_env = _window->getGUIEnvironment();
	_driver = _window->getVideoDriver();
	_smgr = _window->getSceneManager();
	//_state = mainOptions;
	_lState = menuMain;
	_gState = menu;
	_loadmap = nullptr;
	_menu = nullptr;
	_options = nullptr;
	_splash = nullptr;
}

void Core::setState(Core::gameState_e state)
{
	_state = state;
}

void Core::menuCase()
{
	if (!_menu)
		_menu = new Menu(_env, _driver, _smgr);
	if (_options)
		for (auto &it : _options->getButtons())
			it.second->setVisible(false);
	for (auto &it : _menu->getButtons())
		it.second->setVisible(true);
}

void Core::selectCase()
{
}

void Core::pauseCase()
{
}

void Core::optionsCase()
{
	if (!_options)
		_options = new Options(_env, _driver, _smgr);
	// for (auto &it : _menu->getButtons())
	//     it.second->setVisible(false);
	for (auto &it : _options->getButtons())
		it.second->setVisible(true);
}

void Core::creditsCase()
{
}

void Core::splashCase()
{
	if (!_splash)
		_splash = new Splash(_env, _driver, _smgr);
	hideLayers();
	showLayer(_splash);
}

void Core::switchScenes()
{
	if (!_loadmap)
		_loadmap = new LoadMap(_env, _driver, _smgr);
	_loadmap->run();

	switch (_state) {
	case mainMenu:
		menuCase();
		break;
	case mainSelect:
		selectCase();
		break;
	case mainPause:
		pauseCase();
		break;
	case mainOptions:
		optionsCase();
		break;
	case mainCredits:
		creditsCase();
		break;
	default:
		break;
	}
}

int Core::run()
{
	// Character *character = new Character(scenemgr, {"resources/models/characters/DryBones/dry_bones.MD3",
	//                                             {0, 0}, {0, 0}, {0, 0}, 100}, "drybones");
	//irr::scene::ISceneNode *node = scenemgr->addAnimatedMeshSceneNode(scenemgr->getMesh("resources/models/characters/DryBones/dry_bones.MD3"));
	// if (node) {
	// 	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// }

	if (!_loadmap)
		_loadmap = new LoadMap(_env, _driver, _smgr);
	_loadmap->run();

	while (_window->run() && _driver) {
		_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		drawScene();
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
	case menu: {
		drawLayer();
	}
	case game: {
		break;
	}
	}
}

void Core::drawLayer()
{
	switch (_lState) {
	case menuMain: {
		menuCase();
		break;
	}
	case menuOptions: {
		optionsCase();
		break;
	}
	case menuPause: {
		pauseCase();
		break;
	}
	case menuCredits: {
		creditsCase();
		break;
	}
	case menuSelect: {
		selectCase();
		break;
	}
	case menuSplash: {
		splashCase();
		break;
	}
	}
}

void Core::hideLayers()
{
	if (_menu)
		for (auto &it : _menu->getButtons())
			it.second->setVisible(false);
	if (_options)
		for (auto &it : _options->getButtons())
			it.second->setVisible(false);
	if (_splash)
		for (auto &it : _splash->getButtons())
			it.second->setVisible(false);
}

template<typename T>
void Core::showLayer(T *layer)
{
	for (auto &it : layer->getButtons())
		it.second->setVisible(true);
}
