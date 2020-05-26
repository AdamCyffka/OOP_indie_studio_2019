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
        explicit BombPass(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~BombPass() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBPASS_HPP_ */