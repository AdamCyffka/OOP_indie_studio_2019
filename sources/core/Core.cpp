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
	_window = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1920, 1080), 32, true);
	if (!_window) {
        std::cerr << "Couldn't open a window" << std::endl;
        return;
    }
	_window->setWindowCaption(L"Super Bomberman Bros");
    _state = mainMenu;
    _menu = nullptr;
}

void Core::menuCase()
{
    if (!_menu)
        _menu = new Menu(_window);
    _menu->run(_window);
}

int Core::run()
{
	irr::video::IVideoDriver *driver = _window->getVideoDriver();
	irr::scene::ISceneManager *scenemgr = _window->getSceneManager();
    irr::gui::IGUIEnvironment *env = _window->getGUIEnvironment();

    // Character *character = new Character(scenemgr, {"resources/models/characters/DryBones/dry_bones.MD3",
    //                                             {0, 0}, {0, 0}, {0, 0}, 100}, "drybones");
    //irr::scene::ISceneNode *node = scenemgr->addAnimatedMeshSceneNode(scenemgr->getMesh("resources/models/characters/DryBones/dry_bones.MD3"));
    // if (node) {
	// 	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	// }

	scenemgr->addCameraSceneNodeFPS();

	while (_window->run() && driver) {
		driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255));

		switch (_state) {
			case mainMenu:
                menuCase();
                break;
			case mainSelect:
                //selectCase();
                break;
            case mainGame:
                //gameCase();
                break;
            case mainPause:
                //pauseCase();
                break;
            case mainOptions:
                //optionsCase();
                break;
			default:
                break;
		}

	    scenemgr->drawAll();
        env->drawAll();
	    driver->endScene();
    }
    _window->drop();
    return 0;
}