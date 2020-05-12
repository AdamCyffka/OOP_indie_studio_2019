/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <array>
#include <SDL2/SDL.h>

#include "AI.hpp"
#include "powerUp.hpp"
#include "define.hpp"

class Game {
    public:
        Game();
        ~Game();
        void simulate();
        void simulateClick();
        void simulateAI();
        void simulateMovement();
        void chooseMap(int map);
        void setPowerUp(PowerUp, int);
        void drawMap(SDL_Renderer *renderer);
        void drawAI(SDL_Renderer *renderer);
        int **getMap();
        //Maps
        void emptyMap();
        void setClick(int x, int y);
    protected:
    private:
        int **map;
        AI *bot;
        int mouseClick[2] = {-1, -1};
        int normalSpeed = 5;
};

#endif /* !GAME_HPP_ */
