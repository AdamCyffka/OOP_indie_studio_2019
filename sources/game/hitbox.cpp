/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** hitbox.cpp
*/

#include "hitbox.hpp"

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

Point squareWherePlayerIs(IEntity *entity, Map *map)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();
	//std::cout << characterPosition.X << " " << characterPosition.Y << " " << characterPosition.Z << std::endl;
	Point point = {0, 0};
	float overlap = 0.0;

	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			if (overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock) > overlap)
			{
				//Je check si l'overLap du bloc et plus grand que celui que j'avais si c'est le cas je remplace les coordonnées
				overlap = overLap(characterPosition.X, characterPosition.Z, xBlock, zBlock);
				point = {int(i), int(j)};
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

bool canMove(IEntity *entity, Map *map, side direction)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();
	Point point = {squareWherePlayerIs(entity, map).x, squareWherePlayerIs(entity, map).y};

	switch (direction)
	{
	case north:
		characterPosition.X += 1.0f;
		break;
	case south:
		characterPosition.X -= 1.0f;
		break;
	case east:
		characterPosition.Z -= 1.0f;
		break;
	case west:
		characterPosition.Z += 1.0f;
		break;
	}
	//std::cout << entity->getCharacter()->getModelInfos().name << std::endl;
	//std::cout << squareWherePlayerIs(entity, map).x << " " << squareWherePlayerIs(entity, map).y << std::endl;
	for (unsigned int i = 0; i < map->getMap().size(); ++i)
	{
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			//x + (-10 * i) = position X inGame [1][1] = -450
			//z + (-10 * j) = position Z inGame [1][1] = 780

			//Pour les collisions je pars du principe que le x et Z sont en haut à gauche de l'élèment
			if (characterPosition.X == xBlock && characterPosition.Z == zBlock) // si == alors c'est good le character n'est aps dans le bloc
			{
				//std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is in position " << i << " " << j << std::endl;
			}
			if (characterHitBoxTouchBlock(characterPosition.X, characterPosition.Z, xBlock, zBlock))
			{
				if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !entity->getWallPass()))
				{
					if ((direction == side::south || direction == side::north) && j == point.y)
						return false;
					if ((direction == side::east || direction == side::west) && i == point.x)
						return false;
				}
			}
			/*if ((xBlock == characterPosition.X || zBlock == characterPosition.Z)							// Si le bloc est sur un des axes du character
				|| ((isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock, 10.0))				//check le côté haut gauche
					|| isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock, 10.0))) //check le côté bas droit
			{
				if (map->getMap()[i][j] == unbreakable || (map->getMap()[i][j] == breakable && !entity->getWallPass()))
				{
					return false;
				}
				/*
				if (characterHitBoxTouchBlock(characterPosition.X, characterPosition.Z, xBlock, zBlock))
				{	//Check Hitbox for bombs
					//					std::cout << "Hitbox touch" << std::endl;
				}
				if (!getNextPosIsValid(characterPosition, map, i, j, direction, entity->getWallPass(), xBlock, zBlock)) //check that next block is walkable
					return false;
				//				std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is inside: " << i << " " << j << std::endl;
				
			}*/
		}
	}
	//std::cout << "You can move"  << std::endl;
	return true;
}