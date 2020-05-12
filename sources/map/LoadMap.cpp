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
	irr::scene::ISceneNode *plateA;
	irr::scene::ISceneNode *plateB;
	irr::scene::ISceneNodeAnimator *animA;
	irr::scene::ISceneNodeAnimator *animB;
	irr::scene::ISceneNodeAnimator *rotatePlanet;
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
	towerPlanet->setPosition({1000, 400, 500});
	towerPlanet->setScale({10, 10, 10});
	if (towerPlanet) {
		towerPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}

	// dreadnoughtPlanet
	dreadnoughtPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/dreadnought_planet/dreadnought_planet.obj"));
	dreadnoughtPlanet->setPosition({-4000, 400, -2000});
	dreadnoughtPlanet->setScale({15, 15, 15});
	dreadnoughtPlanet->setRotation({50, 0, 0});
	if (dreadnoughtPlanet) {
		dreadnoughtPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}

	// dustyPlanet
	dustyPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/dusty_planet/dusty_planet.obj"));
	dustyPlanet->setPosition({-1000, -1500, 2000});
	dustyPlanet->setScale({15, 15, 15});
	dustyPlanet->setRotation({50, 0, 0});
	if (dustyPlanet) {
		dustyPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}

	// gatewayPlanet
	gatewayPlanet = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/gateway_planet/gateway_planet.obj"));
	gatewayPlanet->setPosition({4000, 0, -3000});
	gatewayPlanet->setScale({500, 500, 500});
	if (gatewayPlanet) {
		gatewayPlanet->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	}
	rotatePlanet = _smgr->createRotationAnimator({0.05, 0, 0});
	gatewayPlanet->addAnimator(rotatePlanet);
	rotatePlanet->drop();

	// plateA
	plateA = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateA.obj"));
	plateA->setPosition({0, 0, 0});
	plateA->setScale({3, 3, 3});
	animA = _smgr->createRotationAnimator({0, 0.3, 0});
	plateA->addAnimator(animA);
	animA->drop();

	// plateB
	plateB = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/planets/observatory/plateB.obj"));
	plateB->setPosition({0, 10, 0});
	plateB->setScale({3, 3, 3});
	animB = _smgr->createRotationAnimator({0, 0.1, 0});
	plateB->addAnimator(animB);
	animB->drop();

	// skybox
	_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
	skybox = _smgr->addSkyBoxSceneNode(_driver->getTexture("resources/images/terrain/interstellar_up.tga"), _driver->getTexture("resources/images/terrain/interstellar_dn.tga"),
		_driver->getTexture("resources/images/terrain/interstellar_rt.tga"), _driver->getTexture("resources/images/terrain/interstellar_lf.tga"),
		_driver->getTexture("resources/images/terrain/interstellar_ft.tga"), _driver->getTexture("resources/images/terrain/interstellar_bk.tga"));
	_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

	// light core
	light = _smgr->addLightSceneNode(0, {0, 50, 0}, {240, 248, 255, 0}, 800);
	irr::scene::IParticleSystemSceneNode *ps = _smgr->addParticleSystemSceneNode(false, light);
	irr::scene::IParticleEmitter *em = ps->createBoxEmitter({-3, 0, -3, 3, 1, 3}, {0, 0, 0}, 20, 30, {10, 255, 255, 255}, {10, 255, 255, 255}, 400, 1100);
	em->setMinStartSize({30, 40});
	em->setMaxStartSize({30, 40});
	ps->setEmitter(em);
	em->drop();
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _driver->getTexture("resources/images/fx/fireball.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);

	// gameMap
	loadGameMap(-500, 300, 1000);
}

void LoadMap::loadGameMap(float x, float y, float z)
{
	for (int i = 0; i < _map->getMap().size(); ++i) {
		for (int j = 0; j < _map->getMap()[i].size(); ++j) {
			switch (_map->getMap()[i][j]) {
				case EMPTY: {
					break;
				}
				case BREAKABLE: {
					irr::scene::ISceneNode *brick;
					brick = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/blocks/brick.obj"));
					brick->setPosition({x + (-40 * i), y, z + (-40 * j)}); // pas toucher au y
					brick->setScale({20, 20, 20});
					if (brick) {
						brick->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					}
					brick->setVisible(false); //A decommenter pour voir la map
					break;
				}
				case UNBREAKABLE: {
					irr::scene::ISceneNode *unbreakable;
					unbreakable = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/blocks/solid.obj"));
					unbreakable->setPosition({x + (-40 * i), y, z + (-40 * j)}); // pas toucher au y
					unbreakable->setScale({20, 20, 20});
					if (unbreakable) {
						unbreakable->setMaterialFlag(irr::video::EMF_LIGHTING, false);
					}
					unbreakable->setVisible(false); //A decommenter pour voir la map
					break;
				}
			}
		}
	}
}