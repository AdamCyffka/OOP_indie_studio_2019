/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** drawGame
*/

#include "graphicFunctions.hpp"

void printRectangle(SDL_Renderer *renderer, int x, int y, int w, int h, int R, int G, int B)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    SDL_SetRenderDrawColor(renderer, R, G, B, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
}

void draw_gameMain(SDL_Renderer *renderer, Game *game)
{
    SDL_RenderClear(renderer);
    game->drawMap(renderer);
    game->drawAI(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}