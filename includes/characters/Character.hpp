/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>
#include <irrlicht.h>
#include "CharacterException.hpp"
#include "modelinfos.hpp"
#include "side.hpp"

using namespace irr;
class Character {
    public:
        Character(scene::ISceneManager *sManager, video::IVideoDriver *driver, modelInfos_t model,
                  std::string name = "Player", int travelingTime = 1000,
                  side orientation = side::north);
        ~Character();

        enum state {
            idle,
            moving,
            dying,
            dead,
            victory
        };

        //setters
        void setSize(int size);
        void setPosition(core::vector3df position);
        void setState(Character::state state);
        void setOrientation(side side);
        void setAnimationSpeed(int animationSpeed);
        void setTravelingTime(int travelingTime);

        //getters
        int getSize() const;
        core::vector3df getPosition() const;
        Character::state getState() const;
        side getOrientation() const;
        int getAnimationSpeed() const;
        int getTravelingTime() const;

        //methods
        bool moveTo(core::vector3df position, int travelingTime = 0);
    protected:
    private:
        //attributes
            //irr
        scene::ISceneManager *_sManager;
        video::IVideoDriver *_driver;
        scene::IAnimatedMeshSceneNode *_mesh;
            //non irr
        Character::state _state;
        side _orientation;
        modelInfos_t _model;
        std::string _name;
        int _travelingTime;

        //methods
        side getOrientationFromPath(core::vector3df posA, core::vector3df posB);
};

#endif /* !CHARACTER_HPP_ */
