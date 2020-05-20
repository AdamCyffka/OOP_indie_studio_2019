/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedDown
*/

#ifndef SPEEDDOWN_HPP_
#define SPEEDDOWN_HPP_

#include "IPowerUps.hpp"

class SpeedDown : public IPowerUps {
    public:
        explicit SpeedDown(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~SpeedDown() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !SPEEDDOWN_HPP_ */