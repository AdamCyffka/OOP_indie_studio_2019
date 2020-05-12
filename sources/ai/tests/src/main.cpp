/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** main.cpp
*/

#define X_SIZE 13
#define YSIZE 13

#include "graphicFunctions.hpp"

int main_game(char **av)
{
    SDL_Window *pWindow = NULL;
    SDL_Renderer *renderer;
    int level = 0;

    if (SDL_CreateWindowAndRenderer(1920, 1080, SDL_WINDOW_RESIZABLE, &pWindow, &renderer))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 84;
    }
    if (pWindow)
    {
        loopMainGame(pWindow, renderer, av);
    }
    else
    {
        fprintf(stderr, "Error to create Window %s\n", SDL_GetError());
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    if (env[0] == NULL)
    {
        return (84);
    }
    if (ac < 3)
    {
        fprintf(stderr, "First argument : map\nSecond argument : Bomb Power Up\n");
        return 84;
    }
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Error to init SDL (%s)\n", SDL_GetError());
        return 84;
    }
    if (main_game(av) == 84)
        return 84;
    return (0);
}