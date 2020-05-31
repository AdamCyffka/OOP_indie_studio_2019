/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomb::Bomb(): _radius(2), _delay(TIMER)
{
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

bool Bomb::addExplosion(int x, int y, bool inGame)
{
    if (inGame == true) {
    }
}

int Bomb::canPoseBomb()
{
    if (blockState::empty) {
        return (1);
    } else {
        return (0);
    }
}

int Bomb::enoughBombToPose()
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
    Map map;

    setIsBlast(true);
    if (canPoseBomb() == true && enoughBombToPose() == true && getIsBlast() == true) {
        map.printMap();
    }
}

int Bomb::killedByBomb()
{
}