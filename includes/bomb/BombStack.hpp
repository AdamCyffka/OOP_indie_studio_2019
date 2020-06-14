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
#include "hitbox.hpp"

class Core;
class IEntity;

class BombStack {
    public:
        BombStack(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, int bombsAvailable, Core *core);
        ~BombStack();

        void addBombs(int bombsAvailable);
        std::size_t getBombAmount() const;
        void setBombAmount(std::size_t amount);
        int bombsAvailable();
        std::vector<std::pair<std::pair<irr::scene::IMeshSceneNode *, bool>, bool>> &getStack();
        void putBomb(Map *map, irr::core::vector3df bombPosition3d);
        std::vector<Point> explodeBomb(Map *map, IEntity *entity, irr::core::vector3df bombPosition3d, std::vector<int> stopBlocks);

    protected:
    private:
        Core *_core;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;

        std::vector<std::pair<std::pair<irr::scene::IMeshSceneNode *, bool>, bool>> _stack; // {node, available}
};

#endif /* !BOMBSTACK_HPP_ */
