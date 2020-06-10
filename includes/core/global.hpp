/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <map>
#include <irrlicht.h>
#include "IPowerUps.hpp"
#include "modelInfos.hpp"

void setGlobalVariables(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
extern irr::video::ITexture *fireTexture;
extern irr::scene::IMesh *bombDown;
extern irr::scene::IMesh *bombFull;
extern irr::scene::IMesh *bombPass;
extern irr::scene::IMesh *bombUp;
extern irr::scene::IMesh *fireDown;
extern irr::scene::IMesh *fireFull;
extern irr::scene::IMesh *fireUp;
extern irr::scene::IMesh *speedDown;
extern irr::scene::IMesh *speedUp;
extern irr::scene::IMesh *wallPass;
extern const std::map<std::string, modelInfos_t> g_modelInfos;

#endif /* !GLOBAL_HPP_ */
