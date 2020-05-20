/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Fire
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include "IPowerUps.hpp"

class Fire : public IPowerUps {
    public:
        explicit Fire(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~Fire() = default;
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !FIRE_HPP_ */