/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombDown
*/

#ifndef BOMBDOWN_HPP_
#define BOMBDOWN_HPP_

#include "IPowerUps.hpp"

class BombDown : public IPowerUps {
    public:
        explicit BombDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~BombDown() = default;

        void spawn();
		void die();
		void update();
        PowerUps::PowerUpsType getType();
        irr::core::vector3df getPosition();
    private:
        irr::scene::IMeshSceneNode *_bomb;
        irr::core::vector3df _pos;
        PowerUps::PowerUpsType _type;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBDOWN_HPP_ */