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
        explicit FireDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~FireDown() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !FIREDOWN_HPP_ */