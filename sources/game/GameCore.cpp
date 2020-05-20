/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include "GameCore.hpp"
#include "GameCoreException.hpp"

GameCore::GameCore(const std::vector<Character *> &characters, std::map<int, Key_mouvement> inputs, const std::vector<EntityType::EntityType> &entityTypes)
{
	if (characters.size() != 4)
		throw GameCoreException("Wrong size of character vector");

	auto itChar = characters.begin();
	auto itTypes = entityTypes.begin();
	for (int i = 1; i <= 4; ++i)
	{
		IEntity *entity;
		if (*itTypes == EntityType::EntityType::AI)
			entity = new AI(*itChar, i);
		else
			entity = new Player(*itChar, inputs[i], i);
		++itChar;
		++itTypes;
		_entities.push_back(entity);
	}
	_spawnAreas[1] = irr::core::vector3df{0.0f, 0.0f, 0.0f};
	_spawnAreas[2] = irr::core::vector3df{0.0f, 0.0f, 0.0f};
	_spawnAreas[3] = irr::core::vector3df{0.0f, 0.0f, 0.0f};
	_spawnAreas[4] = irr::core::vector3df{0.0f, 0.0f, 0.0f};
}

void GameCore::init()
{
	spawnPlayers();
}

void GameCore::run()
{
	std::cout << _entities.size() << std::endl;
}

void GameCore::spawnPlayers()
{

}
