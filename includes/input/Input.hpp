/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** Event
*/

#ifndef input
#define input

#include <map>
#include "irrlicht.h"

using namespace irr;                    // NONE A PAS OUBLIER , POUR NON TOUCHE OU TOUCHE NON BIND

enum Key_mouvement
{
    Right = 1 ,
    Left = 2 ,
    Up = 3 ,
    Down = 4,
    Exit = 6,
    None = 666
};

class Input : public IEventReceiver
{
    public:
        const SEvent::SJoystickEvent &GetJoystickStatePone(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePtwo(void) const;
	    virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
        bool IsKeyPressed(Input receiver);
        void keyBoard(Input receiver);
        std::map<int, Key_mouvement> getPlayerInput();
	    Input();
        ~Input();

    private:
	    bool KeyIsDown[KEY_KEY_CODES_COUNT];
        bool _keyIsPressed;
        std::map<int, Key_mouvement> _playerInput;
        SEvent::SJoystickEvent JoystickStatePone;
        SEvent::SJoystickEvent JoystickStatePtwo;
};


#endif //input