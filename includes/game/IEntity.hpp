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

namespace EntityType {
	enum EntityType {
		AI,
		player
	};
}

class IEntity {
    public:
        virtual ~IEntity() = default;

        virtual void kill() = 0;
        virtual void move() = 0;
        virtual void run() = 0;
    	virtual void putBomb() = 0;

	protected:
        virtual int getFirePower() = 0;
		virtual int getBombAmount() = 0;
        virtual int getSpeed() = 0;
        virtual bool getWallPass() = 0;
        virtual bool getBombPass() = 0;
        virtual int getEntityNumber() = 0;
        virtual int getScore() = 0;
        virtual Character *getCharacter() = 0;
        virtual void moveTo(Move) = 0;
        virtual bool isAlive() = 0;
};

#endif /* !IENTITY_HPP_ */