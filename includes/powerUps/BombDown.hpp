/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombDown
*/

#ifndef BOMBDOWN_HPP_
#define BOMBDOWN_HPP_

#include "IPowerUps.hpp"

class BombDown : public IPowerUps {
    public:
        explicit BombDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~BombDown() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !BOMBDOWN_HPP_ */