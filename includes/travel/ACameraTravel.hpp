/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ACameraTravel
*/

#ifndef ACAMERATRAVEL_HPP_
#define ACAMERATRAVEL_HPP_

#include <irrlicht.h>
#include <iostream>

using namespace irr;

class ACameraTravel {
    public:
        ACameraTravel(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr) : _camera(camera), _smgr(smgr) {};
        ~ACameraTravel() = default;

        virtual void start() = 0;
        virtual void stop() = 0;

    protected:
        scene::ISceneNodeAnimator *_anim = nullptr;

        scene::ICameraSceneNode *getCamera() const {return _camera;};
        scene::ISceneManager *getSceneManager() const {return _smgr;};
    private:
        scene::ISceneManager *_smgr;
        scene::ICameraSceneNode *_camera;
};

#endif /* !ACAMERATRAVEL_HPP_ */
