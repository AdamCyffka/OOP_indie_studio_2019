/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomber.hpp"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

Bomber::Bomber(Map *map, LoadMap *loadMap): _radius(2), _delay(TIMER), _map(map), _loadMap(loadMap), _isBlast(false)
{
}

Bomber::~Bomber()
{
}

void Bomber::run(IEntity *it)
{
    irr::core::vector3df bombPosition3d = it->getCharacter()->getPosition();
    it->getBombStack()->putBomb(_map, bombPosition3d);
    boost::this_thread::sleep_for(boost::chrono::seconds(3));
    blastNorth(it, bombPosition3d);
    blastSouth(it, bombPosition3d);
    blastEast(it, bombPosition3d);
    blastWest(it, bombPosition3d);
    it->getBombStack()->explodeBomb(_map, it, bombPosition3d);
    clearMapAfterBlast(it, bombPosition3d);
    giveNewBombInInventory(it);
    boost::this_thread::yield();
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
        return (true);
    return (false);
}

void Bomber::putBomb(IEntity *it)
{
    irr::core::vector3df bombPosition3d = it->getCharacter()->getPosition();

    if (canPutBomb(it) == true && hasEnoughBombToPut(it) == true) {
        epicenter(it, bombPosition3d);
        removeBombFromInventory(it);
        boost::thread thr = boost::thread(boost::bind(&Bomber::run, this, it));
        thr.detach();
    }
}

void Bomber::epicenter(IEntity *it, irr::core::vector3df bombPosition3d)
{
    _map->getBombMap()[squareWhereBombIs(bombPosition3d, _map).x][squareWhereBombIs(bombPosition3d, _map).y] = bombState::bomb;
}

void Bomber::blastNorth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[xVisual + i][yVisual] == blockState::unbreakable)
            break;
        else if (_map->getMap()[xVisual + i][yVisual] == blockState::breakable)
            _map->getMap()[xVisual + i][yVisual] = blockState::empty;
            _map->getBombMap()[xVisual + i][yVisual] = bombState::clear;
            _loadMap->getVisualMap()[xVisual + i][yVisual]->setVisible(false);
    }
}

void Bomber::blastSouth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[xVisual - i][yVisual] == blockState::unbreakable)
            break;
        else if (_map->getMap()[xVisual - i][yVisual] == blockState::breakable)
            _map->getMap()[xVisual - i][yVisual] = blockState::empty;
            _map->getBombMap()[xVisual - i][yVisual] = bombState::clear;
            _loadMap->getVisualMap()[xVisual - i][yVisual]->setVisible(false);
    }
}

void Bomber::blastEast(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[xVisual][yVisual + i] == blockState::unbreakable)
            break;
        else if (_map->getMap()[xVisual][yVisual + i] == blockState::breakable)
            _map->getMap()[xVisual][yVisual + i] = blockState::empty;
            _map->getBombMap()[xVisual][yVisual + i] = bombState::clear;
            _loadMap->getVisualMap()[xVisual][yVisual + i]->setVisible(false);
    }
}

void Bomber::blastWest(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[xVisual][yVisual - i] == blockState::unbreakable)
            break;
        else if (_map->getMap()[xVisual][yVisual - i] == blockState::breakable)
            _map->getMap()[xVisual][yVisual - i] = blockState::empty;
            _map->getBombMap()[xVisual][yVisual - i] = bombState::clear;
            _loadMap->getVisualMap()[xVisual][yVisual - i]->setVisible(false);
    }
}

void Bomber::clearMapAfterBlast(IEntity *it, irr::core::vector3df bombPosition3d)
{
    _map->getBombMap()[squareWhereBombIs(bombPosition3d, _map).x][squareWhereBombIs(bombPosition3d, _map).y] = bombState::clear;
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