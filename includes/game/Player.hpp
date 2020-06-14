/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Map.hpp"
#include "IEntity.hpp"
#include "hitbox.hpp"
#include "Bomber.hpp"

class GameCore;

class Player : public IEntity {
    public:
        Player(Character *character, const Key_mouvement &input, int entityNumber,
		Map *map, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr,
		GameCore *gameCore, Bomber *bomb, Core *core, bool isSave);

	 	void run(Key_mouvement) final;
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
		void setInput(Key_mouvement) final;
		Key_mouvement getInput() final;
		void checkMovement(Key_mouvement input);

		void moveTo(side) final;
		void setIsAlive(bool) final;
		bool isAlive() final;

	private:
		bool _isAlive;
		int _entityNumber;
		int _winNumber;
		int _score;
		GameCore *_gameCore;
		Character *_character;
		BombStack * _bombStack;
		Map *_map;
		Bomber *_bomb;
		Core *_core;
		irr::video::IVideoDriver *_driver;
		irr::scene::ISceneManager *_smgr;
		core::vector3df _wantedPosition;

		Key_mouvement _input;
		Key_mouvement _savedInput;
		int _firePower;
		int _bombAmount;
		int _speed;
		bool _wallPass;
		bool _bombPass;
};

#endif /* !PLAYER_HPP_ */