/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** movement
*/

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

enum bestMovement
{
    idleB,
    leftB,
    rightB,
    topB,
    bottomB
};

enum wishMovement
{
    idleW,
    leftW,
    rightW,
    topW,
    bottomW
};

enum horMovement
{
    idleHor = 0,
    left = -1,
    right = 1
};

enum verMovement
{
    idleVer = 0,
    top = -1,
    bottom = 1
};

#endif /* !MOVEMENT_HPP_ */
