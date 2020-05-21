/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallPass
*/

#include "WallPass.hpp"

WallPass::WallPass(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z)
{
    _driver = driver;
	_env = env;
	_smgr = smgr;

	irr::scene::ISceneNode *mushRoom;
	irr::scene::ISceneNodeAnimator *anim;
    mushRoom = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/wallPass/wallPass.obj"));
	mushRoom->setPosition({x, 310, z});
	mushRoom->setRotation({-50, 0, 0});
	mushRoom->setScale({4, 4, 4});
	if (mushRoom)
		mushRoom->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	mushRoom->addAnimator(anim);
	anim->drop();
}

void WallPass::spawn()
{
}

void WallPass::die()
{
	// _map.getMap().removeEntity(this);
	// delete this;
}

void WallPass::update()
{
}