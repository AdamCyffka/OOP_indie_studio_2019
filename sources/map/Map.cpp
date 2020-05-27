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

std::map<int, std::map<int, blockState>> &Map::getMap()
{
	return _map;
}

std::map<int, std::map<int, bombState>> &Map::getBombMap()
{
	return _bombMap;
}

std::map<int, std::map<int, playerState>> &Map::getPlayerMap()
{
	return _playerMap;
}

void Map::generateMap()
{
	std::map<int, blockState> line;
	std::map<int, bombState> bombLine;
	std::map<int, playerState> playerLine;

	addHeaderLine();
	for (int i = 1; i < MAP_HEIGHT + 1; ++i) {
		line[0] = unbreakable;
		bombLine[0] = block;
		playerLine[0] = obstacle;
		for (int j = 1; j < MAP_WIDTH + 1; ++j) {
			int res = generateBlock();
			if (res == 0) {
				line[j] = empty;
				bombLine[j] = clear;
				playerLine[j] = none;
			} else if (res == 1) {
				line[j] = breakable;
				bombLine[j] = block;
				playerLine[j] = obstacle;
			} else if (res == 2) {
				line[j] = unbreakable;
				bombLine[j] = block;
				playerLine[j] = obstacle;
			} else {
				throw MapException("Unexpected value found : generateBlock()");
			}
		}
		line[MAP_WIDTH + 1] = unbreakable;
		bombLine[MAP_WIDTH + 1] = block;
		playerLine[MAP_WIDTH + 1] = obstacle;
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
	if (x <= 2)
		return 0;
	return 1;
}

void Map::addHeaderLine()
{
	std::map<int, blockState> line;
	std::map<int, bombState> bombLine;
	std::map<int, playerState> playerLine;

	for (int j = 0; j < MAP_WIDTH + 2; ++j) {
		line[j] = unbreakable;
		bombLine[j] = block;
		playerLine[j] = obstacle;
	}
	_map[0] = line;
	_bombMap[0] = bombLine;
	_playerMap[0] = playerLine;
	line.clear();
}

void Map::addFooterLine()
{
	std::map<int, blockState> line;
	std::map<int, bombState> bombLine;
	std::map<int, playerState> playerLine;

	for (int j = 0; j < MAP_WIDTH + 2; ++j) {
		line[j] = unbreakable;
		bombLine[j] = block;
		playerLine[j] = obstacle;
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
	_map[1][1] = empty;
	_map[1][2] = empty;
	_map[2][1] = empty;
	_bombMap[1][1] = clear;
	_bombMap[1][2] = clear;
	_bombMap[2][1] = clear;
	_playerMap[1][1] = playerOne;

	//Player 2
	_map[1][lineLen] = empty;
	_map[1][lineLen - 1] = empty;
	_map[2][lineLen] = empty;
	_bombMap[1][lineLen] = clear;
	_bombMap[1][lineLen - 1] = clear;
	_bombMap[2][lineLen] = clear;
	_playerMap[1][lineLen] = playerTwo;

	//Player 3
	_map[columnLen][1] = empty;
	_map[columnLen][2] = empty;
	_map[columnLen - 1][1] = empty;
	_bombMap[columnLen][1] = clear;
	_bombMap[columnLen][2] = clear;
	_bombMap[columnLen - 1][1] = clear;
	_playerMap[columnLen][1] = playerThree;

	//Player 4
	_map[columnLen][lineLen] = empty;
	_map[columnLen][lineLen - 1] = empty;
	_map[columnLen - 1][lineLen] = empty;
	_bombMap[columnLen][lineLen] = clear;
	_bombMap[columnLen][lineLen - 1] = clear;
	_bombMap[columnLen - 1][lineLen] = clear;
	_playerMap[columnLen][lineLen] = playerFour;
}

void Map::addWalls()
{
	for (int i = 2; i < MAP_HEIGHT; i += 2)
		for (int j = 2; j < MAP_WIDTH; j += 2) {
			_map[i][j] = unbreakable;
			_bombMap[i][j] = block;
			_playerMap[i][j] = obstacle;
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

std::pair<int, int> Map::getPlayerPosition(int playerNb)
{
	std::pair<int, int> pos;
	for (const auto &column : _playerMap) {
		for (auto line : column.second) {
			if ((playerNb == 1 && line.second == playerOne) ||
				(playerNb == 2 && line.second == playerTwo) ||
				(playerNb == 3 && line.second == playerThree) ||
				(playerNb == 4 && line.second == playerFour)) {
				pos = std::make_pair(column.first, line.first);
				return pos;
			}
		}
	}
	throw MapException("Could not find player " + std::to_string(playerNb));
}

void Map::setPlayerPosition(int z, int x, int playerNb)
{
	std::pair<int, int> pos = getPlayerPosition(playerNb);
	_playerMap[pos.first][pos.second] = none;
	switch (playerNb) {
	case 1:
		_playerMap[pos.first + z][pos.second + x] = playerOne;
		break;
	case 2:
		_playerMap[pos.first + z][pos.second + x] = playerTwo;
		break;
	case 3:
		_playerMap[pos.first + z][pos.second + x] = playerThree;
		break;
	case 4:
		_playerMap[pos.first + z][pos.second + x] = playerFour;
		break;
	default:
		break;
	}
}
