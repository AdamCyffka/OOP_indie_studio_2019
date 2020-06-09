/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "Player.hpp"
#include "GameCore.hpp"

Player::Player(Character *character, const Key_mouvement &input, int entityNumber, Map *map, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, GameCore *gameCore, Bomber *bomb)
	: _isAlive(false), _entityNumber(entityNumber), _map(map), _driver(driver), _smgr(smgr), _gameCore(gameCore), _score(0), _winNumber(0), _character(character), _bomb(bomb), _input(input),
	_firePower(1), _bombAmount(1), _speed(5), _wallPass(false), _bombPass(false)
{
	_bombStack = new BombStack(_driver, _smgr);
}

void Player::kill()
{
	_character->setState(Character::dead);
}

void Player::run(Key_mouvement input)
{
	if (isAlive()) {
		for (auto it : _character->getAnimators()) {
			if (it->hasFinished())
				_savedInput = Ia;
		}
		if (input != _savedInput) {
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
				_character->removeAnimators();
				_character->setState(Character::idle);
				break;
			}
			_savedInput = input;
		}
	}
}

void Player::putBomb()
{
	_bomb->putBomb(this);
}

void Player::setFirePower(int firePower)
{
	_firePower += firePower;
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
	_speed += speed;
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

BombStack *Player::getBombStack()
{
	return _bombStack;
}

void Player::moveTo(side direction)
{
	irr::core::vector3df pos = _character->getPosition();
	irr::u32 distanceTravel = 10.0f;
	irr::u32 speedTime = 1000.0f / _speed;

	switch (direction) {
	case north:
		if (canMove(this, _map, north)) {
			pos.X += distanceTravel;
			_character->moveTo(pos, speedTime);
		}
		break;
	case south:
		if (canMove(this, _map, south)) {
			pos.X -= distanceTravel;
			_character->moveTo(pos, speedTime);
		}
		break;
	case east:
		if (canMove(this, _map, east)) {
			pos.Z -= distanceTravel;
			_character->moveTo(pos, speedTime);
		}
		break;
	case west:
		if (canMove(this, _map, west)) {
			pos.Z += distanceTravel;
			_character->moveTo(pos, speedTime);
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
