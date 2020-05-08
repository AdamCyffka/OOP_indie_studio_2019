/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadMap
*/

#include "LoadMap.hpp"

LoadMap::LoadMap(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;
}

LoadMap::~LoadMap()
{
}

void LoadMap::run()
{
    irr::scene::ISceneNode *skybox;
    irr::scene::ISceneNode *skydome;
    irr::scene::ISceneNode *castle;
    irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNode(); // addCameraSceneNodeMaya

    // camera
    camera->setPosition(irr::core::vector3df(0, 100, 0));
    camera->setTarget(irr::core::vector3df(0, 0, -200));
    camera->setFarValue(42000.0f);

    // castle
    castle = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/castle/Castle.obj"));
    castle->setScale({100, 100, 100});
    castle->setPosition({520, 0, -760}); // pas toucher a y - x+=ouest, x-=est y+=haut, y-=bas z+=sud, z-=nord
    if (castle) {
        castle->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // skybox
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
    skydome = _smgr->addSkyDomeSceneNode(_driver->getTexture("resources/images/terrain/skydome.png"), 16, 8, 0.95f, 2.0f);
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}