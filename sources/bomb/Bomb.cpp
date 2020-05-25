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

int Bomb::ifCanPoseBomb()
{
    if (playerState::playerOne) {
        if (blockState::empty) {
            return (1);
        } else {
            return (0);
        }
    }
    if (playerState::playerTwo) {
        if (blockState::empty) {
            return (1);
        } else {
            return (0);
        }
    }
    if (playerState::playerThree) {
        if (blockState::empty) {
            return (1);
        } else {
            return (0);
        }
    }
    if (playerState::playerFour) {
        if (blockState::empty) {
            return (1);
        } else {
            return (0);
        }
    }
}

void Bomb::poseBomb()
{
    if (ifCanPoseBomb() == true && getIsBlast() == true) {
        if (playerState::playerOne) { // pose bomb here if player One
        }
        if (playerState::playerTwo) { // pose bomb here if player Two
        }
        if (playerState::playerThree) { // pose bomb here if player Three
        }
        if (playerState::playerFour) { // pose bomb here if player Four
        }
    }
}