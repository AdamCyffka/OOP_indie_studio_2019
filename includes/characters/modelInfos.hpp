/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** modelInfos
*/

#ifndef MODELINFOS_HPP_
#define MODELINFOS_HPP_

#include <iostream>

typedef struct modelInfos_s {
    std::string filename;
    std::pair<int, int> idleLoop;
    std::pair<int, int> movingLoop;
    std::pair<int, int> dyingLoop;
    int size;
} modelInfos_t;

#endif /* !MODELINFOS_HPP_ */
