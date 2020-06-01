/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** hitbox.cpp
*/

#include "hitbox.hpp"

int isInside(float x, float z, float xBlock, float zBlock)
{
	if (x < xBlock && x > xBlock - 10.0f)
		return 1;
	if (z < zBlock && z > zBlock - 10.0f)
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
	if (overLap(x, z, xBlock, zBlock) >= 20.0) //20 is the pourcent of the character's body you need for the hitbox
		return true;
	return false;
}

bool getNextPosIsValid(const irr::core::vector3df &characterPosition, Map *map, unsigned int i, unsigned int j, side direction, bool wallPass, float xBlock, float zBlock)
{
	switch (direction) {
	case north:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock) || isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock)) {
			if (map->getMap()[i][j] == empty || (map->getMap()[i][j] == breakable && wallPass))
				return true;
		}
		break;
	case south:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock) || isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock)) {
			if (map->getMap()[i][j] == empty || (map->getMap()[i][j] == breakable && wallPass))
				return true;
		}
		break;
	case east:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock) || isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock)) {
			if (map->getMap()[i][j] == empty || (map->getMap()[i][j] == breakable && wallPass))
				return true;
		}
		break;
	case west:
		if (isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock) || isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock)) {
			if (map->getMap()[i][j] == empty || (map->getMap()[i][j] == breakable && wallPass))
				return true;
		}
		break;
	}
	return false;
}

bool canMove(IEntity *entity, Map *map, side direction)
{
	irr::core::vector3df characterPosition = entity->getCharacter()->getPosition();

	for (unsigned int i = 0; i < map->getMap().size(); ++i) {
		for (unsigned int j = 0; j < map->getMap()[i].size(); ++j) {
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			//x + (-10 * i) = position X inGame [1][1] = -450
			//z + (-10 * j) = position Z inGame [1][1] = 780

			//Pour les collisions je pars du principe que le x et Z sont en haut à gauche de l'élèment
			if (characterPosition.X == xBlock && characterPosition.Z == zBlock) // si == alors c'est good le character n'est aps dans le bloc
			{
				//std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is in position " << i << " " << j << std::endl;
			}
			if ((xBlock == characterPosition.X || zBlock == characterPosition.Z) // Si le bloc et sur un des axes du character
				&& ((isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock))               //check le côté haut gauche
				|| isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock))) //check le côté bas droit
			{
				if (characterHitBoxTouchBlock(characterPosition.X, characterPosition.Z, xBlock, zBlock)) {//Check Hitbox for bombs
//					std::cout << "Hitbox touch" << std::endl;
				}
				if (!getNextPosIsValid(characterPosition, map, i, j, direction, entity->getWallPass(), xBlock, zBlock)) //check that next block is walkable
					return false;
//				std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is inside: " << i << " " << j << std::endl;
			}
		}
	}
	return true;
}
