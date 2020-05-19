/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StraightCameraTravel
*/

#include "StraightCameraTravel.hpp"
#include "CameraTravelException.hpp"

StraightCameraTravel::StraightCameraTravel(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr,
core::vector3df startPosition, core::vector3df stopPosition, core::vector3df targetPosition, u32 travelTime)
: ACameraTravel(camera, smgr), _startPosition(startPosition), _stopPosition(stopPosition),
_targetPosition(targetPosition), _travelTime(travelTime)
{
    std::cout << "Straight camera travel created." << std::endl;
}

StraightCameraTravel::~StraightCameraTravel()
{
    if (_anim)
        _anim->drop();
    _anim = nullptr;
    std::cout << "Straight camera travel deleted." << std::endl;
}

void StraightCameraTravel::start()
{
    _anim = getSceneManager()->createFlyStraightAnimator(_startPosition, _stopPosition, _travelTime);
    if (_anim) {
        auto *camera = getCamera();
        camera->addAnimator(_anim);
        camera->setTarget(_targetPosition);
    } else {
        throw CameraTravelException("Could not create fly circle animator.");
    }
}

void StraightCameraTravel::stop()
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
