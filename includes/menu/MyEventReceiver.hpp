/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#ifndef MYEVENTRECEIVER_HPP_
#define MYEVENTRECEIVER_HPP_

#include <irrlicht.h>

class MyEventReceiver : public irr::IEventReceiver {
    public:
        MyEventReceiver(irr::IrrlichtDevice *window) {};
        bool OnEvent(const irr::SEvent &event) override;
        bool clicks(const irr::SEvent &event);
    private:
        irr::IrrlichtDevice *_window;
};

#endif /* !MYEVENTRECEIVER_HPP_ */