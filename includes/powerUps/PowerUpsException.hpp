/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** PowerUpsException
*/

#ifndef POWERUPSEXCEPTION_HPP_
#define POWERUPSEXCEPTION_HPP_

#include <iostream>

class PowerUpsException : public std::exception {
    public:
        PowerUpsException(const std::string &msg) : _msg("Power Up exception : " + msg) {}
        const char *what() const noexcept override {return _msg.data();}
    protected:
    private:
        std::string _msg;
};

#endif /* !POWERUPSEXCEPTION_HPP_ */