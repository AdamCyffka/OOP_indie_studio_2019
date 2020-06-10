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
	_pos = pos;
	_type = PowerUps::PowerUpsType::FireFull;

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/fires/fireFull.obj"));
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df FireFull::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType FireFull::getType()
{
	return _type;
}

void FireFull::spawn()
{
}

void FireFull::die()
{
	_bomb->setVisible(false);
}

void FireFull::update()
{
}