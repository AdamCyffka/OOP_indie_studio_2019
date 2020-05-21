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
	AI(Character *, int);

	void kill() override;
	void move() override;
	void run() override;
	void putBomb() override;

	int getFirePower() override;
	int getBombAmount() override;
	int getSpeed();
	bool getWallPass() override;
	bool getBombPass() override;
	int getEntityNumber() override;
	int getScore() override;
	Character *getCharacter() override;
	void moveTo(Move) override;
	bool isAlive() override;

	private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	Character *_character;

	int _firePower;
	int _bombAmount;
	int _speed;
	bool _wallPass;
	bool _bombPass;
};

#endif /* !IA_HPP_ */