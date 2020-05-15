/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CircleCameraTraveling
*/

#include "CircleCameraTraveling.hpp"

CircleCameraTraveling::CircleCameraTraveling(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr, core::vector3df center, float radius, float speed)
: ACameraTraveling(camera, smgr), _center(center), _radius(radius), _speed(speed)
{
}

CircleCameraTraveling::~CircleCameraTraveling()
{
}

void CircleCameraTraveling::start()
{
    _anim = getSceneManager()->createFlyCircleAnimator(_center, _radius, _speed);
    if (_anim) {
        if (auto *camera = getCamera()) {
            camera->addAnimator(_anim);
            camera->setTarget(_center);
        }
        _anim->drop();
    }
}

bool CircleCameraTraveling::accelerateTo(irr::core::vector3df pos)
{
    return false;
}
