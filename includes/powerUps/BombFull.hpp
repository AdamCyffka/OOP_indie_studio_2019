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
        explicit BombFull(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~BombFull() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBFULL_HPP_ */