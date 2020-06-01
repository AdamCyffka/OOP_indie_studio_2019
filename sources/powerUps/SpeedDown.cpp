/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedDown
*/

#include "SpeedDown.hpp"

SpeedDown::SpeedDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_driver = driver;
	_env = env;
	_smgr = smgr;

    irr::scene::ISceneNode *speed;
	irr::scene::ISceneNodeAnimator *anim;
    speed = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/speeds/speedDown.obj"));
	speed->setPosition(pos);
	speed->setScale({5, 5, 5});
	if (speed)
		speed->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	speed->addAnimator(anim);
	anim->drop();
}

void SpeedDown::spawn()
{
}

void SpeedDown::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void SpeedDown::update()
{
}