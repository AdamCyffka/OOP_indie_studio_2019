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
        MyEventReceiver(irr::IrrlichtDevice *window, Core &core, CameraTravelManager *cameraTravelManager);
        bool OnEvent(const irr::SEvent &event) override;
        bool clicks(const irr::SEvent &event);
        bool IsKeyDown(irr::EKEY_CODE keyCode) const;
        bool keyHasBeenPressed(irr::EKEY_CODE keyCode) const;
    private:
        bool _keyDown[irr::KEY_KEY_CODES_COUNT];
        bool _keyPressed[irr::KEY_KEY_CODES_COUNT];
        Core &_core;
        irr::IrrlichtDevice *_window;
        CameraTravelManager *_cameraTravelManager;
};

#endif /* !MYEVENTRECEIVER_HPP_ */