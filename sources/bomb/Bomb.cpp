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
    //if (_ai->getInput() == Key_mouvement::Ia && _ai->getBombAmount() > 0) { // crash random
    //    _ai->setBombAmount(_ai->getBombAmount() - 1);
        return (true);
    //} else if (_player->getInput() == Key_mouvement::Bomb && _player->getBombAmount() > 0) {
    //    _player->setBombAmount(_player->getBombAmount() - 1);
    //    return (true);
    //} else {
    //    return (false);
    //}
}

void waiter()
{
    std::this_thread::sleep_for(3s);
}

void Bomby::poseBomb()
{
    std::mutex mutex;

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
                { // edit map to break block
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x + 1][squareWherePlayerIs(this, _map).y] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x + 1][squareWherePlayerIs(this, _map).y] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x + 1][squareWherePlayerIs(this, _map).y] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x + 2][squareWherePlayerIs(this, _map).y] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x + 2][squareWherePlayerIs(this, _map).y] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x + 2][squareWherePlayerIs(this, _map).y] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x - 1][squareWherePlayerIs(this, _map).y] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x - 1][squareWherePlayerIs(this, _map).y] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x - 1][squareWherePlayerIs(this, _map).y] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x - 2][squareWherePlayerIs(this, _map).y] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x - 2][squareWherePlayerIs(this, _map).y] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x - 2][squareWherePlayerIs(this, _map).y] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 1] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 1] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 1] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 2] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 2] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y + 2] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 1] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 1] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 1] == blockState::empty;
                    //if (_map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 2] == blockState::breakable || _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 2] == blockState::empty)
                    //    _map->getMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y - 2] == blockState::empty;
                }
                //_map->getBombMap()[squareWherePlayerIs(this, _map).x][squareWherePlayerIs(this, _map).y] == bombState::clear; // edit map bomb a explosé | crash why ?! bad used probably
                setIsBlast(false); // explosion fini
                //if (_ai->getInput() == Key_mouvement::Ia)
                //    _ai->setBombAmount(_ai->getBombAmount() + 1);
                //if (_player->getInput() == Key_mouvement::Down || _player->getInput() == Key_mouvement::Left || _player->getInput() == Key_mouvement::Right || _player->getInput() == Key_mouvement::Up)
                //    _player->setBombAmount(_player->getBombAmount() + 1); // crash with player class like hasEnoughtBombToPose function
            }
        }
    }
}

bool Bomby::isKilledByBomb()
{
    return (false); // pas encore implementer!
}