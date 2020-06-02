/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#include "Bomb.hpp"

Bomby::Bomby(Character *character, Map *map, Player *player, AI *ai): _radius(2), _delay(TIMER), _map(map),
_character(character), _player(player), _ai(ai), _isBlast(false)
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

bool Bomby::addExplosion(bool inGame)
{
    if (inGame == true) { // mis en pause !...
        return (true);
    }
    return (false);
}

bool Bomby::canPoseBomb()
{
    //if ((_map->getMap() == blockState::empty) && (_map->getBombMap() == bombState::clear)) { // Erreur bad used
    //    return (true);
    //} else {
    //    return (false);
    //}
    return (true);
}

bool Bomby::hasEnoughBombToPose()
{
    //if (_ai->getBombAmount() > 0 ) {
    //    return (true);
    //} else {
    //    return (false);
    //}
    return (true);
}

void waiter()
{
    //std::cout << "Bomb waiting" << std::endl;
    std::this_thread::sleep_for(3s);
}

void Bomby::poseBomb()
{
    std::mutex mutex;
    if (canPoseBomb() == true && hasEnoughBombToPose() == true) {
        //pose la bombe et edit map
        {
            mutex.lock();
            std::thread t1(waiter); // attend 3 s
            t1.detach();
            mutex.unlock();
            setIsBlast(true); // active l'explosion
            if (getIsBlast() == true) {
                //anim explosion
                setIsBlast(false); // explosion fini
            }
        }
    }
}

bool Bomby::isKilledByBomb()
{
    return (false); // pas encore implementer!
}