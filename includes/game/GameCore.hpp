/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_

#include <map>
#include "IEntity.hpp"
#include "Input.hpp"
#include "Player.hpp"
#include "Ai.hpp"

class MyEventReceiver;
class Core;

class GameCore {
    public:
        GameCore(Core *core, const std::vector<Character *>&, std::map<int, Key_mouvement>, const std::vector<EntityType::EntityType> &);
        ~GameCore() = default;
		std::vector<IEntity *> getEntities() const;
		void init();
        void run();

    protected:
    private:
		void spawnPlayers();
    	bool gameOver();
		std::map<int, irr::core::vector3df> _spawnAreas;
		std::vector<IEntity *> _entities;
		Core *_core;
		Map *_map;
		MyEventReceiver *_receiver;
};

#endif /* !GAMECORE_HPP_ */