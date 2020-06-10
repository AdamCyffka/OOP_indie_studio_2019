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
#include "modelInfos.hpp"
#include "IPowerUps.hpp"

void setGlobalVariables(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
extern irr::video::ITexture *fireTexture;
extern std::map<IPowerUps::PowerUpsType, irr::scene::IMesh *> g_meshes;
extern const std::map<std::string, modelInfos_t> g_modelInfos;

#endif /* !GLOBAL_HPP_ */
