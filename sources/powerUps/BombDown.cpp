/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombDown
*/

#include "BombDown.hpp"

BombDown::BombDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::BombDown;

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/bombs/bombDown.obj"));
	_bomb->setPosition(pos); // y = 310
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombDown::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType BombDown::getType()
{
	return _type;
}

void BombDown::spawn()
{
}

void BombDown::die()
{
	_bomb->setVisible(false);
}

void BombDown::update()
{
}