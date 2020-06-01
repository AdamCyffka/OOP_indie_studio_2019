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
#include "Map.hpp"

#include <ctime>
#include <vector>

#define TIMER (3000)

class Bomb : public IEntity {
    public:
        Bomb(Character *character, Map *map, Player *player);
        ~Bomb();
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
        Player *_player;
        Character *_character;

        int _radius;
        irr::u32 _delay;

        bool _isBlast;
        bool addExplosion(bool inGame);
    protected:
};

#endif /* !__BOMB_HPP__ */