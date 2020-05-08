/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map class
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "MapException.hpp"
#include <vector>
#include <random>
#include <iostream>
#include <map>

#define MAP_WIDTH 17
#define MAP_HEIGHT 11

enum BlockState {
	EMPTY,
	BREAKABLE,
	UNBREAKABLE
};

enum BombState {
	CLEAR,
	BOMB,
	BLOCK
};

enum PlayerState {
	NONE,
	PLAYER_ONE,
	PLAYER_TWO,
	PLAYER_THREE,
	PLAYER_FOUR,
	OBSTACLE
};

class Map {
	public:
		Map();
		~Map();

		const std::map<int, std::map<int, BlockState>> &getMap();
		const std::map<int, std::map<int, BombState>> &getBombMap() const;
		const std::map<int, std::map<int, PlayerState>> &getPlayerMap() const;
		void printMap();

	private:
		void generateMap();
		int generateBlock();
		void addHeaderLine();
		void addFooterLine();
		void addPlayersSpawns();
		void addWalls();
		std::map<int, std::map<int, BlockState>> _map;
		std::map<int, std::map<int, BombState>> _bombMap;
		std::map<int, std::map<int, PlayerState>> _playerMap;
};

#endif