/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Map class
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#define MAP_WIDTH 30
#define MAP_HEIGHT 20

class Map {
	public:
		Map();
		~Map();

		const std::vector<std::vector<int>> &getMap();

	private:
		void generateMap();
		int generateBlock();
		std::vector<std::vector<int>> _map;
};

#endif