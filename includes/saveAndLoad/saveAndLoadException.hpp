/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** SaveAndLoadException
*/

#ifndef SAVE_AND_LOAD_EXCEPTION_HPP
#define SAVE_AND_LOAD_EXCEPTION_HPP

#include <iostream>

class saveAndLoadException : public std::exception {
	public:
	saveAndLoadException(const std::string &msg) : _msg("saveAndLoad exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif
