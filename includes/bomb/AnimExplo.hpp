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
        AnimExplo(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~AnimExplo();
        void doAnimFire();
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        irr::scene::IParticleSystemSceneNode *_pS;
        irr::scene::IParticleEmitter *_pE;
        irr::scene::IParticleAffector *_pA;
        irr::core::vector3df _pos;
        irr::core::vector3df _scale;
};

#endif /* !ANIMEXPLO_HPP_ */