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

#include <chrono>
#include <ctime>
#include <vector>

#include <boost/thread.hpp>

#define TIMER (3)

class Bomber {
    public:
        Bomber(Map *, LoadMap *);
        ~Bomber();
        void run(IEntity *it);

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
        void giveNewBombInInventory(IEntity *it);

        //Dead handling
        bool isKilledByBomb(IEntity *it);
    private:
        Map *_map;
        LoadMap *_loadMap;
        BombStack *_bombStack;
        std::vector<IEntity *> _entities;
        int _delay;
        int _radius;
        bool _isBlast;
    protected:
};

#endif /* !__BOMBER_HPP__ */