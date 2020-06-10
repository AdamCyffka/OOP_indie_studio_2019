/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "GameCore.hpp"
#include "Bomber.hpp"

Bomber::Bomber(Map *map, LoadMap *loadMap, GameCore *gameCore): _radius(3), _delay(TIMER), _map(map), _loadMap(loadMap), _gameCore(gameCore), _isBlast(false)
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
    std::vector<Point> deadZone = it->getBombStack()->explodeBomb(_map, it, bombPosition3d);
    clearMapAfterBlast(it, bombPosition3d);
    giveNewBombInInventory(it);
    if (isKilledByBomb(it, deadZone)) {
        it->setIsAlive(false);
        if (Character *character = it->getCharacter()) {
            character->setState(Character::state::dying);
            boost::this_thread::sleep_for(boost::chrono::seconds(3));
            character->setVisibility(false);
            character->setState(Character::state::idle);
        }
    }
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
    if (it->getBombAmount() > 0 && it->getBombStack()->bombsAvailable() > 0)
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

void Bomber::blastSouth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual + i][yVisual] == breakable)
		{
			_map->getMap()[xVisual + i][yVisual] = blockState::empty;
			_map->getBombMap()[xVisual + i][yVisual] = bombState::clear;
			_loadMap->getVisualMap()[xVisual + i][yVisual]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * (xVisual + i)), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (yVisual * -10.0f)};
            std::cout << xVisual + i << " " << yVisual << std::endl;
            _gameCore->addBonus(pos);
			break;
		} else if (_map->getMap()[xVisual + i][yVisual] == unbreakable)
			break;
	}
}

void Bomber::blastNorth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual - i][yVisual] == breakable)
		{
			_map->getMap()[xVisual - i][yVisual] = blockState::empty;
			_map->getBombMap()[xVisual - i][yVisual] = bombState::clear;
			_loadMap->getVisualMap()[xVisual - i][yVisual]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * (xVisual - i)), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (yVisual * -10.0f)};
            _gameCore->addBonus(pos);
			break;
		} else if (_map->getMap()[xVisual - i][yVisual] == unbreakable)
			break;
	}
}

void Bomber::blastEast(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual][yVisual + i] == breakable)
		{
			_map->getMap()[xVisual][yVisual + i] = blockState::empty;
			_map->getBombMap()[xVisual][yVisual + i] = bombState::clear;
			_loadMap->getVisualMap()[xVisual][yVisual + i]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * xVisual), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (-10.0f * (yVisual + i))};
            _gameCore->addBonus(pos);
			break;
		} else if (_map->getMap()[xVisual][yVisual + i] == unbreakable)
			break;
	}
}

void Bomber::blastWest(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereBombIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereBombIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual][yVisual - i] == breakable)
		{
			_map->getMap()[xVisual][yVisual - i] = blockState::empty;
			_map->getBombMap()[xVisual][yVisual - i] = bombState::clear;
			_loadMap->getVisualMap()[xVisual][yVisual - i]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * xVisual), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (-10.0f * (yVisual - i))};
            _gameCore->addBonus(pos);
			break;
		} else if (_map->getMap()[xVisual][yVisual - i] == unbreakable)
			break;
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

bool Bomber::isKilledByBomb(IEntity *it, std::vector<Point> deadZone)
{
    Point characterPosition = squareWherePlayerIs(it, _map);
    for (Point zone : deadZone)
        if (characterPosition.x == zone.x && characterPosition.y == zone.y)
            return true;
    return false;
}

void Bomber::animateBomb()
{
}