/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombFull
*/

#ifndef BOMBFULL_HPP_
#define BOMBFULL_HPP_

#include "IPowerUps.hpp"

class BombFull : public IPowerUps {
    public:
        explicit BombFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~BombFull();

        void spawn();
		void die();
		void update();
		IPowerUps::PowerUpsType getType();
        irr::core::vector3df getPosition();
    private:
        irr::scene::IMeshSceneNode *_node;
        irr::core::vector3df _pos;
		IPowerUps::PowerUpsType _type;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBFULL_HPP_ */