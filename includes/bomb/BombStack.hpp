/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStack
*/

#ifndef BOMBSTACK_HPP_
#define BOMBSTACK_HPP_

#include <irrlicht.h>
#include <vector>
#include <utility>
#include "Map.hpp"
#include "hitbox.hpp"

class IEntity;
class BombStack {
    public:
        BombStack(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~BombStack();

        void addBomb();
        std::size_t getBombAmount() const;
        int bombsAvailable(); // return the number of available bombs
        void putBomb(Map *map, irr::core::vector3df bombPosition3d);
        std::vector<Point> explodeBomb(Map *map, IEntity *entity, irr::core::vector3df bombPosition3d);

    protected:
    private:
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::vector<std::pair<irr::scene::IMeshSceneNode *, bool>> _stack; // {node, available}
};

#endif /* !BOMBSTACK_HPP_ */
