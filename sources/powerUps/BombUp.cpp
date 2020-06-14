/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombUp
*/

#include "BombUp.hpp"
#include "global.hpp"

BombUp::BombUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::BombUp;

	if (!g_meshes[IPowerUps::PowerUpsType::BombUp])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombUp.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::BombUp]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombUp.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombUp");
	_node->addAnimator(anim);
	anim->drop();
}

BombUp::~BombUp()
{
	_node->remove();
}

irr::core::vector3df BombUp::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType BombUp::getType()
{
	return _type;
}

void BombUp::spawn()
{
}

void BombUp::die()
{
	_node->setVisible(false);
}

void BombUp::update()
{
}