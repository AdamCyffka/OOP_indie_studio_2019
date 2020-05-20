/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "Ai.hpp"

AI::AI(Character *character, int entityNumber) : _isAlive(false), _entityNumber(entityNumber), _score(0), _character(character), _firePower(1), _bombAmount(1), _speed(1), _wallPass(false), _bombPass(false)
{
	std::cout << "created AI" << std::endl;
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

int AI::getFirePower()
{
	return _firePower;
}

int AI::getBombAmount()
{
	return _bombAmount;
}

int AI::getSpeed()
{
	return _speed;
}

bool AI::getWallPass()
{
	return _wallPass;
}

bool AI::getBombPass()
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
