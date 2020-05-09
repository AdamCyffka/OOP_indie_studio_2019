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
    irr::scene::ISceneNode *skydome;
    irr::scene::ISceneNode *castle;
    irr::scene::ISceneNode *arena;
    irr::scene::ISceneNode *water = 0;
    irr::scene::IAnimatedMesh *mesh = _smgr->getMesh("resources/models/blocks/block.obj");
    irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNodeMaya(); // addCameraSceneNodeMaya

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

    // lakituPlanet
    arena = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/lakitu_planet/BossJugemPlanet.obj"));
    arena->setScale({0.1, 0.1, 0.1});
    arena->setPosition({-2000, 700, -3000}); // pas toucher a y - x+=ouest, x-=est y+=haut, y-=bas z+=sud, z-=nord
    arena->setRotation({0, 250, -10});
    if (arena) {
        arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // arena
    arena = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/arena/Main.obj"));
    arena->setScale({0.1, 0.1, 0.1});
    arena->setPosition({1500, 1200, -760}); // pas toucher a y - x+=ouest, x-=est y+=haut, y-=bas z+=sud, z-=nord
    if (arena) {
        arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // light for water
    water = _smgr->addLightSceneNode(0, {0, 700 ,0}, {1.0f, 0.6f, 0.7f, 1.0f}, 8000.0f);

    // water
    mesh = _smgr->addHillPlaneMesh( "myHill",
        irr::core::dimension2d<irr::f32>(20, 20),
        irr::core::dimension2d<irr::u32>(40, 40), 0, 0,
        irr::core::dimension2d<irr::f32>(50, 50),
        irr::core::dimension2d<irr::f32>(10, 10));
    water = _smgr->addWaterSurfaceSceneNode(mesh->getMesh(0), 3.0f, 300.0f, 30.0f);
    water->setPosition({0, 15, -800});
    water->setMaterialTexture(0, _driver->getTexture("resources/models/castle/CastleWaterWave.png"));
    water->setMaterialType(irr::video::EMT_REFLECTION_2_LAYER);

    // goal planet
    arena = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/goal_planet/Race_Goal_Planet.obj"));
    arena->setScale({0.1, 0.1, 0.1});
    arena->setPosition({900, 1200, -3000}); // pas toucher a y - x+=ouest, x-=est y+=haut, y-=bas z+=sud, z-=nord
    if (arena) {
        arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    }

    // skybox
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
    skydome = _smgr->addSkyDomeSceneNode(_driver->getTexture("resources/images/terrain/skydome.png"), 16, 8, 0.95f, 2.0f);
    _driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

    // particules
    irr::scene::IParticleSystemSceneNode *ps = _smgr->addParticleSystemSceneNode(false);
    irr::scene::IParticleEmitter* em = ps->createBoxEmitter(
        irr::core::aabbox3d<irr::f32>(-7, 0, -7, 7, 1, 7),
        irr::core::vector3df(0.0f, 0.06f, 0.0f),
        5, 100,
        irr::video::SColor(0,255, 255, 255),
        irr::video::SColor(0,255, 255, 255),
        800, 2000, 0,
        irr::core::dimension2df(10.f, 10.f),
        irr::core::dimension2df(20.f, 20.f));

    ps->setEmitter(em);
    em->drop();

    irr::scene::IParticleAffector* paf = ps->createFadeOutParticleAffector();

    ps->addAffector(paf);
    paf->drop();

    ps->setPosition({665, 50, -560});
    ps->setScale({0.5, 0.5, 0.5});
    ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
    ps->setMaterialTexture(0, _driver->getTexture("resources/models/castle/fire.bmp"));
    ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}