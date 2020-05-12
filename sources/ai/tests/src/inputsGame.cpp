/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** inputsGame
*/

#include "graphicFunctions.hpp"
#include "Game.hpp"

int getInputs(SDL_Window *window, Game *game)
{
    SDL_Event event;

    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        SDL_DestroyWindow(window);
        SDL_Quit();
        return (606);
        break;
    case SDL_WINDOWEVENT:
        if (event.window.event == SDL_WINDOWEVENT_CLOSE)
        {
            SDL_DestroyWindow(window);
            SDL_Quit();
            return (606);
        }
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            return 0;
        }
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_ESCAPE)
        {
            return 0;
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            if (event.button.x >= 1770 && event.button.x <= 1870 && event.button.y >= 70 && event.button.y <= 170)
            {
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 606;
            }
            game->setClick(event.button.x, event.button.y);
        }
        break;
    }
    return 0;
}