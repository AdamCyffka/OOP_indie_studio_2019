/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "Ai.hpp"

AI::AI(Character *character, int entityNumber, Map *map) : _isAlive(false), _entityNumber(entityNumber), _map(map), _score(0), _winNumber(0),_character(character), _firePower(1), _bombAmount(1), _speed(1), _wallPass(false), _bombPass(false)
{
	std::cout << "created AI" << std::endl;
}

void AI::kill()
{
}

void AI::run()
{
}

void AI::putBomb()
{
}

void AI::setFirePower(int firePower)
{
	_firePower = firePower;
}

int AI::getFirePower()
{
	return _firePower;
}

void AI::setBombAmount(int bombAmount)
{
	_bombAmount = bombAmount;
}

int AI::getBombAmount()
{
	return _bombAmount;
}

void AI::setSpeed(int speed)
{
	_speed = speed;
}

int AI::getSpeed()
{
	return _speed;
}

void AI::setWallPass(bool wallPass)
{
	_wallPass = wallPass;
}

bool AI::getWallPass()
{
	return _wallPass;
}

void AI::setBombPass(bool bombPass)
{
	_bombPass = bombPass;
}

bool AI::getBombPass()
{
	return _bombPass;
}

void AI::setEntityNumber(int entityNumber)
{
	_entityNumber = entityNumber;
}

int AI::getEntityNumber()
{
	return _entityNumber;
}

void AI::setScore(int score)
{
	_score = score;
}

int AI::getScore()
{
	return _score;
}

void AI::setWinNumber(int nb)
{
	_winNumber = nb;
}

int AI::getWinNumber()
{
	return _winNumber;
}

Character *AI::getCharacter()
{
	return _character;
}

void AI::moveTo(side side)
{
}

void AI::setIsAlive(bool isAlive)
{
	_isAlive = isAlive;
}

bool AI::isAlive()
{
	return _isAlive;
}

Key_mouvement AI::getInput()
{
	return Key_mouvement::Ia;
}
