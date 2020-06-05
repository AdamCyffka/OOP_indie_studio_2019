/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStack
*/

#include "BombStack.hpp"
#include "BombException.hpp"

BombStack::BombStack(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _smgr = smgr;
    addBomb();
}

BombStack::~BombStack()
{
}

void BombStack::addBomb()
{
    irr::scene::IMeshSceneNode *node;
    irr::scene::IAnimatedMesh *mesh = _smgr->getMesh("resources/models/bomb/model.obj");
    if (!mesh)
        throw BombException("can't load model \"bomb/model.obj\"");
    node = _smgr->addMeshSceneNode(mesh);
    if (!node)
        throw BombException("can't add mesh \"bomb/model.obj\" to a node");
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setPosition({0, 0, 0});
    node->setScale({1, 1, 1});
    node->setVisible(false);
    _stack.push_back({node, true});
}


int BombStack::getBombAmount() const
{
    return _stack.size();
}

int BombStack::bombsAvailable()
{
    int count = 0;

    for (auto bomb : _stack)
       count += (int)bomb.second;
    return count;
}

void BombStack::explodeBomb(Map *map, irr::core::vector3df bombPosition)
{
    std::cout << ""
    std::cout << "et BOOOM, dans le sanglier" << std::endl;
}