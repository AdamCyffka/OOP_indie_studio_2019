/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "Ai.hpp"

int isInside(float x, float z, float xBlock, float zBlock)
{
	if (x < xBlock && x > xBlock - 10.0)
		return 1;
	if (z < zBlock && z > zBlock - 10.0)
		return 1;
	return 0;
}

float overLap(float x, float z, float xBlock, float zBlock)
{
	float x_overLap = std::min(x - 10.0, xBlock - 10.0) - std::max(x, xBlock);
	float z_overLap = std::min(z - 10.0, zBlock - 10.0) - std::max(z, zBlock);

	return (200 - (x_overLap * z_overLap));
}

bool characterHitBoxTouchBlock(float x, float z, float xBlock, float zBlock)
{
	if (overLap(x, z, xBlock, zBlock) >= 20.0) //20 is the pourcent of the character's body you need for the hitbox
		return true;
	return false;
}

int canMove(core::vector3df characterPosition, Map *map)
{
	int x = -440;
	int y = 308; //Toujours pareil on le laisse ou on le mets en dur ?
	int z = 790;

	for (int i = 0; i < map->getMap().size(); ++i)
	{
		for (int j = 0; j < map->getMap()[i].size(); ++j)
		{
			float xBlock = x + (-10 * i);
			float zBlock = z + (-10 * j);
			//x + (-10 * i) = position X inGame [1][1] = -450
			//z + (-10 * j) = position Z inGame [1][1] = 780

			//Pour les collisions je pars du principe que le x et Z sont en haut à gauche de l'élèment
			if (characterPosition.X == xBlock && characterPosition.Z == zBlock) // si == alors c'est good le character n'est aps dans le bloc
			{
				//std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is in position " << i << " " << j << std::endl;
			}
			if ((xBlock == characterPosition.X || zBlock == characterPosition.Z) // Si le bloc et sur un des axes du character
				&&
				((isInside(characterPosition.X, characterPosition.Z, xBlock, zBlock))			   //check le côté haut gauche
				 || isInside(characterPosition.X - 10, characterPosition.Z - 10, xBlock, zBlock))) //check le côté bas droit
			{
				if (characterHitBoxTouchBlock(characterPosition.X, characterPosition.Z, xBlock, zBlock)) //Check Hitbox for bombs
					std::cout << "Hitbox touch" << std::endl;
				//std::cout << "The character with the position " << characterPosition.X << " " << characterPosition.Z << " is inside: " << i << " " << j << std::endl;
			}
		}
	}
	return 1;
}

AI::AI(Character *character, int entityNumber, Map *map) : _isAlive(false), _entityNumber(entityNumber), _map(map), _score(0), _winNumber(0), _character(character), _firePower(1), _bombAmount(1), _speed(1), _wallPass(false), _bombPass(false)
{
	std::cout << "created AI" << std::endl;
}

void AI::kill()
{
}

void AI::run()
{
	this->moveTo(side::west);
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
	if (getEntityNumber() == 2)
	{
		canMove(_character->getPosition(), _map);
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
	if (getEntityNumber() == 3)
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
	}
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
