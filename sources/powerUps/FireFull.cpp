/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireFull
*/

#include "FireFull.hpp"
#include "global.hpp"

FireFull::FireFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::FireFull;

	if (!g_meshes[IPowerUps::PowerUpsType::FireFull])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireFull.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::FireFull]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireFull.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireFull");
	_node->addAnimator(anim);
	anim->drop();
}

FireFull::~FireFull()
{
	_node->remove();
}

irr::core::vector3df FireFull::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType FireFull::getType()
{
	return _type;
}

void FireFull::spawn()
{
}

void FireFull::die()
{
	_node->setVisible(false);
	delete this;
}

void FireFull::update()
{
}