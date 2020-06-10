/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** hitbox.cpp
*/

#include <algorithm>
#include "hitbox.hpp"
#include "IEntity.hpp"

int isInside(float x, float z, float xBlock, float zBlock, float degree)
{
	if (x < xBlock && x > xBlock)
		return 1;
	if (z < zBlock && z > zBlock)
		return 1;
	return 0;
}

float overLap(float x, float z, float xBlock, float zBlock)
{
	float x_overLap = std::min(x - 10.0f, xBlock - 10.0f) - std::max(x, xBlock);
	float z_overLap = std::min(z - 10.0f, zBlock - 10.0f) - std::max(z, zBlock);

	return (200 - (x_overLap * z_overLap));
}

bool characterHitBoxTouchBlock(float x, float z, float xBlock, float zBlock)
{
	return overLap(x, z, xBlock, zBlock) >= 5.0;
}

int getPowerUpType(IPowerUps *powerUp)
{
	switch (powerUp->getType()) {
		case PowerUps::BombDown:
			powerUp->die();
			return 1;
		case PowerUps::BombFull:
			powerUp->die();
			return 2;
		case PowerUps::BombPass:
			powerUp->die();
			return 3;
		case PowerUps::BombUp:
			powerUp->die();
			return 4;
		case PowerUps::FireDown:
			powerUp->die();
			return 5;
		case PowerUps::FireFull:
			powerUp->die();
			return 6;
		case PowerUps::FireUp:
			powerUp->die();
			return 7;
		case PowerUps::SpeedDown:
			powerUp->die();
			return 8;
		case PowerUps::SpeedUp:
			powerUp->die();
			return 9;
		case PowerUps::WallPass:
			powerUp->die();
			return 10;
	}
	return 0;
}

int isPowerUpsTaken(std::vector<IPowerUps *> objects, Map *map, IEntity *entity)
{
	Point playerPos = squareWherePlayerIs(entity, map);
	float overlap = 0.0;
	Point point = {0, 0};

	for (auto it : objects) {
		irr::core::vector3df pos = it->getPosition();
		for (unsigned int i = 0; i < map->getMap().size(); ++i) {
			for (unsigned int j = 0; j < map->getMap()[i].size(); ++j) {
				float xBlock = MAP_DEFAULT_X + (-10.0f * i);
				float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
				float tmp = overLap(pos.X, pos.Z, xBlock, zBlock);
				if (tmp > overlap)
				{
					//Je check si l'overLap du bloc et plus grand que celui que j'avais si c'est le cas je remplace les coordonnées
					overlap = tmp;
					point = {int(i), int(j)};
					tmp = overLap(pos.X, pos.Z, xBlock - 10.0f, zBlock);
					if (tmp > overlap)
					{
						overlap = tmp;
						point = {int(i + 1), int(j)};
					}
					tmp = overLap(pos.X, pos.Z, xBlock, zBlock - 10.0f);
					if (tmp > overlap)
					{
						overlap = tmp;
						point = {int(i), int(j + 1)};
					}
					if (point.x == playerPos.x && point.y == playerPos.y) {
						auto index = std::find(objects.begin(), objects.end(), it);
						objects.erase(index);
						return (getPowerUpType(it));
					}
				}
			}
		}
	}
	return 0;
}

Point squareWhereBombIs(irr::core::vector3df bombPosition, Map *map)
{
	Point point = {0, 0};
	float overlap = 0.0;

	if (std::fmod((bombPosition.X - MAP_DEFAULT_X) / -10.0f, 1.0) == 0.0f && std::fmod((bombPosition.Z - MAP_DEFAULT_Z) / -10.0f, 1.0) == 0.0f)
	{
		return Point{int((bombPosition.X - MAP_DEFAULT_X) / -10), int((bombPosition.Z - MAP_DEFAULT_Z) / -10)};
	}
	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			float tmp = overLap(bombPosition.X, bombPosition.Z, xBlock, zBlock);
			if (tmp > overlap)
			{
				//Je check si l'overLap du bloc et plus grand que celui que j'avais si c'est le cas je remplace les coordonnées
				overlap = tmp;
				point = {int(i), int(j)};
				tmp = overLap(bombPosition.X, bombPosition.Z, xBlock - 10.0f, zBlock);
				if (tmp > overlap)
				{
					overlap = tmp;
					point = {int(i + 1), int(j)};
				}
				tmp = overLap(bombPosition.X, bombPosition.Z, xBlock, zBlock - 10.0f);
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
	//std::cout << characterPosition.X << " " << characterPosition.Y << " " << characterPosition.Z << std::endl;
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
				//Je check si l'overLap du bloc et plus grand que celui que j'avais si c'est le cas je remplace les coordonnées
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
	//print de x et z et le pourcentage du perso dans le bloc pour le débug
	//std::cout << point.x << " " << point.y << " " << overlap << std::endl;
	return point;
}

bool getNextPosIsValid(const irr::core::vector3df &characterPosition, Map *map, unsigned int i, unsigned int j, side direction, bool wallPass, float xBlock, float zBlock)
{
	switch (direction)
	{
	case north:
		if (isInside(characterPosition.X + 1.0f, characterPosition.Z, xBlock, zBlock, 1.0))
		{
			if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !wallPass))
				return false;
		}
		break;
	case south:
		if (isInside(characterPosition.X - 1.0f, characterPosition.Z, xBlock, zBlock, 1.0))
		{
			if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !wallPass))
				return false;
		}
		break;
	case east:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock, 10.0))
		{
			if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !wallPass))
				return false;
		}
		break;
	case west:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock, 10.0))
		{
			if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !wallPass))
				return false;
		}
		break;
	}
	return true;
}

bool canAiMove(IEntity *entity, Map *map, side direction)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();
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
		break;
	}
	//&& map->getBombMap()[point.x][point.y] != bombState::bomb
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
	Point point = {squareWherePlayerIs(entity, map).x, squareWherePlayerIs(entity, map).y};
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
	//std::cout << "Position: " << squareWherePlayerIs(entity, map).x << " " << squareWherePlayerIs(entity, map).y << std::endl;
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
				{
					return false;
					//std::cout << i << " " << j << std::endl;
					if (i == 0 || j == 0)
						return false;
					if (direction == side::south || direction == side::north)
					{
						if (j == point.y)
							return false;
						/*if (j == point.y + 1 && overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock + 10 > 5.0))
							return false;
						if (j == point.y - 1 && overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock - 10 > 5.0))
							return false;*/
						//if (overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock + 10 > 5.0)
						//return false;
					}
					if (direction == side::east || direction == side::west)
					{
						if (i == point.x)
							return false;
						/*if (i == point.x + 1 && overLap(characterPosition.X, characterPosition.Z, xBlock - 10, zBlock > 5.0))
							return false;
						if (i == point.x - 1 && overLap(characterPosition.X, characterPosition.Z, xBlock + 10, zBlock > 5.0))
							return false;*/
					}
				}
			}
		}
	}
	return true;
}