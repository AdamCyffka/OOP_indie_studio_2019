/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <irrlicht.h>

class IGame {
    public:
        virtual ~IGame() = default;

        virtual void loadButtons() = 0;
        virtual void loadTextures() = 0;
        virtual void run() = 0;
};

#endif /* !IGAME_HPP_ */