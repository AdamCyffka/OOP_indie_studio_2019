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
        explicit BombUp(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~BombUp() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBUP_HPP_ */