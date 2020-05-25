/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CircleCameraTravel
*/

#include "CircleCameraTravel.hpp"
#include "CameraTravelException.hpp"

CircleCameraTravel::CircleCameraTravel(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr, core::vector3df center, core::vector3df targetPosition, float radius, float speed)
: ACameraTravel(camera, smgr), _center(center), _radius(radius), _speed(speed), _targetPosition(targetPosition)
{
    std::cout << "Circle camera travel created." << std::endl;
}

CircleCameraTravel::~CircleCameraTravel()
{
    if (_anim)
        _anim->drop();
    _anim = nullptr;
    std::cout << "Circle camera travel deleted." << std::endl;
}

void CircleCameraTravel::start()
{
    _anim = getSceneManager()->createFlyCircleAnimator(_center, _radius, _speed);
    if (_anim) {
        auto *camera = getCamera();
        camera->addAnimator(_anim);
        camera->setTarget(_targetPosition);
    } else {
        throw CameraTravelException("Could not create fly circle animator.");
    }
}

void CircleCameraTravel::stop()
{
    if (_anim) {
        auto *camera = getCamera();
        for (auto &anim : camera->getAnimators())
            if (anim == _anim)
                camera->removeAnimator(_anim);
        _anim->drop();
    } else {
        throw CameraTravelException("Animator not found.");
    }
}

bool CircleCameraTravel::accelerateTo(irr::core::vector3df pos)
{
    return false;
}
