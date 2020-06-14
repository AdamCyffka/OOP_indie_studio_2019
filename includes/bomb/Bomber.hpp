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

class Core;
class GameCore;

class Bomber {
    public:
        Bomber(Map *, LoadMap *, GameCore *, Core *);
        ~Bomber();
        void run(IEntity *it);


        //Recover entities
        void setEntities(std::vector<IEntity *> entities);

         //Error handling
        bool canPutBomb(IEntity *);
        bool hasEnoughBombToPut(IEntity *it);

        //Pose bomb and blast
        void putBomb(IEntity *);
        void epicenter(IEntity *, irr::core::vector3df);
        int blastNorth(IEntity *, irr::core::vector3df, int radius);
        int blastSouth(IEntity *, irr::core::vector3df, int radius);
        int blastEast(IEntity *, irr::core::vector3df, int radius);
        int blastWest(IEntity *, irr::core::vector3df, int radius);
        void clearMapAfterBlast(IEntity *, irr::core::vector3df);

        //Dead handling
        void killEntity(IEntity *entity);
        std::vector<IEntity *> isKilledByBomb(std::vector<Point> deadZone, IEntity *killer, irr::core::vector3df bombPosition3d);
    private:
        Map *_map;
        LoadMap *_loadMap;
        GameCore *_gameCore;
        Core *_core;
        std::vector<IEntity *> _entities;
        int _delay;
        bool _isBlast;
    protected:
};

#endif /* !__BOMBER_HPP__ */