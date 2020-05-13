/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#include "IGame.hpp"
#include "MyEventReceiver.hpp"

bool MyEventReceiver::clicks(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
                switch (id) {
                    case GUI_ID_QUIT_BUTTON:
                        _window->closeDevice();
                        return true;
                    case GUI_ID_OPTIONS_BUTTON:
                        //_core.setState(Core::mainOptions);
                        return true;
                }
            default:
                break;
        }
    }
    return false;
}

bool MyEventReceiver::OnEvent(const irr::SEvent &event)
{
    if (clicks(event))
        return true;
    return false;
}
