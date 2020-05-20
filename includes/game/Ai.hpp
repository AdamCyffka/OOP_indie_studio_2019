/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "IEntity.hpp"

class AI : public IEntity {
	public:
	AI(Character *);
	~AI() = default;

	void spawn();
	void kill();
	void move();
	void run();
	void putBomb();

	Fire getFirePower();
	Bomb getBombAmount();
	Speed getSpeed();
	WallPass getWallPass();
	BombPass getBombPass();
	int getEntityNumber();
	int getScore();
	Character *getCharacter();
	void moveTo(Move);
	bool isAlive();

	private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	Character *_character;

	Fire _firePower;
	Bomb _bombAmount;
	Speed _speed;
	WallPass _wallPass;
	BombPass _bombPass;
};

#endif /* !IA_HPP_ */