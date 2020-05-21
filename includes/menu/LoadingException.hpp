/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** LoadingException
*/

#ifndef LOADING_EXCEPTION_HPP
#define LOADING_EXCEPTION_HPP

#include <iostream>

class LoadingException : public std::exception {
	public:
	LoadingException(const std::string &msg) : _msg("Loading exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif
