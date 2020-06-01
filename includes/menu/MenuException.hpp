/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** MenuException
*/

#ifndef MENUEXCEPTION_HPP_
#define MENUEXCEPTION_HPP_

#include <iostream>

class MenuException : public std::exception {
    public:
        MenuException(const std::string &msg) : _msg("Menu exception : " + msg) {}
        const char *what() const noexcept override {return _msg.data();}
    protected:
    private:
        std::string _msg;
};

#endif /* !MENUEXCEPTION_HPP_ */
