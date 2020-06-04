/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <irrlicht.h>

#include "IEntity.hpp"
#include "Map.hpp"
#include "hitbox.hpp"
#include "AnimExplo.hpp"

#include <chrono>
#include <ctime>
#include <vector>

#define TIMER (3000)

class Core;
class Bomber : public IEntity {
    public:
        Bomber(Map *, std::vector<IEntity *>);
        ~Bomber();
        void run();

        //Radius
        void setRadius(int radius);
        int getRadius() const;

        //Blast
        void setIsBlast(bool isBlast);
        bool getIsBlast() const;

         //Error handling
        bool canPoseBomb();
        bool hasEnoughBombToPose();

        //Pose bomb and blast
        void putBomb();
        void epicenter();
        void blastNorth();
        void blastSouth();
        void blastEast();
        void blastWest();
        void clearMapAfterBlast();

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