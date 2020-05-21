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
        explicit FireFull(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~FireFull() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !FIREFULL_HPP_ */