/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireDown
*/

#include "FireDown.hpp"

FireDown::FireDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_driver = driver;
	_env = env;
	_smgr = smgr;

    irr::scene::ISceneNode *fire;
	irr::scene::ISceneNodeAnimator *anim;
    fire = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/fires/fireDown.obj"));
	fire->setPosition(pos);
	fire->setScale({5, 5, 5});
	if (fire)
		fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	fire->addAnimator(anim);
	anim->drop();
}

void FireDown::spawn()
{
}

void FireDown::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void FireDown::update()
{
}