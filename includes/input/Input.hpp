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
#include <irrlicht.h>
#include "EnumCheck.hpp"

using namespace irr;                    

enum basic_key
{
    escape = 1,
    exit_game = 2
};

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

using Key_mouvementCheck = EnumCheck<Key_mouvement, Key_mouvement::Right, Key_mouvement::Left, Key_mouvement::Up, Key_mouvement::Down, Key_mouvement::Bomb, Key_mouvement::Ia, Key_mouvement::None>;

class Input
{
    public:
        void setJoystick(IrrlichtDevice*device);
        const SEvent::SJoystickEvent changeController(Input *receiver, int controller);
        bool isKeyPressed() const;
        void setDevice(int player, device devices);
        std::map<int, Key_mouvement> getPlayerInputs();
		const SEvent::SJoystickEvent &getJoystickStatePone(void) const;
        const SEvent::SJoystickEvent &getJoystickStatePtwo(void) const;
        const SEvent::SJoystickEvent &getJoystickStatePthree(void) const;
        const SEvent::SJoystickEvent &getJoystickStatePfour(void) const;
        
        void reset();
	    bool inputEvent(const SEvent& event);
        bool isKeyDown(irr::EKEY_CODE keyCode);
       
        void playerOneKeyboard(Input *receiver, const SEvent& event);
        void playerJoystick(Input *receiver, int controller, int player);
        void playerTwoKeyboard(Input *receiver, const SEvent& event);
        void playerThreeKeyboard(Input *receiver, const SEvent& event);
        void playerFourKeyboard(Input *receiver, const SEvent& event);

        basic_key keyBoard(Input *receiver);
        bool getPlayerInput(Input *receiver, const SEvent& event);
	    Input();
        ~Input();

    private:
	    bool KeyIsDown[KEY_KEY_CODES_COUNT];
        bool _keyIsPressed;

        std::map<int, Key_mouvement> _playerInput;
        std::map<int, device> _player;

        core::array<SJoystickInfo> joystickInfo;
        SEvent::SJoystickEvent _joystickStatePone;
        SEvent::SJoystickEvent _joystickStatePtwo;
        SEvent::SJoystickEvent _joystickStatePthree;
        SEvent::SJoystickEvent _joystickStatePfour;
        int _nbr_controller;
};


#endif //INPUT_HPP_
