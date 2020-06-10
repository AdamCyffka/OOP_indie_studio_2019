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

	if (!fireFull)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireFull.obj\"");
    _bomb = _smgr->addMeshSceneNode(fireFull);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireFull.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireFull");
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