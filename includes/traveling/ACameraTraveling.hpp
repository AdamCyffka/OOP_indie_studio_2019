/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ACameraTraveling
*/

#ifndef ACAMERATRAVELING_HPP_
#define ACAMERATRAVELING_HPP_

#include <irrlicht.h>

using namespace irr;

class ACameraTraveling {
    public:
        ACameraTraveling(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr) : _camera(camera), _smgr(smgr) {};
        ~ACameraTraveling() = default;
        
        virtual bool accelerateTo(irr::core::vector3df pos) = 0;

    protected:
        scene::ISceneNodeAnimator *_anim;

        scene::ICameraSceneNode *getCamera() const {return _camera;};
        scene::ISceneManager *getSceneManager() const {return _smgr;};
    private:
        scene::ISceneManager *_smgr;
        scene::ICameraSceneNode *_camera;
};

#endif /* !ACAMERATRAVELING_HPP_ */
