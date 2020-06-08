/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#pragma warning(disable : 4244)

#include "Ai.hpp"
#include "hitbox.hpp"
#include "Bomber.hpp"
#include "Core.hpp"

AI::AI(Character *character, int entityNumber, Map *map, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::vector<IEntity *> entities, Bomber *bomber)
	: _isAlive(false), _entityNumber(entityNumber), _map(map), _driver(driver), _smgr(smgr), _score(0), _entities(entities),
	  _bomber(bomber), _winNumber(0), _character(character), _firePower(1), _bombAmount(1), _wantedMovement(Key_mouvement::None),
	  _speed(3), _wallPass(false), _bombPass(false)
{
	_bombStack = new BombStack(_driver, _smgr);
	std::srand(std::time(nullptr));
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
	_bombStack->explodeBomb(_map, _character->getPosition());
	_bomber->putBomb(this);
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

BombStack *AI::getBombStack()
{
	return _bombStack;
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
		for (int j = 0; j < MAP_WIDTH; j++)
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
		for (int i = 0; i < MAP_HEIGHT; i++)
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
			if ((it->getCharacter()->getPosition().X == _character->getPosition().X) && canMoveToTargetX(it))
			{
				return it;
			}
			if ((it->getCharacter()->getPosition().Z == _character->getPosition().Z) && canMoveToTargetZ(it))
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
	if (target->getCharacter()->getPosition().Z == _character->getPosition().Z && target->getCharacter()->getPosition().X == _character->getPosition().X)
	{
		return;
	}
	if (target->getCharacter()->getPosition().Z == _character->getPosition().Z)
	{
		int speedMult = 1;
		if (_character->getPosition().X > target->getCharacter()->getPosition().X)
			speedMult = -1;
		_wantedPosition = core::vector3df(_character->getPosition().X + (1 * speedMult), _character->getPosition().Y, _character->getPosition().Z);
		_character->moveTo(_wantedPosition, 800 - (_speed * 100));
	}
	else
	{
		int speedMult = 1;
		if (_character->getPosition().Z > target->getCharacter()->getPosition().Z)
			speedMult = -1;
		_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z + (1 * speedMult));
		_character->moveTo(_wantedPosition, 800 - (_speed * 100));
	}
}

void AI::checkMovement()
{

	if (_character->getState() != Character::state::idle && _character->getPosition() == _wantedPosition)
	{
		bool northB = canAiMove(this, _map, north);
		bool southB = canAiMove(this, _map, south);
		bool eastB = canAiMove(this, _map, east);
		bool westB = canAiMove(this, _map, west);
		_character->setState(Character::state::idle);
		switch (_wantedMovement)
		{
		case Down:
			if (std::rand() % 2)
			{
				if (eastB && westB)
				{
					if (std::rand() % 2)
						_wantedMovement = Left;
					else
						_wantedMovement = Right;
				}
				else if (!eastB && westB)
				{
					_wantedMovement = Left;
				}
				else if (eastB && !westB)
				{
					_wantedMovement = Right;
				}
			}
			break;
		case Up:
			if (std::rand() % 2)
			{
				if (eastB && westB)
				{
					if (std::rand() % 2)
						_wantedMovement = Left;
					else
						_wantedMovement = Right;
				}
				else if (!eastB && westB)
				{
					_wantedMovement = Left;
				}
				else if (eastB && !westB)
				{
					_wantedMovement = Right;
				}
			}
			break;
		case Left:
			if (std::rand() % 2)
			{
				if (southB && northB)
				{
					if (std::rand() % 2)
						_wantedMovement = Up;
					else
						_wantedMovement = Down;
				}
				else if (!southB && northB)
				{
					_wantedMovement = Up;
				}
				else if (southB && !northB)
				{
					_wantedMovement = Down;
				}
			}
			break;
		case Right:
			if (std::rand() % 2)
			{
				if (southB && northB)
				{
					if (std::rand() % 2)
						_wantedMovement = Up;
					else
						_wantedMovement = Down;
				}
				else if (!southB && northB)
				{
					_wantedMovement = Up;
				}
				else if (southB && !northB)
				{
					_wantedMovement = Down;
				}
			}
			break;
		default:
			break;
		}
	}
}

void AI::run(Key_mouvement input, std::vector<IEntity *> entities)
{
	this->putBomb();
	this->moveTo(side::west);
	this->checkMovement();
	return;

	/*if (getEntityNumber() == 3)
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
	}*/
	if (_wantedMovement == Key_mouvement::None)
	{
		bool northB = canAiMove(this, _map, north);
		bool southB = canAiMove(this, _map, south);
		bool eastB = canAiMove(this, _map, east);
		bool westB = canAiMove(this, _map, west);

		Key_mouvement nextMove = None;
		if (southB && northB && eastB && westB)
			nextMove = Key_mouvement(std::rand() % 4 + 1);

		if (southB && !northB && !eastB && !westB)
			_wantedMovement = Down;
		if (!southB && northB && !eastB && !westB)
			_wantedMovement = Up;
		if (!southB && !northB && eastB && !westB)
			_wantedMovement = Right;
		if (!southB && !northB && !eastB && westB)
			_wantedMovement = Left;
		if (!southB && !northB && eastB && westB)
			nextMove = Key_mouvement(std::rand() % 2 + 1);
		if (southB && northB && !eastB && !westB)
			nextMove = Key_mouvement(std::rand() % 4 + 3);

		if (!southB && northB && eastB && westB)
		{
			nextMove = Key_mouvement(std::rand() % 3 + 1);
		}
		if (southB && !northB && eastB && westB)
		{
			if (std::rand() % 3 == 0)
				nextMove = Down;
			else if (std::rand() % 3 == 0)
				nextMove = Right;
			else
				nextMove = Left;
		}
		if (southB && northB && !eastB && westB)
		{
			if (std::rand() % 3 == 0)
				nextMove = Down;
			else if (std::rand() % 3 == 0)
				nextMove = Up;
			else
				nextMove = Left;
		}
		if (southB && northB && eastB && !westB)
		{
			if (std::rand() % 3 == 0)
				nextMove = Down;
			else if (std::rand() % 3 == 0)
				nextMove = Right;
			else
				nextMove = Up;
		}

		if (southB && !northB && !eastB && westB)
		{
			if (std::rand() % 2)
				nextMove = Key_mouvement::Down;
			else
				nextMove = Key_mouvement::Left;
		}
		if (!southB && northB && !eastB && westB)
		{
			if (std::rand() % 2)
				nextMove = Key_mouvement::Up;
			else
				nextMove = Key_mouvement::Left;
		}
		if (!southB && northB && eastB && !westB)
		{
			if (std::rand() % 2)
				nextMove = Key_mouvement::Up;
			else
				nextMove = Key_mouvement::Right;
		}
		if (southB && !northB && eastB && !westB)
		{
			if (std::rand() % 2)
				nextMove = Key_mouvement::Down;
			else
				nextMove = Key_mouvement::Right;
		}

		if (nextMove == Key_mouvement::Down && southB)
			_wantedMovement = nextMove;
		if (nextMove == Key_mouvement::Up && northB)
			_wantedMovement = nextMove;
		if (nextMove == Key_mouvement::Left && westB)
			_wantedMovement = nextMove;
		if (nextMove == Key_mouvement::Right && eastB)
			_wantedMovement = nextMove;
	}

	if (_character->getState() == Character::state::idle)
	{
		switch (_wantedMovement)
		{
		case Down:
			if (!canAiMove(this, _map, south))
			{
				_wantedMovement = None;
				break;
			}
			_wantedPosition = core::vector3df(_character->getPosition().X - 10, _character->getPosition().Y, _character->getPosition().Z);
			_character->moveTo(_wantedPosition, 300 - (_speed * 10));
			break;
		case Up:
			if (!canAiMove(this, _map, north))
			{
				_wantedMovement = None;
				break;
			}
			_wantedPosition = core::vector3df(_character->getPosition().X + 10, _character->getPosition().Y, _character->getPosition().Z);
			_character->moveTo(_wantedPosition, 300 - (_speed * 10));
			break;
		case Left:
			if (!canAiMove(this, _map, west))
			{
				_wantedMovement = None;
				break;
			}
			_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z + 10);
			_character->moveTo(_wantedPosition, 300 - (_speed * 10));
			break;
		case Right:
			if (!canAiMove(this, _map, east))
			{
				_wantedMovement = None;
				break;
			}
			_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z - 10);
			_character->moveTo(_wantedPosition, 300 - (_speed * 10));
			break;
		default:
			break;
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
