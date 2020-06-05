/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomber management
*/

#ifndef __BOMBER_HPP__
# define __BOMBER_HPP__

#include <irrlicht.h>

#include "Map.hpp"
#include "LoadMap.hpp"
#include "hitbox.hpp"
#include "AnimExplo.hpp"
#include "IEntity.hpp"

#include <utility>
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
        bool canPutBomb(IEntity *);
        bool hasEnoughBombToPut(IEntity *it);

        //Pose bomb and blast
        void putBomb(IEntity *);
        void epicenter(IEntity *);
        void blastNorth(IEntity *);
        void blastSouth(IEntity *);
        void blastEast(IEntity *);
        void blastWest(IEntity *);
        void clearMapAfterBlast(IEntity *);
        void animateBomb();

        //Remove and give bomb
        void removeBombFromInventory(IEntity *it);
        void giveNewBombInInventory();

        //Dead handling
        bool isKilledByBomb();
    private:
        Map *_map;
        std::vector<IEntity *> _entities;
        std::chrono::milliseconds _delay;
        LoadMap *_visualMap;
        int _radius;
        bool _isBlast;
    protected:
};

void waiter();

#endif /* !__BOMBER_HPP__ */