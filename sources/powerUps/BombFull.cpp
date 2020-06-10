/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombFull
*/

#include "BombFull.hpp"

BombFull::BombFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::BombFull;

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombFull.obj"));
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombFull::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType BombFull::getType()
{
	return _type;
}

void BombFull::spawn()
{
}

void BombFull::die()
{
	_bomb->setVisible(false);
}

void BombFull::update()
{
}