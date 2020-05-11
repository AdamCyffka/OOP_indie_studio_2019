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
    _music = std::unique_ptr<Music>(new Music());
	_window->setWindowCaption(L"Super Bomberman Bros");
    _env = _window->getGUIEnvironment();
    _driver = _window->getVideoDriver();
    _smgr = _window->getSceneManager();
    //_state = mainMenu;
    _loadmap = nullptr;
    _menu = nullptr;
}

void Core::menuCase()
{
    if (!_menu)
        _menu = new Menu(_env, _driver, _smgr);
}

void Core::selectCase()
{
}

void Core::pauseCase()
{
}

void Core::optionsCase()
{
}

void Core::creditsCase()
{
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

    switchScenes();
    _music->playSound("resources/music/first.mp3");

	while (_window->run() && _driver) {
		_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

	    _smgr->drawAll();
        _env->drawAll();
    
	    _driver->endScene();
    }
    _window->drop();
    return 0;
}