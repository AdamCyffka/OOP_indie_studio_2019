/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#pragma warning(disable : 4244)

#include "Ai.hpp"
#include "hitbox.hpp"
#include "Bomb.hpp"

AI::AI(Character *character, int entityNumber, Map *map, std::vector<IEntity *> entities, Bomber *bomb) : _isAlive(false), _entityNumber(entityNumber), _map(map), _score(0), _entities(entities), _bomb(bomb), _winNumber(0), _character(character), _firePower(1), _bombAmount(1), _speed(3), _wallPass(false), _bombPass(false)
{
}

void AI::kill()
{
}

void AI::run(Key_mouvement input)
{
	this->moveTo(side::west);
}

void AI::putBomb()
{
	_bomb->putBomb(_entities, this);
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

bool AI::isSafe()
{
	return 1;
}

bool AI::canMoveToTargetX(IEntity *it)
{
	int x = (_character->getPosition().X - MAP_DEFAULT_X) / -10;
	int z = std::min(it->getCharacter()->getPosition().Z, _character->getPosition().Z);
	int zMax = std::max(it->getCharacter()->getPosition().Z, _character->getPosition().Z);
	for (z; z < zMax - 10; z++)
	{
		for (int j = 0; j < MAP_DEFAULT_Y; j++)
		{
			float zBlock = MAP_DEFAULT_Z + (-10.0f * j);
			if (isInside(_character->getPosition().X, z, x, zBlock, 10))
			{
				if (_map->getMap()[x][j] == unbreakable || (_map->getMap()[x][j] == breakable && !_wallPass))
					return false;
			}
		}
	}
	//std::cout << "x: " << x << std::endl;
	return true;
}

bool AI::canMoveToTargetZ(IEntity *it)
{
	int z = (_character->getPosition().Z - MAP_DEFAULT_Z) / -10;
	int x = std::min(it->getCharacter()->getPosition().X, _character->getPosition().X);
	int xMax = std::max(it->getCharacter()->getPosition().X, _character->getPosition().X);
	for (x; x < xMax - 10; x++)
	{
		for (int i = 0; i < MAP_DEFAULT_X; i++)
		{
			float xBlock = MAP_DEFAULT_X + (-10.0f * i);
			if (isInside(_character->getPosition().X, z, xBlock, z, 10))
			{
				if (_map->getMap()[i][z] == unbreakable || (_map->getMap()[i][z] == breakable && !_wallPass))
					return false;
			}
		}
	}
	//std::cout << "z: " << x << std::endl;
	return true;
}

IEntity *AI::canMoveToTarget(std::vector<IEntity *> entities)
{
	for (auto it : entities)
	{
		if (it->getEntityNumber() != this->getEntityNumber())
		{
			if ((it->getCharacter()->getPosition().X == _character->getPosition().X)
			&& canMoveToTargetX(it))
			{
				return it;
			}
			if ((it->getCharacter()->getPosition().Z == _character->getPosition().Z)
			&& canMoveToTargetZ(it))
			{
				return it;
			}
		}
	}
	return nullptr;
}

void AI::actionWithTarget(IEntity *target)
{
	if (_character->getState() != Character::state::idle)
		return;
	if (target->getCharacter()->getPosition().Z == _character->getPosition().Z
	&& target->getCharacter()->getPosition().X == _character->getPosition().X)
	{ 
		return;
	}
	if (target->getCharacter()->getPosition().Z == _character->getPosition().Z)
	{
		int speedMult = 1;
		if (_character->getPosition().X > target->getCharacter()->getPosition().X)
			speedMult = -1;
		_wantedPosition = core::vector3df(_character->getPosition().X + (5 * speedMult), _character->getPosition().Y, _character->getPosition().Z);
		_character->moveTo(_wantedPosition, 1000 - (_speed * 100));
	} else {
		int speedMult = 1;
		if (_character->getPosition().Z > target->getCharacter()->getPosition().Z)
			speedMult = -1;
		_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z + (5 * speedMult));
		_character->moveTo(_wantedPosition, 1000 - (_speed * 100));
	}
}

void AI::checkMovement()
{
	if (_character->getState() != Character::state::idle
	&& _character->getPosition() == _wantedPosition)
	{
		_character->setState(Character::state::idle);
	}
}

void AI::run(Key_mouvement input, std::vector<IEntity *> entities)
{
	this->moveTo(side::west);
	this->checkMovement();

	if (getEntityNumber() == 3)
	{
		// J'appelle la fonction ici seulement pour lakitu
		//squareWherePlayerIs(this, _map);
		if (this->isSafe())
		{
			IEntity *target = canMoveToTarget(entities);
			if (target != nullptr)
			{
				actionWithTarget(target);
				return;
			}
			else
			{
				return;
			}
		}
		else
		{
			return;
		}
	}
}

void AI::moveTo(side side)
{
	if (getEntityNumber() == 2)
	{
		canMove(this, _map, side);
		if (_character->getState() == Character::state::idle && _character->getPosition() != core::vector3df(-460.0f, 308.0f, 620.0f))
		{
			_character->moveTo(core::vector3df(-460.0f, 308.0f, 620.0f), 5000);
		}
		if (_character->getPosition() == core::vector3df(-460.0f, 308.0f, 620.0f) && _character->getState() != Character::state::idle)
		{
			this->putBomb();
			_character->setState(Character::state::idle);
		}
	}
	/*if (getEntityNumber() == 3)
	{
		if (_character->getState() == Character::state::idle && _character->getPosition() != core::vector3df(-550, 308, 770))
		{
			_character->moveTo(core::vector3df(-550, 308, 770), 5000);
		}
		if (_character->getPosition() == core::vector3df(-550, 308, 770) && _character->getState() != Character::state::idle)
		{
			this->putBomb();
			_character->setState(Character::state::idle);
		}
	}*/
	if (getEntityNumber() == 4)
	{
		if (_character->getState() == Character::state::idle && _character->getPosition() != core::vector3df(-550, 308, 630))
		{
			_character->moveTo(core::vector3df(-550, 308, 630), 5000);
		}
		if (_character->getPosition() == core::vector3df(-550, 308, 630) && _character->getState() != Character::state::idle)
		{
			this->putBomb();
			_character->setState(Character::state::idle);
		}
	}
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

void AI::setInput(Key_mouvement input)
{
}
