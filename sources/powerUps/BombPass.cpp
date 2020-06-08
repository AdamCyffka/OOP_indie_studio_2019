/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombPass
*/

#include "BombPass.hpp"

BombPass::BombPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;

    irr::scene::ISceneNode *bomb;
	irr::scene::ISceneNodeAnimator *anim;
    bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombPass.obj"));
	bomb->setPosition(pos);
	bomb->setScale({4, 4, 4});
	if (bomb)
		bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	bomb->addAnimator(anim);
	anim->drop();
}

void BombPass::spawn()
{
}

void BombPass::die()
{
}

void BombPass::update()
{
}