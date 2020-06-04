/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomber::Bomber(Map *map, std::vector<IEntity *> entities): _radius(2), _delay(TIMER), _map(map), _entities(entities), _isBlast(false)
{
}

Bomber::~Bomber()
{
}

void Bomber::run()
{
    auto timeWhenPutBomb = std::chrono::system_clock::now();

    if (timeWhenPutBomb + _delay >= std::chrono::system_clock::now()) {
        setIsBlast(true);
    }

}

void Bomber::setRadius(int radius)
{
    this->_radius = radius;
}

int	Bomber::getRadius() const
{
    return (this->_radius);
}

void Bomber::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomber::getIsBlast() const
{
    return (this->_isBlast);
}

bool Bomber::canPoseBomb()
{

    if ((_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == blockState::empty) &&
    (_map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::clear)) {
        return (true);
    } else {
        return (false);
    }
}

bool Bomber::hasEnoughBombToPose()
{
    for (auto it : _entities) {
		if (it->getBombAmount() > 0) {
            return (true);
        } else {
            return (false);
        }
	}
    return (true);
}

void Bomber::putBomb()
{
    if (canPoseBomb() && hasEnoughBombToPose()) {
        epicenter();
        removeBombFromInventory();
        if (getIsBlast() == true) {
            {
                blastNorth();
                blastSouth();
                blastEast();
                blastWest();
            }
            clearMapAfterBlast();
            setIsBlast(false);
            giveNewBombInInventory();
        }
    }
}

void Bomber::epicenter()
{
    _map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::bomb;
}

void Bomber::blastNorth()
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(this, _map).x + i][squareWherePlayerIs(this, _map).y] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(this, _map).x + i][squareWherePlayerIs(this, _map).y] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(this, _map).x + i][squareWherePlayerIs(this, _map).y] == blockState::empty;
    }
}

void Bomber::blastSouth()
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(this, _map).x - i][squareWherePlayerIs(this, _map).y] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(this, _map).x - i][squareWherePlayerIs(this, _map).y] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(this, _map).x - i][squareWherePlayerIs(this, _map).y] == blockState::empty;
    }
}

void Bomber::blastEast()
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + i] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + i] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + i] == blockState::empty;
    }
}

void Bomber::blastWest()
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - i] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - i] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - i] == blockState::empty;
    }
}

void Bomber::clearMapAfterBlast()
{
    _map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::clear;
}

void Bomber::removeBombFromInventory()
{
    for (auto it : _entities) {
		it->setBombAmount(it->getBombAmount() - 1);
	}
}

void Bomber::giveNewBombInInventory()
{
    for (auto it : _entities) {
		it->setBombAmount(it->getBombAmount() + 1);
	}
}

bool Bomber::isKilledByBomb()
{
    for (auto it : _entities) {
        it->setIsAlive(false);
        it->getCharacter()->setVisibility(false);
	}
    return (true);
}