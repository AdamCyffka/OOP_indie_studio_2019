/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombUp
*/

#include "BombUp.hpp"

BombUp::BombUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::BombUp;

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombUp.obj"));
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombUp::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType BombUp::getType()
{
	return _type;
}

void BombUp::spawn()
{
}

void BombUp::die()
{
	_bomb->setVisible(false);
}

void BombUp::update()
{
}