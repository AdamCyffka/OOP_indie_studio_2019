/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#ifndef MYEVENTRECEIVER_HPP_
#define MYEVENTRECEIVER_HPP_

#include "Core.hpp"
#include "CameraTravelManager.hpp"
#include "IMenu.hpp"
#include "Intro.hpp"
#include "saveAndLoad.hpp"

class MyEventReceiver : public irr::IEventReceiver {
    public:
        MyEventReceiver(irr::IrrlichtDevice *window, Core &core, CameraTravelManager *cameraTravelManager)
        : _window(window), _core(core), _cameraTravelManager(cameraTravelManager) {};
        bool OnEvent(const irr::SEvent &event) override;
        bool clicks(const irr::SEvent &event);
    private:
        Core &_core;
        irr::IrrlichtDevice *_window;
        CameraTravelManager *_cameraTravelManager;
};

#endif /* !MYEVENTRECEIVER_HPP_ */