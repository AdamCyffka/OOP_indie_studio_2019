/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombPass
*/

#include "BombPass.hpp"

BombPass::BombPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = PowerUps::PowerUpsType::BombPass;

	if (!bombPass)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombPass.obj\"");
    _bomb = _smgr->addMeshSceneNode(bombPass);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombPass.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombPass");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombPass::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType BombPass::getType()
{
	return _type;
}

void BombPass::spawn()
{
}

void BombPass::die()
{
	_bomb->setVisible(false);
}

void BombPass::update()
{
}