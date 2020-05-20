/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#include "Ai.hpp"

AI::AI(Character *)
{
}

void AI::spawn()
{
}

void AI::kill()
{
}

void AI::move()
{
}

void AI::run()
{
}

void AI::putBomb()
{
}

Fire AI::getFirePower()
{
    return _firePower;
}

Bomb AI::getBombAmount()
{
    return _bombAmount;
}

Speed AI::getSpeed()
{
    return _speed;
}

WallPass AI::getWallPass()
{
    return _wallPass;
}

BombPass AI::getBombPass()
{
    return _bombPass;
}

int AI::getEntityNumber()
{
    return _entityNumber;
}

int AI::getScore()
{
    return _score;
}

Character *AI::getCharacter()
{
    return _character;
}

void AI::moveTo(Move)
{
}

bool AI::isAlive()
{
    return _isAlive;
}