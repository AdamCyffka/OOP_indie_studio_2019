/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireFull
*/

#include "FireFull.hpp"

FireFull::FireFull(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z)
{
	_driver = driver;
	_env = env;
	_smgr = smgr;

    irr::scene::ISceneNode *fire;
	irr::scene::ISceneNodeAnimator *anim;
    fire = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/fires/fireFull.obj"));
	fire->setPosition({x, 310, z});
	fire->setScale({5, 5, 5});
	if (fire)
		fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	fire->addAnimator(anim);
	anim->drop();
}

void FireFull::spawn()
{
}

void FireFull::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void FireFull::update()
{
}