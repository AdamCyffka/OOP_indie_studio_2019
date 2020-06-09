/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomber.hpp"

Bomber::Bomber(Map *map, LoadMap *loadMap): _radius(3), _delay(TIMER), _map(map), _loadMap(loadMap), _isBlast(false)
{
}

Bomber::~Bomber()
{
}

void Bomber::run()
{
    setIsBlast(true);
}

void Bomber::setRadius(int radius)
{
    this->_radius = radius;
}

int	Bomber::getRadius() const
{
    return (this->_radius);
}

void Bomber::setEntities(std::vector<IEntity *> entities)
{
    this->_entities = entities;
}

std::vector<IEntity *> Bomber::getEntities() const
{
    return (this->_entities);
}

void Bomber::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomber::getIsBlast() const
{
    return (this->_isBlast);
}

bool Bomber::canPutBomb(IEntity *it)
{
    if ((_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == blockState::empty) &&
    (_map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == bombState::clear))
        return (true);
    return (false);
}

bool Bomber::hasEnoughBombToPut(IEntity *it)
{
    if (it->getBombStack()->bombsAvailable() > 0 && it->getBombAmount() > 0)
        return true;
    return false;
}

void Bomber::putBomb(IEntity *it)
{
    std::cout << "bomb function" << std::endl;
    if (canPutBomb(it) == true && hasEnoughBombToPut(it) == true) {
        std::cout << "in function" << std::endl;
        epicenter(it);
        removeBombFromInventory(it);
        {
			//
        }
        setIsBlast(true); // casse block sans timer
        if (getIsBlast() == true) {
            {
                std::cout << "blasting" << std::endl;
                blastNorth(it);
                blastSouth(it);
                blastEast(it);
                blastWest(it);
            }
            clearMapAfterBlast(it);
            _map->printMap();
            setIsBlast(false);
            giveNewBombInInventory(it);
        }
    }
}

void Bomber::epicenter(IEntity *it)
{
    _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] = bombState::bomb;
}

void Bomber::blastNorth(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] == blockState::unbreakable)
            break;
        else if (_map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] == blockState::breakable)
            _map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] = blockState::empty;
            _map->getBombMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] = bombState::clear;
            _loadMap->getVisualMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y]->setVisible(false);
    }
}

void Bomber::blastSouth(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] == blockState::unbreakable)
            break;
        else if (_map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] == blockState::breakable)
            _map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] = blockState::empty;
            _map->getBombMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] = bombState::clear;
            _loadMap->getVisualMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y]->setVisible(false);
    }
}

void Bomber::blastEast(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] == blockState::unbreakable)
            break;
        else if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] == blockState::breakable)
            _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] = blockState::empty;
            _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] = bombState::clear;
            _loadMap->getVisualMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i]->setVisible(false);
    }
}

void Bomber::blastWest(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] == blockState::unbreakable)
            break;
        else if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] == blockState::breakable)
            _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] = blockState::empty;
            _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] = bombState::clear;
            _loadMap->getVisualMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i]->setVisible(false);
    }
}

void Bomber::clearMapAfterBlast(IEntity *it)
{
    _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] = bombState::clear;
}

void Bomber::removeBombFromInventory(IEntity *it)
{
	it->setBombAmount(it->getBombAmount() - 1);
}

void Bomber::giveNewBombInInventory(IEntity *it)
{
    it->setBombAmount(it->getBombAmount() + 1);
}

bool Bomber::isKilledByBomb(IEntity *it)
{
    it->setIsAlive(false);
    it->getCharacter()->setVisibility(false);
    it->getCharacter()->dead;
    return (true);
}

void Bomber::animateBomb()
{
}