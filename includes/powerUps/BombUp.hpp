/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombUp
*/

#ifndef BOMBUP_HPP_
#define BOMBUP_HPP_

#include "IPowerUps.hpp"

class BombUp : public IPowerUps {
    public:
        explicit BombUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~BombUp() = default;

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

#endif /* !BOMBUP_HPP_ */