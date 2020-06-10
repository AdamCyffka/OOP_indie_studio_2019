/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** hitbox.cpp
*/

#include <algorithm>
#include "hitbox.hpp"
#include "IEntity.hpp"

float overLap(float x, float z, float xBlock, float zBlock)
{
	float x_overLap = std::min(x - 10.0f, xBlock - 10.0f) - std::max(x, xBlock);
	float z_overLap = std::min(z - 10.0f, zBlock - 10.0f) - std::max(z, zBlock);

	return (200 - (x_overLap * z_overLap));
}

int getPowerUpType(IPowerUps *powerUp, std::vector<IPowerUps *> &objects)
{
	int res = 0;

	switch (powerUp->getType()) {
		case IPowerUps::BombDown:
			powerUp->die();
			res = 1;
			break;
		case IPowerUps::BombFull:
			powerUp->die();
			res = 2;
			break;
		case IPowerUps::BombPass:
			powerUp->die();
			res = 3;
			break;
		case IPowerUps::BombUp:
			powerUp->die();
			res = 4;
			break;
		case IPowerUps::FireDown:
			powerUp->die();
			res = 5;
			break;
		case IPowerUps::FireFull:
			powerUp->die();
			res = 6;
			break;
		case IPowerUps::FireUp:
			powerUp->die();
			res = 7;
			break;
		case IPowerUps::SpeedDown:
			powerUp->die();
			res = 8;
			break;
		case IPowerUps::SpeedUp:
			powerUp->die();
			res = 9;
			break;
		case IPowerUps::WallPass:
			powerUp->die();
			res = 10;
			break;
	}
	auto index = std::find(objects.begin(), objects.end(), powerUp);
	if (index != objects.end()) {
		objects.erase(index);
	}
	return res;
}

int isPowerUpsTaken(std::vector<IPowerUps *> &objects, Map *map, IEntity *entity)
{
	Point playerPos = squareWherePlayerIs(entity, map);
	Point objPos;

	for (auto it : objects)
	{
		objPos = squareWhereObjectIs(it->getPosition(), map);
		if (objPos.x == playerPos.x && objPos.y == playerPos.y) {
			auto index = std::find(objects.begin(), objects.end(), it);
			if (index != objects.end()) {
				return (getPowerUpType(it, objects));
			}
		}
	}
	return 0;
}

Point squareWhereObjectIs(irr::core::vector3df objectPosition, Map *map)
{
	Point point = {0, 0};
	float overlap = 0.0;

	if (std::fmod((objectPosition.X - MAP_DEFAULT_X) / -10.0f, 1.0) == 0.0f && std::fmod((objectPosition.Z - MAP_DEFAULT_Z) / -10.0f, 1.0) == 0.0f)
	{
		return Point{int((objectPosition.X - MAP_DEFAULT_X) / -10), int((objectPosition.Z - MAP_DEFAULT_Z) / -10)};
	}
	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			float tmp = overLap(objectPosition.X, objectPosition.Z, xBlock, zBlock);
			if (tmp > overlap)
			{
				overlap = tmp;
				point = {int(i), int(j)};
				tmp = overLap(objectPosition.X, objectPosition.Z, xBlock - 10.0f, zBlock);
				if (tmp > overlap)
				{
					overlap = tmp;
					point = {int(i + 1), int(j)};
				}
				tmp = overLap(objectPosition.X, objectPosition.Z, xBlock, zBlock - 10.0f);
				if (tmp > overlap)
				{
					overlap = tmp;
					point = {int(i), int(j + 1)};
				}
				return point;
			}
		}
	}
	return point;
}

Point squareWherePlayerIs(IEntity *entity, Map *map)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();
	Point point = {0, 0};
	float overlap = 0.0;

	if (std::fmod((characterPosition.X - MAP_DEFAULT_X) / -10.0f, 1.0) == 0.0f && std::fmod((characterPosition.Z - MAP_DEFAULT_Z) / -10.0f, 1.0) == 0.0f)
	{
		return Point{int((characterPosition.X - MAP_DEFAULT_X) / -10), int((characterPosition.Z - MAP_DEFAULT_Z) / -10)};
	}
	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			float tmp = overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock);
			if (tmp > overlap)
			{
				overlap = tmp;
				point = {int(i), int(j)};
				tmp = overLap(characterPosition.X, characterPosition.Z, xBlock - 10.0f, zBlock);
				if (tmp > overlap)
				{
					overlap = tmp;
					point = {int(i + 1), int(j)};
				}
				tmp = overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock - 10.0f);
				if (tmp > overlap)
				{
					overlap = tmp;
					point = {int(i), int(j + 1)};
				}
				return point;
			}
		}
	}
	return point;
}

bool canAiMove(IEntity *entity, Map *map, side direction)
{
	Point point = squareWherePlayerIs(entity, map);
	Point nextPoint = {point.x, point.y};
	std::map<int, std::map<int, bombState>> tmpBombMap;

	for (unsigned int i = 0; i < map->getBombMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getBombMap()[i].size(); ++j)
		{
			tmpBombMap[i][j] = map->getBombMap()[i][j];
		}
	}
	for (unsigned int i = 0; i < map->getBombMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getBombMap()[i].size(); ++j)
		{
			if (map->getBombMap()[i][j] == bomb) {
				tmpBombMap[i + 1][j] = bomb;
				tmpBombMap[i][j + 1] = bomb;
				tmpBombMap[i + 2][j] = bomb;
				tmpBombMap[i][j + 2] = bomb;
				tmpBombMap[i - 1][j] = bomb;
				tmpBombMap[i][j - 1] = bomb;
				tmpBombMap[i - 2][j] = bomb;
				tmpBombMap[i][j - 2] = bomb;
			}
		}
	}
	switch (direction)
	{
	case north:
		nextPoint.x--;
		break;
	case south:
		nextPoint.x++;
		break;
	case east:
		nextPoint.y++;
		break;
	case west:
		nextPoint.y--;
		break;
	default:
		return false;
	}
	if (map->getMap()[nextPoint.x][nextPoint.y] == unbreakable || (map->getMap()[nextPoint.x][nextPoint.y] == breakable && !entity->getWallPass()))
		return false;
	if (map->getBombMap()[nextPoint.x][nextPoint.y] == bomb && !entity->getBombPass())
		return false;
	if (tmpBombMap[nextPoint.x][nextPoint.y] == bomb) {
		if (tmpBombMap[point.x][point.y] == clear
		|| tmpBombMap[point.x + 1][point.y] == clear
		|| tmpBombMap[point.x][point.y + 1] == clear
		|| tmpBombMap[point.x][point.y - 1] == clear
		|| tmpBombMap[point.x - 1][point.y] == clear)
			return false;
	}
	for (unsigned int j = 0; j < map->getBombMap()[nextPoint.x].size(); ++j)
	{
		if (map->getBombMap()[nextPoint.x][j] == bombState::bomb && (map->getBombMap()[point.x][point.y] >= map->getBombMap()[nextPoint.x][j] - 2 ||
		map->getBombMap()[point.x][point.y] > map->getBombMap()[nextPoint.x][j] + 2)
		&& tmpBombMap[point.x][point.y] != bomb)
		{
			return false;
		}
	}
	for (unsigned int i = 0; i < map->getBombMap().size(); ++i)
	{
		if (map->getBombMap()[i][nextPoint.y] == bombState::bomb && (map->getBombMap()[point.x][point.y] < map->getBombMap()[i][nextPoint.y] - 2 ||
		map->getBombMap()[point.x][point.y] > map->getBombMap()[i][nextPoint.y] + 2)
		&& tmpBombMap[point.x][point.y] != bomb)
		{
			return false;
		}
	}
	return true;
}

bool canMove(IEntity *entity, Map *map, side direction, bool checkState)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();
	float hitBoxValue = 10.0f;

	if (checkState && entity->getCharacter()->getState() != Character::state::idle)
		return false;
	switch (direction)
	{
	case north:
		characterPosition.X += hitBoxValue;
		break;
	case south:
		characterPosition.X -= hitBoxValue;
		break;
	case east:
		characterPosition.Z -= hitBoxValue;
		break;
	case west:
		characterPosition.Z += hitBoxValue;
		break;
	}
	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);

			if (overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock) > 0.0f)
			{
				if (map->getBombMap()[i][j] == bomb && !entity->getBombPass())
					return false;
				if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !entity->getWallPass()))
					return false;
			}
		}
	}
	return true;
}