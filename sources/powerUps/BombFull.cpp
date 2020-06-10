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

	if (!bombFull)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombFull.obj\"");
    _bomb = _smgr->addMeshSceneNode(bombFull);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombFull.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombFull");
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