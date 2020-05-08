/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadMap
*/

#ifndef LOADMAP_HPP_
#define LOADMAP_HPP_

#include <irrlicht.h>

class LoadMap {
    public:
        LoadMap(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~LoadMap();
        void run();

    protected:
    private:
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        irr::scene::ISceneNode *_skybox;
        irr::scene::ISceneNode *_skydome;
        irr::scene::ISceneNode *_castle;
};

#endif /* !LOADMAP_HPP_ */