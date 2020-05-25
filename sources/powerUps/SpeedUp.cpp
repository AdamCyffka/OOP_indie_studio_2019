/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedUp
*/

#include "SpeedUp.hpp"

SpeedUp::SpeedUp(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    irr::scene::ISceneNode *speed;
    irr::scene::ISceneNodeAnimator *anim;
    speed = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/powers/speeds/speedUp.obj"));
    speed->setPosition({x, 310, z});
    speed->setScale({5, 5, 5});
    if (speed)
        speed->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    anim = _smgr->createRotationAnimator({0, 1, 0});
    speed->addAnimator(anim);
    anim->drop();
}

void SpeedUp::spawn()
{
}

void SpeedUp::die()
{
    // _map.getMap().removeEntity(this);
    // delete this;
}

void SpeedUp::update()
{
}