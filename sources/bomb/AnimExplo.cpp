/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** AnimExplo
*/

#include <stdexcept>
#include "global.hpp"
#include "AnimExplo.hpp"

AnimExplo::AnimExplo(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df const &pos)
{
	if (!fireTexture)
		throw std::runtime_error("could not load texture : resources/images/fx/fire.bmp");
	irr::scene::ISceneNodeAnimator *anim = smgr->createDeleteAnimator(2000);
	irr::scene::IParticleSystemSceneNode *fire = smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter *em = fire->createBoxEmitter(
		irr::core::aabbox3d<irr::f32>(-6, 0, -7, 7, 1, 7),
		irr::core::vector3df(0.0f, 0.01f, 0.0f),
		80, 600,
		irr::video::SColor(0, 0, 0, 0),
		irr::video::SColor(0, 255, 255, 255),
		600, 1200, 0,
		irr::core::dimension2df(0.0f, 0.0f),
		irr::core::dimension2df(10.0f, 10.0f));
	fire->setEmitter(em);
	em->drop();
	irr::scene::IParticleAffector *paf = fire->createFadeOutParticleAffector();
	fire->addAffector(paf);
	paf->drop();
	fire->setPosition(irr::core::vector3df(pos));
	fire->setScale(irr::core::vector3df(0.001f, 0.001f, 0.001f));
	fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	fire->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	fire->setMaterialTexture(0, fireTexture);
	fire->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
	fire->addAnimator(anim);
	anim->drop();
}