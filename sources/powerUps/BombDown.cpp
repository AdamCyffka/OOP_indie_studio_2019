/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombDown
*/

#include "BombDown.hpp"
#include "global.hpp"

BombDown::BombDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::BombDown;

	if (!g_meshes[IPowerUps::PowerUpsType::BombDown])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombDown.obj\"");
    _node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::BombDown]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombDown.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombDown");
	_node->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombDown::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType BombDown::getType()
{
	return _type;
}

void BombDown::spawn()
{
}

void BombDown::die()
{
	_node->setVisible(false);
	delete this;
}

void BombDown::update()
{
}