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

	if (!bombUp)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombUp.obj\"");
    _bomb = _smgr->addMeshSceneNode(bombUp);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombUp.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombUp");
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