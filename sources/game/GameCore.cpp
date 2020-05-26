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

GameCore::GameCore(Core *core, const std::vector<Character *> &characters, std::map<int, Key_mouvement> inputs, const std::vector<EntityType::EntityType> &entityTypes)
{
	_core = core;
	_map = _core->getMap();
	if (characters.size() != 4)
		throw GameCoreException("Wrong size of character vector");

	auto itChar = characters.begin();
	auto itTypes = entityTypes.begin();
	for (int i = 1; i <= 4; ++i) {
		IEntity *entity;
		if (*itTypes == EntityType::EntityType::AI)
			entity = new AI(*itChar, i, _map);
		else
			entity = new Player(*itChar, inputs[i], i);
		++itChar;
		++itTypes;
		_entities.push_back(entity);
	}
	_spawnAreas[1] = irr::core::vector3df{-450.0f, 308.0f, 780.0f};
	_spawnAreas[2] = irr::core::vector3df{-450.0f, 308.0f, 620.0f};
	_spawnAreas[3] = irr::core::vector3df{-550.0f, 308.0f, 780.0f};
	_spawnAreas[4] = irr::core::vector3df{-550.0f, 308.0f, 620.0f};
}

void GameCore::init()
{
	spawnPlayers();
}

void GameCore::run()
{
	//+x = haut
	//-x = bas
	//+z = gauche
	//-z = droite

	//	for (auto it : _entities) {
	//		auto pos = it->getCharacter()->getPosition();
	//		pos.Z += 10;
	//		it->getCharacter()->moveTo(pos);
	//	}
	if (gameOver()) //toggle to skip game part
	{
		_core->setGState(Core::menu);
		_core->setLState(Core::menuScore);
		_core->getCameraTravelManager()->doTravel(CameraTravelManager::travel::gameToScore);
		_core->getScore()->spawnEntities();
		return;
	}
	for (auto it : _entities) {
		it->run();
	}
//	std::cout << "game running" << std::endl;
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
