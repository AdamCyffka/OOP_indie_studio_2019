/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map class
*/

#ifndef MAP_HPP
#define MAP_HPP

#include "MapException.hpp"
#include "EnumCheck.hpp"
#include <irrlicht.h>
#include <vector>
#include <random>
#include <string>
#include <iostream>
#include <map>

#define MAP_WIDTH 17
#define MAP_HEIGHT 11

enum blockState {
	empty,
	breakable,
	unbreakable
};

enum bombState {
	clear,
	bomb,
	block
};

enum playerState {
	none,
	playerOne,
	playerTwo,
	playerThree,
	playerFour,
	obstacle
};

using blockStateCheck = EnumCheck<blockState, blockState::empty, blockState::breakable, blockState::unbreakable>;

using bombStateCheck = EnumCheck<bombState, bombState::clear, bombState::bomb, bombState::block>;

using playerStateCheck = EnumCheck<playerState, playerState::none, playerState::playerOne, playerState::playerTwo, playerState::playerThree, playerState::playerFour, playerState::obstacle>;

class Map {
	public:
		Map();
		~Map();

		std::map<int, std::map<int, blockState>> &getMap();
		std::map<int, std::map<int, bombState>> &getBombMap();
		std::map<int, std::map<irr::f32, irr::f32>> &getPlayerMap();
		void printMap();
		void generateMap();

	private:
		int generateBlock();
		void addHeaderLine();
		void addFooterLine();
		void addPlayersSpawns();
		void addWalls();
		std::map<int, std::map<int, blockState>> _map;
		std::map<int, std::map<int, bombState>> _bombMap;
};

#endif