/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomber management
*/

#ifndef __BOMBER_HPP__
# define __BOMBER_HPP__

#include <irrlicht.h>
#include <vector>

#include "Map.hpp"
#include "LoadMap.hpp"
#include "AnimExplo.hpp"
#include "IEntity.hpp"
#include "hitbox.hpp"


#define TIMER (3)

class GameCore;

class Bomber {
    public:
        Bomber(Map *, LoadMap *, GameCore *);
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
        void epicenter(IEntity *, irr::core::vector3df);
        void blastNorth(IEntity *, irr::core::vector3df);
        void blastSouth(IEntity *, irr::core::vector3df);
        void blastEast(IEntity *, irr::core::vector3df);
        void blastWest(IEntity *, irr::core::vector3df);
        void clearMapAfterBlast(IEntity *, irr::core::vector3df);
        int getRemainingEntities();

        //Remove and give bomb
        void removeBombFromInventory(IEntity *it);
        void giveNewBombInInventory(IEntity *it);

        //Dead handling
        IEntity *isKilledByBomb(std::vector<Point> deadZone);
    private:
        Map *_map;
        LoadMap *_loadMap;
        BombStack *_bombStack;
        GameCore *_gameCore;
        std::vector<IEntity *> _entities;
        int _delay;
        int _radius;
        bool _isBlast;
    protected:
};

#endif /* !__BOMBER_HPP__ */