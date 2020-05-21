/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** Event
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <vector>
#include <map>
#include "irrlicht.h"

using namespace irr;                    // NONE A PAS OUBLIER , POUR NON TOUCHE OU TOUCHE NON BIND

enum device 
{
    Keyboard = 1,
    Controller = 2,
    No_device = 3
};

enum Key_mouvement
{
    Right = 1 ,
    Left = 2 ,
    Up = 3 ,
    Down = 4,
    Bomb = 6,
    Ia = 42,
    None = 666
};

class Input : public IEventReceiver
{
    public:
        bool IsKeyPressed(Input receiver);
        const SEvent::SJoystickEvent &GetJoystickStatePone(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePtwo(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePthree(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePfour(void) const;
        
	    virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
       
        void player_one(Input receiver);
        void player_two(Input receiver);
        void player_three(Input receiver);
        void player_four(Input receiver);
        
        void keyBoard(Input receiver);
        std::map<int, Key_mouvement> getPlayerInput();
	    Input();
        ~Input();

    private:
	    bool KeyIsDown[KEY_KEY_CODES_COUNT];
        bool _keyIsPressed;

        std::map<int, Key_mouvement> _playerInput;
        std::map<int, device> _player;

        SEvent::SJoystickEvent JoystickStatePone;
        SEvent::SJoystickEvent JoystickStatePtwo;
        SEvent::SJoystickEvent JoystickStatePthree;
        SEvent::SJoystickEvent JoystickStatePfour;
};


#endif //INPUT_HPP_