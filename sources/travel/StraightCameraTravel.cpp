/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StraightCameraTravel
*/

#include <boost/chrono.hpp>
#include <boost/thread.hpp>
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

void StraightCameraTravel::updateTarget()
{
    auto *camera = getCamera();
    core::vector3df tempTarget = camera->getTarget();
    float x = (int)tempTarget.X;
    float y = (int)tempTarget.Y;
    float z = (int)tempTarget.Z;

    while (std::round(x) != _targetPosition.X || std::round(y) != _targetPosition.Y || std::round(z) != _targetPosition.Z) {
        if (x > _targetPosition.X)
            x -= 0.05;
        else if (x < _targetPosition.X)
            x += 0.05;
        if (y > _targetPosition.Y)
            y -= 0.05;
        else if (y < _targetPosition.Y)
            y += 0.05;
        if (z > _targetPosition.Z)
            z -= 0.05;
        else if (z < _targetPosition.Z)
            z += 0.05;
        boost::this_thread::sleep_for(boost::chrono::microseconds(100));
        camera->setTarget({x, y, z});
        boost::this_thread::yield();
    }
}

void StraightCameraTravel::start()
{
    _anim = getSceneManager()->createFlyStraightAnimator(_startPosition, _stopPosition, _travelTime);
    if (_anim) {
        auto *camera = getCamera();
        camera->addAnimator(_anim);
        camera->setTarget(_targetPosition);
        // boost::thread *thr = new boost::thread(boost::bind(&StraightCameraTravel::updateTarget, this)); // smooth camera target
    } else {
        throw CameraTravelException("Could not create fly straight animator.");
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
