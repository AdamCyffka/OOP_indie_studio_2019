/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomb::Bomb(Character *character, Map *map, Player *player): _radius(2), _delay(TIMER), _map(map), _character(character), _player(player), _isBlast(false)
{
}

Bomb::~Bomb()
{
}

int	Bomb::getRadius() const
{
    return (this->_radius);
}

void Bomb::setRadius(int radius)
{
    this->_radius = radius;
}

void Bomb::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomb::getIsBlast() const
{
    return (this->_isBlast);
}

std::pair<int, int> Bomb::getPosition() const
{
    return (this->_position);
}

void Bomb::setPosition(std::pair<int, int> position)
{
    this->_position = position;
}

bool Bomb::addExplosion(bool inGame)
{
    if (inGame == true) { // pas finis...
        return (true);
    }
    return (false);
}

bool Bomb::canPoseBomb()
{
    if (blockState::empty) {
        return (true);
    } else {
        return (false);
    }
}

bool Bomb::hasEnoughBombToPose()
{
    if (_player->getBombAmount() > 0 ) {
        return (true);
    } else {
        return (false);
    }
}

void Bomb::poseBomb()
{
    setIsBlast(true);
    if (canPoseBomb() == true && hasEnoughBombToPose() == true && getIsBlast() == true) {
        _map->printMap();
    }
}

bool Bomb::isKilledByBomb()
{
    return (false);
}