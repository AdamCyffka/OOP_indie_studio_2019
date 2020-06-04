/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** Event
*/

#include <iostream>
#include "Input.hpp"

using namespace irr;

void Input::setJoystick(IrrlichtDevice*device)
{
	device->activateJoysticks(joystickInfo);
}

void Input::setDevice(int player, device devices)
{
	_player[player - 1] = devices;
}

bool Input::isKeyPressed() const
{
	return _keyIsPressed;
}

const SEvent::SJoystickEvent &Input::getJoystickStatePone(void) const
{
    return JoystickStatePone;
}

const SEvent::SJoystickEvent &Input::getJoystickStatePtwo(void) const
{
    return JoystickStatePtwo;
}

const SEvent::SJoystickEvent &Input::getJoystickStatePthree(void) const
{
    return JoystickStatePthree;
}

const SEvent::SJoystickEvent &Input::getJoystickStatePfour(void) const
{
    return JoystickStatePfour;
}

const SEvent::SJoystickEvent Input::changeController(Input *receiver, int controller)
{
	SEvent::SJoystickEvent joystickData; 
	if (controller == 1)
		joystickData = receiver->getJoystickStatePone();
	if (controller == 2)
		joystickData = receiver->getJoystickStatePtwo();
	if (controller == 3)
		joystickData = receiver->getJoystickStatePthree();
	if (controller == 4)
		joystickData = receiver->getJoystickStatePone();	
	return (joystickData);
}


void Input::playerJoystick(Input *receiver, int controller, int player)
{

	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = changeController(receiver, controller);
	const f32 DEAD_ZONE = 0.05f;
	
	if (joystickInfo.size() > 0) {

		 moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
        if(fabs(moveHorizontal) < DEAD_ZONE)
            moveHorizontal = 0.f;

        moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
        if(fabs(moveVertical) < DEAD_ZONE)
            moveVertical = 0.f;
		
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		
		if (moveVertical == 1.0) {
			_playerInput[player] = Up;
		} else if (moveVertical == -1.0) {
			_playerInput[player] = Down;
		} else if (moveHorizontal == 1.0) {
			_playerInput[player] = Right;
		} else if (moveHorizontal == -1.0) {
			_playerInput[player] = Left;
		} else if (joystickData.IsButtonPressed(0)) {
			_playerInput[player] = Bomb;
		} else {
			_playerInput[player] = None;
		}
	}
}

void Input::player_one_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->isKeyDown(irr::KEY_KEY_Z)) {
	    _playerInput[1] = Up;
    } else if(receiver->isKeyDown(irr::KEY_KEY_S)) {
        _playerInput[1] = Down;
    } else if(receiver->isKeyDown(irr::KEY_KEY_Q)) {
        _playerInput[1] = Left;
    } else if(receiver->isKeyDown(irr::KEY_KEY_D)) {
        _playerInput[1] = Right;
	} else if(receiver->isKeyDown(irr::KEY_SPACE)) {
        _playerInput[1] = Bomb;
    } else {
		_playerInput[1] = None;
	}
}

void Input::player_two_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->isKeyDown(irr::KEY_UP)) {
        _playerInput[2] = Up;
    } else if (receiver->isKeyDown(irr::KEY_DOWN)) {
        _playerInput[2] = Down;
    } else if (receiver->isKeyDown(irr::KEY_LEFT)) {
        _playerInput[2] = Left;
    } else if (receiver->isKeyDown(irr::KEY_RIGHT)) {
        _playerInput[2] = Right;
	} else if (receiver->isKeyDown(irr::KEY_ACCEPT)) {
		_playerInput[2] = Bomb;
    } else {
		_playerInput[2] = None;
	}
}

void Input::player_three_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->isKeyDown(irr::KEY_KEY_Y)) {
        _playerInput[3] = Up;
    } else if (receiver->isKeyDown(irr::KEY_KEY_H)) {
        _playerInput[3] = Down;
    } else if (receiver->isKeyDown(irr::KEY_KEY_J)) {
        _playerInput[3] = Right;
    } else if (receiver->isKeyDown(irr::KEY_KEY_G)) {
        _playerInput[3] = Left;
	} else if (receiver->isKeyDown(irr::KEY_KEY_B)) {
		_playerInput[3] = Bomb;
    } else {
		_playerInput[3] = None;
	}
}

void Input::player_four_keyboard(Input *receiver, const SEvent& event)
{
	
	if (receiver->isKeyDown(irr::KEY_KEY_O)) {
        _playerInput[4] = Up;
    } else if (receiver->isKeyDown(irr::KEY_KEY_L)) {
        _playerInput[4] = Down;
    } else if (receiver->isKeyDown(irr::KEY_KEY_K)) {
        _playerInput[4] = Left;
    } else if (receiver->isKeyDown(irr::KEY_KEY_M)) {
        _playerInput[4] = Right;
	} else if (receiver->isKeyDown(irr::KEY_KEY_P)) {
		_playerInput[4] = Bomb;
    } else {
		_playerInput[4] = None;
	}	
}

basic_key Input::keyBoard (Input *receiver) // fonction tempo
{
	if (receiver->isKeyDown(irr::KEY_F12))
		exit(84);
}
void Input::reset()
{
	if (_playerInput[1] != Ia)
		_playerInput[1] = None;
	if (_playerInput[2] != Ia)
		_playerInput[2] = None;
	if (_playerInput[3] != Ia)
		_playerInput[3] = None;
	if (_playerInput[4] != Ia)
		_playerInput[4] = None;
}

bool Input::OnEvent(const SEvent& event)
{
	reset();
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0) {
		JoystickStatePone = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 1) {
		JoystickStatePtwo = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 2) {
		JoystickStatePthree = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 3) {
		JoystickStatePfour = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		_keyIsPressed = true;
	}
	getPlayerInput(this, event);
    return false;
}

void Input::detectPlayer(Input *receiver, const SEvent& event)
{
	if (receiver->isKeyDown(irr::KEY_KEY_1) && _player[0] != Keyboard) {
		_player[0] = Keyboard;
	}

	if (receiver->isKeyDown(irr::KEY_KEY_2) && _player[1] != Keyboard) {
		_player[1] = Keyboard;
	}

	if (receiver->isKeyDown(irr::KEY_KEY_3) && _player[2] != Keyboard) {
		_player[0] = Keyboard;
	}

	if (receiver->isKeyDown(irr::KEY_KEY_4) && _player[3] != Keyboard) {
		_player[0] = Keyboard;
	}
}

bool Input::getPlayerInput(Input *receiver, const SEvent& event)
{ 
	int controller = 1;
	int player = 1;
	if (_player[0] == Keyboard) {
		player_one_keyboard(receiver, event);
	} else if (_player[0] == Controller) {
		playerJoystick(receiver, controller, player);
		controller++;
	} else {
		_playerInput[1] = Ia;
	}
	player++;

	if (_player[1] == Keyboard) {
		player_two_keyboard(receiver, event);
	} else if (_player[1] == Controller) {
		playerJoystick(receiver, controller, player);
		controller++;
	} else {
		_playerInput[2] = Ia;
	}
	player++;

	if (_player[2] == Keyboard) {
		player_three_keyboard(receiver, event);
	} else if (_player[2] == Controller) {
		playerJoystick(receiver, controller, player);
		controller++;
	} else {
		_playerInput[3] = Ia;
	}
	player++;

	if (_player[3] == Keyboard) {
		player_four_keyboard(receiver, event);
	} else if (_player[3] == Controller) {
		playerJoystick(receiver, controller, player);
		controller++;
	} else {
		_playerInput[4] = Ia;
	}

	return (true);
}

Input::Input()
{
	for (bool & i : KeyIsDown)
    	i = false;
	_playerInput[1] = None;
	_playerInput[2] = Ia;
	_playerInput[3] = Ia;
	_playerInput[4] = Ia;
	_keyIsPressed = false;
	_player[0] = Controller; //tempo
	_player[1] = No_device; 
	_player[2] = No_device;
	_player[3] = No_device;
}

Input::~Input()
{
}

std::map<int, Key_mouvement> Input::getPlayerInputs()
{
	return _playerInput;
}

void Input::detectInput(Input *receiver, const SEvent &event)
{
}

void Input::definePlayer(Input *receiver)
{
}

bool Input::isKeyDown(irr::EKEY_CODE keyCode)
{
	return KeyIsDown[keyCode];
}