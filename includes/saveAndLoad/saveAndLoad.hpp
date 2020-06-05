/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** save
*/

#ifndef SAVEANDLOAD_HPP_
#define SAVEANDLOAD_HPP_

#include "Core.hpp"
#include "CameraTravelManager.hpp"

void saveGame(int slot, Core &core, CameraTravelManager *cameraTravelManager);
void loadGame(int slot, Core &core, CameraTravelManager *cameraTravelManager);

#endif /* !SAVEANDLOAD_HPP_ */