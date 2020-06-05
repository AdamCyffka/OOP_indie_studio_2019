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
#include "Bomber.hpp"

class MyEventReceiver;
class Core;

class GameCore {
    public:
        GameCore(Core *core);
        ~GameCore() = default;
		std::vector<IEntity *> getEntities() const;
		void init(const std::vector<Character *> characters, const std::vector<EntityType::EntityType> entityTypes, std::vector<EntityType::ControlType> controlTypes);
        void run();

        void setPause(bool);
        void reset();
        bool isInit() const;
		bool nextBlockHasBomb(std::pair<int, int>, bool);
		bool nextBlockHasWall(std::pair<int, int>);
		bool nextBlockHasBlock(std::pair<int, int>, bool);
		Bomber *getBomber();
		Core *getCore();
    protected:
    private:
		void spawnPlayers();
    	bool gameOver();
		std::map<int, irr::core::vector3df> _spawnAreas;
		std::vector<IEntity *> _entities;
		bool _isPaused;
		bool _isInit;
		Core *_core;
		Map *_map;
		MyEventReceiver *_receiver;
		Bomber *_bomber;
};

#endif /* !GAMECORE_HPP_ */