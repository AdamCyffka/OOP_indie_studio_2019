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
#include "global.hpp"
#include "PowerUpsException.hpp"

namespace PowerUps {
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
}

class IPowerUps {
    public:
		virtual ~IPowerUps() = default;

		virtual void spawn() = 0;
		virtual void die() = 0;
		virtual void update() = 0;
		virtual PowerUps::PowerUpsType getType() = 0;
		virtual irr::core::vector3df getPosition() = 0;
};

#endif /* !IPOWERUPS_HPP_ */