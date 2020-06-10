/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombPass
*/

#include "BombPass.hpp"
#include "global.hpp"

BombPass::BombPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::BombPass;

	if (!g_meshes[IPowerUps::PowerUpsType::BombPass])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/bombPass.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::BombPass]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/bombPass.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : bombPass");
	_node->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df BombPass::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType BombPass::getType()
{
	return _type;
}

void BombPass::spawn()
{
}

void BombPass::die()
{
	_node->setVisible(false);
}

void BombPass::update()
{
}