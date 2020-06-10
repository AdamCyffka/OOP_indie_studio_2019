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

void BombStack::putBomb(Map *map, irr::core::vector3df bombPosition3d)
{
    for (auto bomb : _stack) {
        if (bomb.second == true) {
            Point bombPosition2d = squareWhereBombIs(bombPosition3d, map);
            bomb.first->setPosition({MAP_DEFAULT_X + (-10.0f * bombPosition2d.x), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * bombPosition2d.y)});
            bomb.first->setVisible(true);
            bomb.second = false;
            break;
        }
    }
}

std::vector<Point> BombStack::explodeBomb(Map *map, IEntity *entity, irr::core::vector3df bombPosition3d)
{
    int firePower = entity->getFirePower();
    Point bombPosition = squareWhereBombIs(bombPosition3d, map);
    std::map<int, std::map<int, blockState>> &map2D = map->getMap();
    int line = bombPosition.x;
    int column = bombPosition.y;
    std::vector<Point> deadZone;

    deadZone.push_back(Point(bombPosition));
    for (int y = line - 1; y >= line - firePower; y--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] == blockState::unbreakable)
                break;
            else if (map2D[y][column] == blockState::empty && y != line) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
                deadZone.push_back({y, column});
            }
        }
    }
    for (int y = line + 1; y <= line + firePower; y++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] == blockState::unbreakable)
                break;
            else if (map2D[y][column] == blockState::empty && y != line) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
                deadZone.push_back({y, column});
            }
        }
    }
    for (int x = column - 1; x >= column - firePower; x--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] == blockState::unbreakable)
                break;
            else if (map2D[line][x] == blockState::empty && x != column) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
                deadZone.push_back({line, x});
            }
        }
    }
    for (int x = column + 1; x <= column + firePower; x++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] == blockState::unbreakable)
                break;
            else if (map2D[line][x] == blockState::empty && x != column) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
                deadZone.push_back({line, x});
            }
        }
    }
    for (auto bomb : _stack) {
        irr::core::vector3df centeredBombPosition3d = {MAP_DEFAULT_X + (-10.0f * bombPosition.x), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * bombPosition.y)};
        if (bomb.first->getPosition() == centeredBombPosition3d) {
            bomb.first->setVisible(false);
            bomb.second = true;
            break;
        }
    }
    return deadZone;
}