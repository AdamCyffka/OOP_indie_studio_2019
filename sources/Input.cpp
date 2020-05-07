/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** Event
*/

#include <iostream>
#include <irrlicht.h>
#include "Input.hpp"

using namespace irr;

void Joystick (IrrlichtDevice* device, Input receiver) //Fonction de l'exemple
{
    core::array<SJoystickInfo> joystickInfo;
    
    if(device->activateJoysticks(joystickInfo))
    {
        std::cout << "Joystick support is enabled and " << joystickInfo.size() << " joystick(s) are present." << std::endl;

        for (u32 joystick = 0; joystick < joystickInfo.size(); ++joystick) {
            std::cout << "Joystick " << joystick << ":" << std::endl;
            std::cout << "\tName: '" << joystickInfo[joystick].Name.c_str() << "'" << std::endl;
            std::cout << "\tAxes: " << joystickInfo[joystick].Axes << std::endl;
            std::cout << "\tButtons: " << joystickInfo[joystick].Buttons << std::endl;

            std::cout << "\tHat is: ";

            switch(joystickInfo[joystick].PovHat)
            {
            case SJoystickInfo::POV_HAT_PRESENT:
                std::cout << "present" << std::endl;
                break;

            case SJoystickInfo::POV_HAT_ABSENT:
                std::cout << "absent" << std::endl;
                break;

            case SJoystickInfo::POV_HAT_UNKNOWN:
            default:
                std::cout << "unknown" << std::endl;
                break;
            }
        }
    } else {
        std::cout << "Joystick support is not enabled." << std::endl;
    }

    core::stringw tmp = L"Irrlicht Joystick Example (";
    tmp += joystickInfo.size();
    tmp += " joysticks)";
    
    
    bool movedWithJoystick = false;
        
    if(joystickInfo.size() > 0)
    {
        f32 moveHorizontal = 0.f; // Range is -1.f for full left to +1.f for full right
        f32 moveVertical = 0.f; // -1.f for full down to +1.f for full up.

        const SEvent::SJoystickEvent & joystickData = receiver.GetJoystickState();

        // We receive the full analog range of the axes, and so have to implement our
        // own dead zone.  This is an empirical value, since some joysticks have more
        // jitter or creep around the center point than others.  We'll use 5% of the
        // range as the dead zone, but generally you would want to give the user the
        // option to change this.
        const f32 DEAD_ZONE = 0.05f;

        moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
        if(fabs(moveHorizontal) < DEAD_ZONE)
            moveHorizontal = 0.f;
        moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
        if(fabs(moveVertical) < DEAD_ZONE)
            moveVertical = 0.f;

        // POV hat info is only currently supported on Windows, but the value is
        // guaranteed to be 65535 if it's not supported, so we can check its range.
        const u16 povDegrees = joystickData.POV / 100;
        if(povDegrees < 360)
        {
            if(povDegrees > 0 && povDegrees < 180)
                moveHorizontal = 1.f;
            else if(povDegrees > 180)
                moveHorizontal = -1.f;
            if(povDegrees > 90 && povDegrees < 270)
                moveVertical = -1.f;
            else if(povDegrees > 270 || povDegrees < 90)
                moveVertical = +1.f;
        }
    }
}

Key_mouvement keyBoard (Input receiver)
{
    if(receiver.IsKeyDown(irr::KEY_KEY_Z))
        return (Up);
    else if(receiver.IsKeyDown(irr::KEY_KEY_S))
        return (Down);
    if(receiver.IsKeyDown(irr::KEY_KEY_Q))
        return (Left);
    else if(receiver.IsKeyDown(irr::KEY_KEY_D))
        return (Right);

}

Key_mouvement getInput(IrrlichtDevice* device, Input receiver)
{
    return (keyBoard(receiver));
}

bool Input::IsKeyDown(EKEY_CODE keyCode)
{
    return KeyIsDown[keyCode];
}

const SEvent::SJoystickEvent &Input::GetJoystickState(void) const
{
    return JoystickState;
}

bool Input::OnEvent(const SEvent& event) 
{
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0) {
        JoystickState = event.JoystickEvent;
    }
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
            KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
    return false;
}

Input::Input()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
}

Input::~Input()
{

}