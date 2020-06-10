/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
    _smgr = smgr;
    _pos = pos;
    _type = PowerUps::PowerUpsType::SpeedUp;

    if (!speedUp)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/speedUp.obj\"");
    _bomb = _smgr->addMeshSceneNode(speedUp);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/speedUp.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : SpeedUp");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df SpeedUp::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType SpeedUp::getType()
{
	return _type;
}

void SpeedUp::spawn()
{
}

void SpeedUp::die()
{
	_bomb->setVisible(false);
}

void SpeedUp::update()
{
}