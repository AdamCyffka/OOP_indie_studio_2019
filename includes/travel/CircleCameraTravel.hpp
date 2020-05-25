/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CircleCameraTravel
*/

#ifndef CIRCLECAMERATRAVEL_HPP_
#define CIRCLECAMERATRAVEL_HPP_

#include "ACameraTravel.hpp"

using namespace irr;

class CircleCameraTravel : public ACameraTravel {
    public:
        CircleCameraTravel(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr,
        core::vector3df center, core::vector3df targetPosition, float radius, float speed);
        ~CircleCameraTravel();

        void start() final;
        void stop() final;
        bool accelerateTo(irr::core::vector3df pos);

        void setCenter(core::vector3df center) {_center = center;}
        void setRadius(float radius) {_radius = radius;}
        void setSpeed(float speed) {_speed = speed;}
        core::vector3df getCenter() const {return _center;}
        float getRadius() const {return _radius;}
        float getSpeed() const {return _speed;}
    protected:
    private:
        core::vector3df _center;
        core::vector3df _targetPosition;
        float _radius;
        float _speed;
};

#endif /* !CIRCLECAMERATRAVEL_HPP_ */
