/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireFull
*/

#include "FireFull.hpp"

FireFull::FireFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;

    irr::scene::ISceneNode *fire;
	irr::scene::ISceneNodeAnimator *anim;
    fire = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/fires/fireFull.obj"));
	fire->setPosition(pos);
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
}

void FireFull::update()
{
}