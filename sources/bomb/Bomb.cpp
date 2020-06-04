/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomber::Bomber(Map *map, irr::scene::ISceneManager *smgr): _smgr(smgr), _radius(2), _delay(TIMER), _map(map), _isBlast(false)
{
    for (int i = 0; i < 4; i++) {
        irr::scene::IAnimatedMeshSceneNode *bomb;
        bomb = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("resources/models/bomb/model.obj"));
        if (bomb) {
            bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            bomb->setPosition({0, 0, 0});
            bomb->setScale({100, 100, 100});
            bomb->setVisible(false);
            _bombs.push_back({bomb, bombAvailability::free});
        }
    }
}

Bomber::~Bomber()
{
}

void Bomber::run()
{
    auto timeWhenPutBomb = std::chrono::system_clock::now();

    if (timeWhenPutBomb + _delay >= std::chrono::system_clock::now()) {
        setIsBlast(true);
    }

}

void Bomber::setRadius(int radius)
{
    this->_radius = radius;
}

int	Bomber::getRadius() const
{
    return (this->_radius);
}

void Bomber::setEntities(std::vector<IEntity *> entities)
{
    this->_entities = entities;
}

std::vector<IEntity *> Bomber::getEntities() const
{
    return (this->_entities);
}

void Bomber::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomber::getIsBlast() const
{
    return (this->_isBlast);
}

bool Bomber::canPutBomb(IEntity *it)
{
    if ((_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == blockState::empty) &&
    (_map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == bombState::clear)) {
        return (true);
    } else {
        return (false);
    }
}

bool Bomber::hasEnoughBombToPut()
{
    for (auto it : getEntities()) {
        std::cout << "BombAmount in Inventory "<< it->getBombAmount() << "\n" << std::endl;
		if (it->getBombAmount() > 0) {
            return (true);
        } else {
            return (false);
        }
	}
    return (true);
}

void Bomber::putBomb(IEntity *it)
{
    std::cout << "bomb function" << std::endl;
    if (canPutBomb(it) == true && hasEnoughBombToPut() == true) {
        std::cout << "in function" << std::endl;
        epicenter(it);
        for (auto bomb: _bombs) {
            if (bomb.second == bombAvailability::free) {
                bomb.first->setPosition(it->getCharacter()->getPosition());
                bomb.first->setVisible(true);
                bomb.second = bombAvailability::planted;
            }
        }
        removeBombFromInventory();
        setIsBlast(true);
        if (getIsBlast() == true) {
            {
                std::cout << "blast" << std::endl;
                blastNorth(it);
                blastSouth(it);
                blastEast(it);
                blastWest(it);
            }
            clearMapAfterBlast(it);
            // for (auto bomb: _bombs) {
            //     bomb.first->setVisible(false);
            // }
            setIsBlast(false);
            giveNewBombInInventory();
        }
    }
}

void Bomber::epicenter(IEntity *it)
{
    _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == bombState::bomb;
}

void Bomber::blastNorth(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(it, _map).x + i][squareWherePlayerIs(it, _map).y] == blockState::empty;
    }
}

void Bomber::blastSouth(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(it, _map).x - i][squareWherePlayerIs(it, _map).y] == blockState::empty;
    }
}

void Bomber::blastEast(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y + i] == blockState::empty;
    }
}

void Bomber::blastWest(IEntity *it)
{
    for (int i = 0; i != _radius; i++) {
        if (_map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] == blockState::breakable ||
        _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] == blockState::empty)
            _map->getMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y - i] == blockState::empty;
    }
}

void Bomber::clearMapAfterBlast(IEntity *it)
{
    _map->getBombMap()[squareWherePlayerIs(it, _map).x][squareWherePlayerIs(it, _map).y] == bombState::clear;
}

void Bomber::removeBombFromInventory()
{
    for (auto it : getEntities()) {
		it->setBombAmount(it->getBombAmount() - 1);
	}
}

void Bomber::giveNewBombInInventory()
{
    for (auto it : getEntities()) {
		it->setBombAmount(it->getBombAmount() + 1);
	}
}

bool Bomber::isKilledByBomb()
{
    for (auto it : getEntities()) {
        it->setIsAlive(false);
        it->getCharacter()->setVisibility(false);
	}
    return (true);
}