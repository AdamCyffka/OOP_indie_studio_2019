/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IBonus
*/

#ifndef IBONUS_HPP_
#define IBONUS_HPP_

#include <irrlicht.h>

class IBonus {
    public:
		IBonus();
		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
};

#endif /* !IBONUS_HPP_ */