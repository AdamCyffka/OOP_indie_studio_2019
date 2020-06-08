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
        ~WallPass() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::scene::ISceneManager *_smgr;
};

#endif /* !WALLPASS_HPP_ */