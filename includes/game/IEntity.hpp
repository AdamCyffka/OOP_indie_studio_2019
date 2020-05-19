/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include <irrlicht.h>
#include "Character.hpp"

enum Move {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class IEntity {
    public:
        virtual ~IEntity() = default;

        virtual void spawn() = 0;
        virtual void kill() = 0;
        virtual void move() = 0;
        virtual void run() = 0;
    	virtual void putBomb() = 0;

        virtual int getFirePower();
        virtual int getSpeed() = 0;
        virtual void getEntityrNumber() = 0;
        virtual void getScore() = 0;
        virtual Character *getCharacter() = 0;
        virtual void moveTo(Move);
    private:
        bool _isAlive;
};

#endif /* !IENTITY_HPP_ */