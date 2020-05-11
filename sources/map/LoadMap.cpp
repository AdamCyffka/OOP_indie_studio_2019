/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadMap
*/

#include "Core.hpp"
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
    irr::scene::ISceneNode *observatory;
    irr::scene::ISceneNode *arena;
    irr::scene::ISceneNode *towerPlanet;
    irr::scene::ISceneNode *plateA;
    irr::scene::ISceneNode *plateB;
    irr::scene::ISceneNodeAnimator *animA;
    irr::scene::ISceneNodeAnimator *animB;
    irr::scene::ISceneNode *light;
    irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNodeMaya(); // addCameraSceneNodeMaya

    // camera
    camera->setPosition(irr::core::vector3df(-300, 80, -400));
    camera->setTarget(irr::core::vector3df(0, 0, 0));
    camera->setFarValue(42000.0f);

    // observatory
    observatory = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/observatory.obj"));
    observatory->setPosition({0, 0, 0}); // pas toucher au y
    observatory->setScale({5, 5, 5});
    if (observatory) {
        observatory->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // arena
    arena = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/arena/Main.obj"));
    arena->setPosition({-500, 300, 700}); // pas toucher au y
    arena->setScale({0.05, 0.05, 0.05});
    if (arena) {
        arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // towerPlanet
    towerPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/tower_planet/tower_planet.obj"));
    towerPlanet->setPosition({1000, 400, 500}); // pas toucher au y
    towerPlanet->setScale({10, 10, 10});
    if (towerPlanet) {
        towerPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // plateA
    plateA = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateA.obj"));
    plateA->setPosition({0, 0, 0});
    plateA->setScale({3, 3, 3});
    animA = _smgr->createRotationAnimator({0, 0.3f, 0});
    plateA->addAnimator(animA);
    animA->drop();

    // plateB
    plateB = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateB.obj"));
    plateB->setPosition({0, 10, 0});
    plateB->setScale({3, 3, 3});
    animB = _smgr->createRotationAnimator({0, 0.1f, 0});
    plateB->addAnimator(animB);
    animB->drop();

    // skybox
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
    skybox = _smgr->addSkyBoxSceneNode(
        _driver->getTexture("resources/images/terrain/interstellar_up.tga"),
        _driver->getTexture("resources/images/terrain/interstellar_dn.tga"),
        _driver->getTexture("resources/images/terrain/interstellar_rt.tga"),
        _driver->getTexture("resources/images/terrain/interstellar_lf.tga"),
        _driver->getTexture("resources/images/terrain/interstellar_ft.tga"),
        _driver->getTexture("resources/images/terrain/interstellar_bk.tga"));
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    // light core
    light = _smgr->addLightSceneNode(0, {0, 50, 0}, {240, 248, 255, 0}, 800);
    irr::scene::IParticleSystemSceneNode* ps = _smgr->addParticleSystemSceneNode(false, light);
    irr::scene::IParticleEmitter* em = ps->createBoxEmitter({-3, 0, -3, 3, 1, 3}, {0, 0, 0}, 20, 30, {10, 255, 255, 255}, {10, 255, 255, 255}, 400, 1100);
    em->setMinStartSize({30, 40});
    em->setMaxStartSize({30, 40});
    ps->setEmitter(em);
    em->drop();
    ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    ps->setMaterialTexture(0, _driver->getTexture("resources/images/fx/fireball.bmp"));
    ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}