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

class AI : public IEntity
{
public:
	AI(Character *, int, Map *);

	void kill() override;
	void run() override;
	void putBomb() override;

	void setFirePower(int) override;
	int getFirePower() override;
	void setBombAmount(int) override;
	int getBombAmount() override;
	void setSpeed(int) override;
	int getSpeed() override;
	void setWallPass(bool) override;
	bool getWallPass() override;
	void setBombPass(bool) override;
	bool getBombPass() override;
	void setEntityNumber(int) override;
	int getEntityNumber() override;
	void setScore(int) override;
	int getScore() override;
	void setWinNumber(int) override;
	int getWinNumber() override;
	Character *getCharacter() override;
	void moveTo(side) override;
	void setIsAlive(bool) override;
	bool isAlive() override;
	void setInput(Key_mouvement) override;
	Key_mouvement getInput() override;

	std::pair<int, int> getPosition();
	void setPosition(std::pair<int, int>);
	void findPosition();

private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	int _winNumber;
	Character *_character;
	Map *_map;
	std::pair<int, int> _position;

	int _firePower;
	int _bombAmount;
	int _speed;
	bool _wallPass;
	bool _bombPass;
};

#endif /* !IA_HPP_ */