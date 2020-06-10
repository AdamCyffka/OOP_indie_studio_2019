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
	_pos = pos;
	_type = PowerUps::PowerUpsType::BombPass;

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombPass.obj"));
	_bomb->setPosition(pos);
	_bomb->setScale({4, 4, 4});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombPass::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType BombPass::getType()
{
	return _type;
}

void BombPass::spawn()
{
}

void BombPass::die()
{
	_bomb->setVisible(false);
}

void BombPass::update()
{
}