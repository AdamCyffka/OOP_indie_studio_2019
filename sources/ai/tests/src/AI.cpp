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
#include <ctime>

AI::AI()
{
    x = 80;
    y = 80;
}

AI::~AI()
{
}

int AI::oneSideIsTheSame(AI *secondPlayer)
{
    if (this->x == secondPlayer->getX() || this->y == secondPlayer->getY())
    {
        return 1;
    }
    return 0;
}

void AI::chooseMovementTo(AI *secondPlayer)
{
    if (this->x == secondPlayer->getX() && this->y == secondPlayer->getY())
    {
        return;
    }
    if (this->x == secondPlayer->getX())
    {
        if (this->y > secondPlayer->getY())
        {
            _verMovement = verMovement::top;
        }
        else
        {
            _verMovement = verMovement::bottom;
        }
    }
    if (this->y == secondPlayer->getY())
    {
        if (this->x > secondPlayer->getX())
        {
            _horMovement = horMovement::left;
        }
        else
        {
            _horMovement = horMovement::right;
        }
    }
}

int AI::pathClear(AI *secondPlayer, int ***map)
{
    if (this->x == secondPlayer->getX())
    {
        int pathY = this->y;
        int mult = 1;
        if (this->y > secondPlayer->getY())
            mult = -1;
        while (pathY != secondPlayer->getY())
        {
            if (!canMove(*map, x, pathY))
                return 0;
            pathY = pathY + (speed * mult);
        }
        return 1;
    }
    if (this->y == secondPlayer->getY())
    {
        int pathX = this->x;
        int mult = 1;
        if (this->x > secondPlayer->getX())
            mult = -1;
        while (pathX != secondPlayer->getX())
        {
            if (!canMove(*map, pathX, y))
                return 0;
            pathX = pathX + (speed * mult);
        }
        return 1;
    }
    return 0;
}

int AI::canPoseBomb(AI *secondPlayer)
{
    if (this->x == secondPlayer->getX())
    {
        int distance = (this->y - secondPlayer->getY()) / 80;
        if (distance < 0)
            distance *= -1;
        if (distance <= this->bombUp)
            return 1;
    }
    if (this->y == secondPlayer->getY())
    {
        int distance = (this->x - secondPlayer->getX()) / 80;
        if (distance < 0)
            distance *= -1;
        if (distance <= this->bombUp)
            return 1;
    }
    return 0;
}

void AI::poseBomb(int ***map)
{
    if ((*map)[int(this->y / 80)][int(this->x) / 80] != 1)
    {
        (*map)[int(this->y / 80)][int(this->x) / 80] = 3;
    }
}

int AI::isMovingToPlayer(int ***map, AI *secondPlayer)
{
    if (this == secondPlayer)
    {
        return 0;
    }
    if (this->oneSideIsTheSame(secondPlayer) && this->pathClear(secondPlayer, map))
    {
        if (this->canPoseBomb(secondPlayer))
        {
            this->poseBomb(map);
        }
        else
        {
            this->chooseMovementTo(secondPlayer);
        }
        return 1;
    }
    return 0;
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
        if (!stopMinusX && ((*map)[i - k][j] == 0 || (*map)[i - k][j] == 4))
            (*map)[i - k][j] = 4;
        else
            stopMinusX = 1;
        if (!stopPlusX && ((*map)[i + k][j] == 0 || (*map)[i + k][j] == 4))
            (*map)[i + k][j] = 4;
        else
            stopPlusX = 1;
        if (!stopMinusY && ((*map)[i][j - k] == 0 || (*map)[i][j - k] == 4))
            (*map)[i][j - k] = 4;
        else
            stopMinusY = 1;
        if (!stopPlusY && ((*map)[i][j + k] == 0 || (*map)[i][j + k] == 4))
            (*map)[i][j + k] = 4;
        else
            stopPlusY = 1;
    }
}

void AI::renderBombOnMap(int ***map)
{
    int Ystart = 0;
    int sizeHitBox = 80;
    int bomb = 0;

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

int AI::canMoveAfter(int **map, int **copyMap, int multX, int multY)
{
    if (multX == 0 && multY == 1 && canMove(copyMap, x + (80), y + (80 * multY)))
    {
        _lastMovement = bestMovement::bottomB;
        return 1;
    }
    if (multX == 0 && multY == 1 && canMove(copyMap, x + (-80), y + (80 * multY)))
    {
        _lastMovement = bestMovement::bottomB;
        return 1;
    }
    if (multX == 0 && multY == -1 && canMove(copyMap, x + (80), y + (80 * multY)))
    {
        _lastMovement = bestMovement::topB;
        return 1;
    }
    if (multX == 0 && multY == -1 && canMove(copyMap, x + (-80), y + (80 * multY)))
    {
        _lastMovement = bestMovement::topB;
        return 1;
    }

    if (multX == 1 && multY == 0 && canMove(copyMap, x + (80 * multX), y + (80)))
    {
        _lastMovement = bestMovement::rightB;
        return 1;
    }
    if (multX == 1 && multY == 0 && canMove(copyMap, x + (80 * multX), y + (-80)))
    {
        _lastMovement = bestMovement::rightB;
        return 1;
    }

    if (multX == -1 && multY == 0 && canMove(copyMap, x + (80 * multX), y + (80)))
    {
        _lastMovement = bestMovement::leftB;
        return 1;
    }
    if (multX == -1 && multY == 0 && canMove(copyMap, x + (80 * multX), y + (-80)))
    {
        _lastMovement = bestMovement::leftB;
        return 1;
    }

    return 0;
}

int AI::onlyWay(int **map, int multX, int multY)
{
    int way = 0;

    if (map[int(this->y / 80)][int(this->x / 80) - 1] == 0)
    {
        way++;
    }
    if (map[int(this->y / 80)][int(this->x / 80) + 1] == 0)
    {
        way++;
    }
    if (map[int(this->y / 80) - 1][int(this->x / 80)] == 0)
    {
        way++;
    }
    if (map[int(this->y / 80) + 1][int(this->x / 80)] == 0)
    {
        way++;
    }
    if (way == 1 && map[int(this->y / 80) + multY][int(this->x / 80) + multX] == 0) {
        return 1;
        std::cout << "only one way !" << std::endl;
    }
    return 0;
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
    if (canMove(map, x + (80 * multX), y + (80 * multY)) && canMoveAfter(map, copyMap, multX, multY))
    {
        return 0;
    }
    /*if (onlyWay(map, multX, multY)) {
        return 0;
    }*/
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
        if (_lastMovement != bestMovement::idleB)
            _lastMovement = bestMovement::idleB;
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
    if (movement == bestMovement::idleB)
    {
        if (_lastMovement == bestMovement::rightB)
            _horMovement = horMovement::right;
        if (_lastMovement == bestMovement::leftB)
            _horMovement = horMovement::left;
        if (_lastMovement == bestMovement::bottomB)
            _verMovement = verMovement::bottom;
        if (_lastMovement == bestMovement::topB)
            _verMovement = verMovement::top;
    }
    else
    {
        _lastMovement = movement;
    }
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

void AI::moveDependingOfWishMovement()
{
    if (_wishMovement == wishMovement::bottomW)
        _verMovement = verMovement::bottom;
    if (_wishMovement == wishMovement::topW)
        _verMovement = verMovement::top;
    if (_wishMovement == wishMovement::leftW)
        _horMovement = horMovement::left;
    if (_wishMovement == wishMovement::rightW)
        _horMovement = horMovement::right;
}

int AI::canStillMove(int **map)
{
    if (_wishMovement == wishMovement::bottomW && canMove(map, x, y + speed))
        return 1;
    if (_wishMovement == wishMovement::topW && canMove(map, x, y - speed))
        return 1;
    if (_wishMovement == wishMovement::leftW && canMove(map, x - speed, y))
        return 1;
    if (_wishMovement == wishMovement::rightW && canMove(map, x + speed, y))
        return 1;
    return 0;
}

void AI::choseAMove(int **map)
{
    if (!canMove(map, x, y + speed) && !canMove(map, x, y - speed) && !canMove(map, x + speed, y) && !canMove(map, x - speed, y))
        return;
    std::srand(std::time(nullptr));
    while (1)
    {
        int wish = rand() % 4 + 1;

        if (wish == 4 && canMove(map, x, y + speed))
        {
            _wishMovement = wishMovement::bottomW;
            return;
        }
        if (wish == 3 && canMove(map, x, y - speed))
        {
            _wishMovement = wishMovement::topW;
            return;
        }
        if (wish == 1 && canMove(map, x - speed, y))
        {
            _wishMovement = wishMovement::leftW;
            return;
        }
        if (wish == 2 && canMove(map, x + speed, y))
        {
            _wishMovement = wishMovement::rightW;
            return;
        }
    }
}

int AI::findBreakableWall(int **map)
{
    if (map[int(this->y / 80)][int(this->x / 80) - 1] == 5)
    {
        return 1;
    }
    if (map[int(this->y / 80)][int(this->x / 80) + 1] == 5)
    {
        return 1;
    }
    if (map[int(this->y / 80) - 1][int(this->x / 80)] == 5)
    {
        return 1;
    }
    if (map[int(this->y / 80) + 1][int(this->x / 80)] == 5)
    {
        return 1;
    }
    return 0;
}

int AI::canSaflyPoseABomb(int **map)
{
    int breakableWall = this->findBreakableWall(map);

    if (breakableWall == 0)
        return 0;
    if (map[int(this->y / 80)][int(this->x / 80) - 1] == 0)
    {
        return 1;
    }
    if (map[int(this->y / 80)][int(this->x / 80) + 1] == 0)
    {
        return 1;
    }
    if (map[int(this->y / 80) - 1][int(this->x / 80)] == 0)
    {
        return 1;
    }
    if (map[int(this->y / 80) + 1][int(this->x / 80)] == 0)
    {
        return 1;
    }
    return 0;
}

void AI::moveRandomly(int ***map)
{
    int **copyMap = copyDoubleArray(*map);
    renderBombOnMap(&copyMap);

    if (_wishMovement != wishMovement::idleW)
    {
        if (this->canStillMove(copyMap))
        {
            this->moveDependingOfWishMovement();
        }
        else
        {
            if (this->canSaflyPoseABomb(copyMap)) {
                this->poseBomb(map);
                return;
                std::cout << "pose the bomb !" << std::endl;
            }
            _wishMovement = wishMovement::idleW;
        }
    }
    if (_wishMovement == wishMovement::idleW)
    {
        this->choseAMove(copyMap);
        this->moveDependingOfWishMovement();
    }
}