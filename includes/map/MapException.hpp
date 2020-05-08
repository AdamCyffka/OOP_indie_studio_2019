/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** MapException
*/

#ifndef MAPEXCEPTION_HPP_
#define MAPEXCEPTION_HPP_

#include <iostream>

class MapException : public std::exception {
	public:
	MapException(const std::string &msg) : _msg("Map exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif