/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <irrlicht.h>

enum Move {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

enum PlayerType {
    AI,
    PLAYER
};

class Player {
    public:
        Player(float x, float y);
        ~Player();
        void spawn();
        void die();
        void move();
		void putBomb();
        void getPlayerConfig();
        void onEvent(const irr::SEvent &event);
    protected:
        void getBonus();
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
    private:
};

#endif /* !PLAYER_HPP_ */