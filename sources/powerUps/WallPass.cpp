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

	irr::scene::ISceneNodeAnimator *anim;
    _bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/wallPass/wallPass.obj"));
	_bomb->setPosition(pos);
	_bomb->setRotation({-50, 0, 0});
	_bomb->setScale({4, 4, 4});
	if (_bomb)
		_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	anim = _smgr->createRotationAnimator({0, 1, 0});
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