/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#ifndef AI_HPP_
#define AI_HPP_

#include "IEntity.hpp"
#include "Map.hpp"
#include "hitbox.hpp"
#include "Bomber.hpp"

class Core;
class AI : public IEntity
{
public:
	AI(Character *character, int entityNumber, Map *map,
	irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr,
	std::vector<IEntity *> entities, GameCore *gameCore, Bomber *bomber, Core *core, bool isSave);

	void run(Key_mouvement) final;
	void run(Key_mouvement input, std::vector<IEntity *> entities);
	void putBomb() final;

	void setPowerUps() final;
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
	BombStack *getBombStack() final;
	Character *getCharacter() final;
	void moveTo(side) final;
	void setIsAlive(bool) final;
	bool isAlive() final;
	Key_mouvement getInput() final;
	void setInput(Key_mouvement input) final;

	void canHitPlayers(std::vector<IEntity *> entities);
	void checkMovement();
	void checkMovementDown(bool eastB, bool westB);
	void checkMovementUp(bool eastB, bool westB);
	void checkMovementRight(bool northB, bool southB);
	void checkMovementLeft(bool northB, bool southB);
	void movePlayerWithWantedMovement();
	void setWantedPositionRandom();

private:
	bool _isAlive;
	int _entityNumber;
	int _score;
	int _winNumber;
	irr::video::IVideoDriver *_driver;
	irr::scene::ISceneManager *_smgr;
	Character *_character;
	Map *_map;
	std::vector<IEntity *> &_entities;
	Key_mouvement _wantedMovement;
	core::vector3df _wantedPosition;
	Bomber *_bomber;
	BombStack *_bombStack;
	GameCore *_gameCore;
	Core *_core;

	int _firePower;
	int _bombAmount;
	int _speed;
	bool _wallPass;
	bool _bombPass;
};

#endif /* !IA_HPP_ */