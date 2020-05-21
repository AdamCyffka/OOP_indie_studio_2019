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
        explicit FireUp(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~FireUp() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !FIREUP_HPP_ */