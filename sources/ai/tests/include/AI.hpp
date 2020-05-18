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

class AI
{
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
    int canMoveAfter(int **map, int **copyMap, int multX, int multY);
    //int canMoveJustAfter(int **map, int xNext, int yNext);
    void resetMovement();
    int isSafe(int **map);
    void renderBombOnMap(int ***map);
    bestMovement findSafePlace(int **map, int **copyMap);
    void setPowerUp(PowerUp power, int up);
    int rushToSafety(int **map, int **copyMap, int multX, int multY);
    int getNumberMovement(int **map, int **copyMap, int multX, int multY);
    int isMovingToPlayer(int ***map, AI *secondPlayer);
    int oneSideIsTheSame(AI *secondPlayer);
    int pathClear(AI *secondPlayer, int ***map);
    void chooseMovementTo(AI *secondPlayer);
    int canPoseBomb(AI *secondPlayer);
    void poseBomb(int ***map);
    void moveRandomly(int ***map);
    void moveDependingOfWishMovement();
    int canStillMove(int **map);
    void choseAMove(int **map);
    int canSaflyPoseABomb(int **map);
    int findBreakableWall(int **map);
    int onlyWay(int **map, int multX, int multY);

protected:
private:
    int x = 0;
    int y = 0;
    int speed = 5;
    int bombUp = 0;
    horMovement _horMovement = horMovement::idleHor;
    verMovement _verMovement = verMovement::idleVer;
    bestMovement _lastMovement = bestMovement::idleB;
    wishMovement _wishMovement = wishMovement::idleW;
};

#endif /* !CLASSEAI_HPP_ */
