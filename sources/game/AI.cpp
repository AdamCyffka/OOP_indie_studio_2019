/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include <chrono>
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
	std::srand((unsigned int)(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())));
	_character->setState(Character::state::idle);
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
	Point point = squareWherePlayerIs(this, _map);
	if ((point.x == 1 && point.y == 1) || (point.x == 1 && point.y == 17) || (point.x == 11 && point.y == 1) || (point.x == 11 && point.y == 17))
		return;
	std::map<int, std::map<int, bombState>> tmpBombMap;

	for (unsigned int i = 0; i < _map->getBombMap().size(); ++i)
	{
		for (unsigned int j = 0; j < _map->getBombMap()[i].size(); ++j)
		{
			tmpBombMap[i][j] = _map->getBombMap()[i][j];
		}
	}
	for (unsigned int i = 0; i < _map->getBombMap().size(); ++i)
	{
		for (unsigned int j = 0; j < _map->getBombMap()[i].size(); ++j)
		{
			if (_map->getBombMap()[i][j] == bomb) {
				tmpBombMap[i + 1][j] = bomb;
				tmpBombMap[i][j + 1] = bomb;
				tmpBombMap[i + 2][j] = bomb;
				tmpBombMap[i][j + 2] = bomb;
				tmpBombMap[i - 1][j] = bomb;
				tmpBombMap[i][j - 1] = bomb;
				tmpBombMap[i - 2][j] = bomb;
				tmpBombMap[i][j - 2] = bomb;
			}
		}
	}
	if (tmpBombMap[point.x][point.y] == bomb || tmpBombMap[point.x + 1][point.y] == bomb ||
	tmpBombMap[point.x][point.y + 1] == bomb || tmpBombMap[point.x - 1][point.y] == bomb || tmpBombMap[point.x][point.y - 1] == bomb
	|| tmpBombMap[point.x + 2][point.y] == bomb ||
	tmpBombMap[point.x][point.y + 2] == bomb || tmpBombMap[point.x - 2][point.y] == bomb || tmpBombMap[point.x][point.y - 2] == bomb)
		return;
	_bomber->putBomb(this);
}

void AI::setFirePower(int firePower)
{
	_firePower += firePower;
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
	_speed += speed;
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

void AI::canHitPlayers(std::vector<IEntity *> entities)
{
	Point point = squareWherePlayerIs(this, _map);
	int hitDistance = 3;

	for (auto it : entities)
	{
		if (it->getEntityNumber() != this->getEntityNumber())
		{
			Point pointTarget = squareWherePlayerIs(it, _map);
			if (point.x == pointTarget.x)
			{
				if (point.y == pointTarget.y || (point.y < pointTarget.y && point.y + hitDistance >= pointTarget.y) || (point.y > pointTarget.y && point.y - hitDistance <= pointTarget.y)) {
					this->putBomb();
				}
			}
			else if (point.y == pointTarget.y)
			{
				if (point.x == pointTarget.x || (point.x < pointTarget.x && point.x + hitDistance >= pointTarget.x) || (point.x > pointTarget.x && point.x - hitDistance <= pointTarget.x))
				{
					this->putBomb();
				}
			}
		}
	}
}

IEntity *AI::canMoveToTarget(std::vector<IEntity *> entities)
{
	for (auto it : entities)
	{
		if (it->getEntityNumber() != this->getEntityNumber())
		{
			return it;
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

void AI::run(Key_mouvement input, std::vector<IEntity *> entities)
{
	//this->putBomb();
	//this->moveTo(side::west);
	if (!isAlive())
		return;
	this->checkMovement();
	this->canHitPlayers(entities);

	if (_wantedMovement == Key_mouvement::None)
	{
		setWantedPositionRandom();
	}

	if (_character->getState() == Character::state::idle)
	{
		movePlayerWithWantedMovement();
	}
}

void AI::moveTo(side side)
{
	if (getEntityNumber() == 2)
	{
		canMove(this, _map, side, false);
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

//Longs functions for AI:

void AI::checkMovement()
{
	if (_character->getState() != Character::state::idle && _character->getPosition() == _wantedPosition)
	{
		bool northB = canAiMove(this, _map, north);
		bool southB = canAiMove(this, _map, south);
		bool eastB = canAiMove(this, _map, east);
		bool westB = canAiMove(this, _map, west);
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
				else
				{
					Point point = squareWherePlayerIs(this, _map);
					if (_map->getMap()[point.x][point.y - 1] == breakable || _map->getMap()[point.x][point.y + 1] == breakable)
						this->putBomb();
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
				else
				{
					Point point = squareWherePlayerIs(this, _map);
					if (_map->getMap()[point.x][point.y - 1] == breakable || _map->getMap()[point.x][point.y + 1] == breakable)
						this->putBomb();
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
				else
				{
					Point point = squareWherePlayerIs(this, _map);
					if (_map->getMap()[point.x - 1][point.y] == breakable || _map->getMap()[point.x + 1][point.y] == breakable)
						this->putBomb();
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
				else
				{
					Point point = squareWherePlayerIs(this, _map);
					if (_map->getMap()[point.x - 1][point.y] == breakable || _map->getMap()[point.x + 1][point.y] == breakable)
						this->putBomb();
				}
			}
			break;
		default:
			break;
		}
		_character->setState(Character::state::idle);
	}
}

void AI::setWantedPositionRandom()
{
	bool northB = canAiMove(this, _map, north);
	bool southB = canAiMove(this, _map, south);
	bool eastB = canAiMove(this, _map, east);
	bool westB = canAiMove(this, _map, west);

	Key_mouvement nextMove = None;
	if (southB && northB && eastB && westB)
		nextMove = Key_mouvement(std::rand() % 4 + 1);

	if (southB && !northB && !eastB && !westB)
	{
		_wantedMovement = Down;
		this->putBomb();
	}
	if (!southB && northB && !eastB && !westB)
	{
		_wantedMovement = Up;
		this->putBomb();
	}
	if (!southB && !northB && eastB && !westB)
	{
		_wantedMovement = Right;
		this->putBomb();
	}
	if (!southB && !northB && !eastB && westB)
	{
		_wantedMovement = Left;
		this->putBomb();
	}
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

void AI::movePlayerWithWantedMovement()
{
	irr::u32 speedTime = 1000 / _speed;

	switch (_wantedMovement)
	{
	case Down:
		if (!canAiMove(this, _map, south))
		{
			_wantedMovement = None;
			break;
		}
		_wantedPosition = core::vector3df(_character->getPosition().X - 10, _character->getPosition().Y, _character->getPosition().Z);
		_character->moveTo(_wantedPosition, speedTime);
		break;
	case Up:
		if (!canAiMove(this, _map, north))
		{
			_wantedMovement = None;
			break;
		}
		_wantedPosition = core::vector3df(_character->getPosition().X + 10, _character->getPosition().Y, _character->getPosition().Z);
		_character->moveTo(_wantedPosition, speedTime);
		break;
	case Left:
		if (!canAiMove(this, _map, west))
		{
			_wantedMovement = None;
			break;
		}
		_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z + 10);
		_character->moveTo(_wantedPosition, speedTime);
		break;
	case Right:
		if (!canAiMove(this, _map, east))
		{
			_wantedMovement = None;
			break;
		}
		_wantedPosition = core::vector3df(_character->getPosition().X, _character->getPosition().Y, _character->getPosition().Z - 10);
		_character->moveTo(_wantedPosition, speedTime);
		break;
	default:
		break;
	}
}