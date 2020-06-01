/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** modelInfos
*/

#ifndef MODELINFOS_HPP_
#define MODELINFOS_HPP_

#include <iostream>
#include <vector>

typedef struct modelInfos_s {
    std::string name;
    std::string filename;
    std::vector<std::string> textures;
    std::pair<int, int> idleLoop;
    std::pair<int, int> runningLoop;
    std::pair<int, int> dyingLoop;
    std::pair<int, int> deadLoop;
    std::pair<int, int> victoryLoop;
    float size;
} modelInfos_t;

#endif /* !MODELINFOS_HPP_ */
