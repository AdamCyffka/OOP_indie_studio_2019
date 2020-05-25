/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** CoreException
*/

#ifndef CORE_EXCEPTION_HPP
#define CORE_EXCEPTION_HPP

#include <iostream>

class CoreException : public std::exception {
	public:
	CoreException(const std::string &msg) : _msg("Core exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif
