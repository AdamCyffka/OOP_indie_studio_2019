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

#endif /* !BOMBDOWN_HPP_ */