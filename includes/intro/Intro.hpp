/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** intro
*/

#ifndef INTRO_HPP_
#define INTRO_HPP_

#include <irrlicht.h>

class Intro {
    public:
        Intro();
        void run();

    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
    
        irr::scene::ISceneNode *_skybox;
        irr::scene::ISceneNode *_skydome;
        irr::scene::ISceneNode *_castle;
};

#endif /* !INTRO_HPP_ */