/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallPass
*/

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "IPowerUps.hpp"

class WallPass : public IPowerUps {
    public:
        explicit WallPass(irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);

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

#endif /* !WALLPASS_HPP_ */