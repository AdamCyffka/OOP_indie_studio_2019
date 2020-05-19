/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** WallPass
*/

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "IPowerUps.hpp"

class WallPass : public IPowerUps {
    public:
        explicit WallPass(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~WallPass() = default;
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !WALLPASS_HPP_ */