/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "GameCore.hpp"
//#include "hitbox.cpp" //TODO REMOVE

Player::Player(Character *character, const Key_mouvement &input, int entityNumber, Map *map, GameCore *gameCore, Bomber *bomb) : _isAlive(false), _entityNumber(entityNumber), _map(map), _gameCore(gameCore),
	_score(0), _winNumber(0), _character(character), _bomb(bomb), _input(input), _firePower(1), _bombAmount(1), _speed(3), _wallPass(false), _bombPass(false)
{
}

void Player::kill()
{
	_character->setState(Character::dead);
}

void Player::run(Key_mouvement input)
{
	//	std::cout << _map->getPlayerPosition(_entityNumber).first << " " << _map->getPlayerPosition(_entityNumber).second << std::endl;
	if (isAlive()) {
		switch (input) {
		case Right:
			moveTo(east);
			break;
		case Left:
			moveTo(west);
			break;
		case Up:
			moveTo(north);
			break;
		case Down:
			moveTo(south);
			break;
		case Bomb:
			putBomb();
			break;
		case Ia:
			break;
		case None:
			if (_character->getState() != Character::idle)
				_character->setState(Character::idle);
			break;
		}
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
	//+x = haut
	//-x = bas
	//+z = gauche
	//-z = droite
//		std::cout << canMove(this, _map, north) << std::endl;
	irr::core::vector3df pos = _character->getPosition();
	switch (direction) {
	case north:
		if (canMove(this, _map, north)) {
			if (_character->getOrientation() != west)
				_character->setOrientation(west);
			if (_character->getState() != Character::running)
				_character->setState(Character::running);
			pos.X += 0.01f * _speed;
			_character->setPosition(pos);
		}
		break;
	case south:
		if (canMove(this, _map, south)) {
			if (_character->getOrientation() != east)
				_character->setOrientation(east);
			if (_character->getState() != Character::running)
				_character->setState(Character::running);
			pos.X -= 0.01f * _speed;
			_character->setPosition(pos);
		}
		break;
	case east:
		if (canMove(this, _map, east)) {
			if (_character->getOrientation() != north)
				_character->setOrientation(north);
			if (_character->getState() != Character::running)
				_character->setState(Character::running);
			pos.Z -= 0.01f * _speed;
			_character->setPosition(pos);
		}
		break;
	case west:
		if (canMove(this, _map, west)) {
			if (_character->getOrientation() != south)
				_character->setOrientation(south);
			if (_character->getState() != Character::running)
				_character->setState(Character::running);
			pos.Z += 0.01f * _speed;
			_character->setPosition(pos);
		}
		break;
	}
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
