/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedDown
*/

#ifndef SPEEDDOWN_HPP_
#define SPEEDDOWN_HPP_

#include "IPowerUps.hpp"

class SpeedDown : public IPowerUps {
    public:
        explicit SpeedDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~SpeedDown() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::scene::ISceneManager *_smgr;
};

#endif /* !SPEEDDOWN_HPP_ */