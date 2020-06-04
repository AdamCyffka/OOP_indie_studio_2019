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
        bool IsKeyPressed() const;
        void set_controller(int player, device devices);
        std::map<int, Key_mouvement> getPlayerInputs();
		const SEvent::SJoystickEvent &GetJoystickStatePone(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePtwo(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePthree(void) const;
        const SEvent::SJoystickEvent &GetJoystickStatePfour(void) const;
        
        void reset();
	    bool inputEvent(const SEvent& event);
        bool IsKeyDown(irr::EKEY_CODE keyCode);
       
        void player_one_keyboard(Input *receiver, const SEvent& event);
        void player_one_joystick(Input *receiver);
        void player_two_joystick(Input *receiver);
        void player_two_keyboard(Input *receiver, const SEvent& event);
        void player_three_joystick(Input *receiver);
        void player_three_keyboard(Input *receiver, const SEvent& event);
        void player_four_joystick(Input *receiver);
        void player_four_keyboard(Input *receiver, const SEvent& event);
        void detect_player(Input *receiver, const SEvent& event);
        void detect_input(Input *receiver, const SEvent& event);

        basic_key keyBoard(Input *receiver);
        void define_player(Input *receiver);
        bool getPlayerInput(Input *receiver, const SEvent& event);
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
