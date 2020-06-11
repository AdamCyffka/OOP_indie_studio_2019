/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombPass
*/

#ifndef BOMBPASS_HPP_
#define BOMBPASS_HPP_

#include "IPowerUps.hpp"

class BombPass : public IPowerUps {
    public:
        explicit BombPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~BombPass();

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

#endif /* !BOMBPASS_HPP_ */