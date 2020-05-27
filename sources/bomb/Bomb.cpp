/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"
#include "Map.hpp"

Bomb::Bomb(int x, int y, int radius, irr::u32 delay)
{
    this->_x = x;
    this->_y = y;
    this->_radius = radius;
    this->_delay = delay;
    this->_isBlast = false;
}

Bomb::~Bomb()
{
}

int	Bomb::getX() const
{
    return (this->_x);
}

int	Bomb::getY() const
{
    return (this->_y);
}

int	Bomb::getRadius() const
{
    return (this->_radius);
}

irr::u32 Bomb::getDelay() const
{
    return (this->_delay);
}

void Bomb::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomb::getIsBlast() const
{
    return (this->_isBlast);
}

int Bomb::canPoseBomb()
{
    if (blockState::empty) {
        return (1);
    } else {
        return (0);
    }
}

int Bomb::checkEnoughBombToPose()
{
    Player player;

    if (player.getBombAmount() <= 0 ) {
        return (0);
    } else {
        return (1);
    }
}

void Bomb::poseBomb()
{
    if (canPoseBomb() == true && checkEnoughBombToPose() == true && getIsBlast() == true) {
        //pose bombe here
    }
}