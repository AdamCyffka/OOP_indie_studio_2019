/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** BombException
*/

#ifndef BOMBEXCEPTION_HPP_
#define BOMBEXCEPTION_HPP_

#include <iostream>

class BombException : public std::exception {
	public:
	BombException(const std::string &msg) : _msg("Bomb exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif /* !BOMBEXCEPTION_HPP_ */
