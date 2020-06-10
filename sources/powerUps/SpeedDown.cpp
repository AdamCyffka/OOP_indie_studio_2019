/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedDown
*/

#include "SpeedDown.hpp"

SpeedDown::SpeedDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::SpeedDown;

	if (!speedDown)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/speedDown.obj\"");
    _bomb = _smgr->addMeshSceneNode(speedDown);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/speedDown.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : speedDown");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df SpeedDown::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType SpeedDown::getType()
{
	return _type;
}

void SpeedDown::spawn()
{
}

void SpeedDown::die()
{
	_bomb->setVisible(false);
}

void SpeedDown::update()
{
}