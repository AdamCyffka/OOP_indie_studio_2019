/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** ClasseAI
*/

#ifndef CLASSEAI_HPP_
#define CLASSEAI_HPP_

#include "movement.hpp"
#include "define.hpp"
#include "powerUp.hpp"

class AI {
    public:
        AI();
        ~AI();
        int getX();
        int getY();
        void setPosition(int x, int y);
        horMovement getHorMovement();
        verMovement getVerMovement();
        void testMovement(int **map);
        int canMove(int **map, int xNext, int yNext);
        void resetMovement();
        int isSafe(int **map);
        void renderBombOnMap(int ***map);
        bestMovement findSafePlace(int **map, int **copyMap);
        void setPowerUp(PowerUp power, int up);
        int rushToSafety(int **map, int **copyMap, int multX, int multY);
        int getNumberMovement(int **map, int **copyMap, int multX, int multY);
    protected:
    private:
        int x = 0;
        int y = 0;
        int speed = 5;
        int bombUp = 0;
        horMovement _horMovement = horMovement::idleHor;
        verMovement _verMovement= verMovement::idleVer;
};

#endif /* !CLASSEAI_HPP_ */
