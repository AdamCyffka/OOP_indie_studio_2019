/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimExplo
*/

#include "AnimExplo.hpp"

AnimExplo::AnimExplo(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	_driver = driver;
    _env = env;
    _smgr = smgr;

	irr::scene::ISceneNodeAnimator *anim = _smgr->createDeleteAnimator(1000);
	irr::scene::IParticleSystemSceneNode *_fire = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter *em = _fire->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-6, 0, -7, 7, 1, 7),
		irr::core::vector3df(0.0f, 0.01f, 0.0f),
		80, 600,
		irr::video::SColor(0, 0, 0, 0),
		irr::video::SColor(0, 255, 255, 255),
		600, 1200, 0,
		irr::core::dimension2df(0.0f, 0.0f),
		irr::core::dimension2df(30.0f, 30.0f));
	_fire->setEmitter(em);
	em->drop();
	irr::scene::IParticleAffector *_paf = _fire->createFadeOutParticleAffector();
	_fire->addAffector(_paf);
	_paf->drop();
	_fire->setPosition(irr::core::vector3df(pos));
	_fire->setScale(irr::core::vector3df(2, 2, 2));
	_fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_fire->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_fire->setMaterialTexture(0, _driver->getTexture("resources/images/fx/fire.bmp"));
	_fire->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	_fire->addAnimator(anim);
}