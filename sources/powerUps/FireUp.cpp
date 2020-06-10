/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireUp
*/

#include "FireUp.hpp"

FireUp::FireUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::FireUp;

	if (!fireUp)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireUp.obj\"");
    _bomb = _smgr->addMeshSceneNode(fireUp);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireUp.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireUp");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df FireUp::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType FireUp::getType()
{
	return _type;
}

void FireUp::spawn()
{
}

void FireUp::die()
{
	_bomb->setVisible(false);
}

void FireUp::update()
{
}