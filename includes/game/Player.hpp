/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "IEntity.hpp"
#include "Input.hpp"

class Player : public IEntity {
    public:
        Player(Character *, const Key_mouvement &, int);

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