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

#define MAP_DEFAULT_X -440.0f
#define MAP_DEFAULT_Y 308.0f
#define MAP_DEFAULT_Z 790.0f

struct Point { 
    int x, y; 
}; 

bool canMove(IEntity *characterPosition, Map *map, side direction);
Point squareWherePlayerIs(IEntity *entity, Map *map);

#endif
