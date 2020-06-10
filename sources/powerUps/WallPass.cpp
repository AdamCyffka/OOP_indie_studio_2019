/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallPass
*/

#include "WallPass.hpp"

WallPass::WallPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_type = PowerUps::PowerUpsType::WallPass;

	if (!wallPass)
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/wallPass.obj\"");
    _bomb = _smgr->addMeshSceneNode(wallPass);
    if (!_bomb)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/wallPass.obj\" to a node");
	_bomb->setPosition(pos);
	_bomb->setScale({5, 5, 5});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : wallPass");
	_bomb->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df WallPass::getPosition()
{
	return _pos;
}

PowerUps::PowerUpsType WallPass::getType()
{
	return _type;
}

void WallPass::spawn()
{
}

void WallPass::die()
{
	delete this;
}

void WallPass::update()
{
}