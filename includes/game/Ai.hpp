/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Ai
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "IEntity.hpp"
#include "Map.hpp"

class AI : public IEntity {
	public:
	AI(Character *, int, Map *);

	void kill() override;
	void run() override;
	void putBomb() override;

	int getFirePower() override;
	int getBombAmount() override;
	int getSpeed() override;
	bool getWallPass() override;
	bool getBombPass() override;
	int getEntityNumber() override;
	void setScore(int) override;
	int getScore() override;
	void setWinNumber(int) override;
	int getWinNumber() override;
	Character *getCharacter() override;
	void moveTo(side) override;
	bool isAlive() override;

	private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	int _winNumber;
	Character *_character;
	Map *_map;

	int _firePower;
	int _bombAmount;
	int _speed;
	bool _wallPass;
	bool _bombPass;
};

#endif /* !IA_HPP_ */