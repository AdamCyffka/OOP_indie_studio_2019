/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallPass
*/

#include "WallPass.hpp"
#include "global.hpp"

WallPass::WallPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::WallPass;

	if (!g_meshes[IPowerUps::PowerUpsType::WallPass])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/wallPass.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::WallPass]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/wallPass.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({7, 7, 7});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : wallPass");
	_node->addAnimator(anim);
	anim->drop();
}

WallPass::~WallPass()
{
	_node->remove();
}

irr::core::vector3df WallPass::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType WallPass::getType()
{
	return _type;
}

void WallPass::spawn()
{
}

void WallPass::die()
{
	_node->setVisible(false);
}

void WallPass::update()
{
}