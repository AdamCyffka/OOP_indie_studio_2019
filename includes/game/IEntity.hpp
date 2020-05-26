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
#include "Input.hpp"

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
        virtual void run() = 0;
    	virtual void putBomb() = 0;
        virtual void setFirePower(int) = 0;
        virtual int getFirePower() = 0;
		virtual void setBombAmount(int) = 0;
		virtual int getBombAmount() = 0;
        virtual void setSpeed(int) = 0;
        virtual int getSpeed() = 0;
        virtual void setWallPass(bool) = 0;
        virtual bool getWallPass() = 0;
        virtual void setBombPass(bool) = 0;
        virtual bool getBombPass() = 0;
        virtual void setEntityNumber(int) = 0;
        virtual int getEntityNumber() = 0;
		virtual void setScore(int) = 0;
        virtual int getScore() = 0;
        virtual void setWinNumber(int) = 0;
        virtual int getWinNumber() = 0;
        virtual Character *getCharacter() = 0;
        virtual void moveTo(side) = 0;
        virtual void setIsAlive(bool) = 0;
        virtual bool isAlive() = 0;
        virtual Key_mouvement getInput() = 0;
};

#endif /* !IENTITY_HPP_ */