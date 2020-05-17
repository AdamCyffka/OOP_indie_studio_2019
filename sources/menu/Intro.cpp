/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Intro
*/

#include "Enum.hpp"
#include "CircleCameraTraveling.hpp"
#include "Intro.hpp"

Intro::Intro(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();

    irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNodeMaya();
    // CircleCameraTraveling traveling = CircleCameraTraveling(camera, _smgr, {0, 100, 0}, 500.0, 0.00025);
	// traveling.start();
    camera->setFarValue(42000);
}

void Intro::loadTextures()
{
    _textures["press"] = _driver->getTexture("resources/images/buttons/press.png");
}

void Intro::loadButtons()
{
    _buttons["press"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_INTRO_BUTTON, L"");
    _buttons["press"]->setImage(_textures["press"]);
    _buttons["press"]->setRelativePosition(irr::core::position2d<irr::s32>(790, 800));
}

void Intro::run()
{}

std::map<std::string, irr::gui::IGUIButton *> Intro::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Intro::getImages()
{
    return _images;
}