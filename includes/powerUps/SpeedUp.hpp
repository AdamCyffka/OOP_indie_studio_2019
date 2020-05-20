/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SpeedUp
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

#include "IPowerUps.hpp"

class SpeedUp : public IPowerUps {
    public:
        explicit SpeedUp(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, float x, float z);
        ~SpeedUp() = default;

        void spawn();
		void die();
		void update();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !SPEEDUP_HPP_ */