/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Speed
*/

#ifndef SPEED_HPP_
#define SPEED_HPP_

#include "IPowerUps.hpp"

class Speed : public IPowerUps {
    public:
        explicit Speed(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Speed() = default;
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !SPEED_HPP_ */