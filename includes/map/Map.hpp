/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map class
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <random>
#include <iostream>
#include <map>

#define MAP_WIDTH 17
#define MAP_HEIGHT 11

class Map {
	public:
		Map();
		~Map();

		const std::map<int, std::map<int, int>> &getMap();
		void printMap();

	private:
		void generateMap();
		int generateBlock();
		void addPlayersSpawns();
		void addWalls();
		std::map<int, std::map<int, int>> _map;
};

#endif