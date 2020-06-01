/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombUp
*/

#include "BombUp.hpp"

BombUp::BombUp(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
    _driver = driver;
	_env = env;
	_smgr = smgr;

    irr::scene::ISceneNode *bomb;
	irr::scene::ISceneNodeAnimator *anim;
    bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombUp.obj"));
	bomb->setPosition(pos);
	bomb->setScale({5, 5, 5});
	if (bomb)
		bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	bomb->addAnimator(anim);
	anim->drop();
}

void BombUp::spawn()
{
}

void BombUp::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void BombUp::update()
{
}