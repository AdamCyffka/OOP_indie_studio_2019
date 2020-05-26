/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IEntity.hpp"

class Player : public IEntity {
    public:
        Player(Character *, const Key_mouvement &, int);

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
		Key_mouvement getInput();

	private:
		bool _isAlive;
		int _entityNumber;
		int _winNumber;
		int _score;
		Character *_character;

		Key_mouvement _input;
		int _firePower;
		int _bombAmount;
		int _speed;
		bool _wallPass;
		bool _bombPass;

		std::map<int, irr::core::vector3df> _spawnAreas;
};

#endif /* !PLAYER_HPP_ */