/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** hitbox.hpp
*/

#ifndef HITBOX_HPP
#define HITBOX_HPP

#include "Map.hpp"
#include "irrlicht.h"
#include "side.hpp"
#include "IEntity.hpp"
#include "IPowerUps.hpp"

#define MAP_DEFAULT_X -440.0f
#define MAP_DEFAULT_Y 308.0f
#define MAP_DEFAULT_Z 790.0f

struct Point {
    int x, y;
}; 

bool canMove(IEntity *characterPosition, Map *map, side direction);
bool canAiMove(IEntity *entity, Map *map, side direction);

int isPowerUpsTaken(std::vector<IPowerUps *> objects, Map *map, IEntity *entity);

Point squareWherePlayerIs(IEntity *entity, Map *map);
Point squareWhereBombIs(irr::core::vector3df, Map *map);
int isInside(float x, float z, float xBlock, float zBlock, float degree);

#endif
