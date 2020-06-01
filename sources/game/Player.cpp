/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "GameCore.hpp"

Player::Player(Character *character, const Key_mouvement &input, int entityNumber, Map *map, GameCore *gameCore) : _isAlive(false), _entityNumber(entityNumber), _map(map), _gameCore(gameCore),
	_score(0), _winNumber(0), _character(character), _input(input), _firePower(1), _bombAmount(1), _speed(1), _wallPass(true), _bombPass(false)
{
}

void Player::kill()
{
	_character->setState(Character::dead);
}

void Player::run()
{
	//+x = haut
	//-x = bas
	//+z = gauche
	//-z = droite
	//	std::cout << _map->getPlayerPosition(_entityNumber).first << " " << _map->getPlayerPosition(_entityNumber).second << std::endl;
	if (isAlive()) {
		auto pos = getCharacter()->getPosition();
	}
}

void Player::putBomb()
{
}

void Player::setFirePower(int firePower)
{
	_firePower = firePower;
}

int Player::getFirePower()
{
	return _firePower;
}

void Player::setBombAmount(int bombAmount)
{
	_bombAmount = bombAmount;
}

int Player::getBombAmount()
{
	return _bombAmount;
}

void Player::setSpeed(int speed)
{
	_speed = speed;
}

int Player::getSpeed()
{
	return _speed;
}

void Player::setWallPass(bool wallPass)
{
	_wallPass = wallPass;
}

bool Player::getWallPass()
{
	return _wallPass;
}

void Player::setBombPass(bool bombPass)
{
	_bombPass = bombPass;
}

bool Player::getBombPass()
{
	return _bombPass;
}

void Player::setEntityNumber(int entityNumber)
{
	_entityNumber = entityNumber;
}

int Player::getEntityNumber()
{
	return _entityNumber;
}

void Player::setScore(int score)
{
	_score = score;
}

int Player::getScore()
{
	return _score;
}

void Player::setWinNumber(int nb)
{
	_winNumber = nb;
}

int Player::getWinNumber()
{
	return _winNumber;
}

Character *Player::getCharacter()
{
	return _character;
}

void Player::moveTo(side direction)
{
	if (_character->getOrientation() != direction)
		_character->setOrientation(direction);
}

void Player::setIsAlive(bool isAlive)
{
	_isAlive = isAlive;
}

bool Player::isAlive()
{
	return _isAlive;
}

Key_mouvement Player::getInput()
{
	return _input;
}

void Player::setInput(Key_mouvement input)
{
	_input = input;
}
