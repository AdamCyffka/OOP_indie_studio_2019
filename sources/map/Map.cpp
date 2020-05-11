/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map
*/

#include "Map.hpp"

Map::Map()
{
	generateMap();
}

Map::~Map() = default;

const std::map<int, std::map<int, BlockState>> &Map::getMap()
{
	return _map;
}

const std::map<int, std::map<int, BombState>> &Map::getBombMap() const
{
	return _bombMap;
}

const std::map<int, std::map<int, PlayerState>> &Map::getPlayerMap() const
{
	return _playerMap;
}

void Map::generateMap()
{
	std::map<int, BlockState> line;
	std::map<int, BombState> bombLine;
	std::map<int, PlayerState> playerLine;

	addHeaderLine();
	for (int i = 1; i < MAP_HEIGHT + 1; ++i) {
		line[0] = UNBREAKABLE;
		bombLine[0] = BLOCK;
		playerLine[0] = OBSTACLE;
		for (int j = 1; j < MAP_WIDTH + 1; ++j) {
			int res = generateBlock();
			if (res == 0) {
				line[j] = EMPTY;
				bombLine[j] = CLEAR;
				playerLine[j] = NONE;
			} else if (res == 1) {
				line[j] = BREAKABLE;
				bombLine[j] = BLOCK;
				playerLine[j] = OBSTACLE;
			} else if (res == 2) {
				line[j] = UNBREAKABLE;
				bombLine[j] = BLOCK;
				playerLine[j] = OBSTACLE;
			} else {
				throw MapException("Unexpected value found : generateBlock()");
			}
		}
		line[MAP_WIDTH + 1] = UNBREAKABLE;
		bombLine[MAP_WIDTH + 1] = BLOCK;
		playerLine[MAP_WIDTH + 1] = OBSTACLE;
		_map[i] = line;
		_bombMap[i] = bombLine;
		_playerMap[i] = playerLine;
		line.clear();
		bombLine.clear();
		playerLine.clear();
	}
	addFooterLine();
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

void Map::addHeaderLine()
{
	std::map<int, BlockState> line;
	std::map<int, BombState> bombLine;
	std::map<int, PlayerState> playerLine;

	for (int j = 0; j < MAP_WIDTH + 2; ++j) {
		line[j] = UNBREAKABLE;
		bombLine[j] = BLOCK;
		playerLine[j] = OBSTACLE;
	}
	_map[0] = line;
	_bombMap[0] = bombLine;
	_playerMap[0] = playerLine;
	line.clear();
}

void Map::addFooterLine()
{
	std::map<int, BlockState> line;
	std::map<int, BombState> bombLine;
	std::map<int, PlayerState> playerLine;

	for (int j = 0; j < MAP_WIDTH + 2; ++j) {
		line[j] = UNBREAKABLE;
		bombLine[j] = BLOCK;
		playerLine[j] = OBSTACLE;
	}
	_map[MAP_HEIGHT + 1] = line;
	_bombMap[MAP_HEIGHT + 1] = bombLine;
	_playerMap[MAP_HEIGHT + 1] = playerLine;
}

void Map::addPlayersSpawns()
{
	int lineLen = MAP_WIDTH;
	int columnLen = MAP_HEIGHT;

	//Player 1
	_map[1][1] = EMPTY;
	_map[1][2] = EMPTY;
	_map[2][1] = EMPTY;
	_bombMap[1][1] = CLEAR;
	_bombMap[1][2] = CLEAR;
	_bombMap[2][1] = CLEAR;
	_playerMap[1][1] = PLAYER_ONE;

	//Player 2
	_map[1][lineLen] = EMPTY;
	_map[1][lineLen - 1] = EMPTY;
	_map[2][lineLen] = EMPTY;
	_bombMap[1][lineLen] = CLEAR;
	_bombMap[1][lineLen - 1] = CLEAR;
	_bombMap[2][lineLen] = CLEAR;
	_playerMap[1][lineLen] = PLAYER_TWO;

	//Player 3
	_map[columnLen][1] = EMPTY;
	_map[columnLen][2] = EMPTY;
	_map[columnLen - 1][1] = EMPTY;
	_bombMap[columnLen][1] = CLEAR;
	_bombMap[columnLen][2] = CLEAR;
	_bombMap[columnLen - 1][1] = CLEAR;
	_playerMap[columnLen][1] = PLAYER_THREE;

	//Player 4
	_map[columnLen][lineLen] = EMPTY;
	_map[columnLen][lineLen - 1] = EMPTY;
	_map[columnLen - 1][lineLen] = EMPTY;
	_bombMap[columnLen][lineLen] = CLEAR;
	_bombMap[columnLen][lineLen - 1] = CLEAR;
	_bombMap[columnLen - 1][lineLen] = CLEAR;
	_playerMap[columnLen][lineLen] = PLAYER_FOUR;
}

void Map::addWalls()
{
	for (int i = 2; i < MAP_HEIGHT; i += 2)
		for (int j = 2; j < MAP_WIDTH; j += 2) {
			_map[i][j] = UNBREAKABLE;
			_bombMap[i][j] = BLOCK;
			_playerMap[i][j] = OBSTACLE;
		}
}

void Map::printMap()
{
	std::cout << "Main map" << std::endl;
	for (auto &l : _map) {
		for (auto &it : l.second)
			std::cout << it.second << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Bomb map" << std::endl;
	for (auto &l : _bombMap) {
		for (auto &it : l.second)
			std::cout << it.second << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Player map" << std::endl;
	for (auto &l : _playerMap) {
		for (auto &it : l.second)
			std::cout << it.second << " ";
		std::cout << std::endl;
	}
}
