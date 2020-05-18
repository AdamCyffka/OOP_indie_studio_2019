/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** MusicException
*/

#ifndef MUSIC_EXCEPTION_HPP
#define MUSIC_EXCEPTION_HPP

#include <iostream>

class MusicException : public std::exception {
	public:
	MusicException(const std::string &msg) : _msg("Music exception : " + msg) {}
	const char *what() const noexcept override {return _msg.data();}
	protected:
	private:
	std::string _msg;
};

#endif
