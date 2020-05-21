/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** GameCoreException
*/

#ifndef GAMECORE_EXCEPTION_HPP
#define GAMECORE_EXCEPTION_HPP

#include <iostream>

class GameCoreException : public std::exception {
	public:
	GameCoreException(const std::string &msg) : _msg("GameCore exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif
