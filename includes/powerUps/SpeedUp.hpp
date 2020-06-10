/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedUp
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "IPowerUps.hpp"

class SpeedUp : public IPowerUps {
    public:
        explicit SpeedUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~SpeedUp() = default;

        void spawn();
		void die();
		void update();
        PowerUps::PowerUpsType getType();
        irr::core::vector3df getPosition();
    private:
        irr::scene::ISceneNode *_bomb;
        irr::core::vector3df _pos;
        PowerUps::PowerUpsType _type;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !SPEEDUP_HPP_ */