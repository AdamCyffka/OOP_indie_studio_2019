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
#include "hitbox.hpp"

class AI : public IEntity
{
public:
	AI(Character *, int, Map *, std::vector<IEntity *> entities);

	void kill() final;
	void run(Key_mouvement) final;
	void run(Key_mouvement input, std::vector<IEntity *> entities);
	void putBomb() final;

	void setFirePower(int) final;
	int getFirePower() final;
	void setBombAmount(int) final;
	int getBombAmount() final;
	void setSpeed(int) final;
	int getSpeed() final;
	void setWallPass(bool) final;
	bool getWallPass() final;
	void setBombPass(bool) final;
	bool getBombPass() final;
	void setEntityNumber(int) final;
	int getEntityNumber() final;
	void setScore(int) final;
	int getScore() final;
	void setWinNumber(int) final;
	int getWinNumber() final;
	Character *getCharacter() final;
	void moveTo(side) final;
	void setIsAlive(bool) final;
	bool isAlive() final;
	Key_mouvement getInput() final;
	void setInput(Key_mouvement input) final;

	bool isSafe();
	bool canMoveToTarget(std::vector<IEntity *> entities);

private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	int _winNumber;
	Character *_character;
	Map *_map;
	std::vector<IEntity *> _entities;
	Key_mouvement wantedMovement;

	int _firePower;
	int _bombAmount;
	int _speed;
	bool _wallPass;
	bool _bombPass;
};

#endif /* !IA_HPP_ */