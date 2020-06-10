/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireDown
*/

#include "FireDown.hpp"
#include "global.hpp"

FireDown::FireDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::FireDown;

	if (!g_meshes[IPowerUps::PowerUpsType::FireDown])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/fireDown.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::FireDown]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/fireDown.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : fireDown");
	_node->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df FireDown::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType FireDown::getType()
{
	return _type;
}

void FireDown::spawn()
{
}

void FireDown::die()
{
	_node->setVisible(false);
	delete this;
}

void FireDown::update()
{
}