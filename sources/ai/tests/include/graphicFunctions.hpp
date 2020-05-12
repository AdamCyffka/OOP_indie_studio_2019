/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** graphicFunctions
*/

#ifndef GRAPHICFUNCTIONS_HPP_
#define GRAPHICFUNCTIONS_HPP_

#include <cstdlib>
#include <ctime>
#include <chrono>

#include <SDL2/SDL.h>

#include "Game.hpp"

void printRectangle(SDL_Renderer *renderer, int x, int y, int w, int h, int R, int G, int B);

void draw_gameMain(SDL_Renderer *renderer, Game *game);

int loopMainGame(SDL_Window *window, SDL_Renderer *renderer, char **av);

int getInputs(SDL_Window *window, Game *game);

#endif /* !GRAPHICFUNCTIONS_HPP_ */