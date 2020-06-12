/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedDown
*/

#include "SpeedDown.hpp"
#include "global.hpp"

SpeedDown::SpeedDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_smgr = smgr;
	_pos = pos;
	_type = IPowerUps::PowerUpsType::SpeedDown;

	if (!g_meshes[IPowerUps::PowerUpsType::SpeedDown])
        throw PowerUpsException("can't load model \"resources/models/powers/speeds/speedDown.obj\"");
	_node = _smgr->addMeshSceneNode(g_meshes[IPowerUps::PowerUpsType::SpeedDown]);
    if (!_node)
        throw PowerUpsException("can't add mesh \"resources/models/powers/speeds/speedDown.obj\" to a node");
	_node->setPosition(pos);
	_node->setScale({0.1f, 0.1f, 0.1f});
	if (_node)
		_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	irr::scene::ISceneNodeAnimator *anim = _smgr->createRotationAnimator({0, 1, 0});
	if (!anim)
		throw PowerUpsException("can't load anim : speedDown");
	_node->addAnimator(anim);
	anim->drop();
}

SpeedDown::~SpeedDown()
{
	_node->remove();
}

irr::core::vector3df SpeedDown::getPosition()
{
	return _pos;
}

IPowerUps::PowerUpsType SpeedDown::getType()
{
	return _type;
}

void SpeedDown::spawn()
{
}

void SpeedDown::die()
{
	_node->setVisible(false);

}

void SpeedDown::update()
{
}