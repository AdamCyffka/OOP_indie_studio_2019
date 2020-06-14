/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** StraightCameraTravel
*/

#ifndef STRAIGHTCAMERATRAVEL_HPP_
#define STRAIGHTCAMERATRAVEL_HPP_

#include "ACameraTravel.hpp"

using namespace irr;

class StraightCameraTravel : public ACameraTravel {
    public:
        StraightCameraTravel(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr,
        core::vector3df startPosition, core::vector3df stopPosition, core::vector3df targetPosition, u32 travelTime);
        ~StraightCameraTravel();

        void start() final;
        void stop() final;
    protected:
    private:
        core::vector3df _startPosition;
        core::vector3df _stopPosition;
        core::vector3df _targetPosition;
        u32 _travelTime;
};

#endif /* !STRAIGHTCAMERATRAVEL_HPP_ */
