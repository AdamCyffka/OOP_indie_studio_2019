/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomby::Bomby(Character *character, Map *map, Player *player, AI *ai, std::vector<IEntity *> entities): _radius(2), _delay(TIMER), _map(map),
_character(character), _player(player), _ai(ai), _entities(entities), _isBlast(false)
{
}

Bomby::~Bomby()
{
}

void Bomby::setRadius(int radius)
{
    this->_radius = radius;
}

int	Bomby::getRadius() const
{
    return (this->_radius);
}

void Bomby::setIsBlast(bool isBlast)
{
    this->_isBlast = isBlast;
}

bool Bomby::getIsBlast() const
{
    return (this->_isBlast);
}

std::pair<int, int> Bomby::getPosition() const
{
    return (this->_position);
}

void Bomby::setPosition(std::pair<int, int> position)
{
    this->_position = position;
}

bool Bomby::canPoseBomb()
{

    //if ((_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == blockState::empty)
    //&& (_map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::clear)) { // crash why ?! bad used probably
        return (true);
    //} else {
    //    return (false);
    //}
}

bool Bomby::hasEnoughBombToPose()
{
    if (_ai->getInput() == Key_mouvement::Ia && _ai->getBombAmount() >= 0) {
        return (true);
    //} else if (_player->getInput() == Key_mouvement::Bomb && _player->getBombAmount() >= 0) { //crash pour le player why not even using like ai!!
    //    return (true);
    } else {
        return (false);
    }
}

void waiter()
{
    std::this_thread::sleep_for(3s);
}

void Bomby::poseBomb()
{
    std::mutex mutex;
    //irr::core::vector3df pos = _character->getPosition(); crash ?!

    if (canPoseBomb() == true && hasEnoughBombToPose() == true) {
        //_map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::bomb; // edit map to pose bomb | crash why ?! bad used probably
        {
            mutex.lock();
            std::thread t1(waiter); // attend 3 s some bug currently
            t1.detach();
            mutex.unlock();
            setIsBlast(true); // active l'explosion
            if (getIsBlast() == true) {
                //anim explosion
                //_map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::clear; // edit map bomb a explosé | crash why ?! bad used probably
                setIsBlast(false); // explosion fini
            }
        }
    }
}

bool Bomby::isKilledByBomb()
{
    return (false); // pas encore implementer!
}