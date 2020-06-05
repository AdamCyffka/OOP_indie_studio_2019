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

	irr::scene::IAnimatedMesh *meshObservatory;
	irr::scene::IAnimatedMesh *meshArena;
	irr::scene::IAnimatedMesh *meshTowerPlanet;
	irr::scene::IAnimatedMesh *meshDreadnoughtPlanet;
	irr::scene::IAnimatedMesh *meshDustyPlanet;
	irr::scene::IAnimatedMesh *meshGatewayPlanet;
	irr::scene::IAnimatedMesh *meshBeanPlanet;
	irr::scene::IAnimatedMesh *meshPlateA;
	irr::scene::IAnimatedMesh *meshPlateB;

	// observatory
	meshObservatory = _smgr->getMesh("resources/models/planets/observatory/observatory.obj");
	if (!meshObservatory)
		throw LoadingException("could not load mesh : observatory.obj");
	observatory = _smgr->addAnimatedMeshSceneNode(meshObservatory);
	if (!observatory)
		throw LoadingException("could not add scene mesh node : observatory");
	observatory->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	observatory->setPosition({0, 0, 0});
	observatory->setScale({5, 5, 5});

	// arena
	meshArena = _smgr->getMesh("resources/models/planets/arena/Main.obj");
	if (!meshArena)
		throw LoadingException("could not load mesh : Main.obj");
	arena = _smgr->addAnimatedMeshSceneNode(meshArena);
	if (!arena)
		throw LoadingException("could not add scene mesh node : arena");
	arena->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	arena->setPosition({-500, 303, 700});
	arena->setScale({0.047f, 0.047f, 0.047f});

	// beanPlanet
	meshBeanPlanet = _smgr->getMesh("resources/models/planets/bean_planet/bean_planet.obj");
	if (!meshBeanPlanet)
		throw LoadingException("could not load mesh : bean_planet.obj");
	beanPlanet = _smgr->addAnimatedMeshSceneNode(meshBeanPlanet);
	if (!beanPlanet)
		throw LoadingException("could not add scene mesh node : beanPlanet");
	beanPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	beanPlanet->setPosition({200, 300, 1000});
	beanPlanet->setRotation({0, 200, 0});
	beanPlanet->setScale({5, 5, 5});

	// towerPlanet
	meshTowerPlanet = _smgr->getMesh("resources/models/planets/tower_planet/tower_planet.obj");
	if (!meshTowerPlanet)
		throw LoadingException("could not load mesh : tower_planet.obj");
	towerPlanet = _smgr->addAnimatedMeshSceneNode(meshTowerPlanet);
	if (!towerPlanet)
		throw LoadingException("could not add scene mesh node : towerPlanet");
	towerPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	towerPlanet->setPosition({1000, 400, 500});
	towerPlanet->setScale({10, 10, 10});

	// dreadnoughtPlanet
	meshDreadnoughtPlanet = _smgr->getMesh("resources/models/planets/dreadnought_planet/dreadnought_planet.obj");
	if (!meshDreadnoughtPlanet)
		throw LoadingException("could not load mesh : dreadnought_planet.obj");
	dreadnoughtPlanet = _smgr->addAnimatedMeshSceneNode(meshDreadnoughtPlanet);
	if (!dreadnoughtPlanet)
		throw LoadingException("could not add scene mesh node : dreadnoughtPlanet");
	dreadnoughtPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	dreadnoughtPlanet->setPosition({-4000, 400, -2000});
	dreadnoughtPlanet->setScale({15, 15, 15});
	dreadnoughtPlanet->setRotation({50, 0, 0});

	// dustyPlanet
	meshDustyPlanet = _smgr->getMesh("resources/models/planets/dusty_planet/dusty_planet.obj");
	if (!meshDustyPlanet)
		throw LoadingException("could not load mesh : dusty_planet.obj");
	dustyPlanet = _smgr->addAnimatedMeshSceneNode(meshDustyPlanet);
	if (!dustyPlanet)
		throw LoadingException("could not add scene mesh node : dustyPlanet");
	dustyPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	dustyPlanet->setPosition({-1000, -1500, 2000});
	dustyPlanet->setScale({15, 15, 15});
	dustyPlanet->setRotation({50, 0, 0});

	// gatewayPlanet
	meshGatewayPlanet = _smgr->getMesh("resources/models/planets/gateway_planet/gateway_planet.obj");
	if (!meshGatewayPlanet)
		throw LoadingException("could not load mesh : gateway_planet.obj");
	gatewayPlanet = _smgr->addAnimatedMeshSceneNode(meshGatewayPlanet);
	if (!gatewayPlanet)
		throw LoadingException("could not add scene mesh node : gatewayPlanet");
	gatewayPlanet->setPosition({4000, 0, -3000});
	gatewayPlanet->setScale({500, 500, 500});
	gatewayPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	rotatePlanet = _smgr->createRotationAnimator({0.05f, 0.0f, 0.0f});
	gatewayPlanet->addAnimator(rotatePlanet);
	rotatePlanet->drop();

	// plateA
	meshPlateA = _smgr->getMesh("resources/models/planets/observatory/plateA.obj");
	if (!meshPlateA)
		throw LoadingException("could not load mesh : plateA.obj");
	plateA = _smgr->addAnimatedMeshSceneNode(meshPlateA);
	if (!plateA)
		throw LoadingException("could not add scene mesh node : plateA");
	plateA->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	plateA->setPosition({0, 0, 0});
	plateA->setScale({3, 3, 3});
	animA = _smgr->createRotationAnimator({0.0f, -0.2f, 0.0f});
	plateA->addAnimator(animA);
	animA->drop();

	// plateB
	meshPlateB = _smgr->getMesh("resources/models/planets/observatory/plateB.obj");
	if (!meshPlateB)
		throw LoadingException("could not load mesh : plateB.obj");
	plateB = _smgr->addAnimatedMeshSceneNode(meshPlateB);
	if (!plateB)
		throw LoadingException("could not add scene mesh node : plateB");
	plateB->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	plateB->setPosition({0, 10, 0});
	plateB->setScale({3, 3, 3});
	animB = _smgr->createRotationAnimator({0.0f, -0.1f, 0.0f});
	plateB->addAnimator(animB);
	animB->drop();

	// skybox
	_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
	skybox = _smgr->addSkyBoxSceneNode(
		_driver->getTexture("resources/images/terrain/bluecloud_up.jpg"),
		_driver->getTexture("resources/images/terrain/bluecloud_dn.jpg"),
		_driver->getTexture("resources/images/terrain/bluecloud_rt.jpg"), 
		_driver->getTexture("resources/images/terrain/bluecloud_lf.jpg"),
		_driver->getTexture("resources/images/terrain/bluecloud_ft.jpg"),
		_driver->getTexture("resources/images/terrain/bluecloud_bk.jpg"));
	_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

	// light core
	irr::scene::IParticleSystemSceneNode *ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter *em = ps->createBoxEmitter(
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
	irr::video::ITexture *fireBall = _driver->getTexture("resources/images/fx/fireball.bmp");
	if (!fireBall)
		throw LoadingException("could not load resource : resources/images/fx/fireball.bmp");
	ps->setMaterialTexture(0, fireBall);
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
			_visualMap[i][j]->setVisible(false);
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
