/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireDown
*/

#include "FireDown.hpp"

FireDown::FireDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::FireDown;

	if (!fireDown)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireDown.obj\"");
    _bomb = _smgr->addMeshSceneNode(fireDown);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireDown.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireDown");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df FireDown::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType FireDown::getType()
{
	return _type;
}

void FireDown::spawn()
{
}

void FireDown::die()
{
	_bomb->setVisible(false);
}

void FireDown::update()
{
}