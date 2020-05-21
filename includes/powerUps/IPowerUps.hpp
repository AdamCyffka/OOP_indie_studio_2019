/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IPowerUps
*/

#ifndef IPOWERUPS_HPP_
#define IPOWERUPS_HPP_

#include <irrlicht.h>

class IPowerUps {
    public:
		virtual ~IPowerUps() = default;

		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
};

#endif /* !IPOWERUPS_HPP_ */