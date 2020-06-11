/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireFull
*/

#ifndef FIREFULL_HPP_
#define FIREFULL_HPP_

#include "IPowerUps.hpp"

class FireFull : public IPowerUps {
    public:
        explicit FireFull(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~FireFull();

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

#endif /* !FIREFULL_HPP_ */