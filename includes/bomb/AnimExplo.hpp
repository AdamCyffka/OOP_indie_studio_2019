/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimExplo
*/

#ifndef ANIMEXPLO_HPP_
#define ANIMEXPLO_HPP_

#include <irrlicht.h>

class AnimExplo {
    public:
        AnimExplo(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos);
        ~AnimExplo() = default;
    protected:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !ANIMEXPLO_HPP_ */