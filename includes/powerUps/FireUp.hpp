/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** FireUp
*/

#ifndef FIREUP_HPP_
#define FIREUP_HPP_

#include "IPowerUps.hpp"

class FireUp : public IPowerUps {
    public:
        explicit FireUp(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);

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

#endif /* !FIREUP_HPP_ */