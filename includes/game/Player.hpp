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
        Player(Character *, Input *);
        ~Player() = default;

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
		void getEntityNumber();
		void getScore();
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

#endif /* !PLAYER_HPP_ */