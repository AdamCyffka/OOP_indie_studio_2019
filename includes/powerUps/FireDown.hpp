/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireDown
*/

#ifndef FIREDOWN_HPP_
#define FIREDOWN_HPP_

#include "IPowerUps.hpp"

class FireDown : public IPowerUps {
    public:
        explicit FireDown(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~FireDown();

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

#endif /* !FIREDOWN_HPP_ */