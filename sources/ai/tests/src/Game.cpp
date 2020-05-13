/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include "Game.hpp"
#include "maps.hpp"
#include "graphicFunctions.hpp"

#include <iostream>

Game::Game()
{
    map = new int *[X_SIZE];
    for (int i = 0; i < X_SIZE; i++)
        map[i] = new int[Y_SIZE];
    int realMap[X_SIZE][Y_SIZE] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
           {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    for (int i = 0; i < X_SIZE; i++) {
        for (int j = 0; j < Y_SIZE; j++) {
            map[i][j] = realMap[i][j];
        }
    }
    bot = new AI();
    bot2 = new AI();
    bot2->setPosition(80, 880);
}

Game::~Game()
{
}

void Game::emptyMap()
{
}

void Game::simulateClick()
{
    int Ystart = 0;
    int sizeHitBox = 80;

    for (int i = 0; i < X_SIZE; i++)
    {
        int Xstart = 0;
        for (int j = 0; j < Y_SIZE; j++)
        {
            if (map[i][j] == 0 && Xstart < mouseClick[0] && Xstart + sizeHitBox > mouseClick[0] &&
            Ystart < mouseClick[1] && Ystart + sizeHitBox > mouseClick[1])
            {
                map[i][j] = 3;
            }
            Xstart += 80;
        }
        Ystart += 80;
    }
}

void Game::simulateAI(AI *Bot)
{
    if (Bot->isSafe(this->getMap()))
    {
        if (Bot->isMovingToPlayer(&map, this->bot)) {
        }
        if (Bot->isMovingToPlayer(&map, this->bot2)) {
        }
    }
}

void Game::simulateMovement()
{
    bot->setPosition(bot->getX() + (normalSpeed * bot->getHorMovement()), bot->getY() + (normalSpeed * bot->getVerMovement()));
    bot2->setPosition(bot2->getX() + (normalSpeed * bot2->getHorMovement()), bot2->getY() + (normalSpeed * bot2->getVerMovement()));

    bot->resetMovement();
    bot2->resetMovement();
}

int **Game::getMap()
{
    return map;
}

void Game::simulate()
{
    this->simulateClick();
    this->simulateAI(bot);
    this->simulateAI(bot2);
    this->simulateMovement();
}

void Game::setPowerUp(PowerUp power, int up)
{
    bot->setPowerUp(power, up);
    bot2->setPowerUp(power, up);
}

void Game::chooseMap(int map)
{
    if (map == 0)
    {
        //this->emptyMap();
    }
    else if (map == 1)
    {
        //this->emptyMap();
    }
    else if (map == 2)
    {
    }
}

void Game::drawAI(SDL_Renderer *renderer)
{
    printRectangle(renderer, bot->getX(), bot->getY(), 80, 80, 0, 255, 0);
    printRectangle(renderer, bot2->getX(), bot2->getY(), 80, 80, 255, 255, 0);
}

void Game::drawMap(SDL_Renderer *renderer)
{
    int Ystart = 0;
    for (int i = 0; i < X_SIZE; i++)
    {
        int Xstart = 0;
        for (int j = 0; j < Y_SIZE; j++)
        {
            if (map[i][j] == 0)
            {
                printRectangle(renderer, Xstart, Ystart, 80, 80, 205, 205, 205);
            }
            if (map[i][j] == 1)
            {
                printRectangle(renderer, Xstart, Ystart, 80, 80, 255, 255, 255);
            }
            Xstart += 80;
        }
        Ystart += 80;
    }
}

void Game::setClick(int x, int y)
{
    mouseClick[0] = x;
    mouseClick[1] = y;
}