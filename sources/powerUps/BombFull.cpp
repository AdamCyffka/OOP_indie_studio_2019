/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombFull
*/

#include "BombFull.hpp"
#include "global.hpp"

BombFull::BombFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::BombFull;

	if (!g_meshes[IPowerUps::PowerUpsType::BombFull])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombFull.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::BombFull]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombFull.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombFull");
	_node->addAnimator(anim);
	anim->drop();
}

BombFull::~BombFull()
{
	_node->remove();
}

irr::core::vector3df BombFull::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType BombFull::getType()
{
	return _type;
}

void BombFull::spawn()
{
}

void BombFull::die()
{
	_node->setVisible(false);
}

void BombFull::update()
{
}