/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, char **av)
{
#ifdef __linux__
	if (!getenv("DISPLAY")) {
		std::cerr << "Error : some environment variable are missing." << std::endl;
		return (84);
    }
#endif
	if (ac != 1) {
		std::cerr << "Error : " << av[0] << " does not take any argument !" << std::endl;
		return (84);
	}
	try {
		Core launch;
		launch.run();
	} catch (std::exception const &msg) {
		std::cerr << msg.what() << std::endl;
		return (84);
	}
	return (0);
}