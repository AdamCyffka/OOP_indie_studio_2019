/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "GameCore.hpp"
#include "Core.hpp"
#include "MyEventReceiver.hpp"
#include "GameCoreException.hpp"

GameCore::GameCore(Core *core)
{
	_core = core;
	_isInit = false;
	_isPaused = false;
	_map = _core->getMap();
	_spawnAreas[1] = irr::core::vector3df{-450.0f, 308.0f, 780.0f};
	_spawnAreas[2] = irr::core::vector3df{-450.0f, 308.0f, 620.0f};
	_spawnAreas[3] = irr::core::vector3df{-550.0f, 308.0f, 780.0f};
	_spawnAreas[4] = irr::core::vector3df{-550.0f, 308.0f, 620.0f};
}

void GameCore::reset()
{
	for (auto it : _entities) {
		delete it;
	}
	_entities.clear();
	_isPaused = false;
	_isInit = false;
}

void GameCore::init(const std::vector<Character *> characters, std::map<int, Key_mouvement> inputs, const std::vector<EntityType::EntityType> entityTypes)
{
	for (int i = 1; i <= 4; ++i) {
		IEntity *entity;
		if (entityTypes.at(i - 1) == EntityType::EntityType::AI)
			entity = new AI(characters.at(i - 1), i, _map);
		else
			entity = new Player(characters.at(i - 1), inputs[i], i, _map, this);
		_entities.push_back(entity);
	}
	spawnPlayers();
	for (auto it : _entities) {
		it->setIsAlive(true);
	}
	_isInit = true;
}

void GameCore::run()
{
	if (gameOver()) //toggle to skip game part
	{
		_core->setGState(Core::menu);
		_core->setLState(Core::menuScore);
		_core->getCameraTravelManager()->doTravel(CameraTravelManager::travel::gameToScore);
		_core->getScore()->spawnEntities();
		return;
	}
	if (_isPaused)
		return;
	for (auto it : _entities) {
		it->setInput(Right);
		it->run();
	}
}

void GameCore::spawnPlayers()
{
	int count = 1;

	for (auto it : _entities) {
		it->getCharacter()->setPosition(_spawnAreas[count]);
		it->getCharacter()->setVisibility(true);
		++count;
	}
}

bool GameCore::gameOver()
{
	for (auto it : _entities) {
		if (it->getWinNumber() >= 3)
			return (true);
	}
	return false;
}

std::vector<IEntity *> GameCore::getEntities() const
{
	return _entities;
}

void GameCore::setPause(bool state)
{
	_isPaused = state;
}

bool GameCore::isInit() const
{
	return _isInit;
}

bool GameCore::nextBlockHasBomb(std::pair<int, int> pos, bool powerUp)
{
	return _map->getBombMap()[pos.first][pos.second] == bomb && !powerUp;
}

bool GameCore::nextBlockHasWall(std::pair<int, int> pos)
{
	return _map->getMap()[pos.first][pos.second] == unbreakable;
}

bool GameCore::nextBlockHasBlock(std::pair<int, int> pos, bool powerUp)
{
	return _map->getMap()[pos.first][pos.second] == breakable && !powerUp;
}
