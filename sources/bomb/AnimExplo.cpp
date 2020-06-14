/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimExplo
*/

#include <stdexcept>
#include "global.hpp"
#include "AnimExplo.hpp"
#include "BombException.hpp"

AnimExplo::AnimExplo(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	if (!fireTexture)
		throw std::runtime_error("could not load texture : resources/images/fx/fire.bmp");
	irr::scene::ISceneNodeAnimator *anim = smgr->createDeleteAnimator(200);
	irr::scene::IParticleSystemSceneNode *fire = smgr->addParticleSystemSceneNode(false);
	if (!fire)
		throw BombException("Can't add particle system scene node for explosion's animation");
	irr::scene::IParticleEmitter *em = fire->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-6, 0, -7, 7, 1, 7),
		irr::core::vector3df(0.0f, 0.01f, 0.0f),
		80, 600,
		irr::video::SColor(0, 0, 0, 0),
		irr::video::SColor(0, 255, 255, 255),
		600, 1200, 0,
		irr::core::dimension2df(0.0f, 0.0f),
		irr::core::dimension2df(10.0f, 10.0f));
	if (!em)
		throw BombException("Can't create a box emitter for explosion's animation");
	fire->setEmitter(em);
	em->drop();
	irr::scene::IParticleAffector *paf = fire->createFadeOutParticleAffector();
	if (!paf)
		throw BombException("Can't create a fade out particle affector for explosion's animation");
	fire->addAffector(paf);
	paf->drop();
	fire->setPosition(irr::core::vector3df(pos));
	fire->setScale(irr::core::vector3df(0.001f, 0.001f, 0.001f));
	fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	fire->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	fire->setMaterialTexture(0, fireTexture);
	fire->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	if (!anim)
		throw BombException("Can't create delete animator for explosion's animation");
	fire->addAnimator(anim);
	anim->drop();
}