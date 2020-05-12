/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AI
*/

#include "AI.hpp"
#include "Game.hpp"

#include <iostream>
#include <algorithm>

AI::AI()
{
    x = 80;
    y = 80;
}

AI::~AI()
{
}

int AI::canMove(int **map, int xNext, int yNext)
{
    int Ystart = 0;
    int sizeHitBox = 80;

    for (int i = 0; i < X_SIZE; i++)
    {
        int Xstart = 0;
        for (int j = 0; j < Y_SIZE; j++)
        {
            if (map[i][j] != 0)
            {
                if ((xNext == Xstart) && (yNext == Ystart))
                {
                    return 0;
                }
                if ((xNext == Xstart) && (yNext + 80 > Ystart && yNext + 80 < Ystart + 80))
                {
                    return 0;
                }
                if ((xNext == Xstart) && (yNext < Ystart + 80 && yNext + 80 > Ystart + 80))
                {
                    return 0;
                }
                if ((yNext == Ystart) && (xNext + 80 > Xstart && xNext + 80 < Xstart + 80))
                {
                    return 0;
                }
                if ((yNext == Ystart) && (xNext < Xstart + 80 && xNext + 80 > Xstart + 80))
                {
                    return 0;
                }
                if ((xNext + 80 > Xstart && xNext + 80 < Xstart + 80) && (yNext + 80 > Ystart && yNext + 80 < Ystart + 80))
                    return 0;
                if ((xNext < Xstart + 80 && xNext + 80 > Xstart + 80) && (yNext + 80 > Ystart && yNext + 80 < Ystart + 80))
                    return 0;
            }
            Xstart += 80;
        }
        Ystart += 80;
    }
    return 1;
}

void poseZoneBomb(int ***map, int bombUp, int i, int j)
{
    int stopPlusX = 0;
    int stopMinusX = 0;
    int stopPlusY = 0;
    int stopMinusY = 0;

    for (int k = 1; k <= bombUp; k++)
    {
        if (!stopMinusX && (*map)[i - k][j] == 0)
            (*map)[i - k][j] = 4;
        else
            stopMinusX = 1;
        if (!stopPlusX && (*map)[i + k][j] == 0)
            (*map)[i + k][j] = 4;
        else
            stopPlusX = 1;
        if (!stopMinusY && (*map)[i][j - k] == 0)
            (*map)[i][j - k] = 4;
        else
            stopMinusY = 1;
        if (!stopPlusY && (*map)[i][j + k] == 0)
            (*map)[i][j + k] = 4;
        else
            stopPlusY = 1;
    }
}

void AI::renderBombOnMap(int ***map)
{
    int Ystart = 0;
    int sizeHitBox = 80;

    for (int i = 0; i < X_SIZE; i++)
    {
        int Xstart = 0;
        for (int j = 0; j < Y_SIZE; j++)
        {
            if ((*map)[i][j] == 3)
            {
                poseZoneBomb(map, bombUp, i, j);
            }
            Xstart += 80;
        }
        Ystart += 80;
    }
}

int **copyDoubleArray(int **map)
{
    int **copyMap = new int *[X_SIZE];
    for (int i = 0; i < X_SIZE; i++)
        copyMap[i] = new int[Y_SIZE];
    for (int i = 0; i < X_SIZE; i++)
    {
        for (int j = 0; j < Y_SIZE; j++)
        {
            copyMap[i][j] = map[i][j];
        }
    }
    return copyMap;
}

int AI::rushToSafety(int **map, int **copyMap, int multX, int multY)
{
    int time = 1;

    while (canMove(map, x + (80 * multX * time), y + (80 * multY * time)))
    {
        if (canMove(copyMap, x + (80 * multX * time), y + (80 * multY * time)))
            return time;
        time++;
    }
    return -1;
}

int AI::getNumberMovement(int **map, int **copyMap, int multX, int multY)
{
    int movement = -1;
    if (canMove(map, x + (80 * multX), y + (80 * multY)))
    {
        if (canMove(copyMap, x + (80 * multX), y + (80 * multY)))
        {
            return 0;
        }
        movement = rushToSafety(map, copyMap, multX, multY);
    }
    return movement;
}

bestMovement AI::findSafePlace(int **map, int **copyMap)
{
    int right = getNumberMovement(map, copyMap, 1, 0);
    int left = getNumberMovement(map, copyMap, -1, 0);
    int bottom = getNumberMovement(map, copyMap, 0, 1);
    int top = getNumberMovement(map, copyMap, 0, -1);

    int listNBMovements[4] = {right, left, bottom, top};
    std::sort(listNBMovements, listNBMovements + (sizeof(listNBMovements) / sizeof(listNBMovements[0])));
    for (int i = 0; i < 4; i++)
    {
        if (listNBMovements[i] != -1)
        {
            if (listNBMovements[i] == right)
                return bestMovement::rightB;
            if (listNBMovements[i] == left)
                return bestMovement::leftB;
            if (listNBMovements[i] == bottom)
                return bestMovement::bottomB;
            if (listNBMovements[i] == top)
                return bestMovement::topB;
        }
    }
    return bestMovement::idleB;
}

int AI::isSafe(int **map)
{
    int **copyMap = copyDoubleArray(map);
    renderBombOnMap(&copyMap);
    if (canMove(copyMap, x, y))
    {
        return 1;
    }
    bestMovement movement = findSafePlace(map, copyMap);
    if (movement == bestMovement::rightB)
        _horMovement = horMovement::right;
    if (movement == bestMovement::leftB)
        _horMovement = horMovement::left;
    if (movement == bestMovement::bottomB)
        _verMovement = verMovement::bottom;
    if (movement == bestMovement::topB)
        _verMovement = verMovement::top;
    return 0;
}

void AI::testMovement(int **map)
{
    if (y == 80 && canMove(map, x + speed, y))
    {
        _horMovement = horMovement::right;
        return;
    }
    if (x != 80 && canMove(map, x, y + speed))
    {
        _verMovement = verMovement::bottom;
        return;
    }
    if (canMove(map, x - speed, y))
    {
        _horMovement = horMovement::left;
        return;
    }
    if (canMove(map, x, y - speed))
    {
        _verMovement = verMovement::top;
        return;
    }
}

horMovement AI::getHorMovement()
{
    return _horMovement;
}

verMovement AI::getVerMovement()
{
    return _verMovement;
}

void AI::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

int AI::getX()
{
    return x;
}

int AI::getY()
{
    return y;
}

void AI::resetMovement()
{
    _horMovement = horMovement::idleHor;
    _verMovement = verMovement::idleVer;
}

void AI::setPowerUp(PowerUp power, int up)
{
    bombUp = up;
}