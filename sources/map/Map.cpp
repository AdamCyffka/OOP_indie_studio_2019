/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map
*/

#include "map/Map.hpp"
//#include <boost/random.hpp>

Map::Map()
{
	generateMap();
}

Map::~Map() = default;

const std::vector<std::vector<int>> &Map::getMap()
{
	return _map;
}

void Map::generateMap()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			_map[i][j] = generateBlock();
		}
	}
}

int Map::generateBlock()
{
	return -1;
}
