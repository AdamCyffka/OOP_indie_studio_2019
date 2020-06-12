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
#include "Core.hpp"

Bomber::Bomber(Map *map, LoadMap *loadMap, GameCore *gameCore, Core *core): _radius(2), _delay(TIMER), _map(map), _loadMap(loadMap), _gameCore(gameCore), _isBlast(false), _core(core)
{
}

Bomber::~Bomber()
{
}

void Bomber::killEntity(IEntity *entity)
{
    entity->setIsAlive(false);
    if (Character *character = entity->getCharacter()) {
        character->setState(Character::state::dying);
        boost::this_thread::sleep_for(boost::chrono::milliseconds(2500));
        character->setVisibility(false);
    }
}

void Bomber::run(IEntity *it)
{
    irr::core::vector3df bombPosition3d = it->getCharacter()->getPosition();
    it->getBombStack()->putBomb(_map, bombPosition3d);
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1500));
    blastNorth(it, bombPosition3d);
    blastSouth(it, bombPosition3d);
    blastEast(it, bombPosition3d);
    blastWest(it, bombPosition3d);
    std::vector<Point> deadZone = it->getBombStack()->explodeBomb(_map, it, bombPosition3d);
    clearMapAfterBlast(it, bombPosition3d);
    std::vector<IEntity *> killedEntities = isKilledByBomb(deadZone, it, bombPosition3d);
    for (auto entity : killedEntities) {
        boost::thread thr = boost::thread(boost::bind(&Bomber::killEntity, this, entity));
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
        setRadius(it->getFirePower() + 1);
        epicenter(it, bombPosition3d);
        boost::thread thr = boost::thread(boost::bind(&Bomber::run, this, it));
        thr.detach();
    }
}

void Bomber::epicenter(IEntity *it, irr::core::vector3df bombPosition3d)
{
    _map->getBombMap()[squareWhereObjectIs(bombPosition3d, _map).x][squareWhereObjectIs(bombPosition3d, _map).y] = bombState::bomb;
}

void Bomber::blastSouth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereObjectIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereObjectIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual + i][yVisual] == breakable)
		{
			_map->getMap()[xVisual + i][yVisual] = blockState::empty;
			_map->getBombMap()[xVisual + i][yVisual] = bombState::clear;
			_loadMap->getVisualMap()[xVisual + i][yVisual]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * (xVisual + i)), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (yVisual * -10.0f)};
            _gameCore->addPowerUps(pos);
			break;
		} else if (_map->getMap()[xVisual + i][yVisual] == unbreakable)
			break;
	}
}

void Bomber::blastNorth(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereObjectIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereObjectIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual - i][yVisual] == breakable)
		{
			_map->getMap()[xVisual - i][yVisual] = blockState::empty;
			_map->getBombMap()[xVisual - i][yVisual] = bombState::clear;
			_loadMap->getVisualMap()[xVisual - i][yVisual]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * (xVisual - i)), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (yVisual * -10.0f)};
            _gameCore->addPowerUps(pos);
			break;
		} else if (_map->getMap()[xVisual - i][yVisual] == unbreakable)
			break;
	}
}

void Bomber::blastEast(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereObjectIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereObjectIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual][yVisual + i] == breakable)
		{
			_map->getMap()[xVisual][yVisual + i] = blockState::empty;
			_map->getBombMap()[xVisual][yVisual + i] = bombState::clear;
			_loadMap->getVisualMap()[xVisual][yVisual + i]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * xVisual), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (-10.0f * (yVisual + i))};
            _gameCore->addPowerUps(pos);
			break;
		} else if (_map->getMap()[xVisual][yVisual + i] == unbreakable)
			break;
	}
}

void Bomber::blastWest(IEntity *it, irr::core::vector3df bombPosition3d)
{
    auto xVisual = squareWhereObjectIs(bombPosition3d, _map).x;
    auto yVisual = squareWhereObjectIs(bombPosition3d, _map).y;

	for (int i = 1; i != _radius; i++)
	{
		if (_map->getMap()[xVisual][yVisual - i] == breakable)
		{
			_map->getMap()[xVisual][yVisual - i] = blockState::empty;
			_map->getBombMap()[xVisual][yVisual - i] = bombState::clear;
			_loadMap->getVisualMap()[xVisual][yVisual - i]->setVisible(false);
            irr::core::vector3df pos = {MAP_DEFAULT_X + (-10.0f * xVisual), MAP_DEFAULT_Y + 2, MAP_DEFAULT_Z + (-10.0f * (yVisual - i))};
            _gameCore->addPowerUps(pos);
			break;
		} else if (_map->getMap()[xVisual][yVisual - i] == unbreakable)
			break;
	}
}

void Bomber::clearMapAfterBlast(IEntity *it, irr::core::vector3df bombPosition3d)
{
    _map->getBombMap()[squareWhereObjectIs(bombPosition3d, _map).x][squareWhereObjectIs(bombPosition3d, _map).y] = bombState::clear;
}


std::vector<IEntity *> Bomber::isKilledByBomb(std::vector<Point> deadZone, IEntity *killer, irr::core::vector3df bombPosition3d)
{
    std::vector<IEntity *> toReturn;
    for (auto entity : _entities) {
        Point characterPosition = squareWherePlayerIs(entity, _map);
        for (Point zone : deadZone)
            if (characterPosition.x == zone.x && characterPosition.y == zone.y)
                toReturn.push_back(entity);
    }
    Point bombPosition = squareWhereObjectIs(bombPosition3d, _map);
    for (auto &bomb : killer->getBombStack()->getStack()) {
        irr::core::vector3df centeredBombPosition3d = {MAP_DEFAULT_X + (-10.0f * bombPosition.x), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * bombPosition.y)};
        if (bomb.first.first->getPosition() == centeredBombPosition3d) {
            bomb.first.first->setVisible(false);
            bomb.first.second = true;
            break;
        }
    }
    return toReturn;
}

int Bomber::getRemainingEntities()
{
	int count = 0;
	for (auto it : _entities) {
		if (it->isAlive()) {
			count++;
		}
	}
	return count;
}