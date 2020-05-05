/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** CharacterException
*/

#ifndef CHARACTEREXCEPTION_HPP_
#define CHARACTEREXCEPTION_HPP_

#include <iostream>

class CharacterException : public std::exception {
    public:
        CharacterException(const std::string &msg) : _msg("Character exception : " + msg) {}
        const char *what() const noexcept override {return _msg.data();}
    protected:
    private:
        std::string _msg;
};

#endif /* !CHARACTEREXCEPTION_HPP_ */
