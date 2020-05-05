/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <irrlicht.h>
#include "CharacterException.hpp"
#include "modelinfos.hpp"

using namespace irr;

class Character {
    public:
        Character(scene::ISceneManager* sManager, modelInfos_t model, std::string name = "Player", int movementSpeed = 100);
        ~Character();

        enum state {
            idle,
            moving,
            dying,
            dead
        };

        //setters
        void setSize(int size);
        void setPosition(core::vector3df position);
        void setState(Character::state state);
        void setAnimationSpeed(int animationSpeed);
        void setMovementSpeed(int movementSpeed);

        //getters
        int getSize() const;
        core::vector3df getPosition() const;
        Character::state getState() const;
        int getAnimationSpeed() const;
        int getMovementSpeed() const;

        //methods
        void moveTo(core::vector3df position, int speed = -1);
    protected:
    private:
        //attributes
            //irr
        scene::ISceneManager *_sManager;
        scene::IAnimatedMeshSceneNode *_mesh;
            //non irr
        Character::state _state = Character::idle;
        modelInfos_t _model;
        std::string _name;
        int _movementSpeed;
};

#endif /* !CHARACTER_HPP_ */
