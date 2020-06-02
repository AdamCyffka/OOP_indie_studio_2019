/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb management
*/

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <irrlicht.h>

#include "IEntity.hpp"

#include "Player.hpp"
#include "Ai.hpp"
#include "Map.hpp"

#include <mutex>
#include <chrono>
#include <thread>
#include <ctime>
#include <vector>

#define TIMER (3000)

using namespace std::chrono_literals;

class Bomby : public IEntity {
    public:
        Bomby(Character *, Map *, Player *, AI *);
        ~Bomby();
        void setRadius(int radius);
        int getRadius() const;
        void setIsBlast(bool isBlast);
        bool getIsBlast() const;
        void setPosition(std::pair<int, int>);
        std::pair<int, int> getPosition() const;

        void poseBomb();
        bool canPoseBomb();
        bool hasEnoughBombToPose();
        bool isKilledByBomb();
    private:
        Map *_map;
        std::pair<int, int> _position;
        Character *_character;
        Player *_player;
        AI *_ai;

        int _radius;
        irr::u32 _delay;

        bool _isBlast;
        bool addExplosion(bool);
    protected:
};

void waiter();

#endif /* !__BOMB_HPP__ */