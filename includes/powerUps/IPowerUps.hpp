/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** IPowerUps
*/

#ifndef IPOWERUPS_HPP_
#define IPOWERUPS_HPP_

#include <irrlicht.h>
#include <iostream>
#include "PowerUpsException.hpp"

class IPowerUps {
	public:
		enum PowerUpsType {
			BombDown,
			BombUp,
			BombFull,
			BombPass,
			FireDown,
			FireFull,
			FireUp,
			SpeedDown,
			SpeedUp,
			WallPass
		};

		virtual ~IPowerUps() = default;

		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		virtual IPowerUps::PowerUpsType getType() = 0;
		virtual irr::core::vector3df getPosition() = 0;
};

#endif /* !IPOWERUPS_HPP_ */