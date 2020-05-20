/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(Character *character, const Key_mouvement &input, int entityNumber) : _isAlive(false), _entityNumber(entityNumber), _score(0), _character(character), _input(input),_firePower(1), _bombAmount(1), _speed(1), _wallPass(false), _bombPass(false)
{
	std::cout << "created player" << std::endl;
}

void Player::kill()
{
}

void Player::move()
{
}

void Player::run()
{
}

void Player::putBomb()
{
}

int Player::getFirePower()
{
	return _firePower;
}

int Player::getBombAmount()
{
	return _bombAmount;
}

int Player::getSpeed()
{
	return _speed;
}

bool Player::getWallPass()
{
	return _wallPass;
}

bool Player::getBombPass()
{
	return _bombPass;
}

int Player::getEntityNumber()
{
	return _entityNumber;
}

int Player::getScore()
{
	return _score;
}

Character *Player::getCharacter()
{
	return _character;
}

void Player::moveTo(Move)
{
}

bool Player::isAlive()
{
	return _isAlive;
}
