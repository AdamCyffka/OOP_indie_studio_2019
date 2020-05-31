/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <irrlicht.h>

#include "Player.hpp"
#include "Map.hpp"

#include <ctime>
#include <vector>

#define TIMER (3000)

class Bomb {
    public:
        Bomb();
        ~Bomb();
        int getX() const;
        int getY() const;
        int getRadius() const;
        irr::u32 getDelay() const;
        void setIsBlast(bool isBlast);
        bool getIsBlast() const;
        int canPoseBomb();
        int enoughBombToPose();
        void poseBomb();
        int killedByBomb();
    private:
        int _x;
        int _y;
        int _radius;
        irr::u32 _delay;
        bool _isBlast;
        bool addExplosion(int x, int y, bool inGame);
    protected:
};

#endif /* !__BOMB_HPP__ */