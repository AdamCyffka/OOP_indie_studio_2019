/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombStack
*/

#include "BombStack.hpp"
#include "BombException.hpp"
#include "AnimExplo.hpp"
#include "IEntity.hpp"
#include "hitbox.hpp"

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
    irr::scene::IAnimatedMesh *mesh = _smgr->getMesh("resources/models/bomb/bomb.obj");
    if (!mesh)
        throw BombException("can't load model \"bomb/bomb.obj\"");
    node = _smgr->addMeshSceneNode(mesh);
    if (!node)
        throw BombException("can't add mesh \"bomb/bomb.obj\" to a node");
    node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    node->setPosition({0, 0, 0});
    node->setScale({1, 1, 1});
    node->setVisible(false);
    _stack.push_back({node, true});
}


std::size_t BombStack::getBombAmount() const
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

void BombStack::putBomb(irr::core::vector3df bombPosition3d)
{
    for (auto bomb : _stack) {
        if (bomb.second == true) {
            bomb.first->setPosition(bombPosition3d);
            bomb.first->setVisible(true);
            bomb.second = false;
            break;
        }
    }
}

void BombStack::explodeBomb(Map *map, IEntity *entity, irr::core::vector3df bombPosition3d)
{
    int firePower = 2;
    Point bombPosition = squareWherePlayerIs(entity, map);
    std::map<int, std::map<int, blockState>> &map2D = map->getMap();
    int line = bombPosition.x;
    int column = bombPosition.y;

    auto characterPosition = entity->getCharacter()->getPosition();
    //std::cout << "entity position: (ligne,colonne) " << line << " " << column << std::endl;
    //std::cout << "character position: (X,Y) " << characterPosition.X << " " << characterPosition.Y << " " << characterPosition.Z << std::endl;
    //std::cout << "character conversion position: (X,Y) " << MAP_DEFAULT_X + (-10.0f * line) << " " << MAP_DEFAULT_Y << " " << MAP_DEFAULT_Z + (-10.0f * column) << std::endl;
    //std::cout << "ma map contient " << map2D.size() << " lignes" << std::endl;
    //std::cout << "ma map contient " << map2D[line].size() <<  " colonnes" << std::endl;

    for (int y = line - 1; y >= line - firePower; y--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] == blockState::unbreakable)
                break;
            else if (map2D[y][column] == blockState::empty && y != line)
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
        }
    }
    for (int y = line + 1; y <= line + firePower; y++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] == blockState::unbreakable)
                break;
            else if (map2D[y][column] == blockState::empty && y != line)
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
        }
    }
    for (int x = column - 1; x >= column - firePower; x--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] == blockState::unbreakable)
                break;
            else if (map2D[line][x] == blockState::empty && x != column)
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
        }
    }
    for (int x = column + 1; x <= column + firePower; x++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] == blockState::unbreakable)
                break;
            else if (map2D[line][x] == blockState::empty && x != column)
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
        }
    }
    for (auto bomb : _stack) {
        if (bomb.first->getPosition() == bombPosition3d) {
            bomb.first->setVisible(false);
            bomb.second = true;
            break;
        }
    }
}