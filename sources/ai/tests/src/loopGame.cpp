/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** loopGame
*/

#include "graphicFunctions.hpp"
#include "Game.hpp"

#include <iostream>

int loopMainGame(SDL_Window *window, SDL_Renderer *renderer, char **av)
{
    std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
    float fps = 1000 / 60;
    Game *game = new Game();
    int map[X_SIZE][Y_SIZE] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
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
    game->chooseMap(std::stoi(av[1]));
    game->setPowerUp(PowerUp::BombUp, std::stoi(av[2]));
    while (window)
    {
        a = std::chrono::system_clock::now();
        std::chrono::duration<double, std::milli> work_time = a - b;
        if (work_time.count() >= fps)
        {
            game->simulate();
            b = std::chrono::system_clock::now();
            std::chrono::duration<double, std::milli> sleep_time = b - a;
            draw_gameMain(renderer, game);
        }
        if (getInputs(window, game) == 606) {
            return 0;
        }
    }
    return 0;
}