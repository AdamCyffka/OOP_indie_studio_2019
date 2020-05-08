/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <irrlicht.h>

#include <ctime>
#include <vector>

class Bomb {
    public:
        Bomb(int x, int y, int radius, irr::u32 delay);
        ~Bomb();
        int getX() const;
        int getY() const;
        int getRadius() const;
        irr::u32 getDelay() const;
        void setIsBlast(bool isBlast);
        bool getIsBlast() const;
    private:
        int _x;
        int _y;
        int _radius;
        irr::u32 _delay;
        bool _isBlast;
    protected:
};

#endif /* !__BOMB_HPP__ */