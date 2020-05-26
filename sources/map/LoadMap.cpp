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
	_map = new Map;
	_driver = driver;
	_env = env;
	_smgr = smgr;
}

void LoadMap::run()
{
	irr::scene::ISceneNode *skybox;
	irr::scene::ISceneNode *observatory;
	irr::scene::ISceneNode *arena;
	irr::scene::ISceneNode *towerPlanet;
	irr::scene::ISceneNode *dreadnoughtPlanet;
	irr::scene::ISceneNode *dustyPlanet;
	irr::scene::ISceneNode *gatewayPlanet;
	irr::scene::ISceneNode *beanPlanet;
	irr::scene::ISceneNode *plateA;
	irr::scene::ISceneNode *plateB;
	irr::scene::ISceneNodeAnimator *animA;
	irr::scene::ISceneNodeAnimator *animB;
	irr::scene::ISceneNodeAnimator *rotatePlanet;
	irr::scene::ISceneNodeAnimator *core;

	// observatory
	observatory = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/observatory.obj"));
	observatory->setPosition({0, 0, 0});
	observatory->setScale({5, 5, 5});
	if (observatory)
		observatory->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// arena
	arena = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/arena/Main.obj"));
	arena->setPosition({-500, 303, 700});
	arena->setScale({0.047f, 0.047f, 0.047f});
	if (arena)
		arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// beanPlanet
	beanPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/bean_planet/bean_planet.obj"));
	beanPlanet->setPosition({200, 300, 1000});
	beanPlanet->setRotation({0, 200, 0});
	beanPlanet->setScale({5, 5, 5});
	if (beanPlanet)
		beanPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// towerPlanet
	towerPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/tower_planet/tower_planet.obj"));
	towerPlanet->setPosition({1000, 400, 500});
	towerPlanet->setScale({10, 10, 10});
	if (towerPlanet)
		towerPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// dreadnoughtPlanet
	dreadnoughtPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/dreadnought_planet/dreadnought_planet.obj"));
	dreadnoughtPlanet->setPosition({-4000, 400, -2000});
	dreadnoughtPlanet->setScale({15, 15, 15});
	dreadnoughtPlanet->setRotation({50, 0, 0});
	if (dreadnoughtPlanet)
		dreadnoughtPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// dustyPlanet
	dustyPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/dusty_planet/dusty_planet.obj"));
	dustyPlanet->setPosition({-1000, -1500, 2000});
	dustyPlanet->setScale({15, 15, 15});
	dustyPlanet->setRotation({50, 0, 0});
	if (dustyPlanet)
		dustyPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);

	// gatewayPlanet
	gatewayPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/gateway_planet/gateway_planet.obj"));
	gatewayPlanet->setPosition({4000, 0, -3000});
	gatewayPlanet->setScale({500, 500, 500});
	if (gatewayPlanet)
		gatewayPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	rotatePlanet = _smgr->createRotationAnimator({0.05f, 0.0f, 0.0f});
	gatewayPlanet->addAnimator(rotatePlanet);
	rotatePlanet->drop();

	// plateA
	plateA = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateA.obj"));
	plateA->setPosition({0, 0, 0});
	plateA->setScale({3, 3, 3});
	if (plateA)
		plateA->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	animA = _smgr->createRotationAnimator({0.0f, -0.2f, 0.0f});
	plateA->addAnimator(animA);
	animA->drop();

	// plateB
	plateB = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateB.obj"));
	plateB->setPosition({0, 10, 0});
	plateB->setScale({3, 3, 3});
	if (plateB)
		plateB->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	animB = _smgr->createRotationAnimator({0.0f, -0.1f, 0.0f});
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
	irr::scene::IParticleSystemSceneNode *ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(
        core::aabbox3d<f32>(-3, 0, -3, 3, 1, 3),
        core::vector3df(0.0f, 0.10f, 0.0f),
        80, 100,
        video::SColor(10, 255, 255, 255), video::SColor(10, 255, 255, 255),
        400, 1100);
	em->setMinStartSize({30, 40});
	em->setMaxStartSize({30, 40});
	ps->setEmitter(em);
	em->drop();
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _driver->getTexture("resources/images/fx/fireball.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	core = _smgr->createFlyCircleAnimator(core::vector3df(0, 0, 0), 70.0f,
            0.001f, core::vector3df(0.2f, 0.9f, 0.f));
    core->drop();

	// gameMap
	loadGameMap(-440, 308, 790);
}

void LoadMap::emptyGameMap(float x, float y, float z)
{
	for (int i = 0; i < _map->getMap().size(); ++i) {
		for (int j = 0; j < _map->getMap()[i].size(); ++j) {
			switch (_map->getMap()[i][j]) {
				case empty: {
					break;
				}
				case breakable: {
					irr::scene::ISceneNode *brick;
					brick = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/blocks/brick.obj"));
					brick->setPosition({x + (-10 * i), y, z + (-10 * j)});
					brick->setScale({5, 5, 5});
					if (brick)
						brick->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					brick->setVisible(true);
					break;
				}
				case unbreakable: {
					irr::scene::ISceneNode *unbreakable;
					unbreakable = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/blocks/solid.obj"));
					unbreakable->setPosition({x + (-10 * i), y, z + (-10 * j)});
					unbreakable->setScale({5, 5, 5});
					if (unbreakable)
						unbreakable->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					unbreakable->setVisible(true);
					break;
				}
			}
		}
	}
}

void LoadMap::loadGameMap(float x, float y, float z)
{
	for (int i = 0; i < _map->getMap().size(); ++i) {
		for (int j = 0; j < _map->getMap()[i].size(); ++j) {
			irr::scene::ISceneNode *sceneBlock;
			irr::scene::IAnimatedMesh *mesh;
			switch (_map->getMap()[i][j]) {
				case empty: {
					break;
				}
				case breakable: {
					mesh = _smgr->getMesh("resources/models/blocks/brick.obj");
					if (!mesh)
						throw LoadingException("could not load mesh : brick.obj");
					sceneBlock = _smgr->addAnimatedMeshSceneNode(mesh);
					if (!sceneBlock)
						throw LoadingException("could not add mesh scene node : sceneblock brick");
					sceneBlock->setPosition({x + (-10 * i), y, z + (-10 * j)});
					sceneBlock->setScale({5, 5, 5});
					sceneBlock->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					sceneBlock->setVisible(true);
					break;
				}
				case unbreakable: {
					mesh = _smgr->getMesh("resources/models/blocks/solid.obj");
					if (!mesh)
						throw LoadingException("could not load mesh : solid.obj");
					sceneBlock = _smgr->addAnimatedMeshSceneNode(mesh);
					if (!sceneBlock)
						throw LoadingException("could not add mesh scene node : sceneblock solid");
					sceneBlock->setPosition({x + (-10 * i), y, z + (-10 * j)});
					sceneBlock->setScale({5, 5, 5});
					sceneBlock->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					sceneBlock->setVisible(true);
					break;
				}
			}
			_visualMap[i][j] = sceneBlock;
		}
	}
}

Map *LoadMap::getMap()
{
	return _map;
}

std::map<int, std::map<int, irr::scene::ISceneNode *>> LoadMap::getVisualMap()
{
	return _visualMap;
}
