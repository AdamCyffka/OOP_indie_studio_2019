/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CameraTravelException
*/

#ifndef CAMERATRAVELEXCEPTION_HPP_
#define CAMERATRAVELEXCEPTION_HPP_

#include <iostream>

class CameraTravelException : public std::exception {
    public:
        CameraTravelException(const std::string &msg) : _msg("Camera travel exception : " + msg) {}
        const char *what() const noexcept override {return _msg.data();}
    protected:
    private:
        std::string _msg;
};

#endif /* !CAMERATRAVELEXCEPTION_HPP_ */
