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
#include "Core.hpp"

BombStack::BombStack(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, int bombsAvailable, Core *core)
{
    _core = core;
    _driver = driver;
    _smgr = smgr;
    addBombs(bombsAvailable);
}

BombStack::~BombStack()
{
}

void BombStack::addBombs(int bombsAvailable)
{
    for (int i = 0; i < 4; i++) {
        irr::scene::IMeshSceneNode *node;
        irr::scene::IAnimatedMesh *mesh = _smgr->getMesh("resources/models/bomb/bomb.obj");
        if (!mesh)
            throw BombException("can't load model \"bomb/bomb.obj\"");
        node = _smgr->addMeshSceneNode(mesh);
        if (!node)
            throw BombException("can't add mesh \"bomb/bomb.obj\" to a node");
        node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
        node->setPosition({0.0f, 0.0f, 0.0f});
        node->setScale({1, 1, 1});
        node->setVisible(true);
        _stack.push_back({{node, true}, (i < bombsAvailable) ? true : false});
    }
}


int BombStack::bombsAvailable()
{
    int count = 0;

    for (auto bomb : _stack)
        if (bomb.second)
            count += (int)bomb.first.second;
    return count;
}

std::size_t BombStack::getBombAmount() const
{
    std::size_t count = 0;

    for (auto bomb : _stack)
       count += (int)bomb.second;
    return count;
}

void BombStack::setBombAmount(std::size_t count)
{
    if (count > 4)
        throw BombException("maximum bomb amount is 4");
    for (std::size_t i = 0; i < 4; i++) {
        if (i < count) {
            _stack.at(i).second = true;
        } else
            _stack.at(i).second = false;
    }
       
}

std::vector<std::pair<std::pair<irr::scene::IMeshSceneNode *, bool>, bool>> &BombStack::getStack()
{
    return _stack;
}

void BombStack::putBomb(Map *map, irr::core::vector3df bombPosition3d)
{
    for (auto &bomb : _stack) {
        if (bomb.second && bomb.first.second) {
            Point bombPosition2d = squareWhereObjectIs(bombPosition3d, map);
            bomb.first.first->setPosition({MAP_DEFAULT_X + (-10.0f * bombPosition2d.x), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * bombPosition2d.y)});
            bomb.first.first->setVisible(true);
            bomb.first.second = false;
            if (bomb.first.second == true)
            break;
        }
    }
}

std::vector<Point> BombStack::explodeBomb(Map *map, IEntity *entity, irr::core::vector3df bombPosition3d)
{
    int firePower = entity->getFirePower();
    Point bombPosition = squareWhereObjectIs(bombPosition3d, map);
    std::map<int, std::map<int, blockState>> &map2D = map->getMap();
    int line = bombPosition.x;
    int column = bombPosition.y;
    std::vector<Point> deadZone;

    _core->getMusicEngine()->add2D("resources/sfx/bomb-explose.wav", false, false, true, irrklang::ESM_AUTO_DETECT, true);
    deadZone.push_back(Point(bombPosition));
    for (int y = line - 1; y >= line - firePower; y--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] != blockState::empty)
                break;
            else if (map2D[y][column] == blockState::empty && y != line) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
                deadZone.push_back({y, column});
            }
        }
    }
    for (int y = line + 1; y <= line + firePower; y++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(column) != map2D[line].end()) {
            if (map2D[y][column] != blockState::empty)
                break;
            else if (map2D[y][column] == blockState::empty && y != line) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * y), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * column)});
                deadZone.push_back({y, column});
            }
        }
    }
    for (int x = column - 1; x >= column - firePower; x--) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] != blockState::empty)
                break;
            else if (map2D[line][x] == blockState::empty && x != column) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
                deadZone.push_back({line, x});
            }
        }
    }
    for (int x = column + 1; x <= column + firePower; x++) {
        if (map2D.find(line) != map2D.end() && map2D[line].find(x) != map2D[line].end()) {
            if (map2D[line][x] != blockState::empty)
                break;
            else if (map2D[line][x] == blockState::empty && x != column) {
                AnimExplo(_driver, _smgr, {MAP_DEFAULT_X + (-10.0f * line), MAP_DEFAULT_Y, MAP_DEFAULT_Z + (-10.0f * x)});
                deadZone.push_back({line, x});
            }
        }
    }
    return deadZone;
}