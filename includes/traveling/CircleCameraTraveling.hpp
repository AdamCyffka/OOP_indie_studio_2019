/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CircleCameraTraveling
*/

#ifndef CIRCLECAMERATRAVELING_HPP_
#define CIRCLECAMERATRAVELING_HPP_

#include "ACameraTraveling.hpp"

using namespace irr;

class CircleCameraTraveling : public ACameraTraveling {
    public:
        CircleCameraTraveling(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr, core::vector3df center, float radius, float speed);
        ~CircleCameraTraveling();

        bool accelerateTo(irr::core::vector3df pos) final;

        void start();

        void setCenter(core::vector3df center) {_center = center;}
        void setRadius(float radius) {_radius = radius;}
        void setSpeed(float speed) {_speed = speed;}
        core::vector3df getCenter() const {return _center;}
        float getRadius() const {return _radius;}
        float getSpeed() const {return _speed;}
    protected:
    private:
        core::vector3df _center;
        float _radius;
        float _speed;
};

#endif /* !CIRCLECAMERATRAVELING_HPP_ */
