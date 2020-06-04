/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <irrlicht.h>

#include "Map.hpp"
#include "hitbox.hpp"
#include "AnimExplo.hpp"
#include "IEntity.hpp"

#include <chrono>
#include <ctime>
#include <vector>

#define TIMER (3000)

class Bomber {
    public:
        Bomber(Map *);
        ~Bomber();
        void run();

        //Radius
        void setRadius(int radius);
        int getRadius() const;

        //Recover entities
        void setEntities(std::vector<IEntity *> entities);
        std::vector<IEntity *> getEntities() const;

        //Blast
        void setIsBlast(bool isBlast);
        bool getIsBlast() const;

         //Error handling
        bool canPoseBomb(IEntity *);
        bool hasEnoughBombToPose();

        //Pose bomb and blast
        void putBomb(std::vector<IEntity *>, IEntity *);
        void epicenter(IEntity *);
        void blastNorth(IEntity *);
        void blastSouth(IEntity *);
        void blastEast(IEntity *);
        void blastWest(IEntity *);
        void clearMapAfterBlast(IEntity *);

        //Remove and give bomb
        void removeBombFromInventory();
        void giveNewBombInInventory();

        //Dead handling
        bool isKilledByBomb();
    private:
        Map *_map;
        std::vector<IEntity *> _entities;
        int _radius;
        std::chrono::milliseconds _delay;
        std::vector<int> _bomb;
        bool _isBlast;
    protected:
};

void waiter();

#endif /* !__BOMB_HPP__ */