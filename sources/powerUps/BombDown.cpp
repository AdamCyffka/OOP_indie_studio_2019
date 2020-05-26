/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombDown
*/

#include "BombDown.hpp"

BombDown::BombDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z)
{
	_driver = driver;
	_env = env;
	_smgr = smgr;

    irr::scene::ISceneNode *bomb;
	irr::scene::ISceneNodeAnimator *anim;
    bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombDown.obj"));
	bomb->setPosition({x, 310, z});
	bomb->setScale({5, 5, 5});
	if (bomb)
		bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	bomb->addAnimator(anim);
	anim->drop();
}

void BombDown::spawn()
{
}

void BombDown::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void BombDown::update()
{
}