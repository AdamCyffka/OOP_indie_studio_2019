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

class GameCore;

class Player : public IEntity {
    public:
        Player(Character *, const Key_mouvement &, int, Map *, GameCore *);
		Player() = default;

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
		void setInput(Key_mouvement) override;
		Key_mouvement getInput() override;

		void moveTo(side) override;
		void setIsAlive(bool) override;
		bool isAlive() override;
		bool canGoTo(Key_mouvement);

		std::pair<int, int> getPosition();
		void setPosition(std::pair<int, int>);

	private:
		void findPosition();

		bool _isAlive;
		int _entityNumber;
		int _winNumber;
		int _score;
		GameCore *_gameCore;
		Character *_character;
		Map *_map;
		std::pair<int, int> _position;

		Key_mouvement _input;
		Key_mouvement _isDoing;
		int _firePower;
		int _bombAmount;
		int _speed;
		bool _wallPass;
		bool _bombPass;
};

#endif /* !PLAYER_HPP_ */