/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** GameCore
*/

#ifndef GAMECORE_HPP_
#define GAMECORE_HPP_

#include <map>
#include <memory>
#include "IEntity.hpp"
#include "Input.hpp"
#include "Player.hpp"
#include "Ai.hpp"
#include "Bomber.hpp"

#include "IPowerUps.hpp"
#include "BombDown.hpp"
#include "BombFull.hpp"
#include "BombPass.hpp"
#include "BombUp.hpp"
#include "FireDown.hpp"
#include "FireFull.hpp"
#include "FireUp.hpp"
#include "SpeedDown.hpp"
#include "SpeedUp.hpp"
#include "WallPass.hpp"

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
		void nextRound();
        bool isInit() const;
		bool nextBlockHasBomb(std::pair<int, int>, bool);
		bool nextBlockHasWall(std::pair<int, int>);
		bool nextBlockHasBlock(std::pair<int, int>, bool);
		Bomber *getBomber();
		Core *getCore();
		std::vector<std::pair<int, int>> getRanking();
    protected:
    private:
	 	std::vector<std::unique_ptr<IPowerUps>> _powerUps;
		void addBonus(irr::core::vector3df &pos);
		void spawnPlayers();
    	bool gameOver();
		int getRemainingEntities();
		std::map<int, irr::core::vector3df> _spawnAreas;
		std::vector<IEntity *> _entities;
		bool _isPaused;
		bool _isWaiting;
		bool _isInit;
		Core *_core;
		Map *_map;
		LoadMap *_loadMap;
		MyEventReceiver *_receiver;
		Bomber *_bomber;
};

#endif /* !GAMECORE_HPP_ */