/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"
#include "global.hpp"

SpeedUp::SpeedUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
    _smgr = smgr;
    _pos = pos;
    _type = IPowerUps::PowerUpsType::SpeedUp;

    if (!g_meshes[IPowerUps::PowerUpsType::SpeedUp])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/speedUp.obj\"");
    _node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::SpeedUp]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/speedUp.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({5, 5, 5});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : SpeedUp");
	_node->addAnimator(anim);
	anim->drop();
}

irr::core::vector3df SpeedUp::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType SpeedUp::getType()
{
	return _type;
}

void SpeedUp::spawn()
{
}

void SpeedUp::die()
{
	_node->setVisible(false);
	delete this;
}

void SpeedUp::update()
{
}