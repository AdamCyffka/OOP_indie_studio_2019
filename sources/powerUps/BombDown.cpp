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

	if (!bombDown)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombDown.obj\"");
    _bomb = _smgr->addMeshSceneNode(bombDown);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombDown.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombDown");
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