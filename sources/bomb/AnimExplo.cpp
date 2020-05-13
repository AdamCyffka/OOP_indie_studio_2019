/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimExplo
*/

#include "AnimExplo.hpp"

AnimExplo::AnimExplo(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
	_env = env;
	_smgr = smgr;
    _pS = _smgr->addParticleSystemSceneNode(false);
    _pE = _pS->createBoxEmitter(
        irr::core::aabbox3d<irr::f32>(-3,0,-3,20,1,20),
		irr::core::vector3df(0.0f,0.06f,0.0f),
		2000,2500,
		irr::video::SColor(0, 255, 255, 255),
		irr::video::SColor(0, 255, 255, 255),
		100,200,0,
		irr::core::dimension2df(10.f,10.f),
		irr::core::dimension2df(20.f,20.f));
    _pS->setEmitter(_pE);
	_pE->drop();
	_pA = _pS->createFadeOutParticleAffector();
	_pS->addAffector(_pA);
	_pA->drop();
	//_pos = getpos();
	//_scale = getScale();
	doAnimFire();
}

AnimExplo::~AnimExplo()
{
    _smgr->addToDeletionQueue(_pS);
}

void AnimExplo::doAnimFire()
{
	_pS->setPosition(_pos);
	_pS->setScale(_scale);
	_pS->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_pS->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	_pS->setMaterialTexture(0, _driver->getTexture("resources/images/fx/particlered.bmp"));
	_pS->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}