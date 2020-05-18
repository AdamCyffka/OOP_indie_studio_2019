/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

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
    protected:
        void getBonus();
		void moveLeft();
		void moveRight();
		void moveTop();
		void moveBottom();
    private:
};

#endif /* !PLAYER_HPP_ */