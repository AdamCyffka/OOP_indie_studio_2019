/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** side
*/

#ifndef SIDE_HPP_
#define SIDE_HPP_

#include "EnumCheck.hpp"

enum side {
    north,
    south,
    east,
    west
};

using sideCheck = EnumCheck<side, side::north, side::south, side::east, side::west>;

#endif /* !SIDE_HPP_ */
