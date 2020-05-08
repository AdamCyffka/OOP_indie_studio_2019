/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map
*/

#include "map/Map.hpp"

Map::Map()
{
	generateMap();
}

Map::~Map() = default;

const std::map<int, std::map<int, int>> &Map::getMap()
{
	return _map;
}

void Map::generateMap()
{
	std::map<int, int> line;

	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			line[j] = generateBlock();
		}
		_map[i] = line;
		line.clear();
	}
	addPlayersSpawns();
	addWalls();
}

int Map::generateBlock()
{
	std::random_device seeder;
	std::mt19937 rng(seeder());
	std::uniform_int_distribution<int> randHundred(0, 100);
	int x = randHundred(rng);
	if (x <= 15)
		return 0;
	return 1;
}

void Map::addPlayersSpawns()
{
	int lineLen = MAP_WIDTH - 1;
	int columnLen = MAP_HEIGHT - 1;

	//Player 1
	_map[0][0] = 0;
	_map[0][1] = 0;
	_map[1][0] = 0;

	//Player 2
	_map[0][lineLen] = 0;
	_map[0][lineLen - 1] = 0;
	_map[1][lineLen] = 0;

	//Player 3
	_map[columnLen][0] = 0;
	_map[columnLen][1] = 0;
	_map[columnLen - 1][0] = 0;

	//Player 4
	_map[columnLen][lineLen] = 0;
	_map[columnLen][lineLen - 1] = 0;
	_map[columnLen - 1][lineLen] = 0;
}

void Map::addWalls()
{
	for (int i = 1; i < MAP_HEIGHT; i += 2)
		for (int j = 1; j < MAP_WIDTH; j += 2)
			_map[i][j] = 2;
}

void Map::printMap()
{
	for (auto &l : _map) {
		for (auto &it : l.second)
			std::cout << it.second << " ";
		std::cout << std::endl;
	}
}
