/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireUp
*/

#include "FireUp.hpp"
#include "global.hpp"

FireUp::FireUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::FireUp;

	if (!g_meshes[IPowerUps::PowerUpsType::FireUp])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireUp.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::FireUp]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireUp.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireUp");
	_node->addAnimator(anim);
	anim->drop();
}

FireUp::~FireUp()
{
	_node->remove();
}

irr::core::vector3df FireUp::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType FireUp::getType()
{
	return _type;
}

void FireUp::spawn()
{
}

void FireUp::die()
{
	_node->setVisible(false);
	delete this;
}

void FireUp::update()
{
}