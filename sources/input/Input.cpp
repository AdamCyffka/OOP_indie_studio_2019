/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** Event
*/

#include <iostream>
#include "Input.hpp"

using namespace irr;

bool Input::IsKeyPressed() const
{
	return _keyIsPressed;
}

const SEvent::SJoystickEvent &Input::GetJoystickStatePone(void) const
{
    return JoystickStatePone;
}

const SEvent::SJoystickEvent &Input::GetJoystickStatePtwo(void) const
{
    return JoystickStatePtwo;
}

const SEvent::SJoystickEvent &Input::GetJoystickStatePthree(void) const
{
    return JoystickStatePthree;
}

const SEvent::SJoystickEvent &Input::GetJoystickStatePfour(void) const
{
    return JoystickStatePfour;
}

void Input::player_one_joystick(Input *receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver->GetJoystickStatePone();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1.0) {
			_playerInput[1] = Up;
		} else if (moveVertical == -1.0) {
			_playerInput[1] = Down;
		} else if (moveHorizontal == 1.0) {
			_playerInput[1] = Right;
		} else if (moveHorizontal == -1.0) {
			_playerInput[1] = Left;
		} else {
			_playerInput[1] = None;
		}
	}
}

void Input::player_one_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->IsKeyDown(irr::KEY_KEY_Z) && (event.KeyInput.PressedDown == false)) {
        _playerInput[1] = Up;
    } else if(receiver->IsKeyDown(irr::KEY_KEY_S) && (event.KeyInput.PressedDown == false)) {
        _playerInput[1] = Down;
    } else if(receiver->IsKeyDown(irr::KEY_KEY_Q) && (event.KeyInput.PressedDown == false)) {
        _playerInput[1] = Left;
    } else if(receiver->IsKeyDown(irr::KEY_KEY_D) && (event.KeyInput.PressedDown == false)) {
        _playerInput[1] = Right;
	} else if(receiver->IsKeyDown(irr::KEY_SPACE) && (event.KeyInput.PressedDown == false)) {
        _playerInput[1] = Bomb;
    } else {
		_playerInput[1] = None;
	}
}

void Input::player_two_joystick(Input *receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver->GetJoystickStatePtwo();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1.0) {
			_playerInput[2] = Up;
		} else if (moveVertical == -1.0) {
			_playerInput[2] = Down;
		} else if (moveHorizontal == 1.0) {
			_playerInput[2] = Right;
		} else if (moveHorizontal == -1.0) {
			_playerInput[2] = Left;
		} else {
			_playerInput[2] = None;
		}
	}
}

void Input::player_two_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->IsKeyDown(irr::KEY_UP)) {
        _playerInput[2] = Up;
    } else if (receiver->IsKeyDown(irr::KEY_DOWN) && (event.KeyInput.PressedDown == false)) {
        _playerInput[2] = Down;
    } else if (receiver->IsKeyDown(irr::KEY_LEFT) && (event.KeyInput.PressedDown == false)) {
        _playerInput[2] = Left;
    } else if (receiver->IsKeyDown(irr::KEY_RIGHT) && (event.KeyInput.PressedDown == false)) {
        _playerInput[2] = Right;
	} else if (receiver->IsKeyDown(irr::KEY_ACCEPT) && (event.KeyInput.PressedDown == false)) {
		_playerInput[2] = Bomb;
    } else {
		_playerInput[2] = None;
	}
}

void Input::player_three_joystick(Input *receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver->GetJoystickStatePthree();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1.0) {
			_playerInput[3] = Up;
		} else if (moveVertical == -1.0) {
			_playerInput[3] = Down;
		} else if (moveHorizontal == 1.0) {
			_playerInput[3] = Right;
		} else if (moveHorizontal == -1.0) {
			_playerInput[3] = Left;
		} else {
			_playerInput[3] = None;
		}
	}
}

void Input::player_three_keyboard(Input *receiver, const SEvent& event)
{
	if (receiver->IsKeyDown(irr::KEY_KEY_Y) && (event.KeyInput.PressedDown == false)) {
        _playerInput[3] = Up;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_H) && (event.KeyInput.PressedDown == false)) {
        _playerInput[3] = Down;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_J) && (event.KeyInput.PressedDown == false)) {
        _playerInput[3] = Left;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_G) && (event.KeyInput.PressedDown == false)) {
        _playerInput[3] = Right;
	} else if (receiver->IsKeyDown(irr::KEY_KEY_B) && (event.KeyInput.PressedDown == false)) {
		_playerInput[3] = Bomb;
    } else {
		_playerInput[3] = None;
	}
}

void Input::player_four_joystick(Input *receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver->GetJoystickStatePfour();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1.0) {
			_playerInput[4] = Up;
		} else if (moveVertical == -1.0) {
			_playerInput[4] = Down;
		} else if (moveHorizontal == 1.0) {
			_playerInput[4] = Right;
		} else if (moveHorizontal == -1.0) {
			_playerInput[4] = Left;
		} else {
			_playerInput[4] = None;
		}
	}

}

void Input::player_four_keyboard(Input *receiver, const SEvent& event)
{
	
	if (receiver->IsKeyDown(irr::KEY_KEY_Y) && (event.KeyInput.PressedDown == false)) {
        _playerInput[4] = Up;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_H) && (event.KeyInput.PressedDown == false)) {
        _playerInput[4] = Down;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_J) && (event.KeyInput.PressedDown == false)) {
        _playerInput[4] = Left;
    } else if (receiver->IsKeyDown(irr::KEY_KEY_G) && (event.KeyInput.PressedDown == false)) {
        _playerInput[4] = Right;
	} else if (receiver->IsKeyDown(irr::KEY_KEY_B) && (event.KeyInput.PressedDown == false)) {
		_playerInput[4] = Bomb;
    } else {
		_playerInput[4] = None;
	}	
}

basic_key Input::keyBoard (Input *receiver) // fonction tempo
{
	if (receiver->IsKeyDown(irr::KEY_F12))
		exit(84);
}

bool Input::inputEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0) {
		JoystickStatePone = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 1) {
        JoystickStatePtwo = event.JoystickEvent;
    }
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		_keyIsPressed = true;
	} else {
		if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick >= 0) {
			for (int i = 0; i < 8; i++) {
				if (JoystickStatePone.IsButtonPressed(i))
					_keyIsPressed = true;
				if (JoystickStatePtwo.IsButtonPressed(i))
					_keyIsPressed = true;
			}
		} else {
			_keyIsPressed = false;
		}
	}
	getPlayerInput(this, event);
    return false;
}

void Input::detect_player(Input *receiver, const SEvent& event)
{
	if (receiver->IsKeyDown(irr::KEY_KEY_1) && _player[0] != Keyboard) {
		_player[0] = Keyboard;
	}

	if (receiver->IsKeyDown(irr::KEY_KEY_2) && _player[1] != Keyboard) {
		_player[1] = Keyboard;
	}

	if (receiver->IsKeyDown(irr::KEY_KEY_3) && _player[2] != Keyboard) {
		_player[0] = Keyboard;
	}

	if (receiver->IsKeyDown(irr::KEY_KEY_4) && _player[3] != Keyboard) {
		_player[0] = Keyboard;
	}
}

bool Input::getPlayerInput(Input *receiver, const SEvent& event)
{
	if (_player[0] == Keyboard) {
		player_one_keyboard(receiver, event);
	} else if (_player[1] == Controller) {
		player_one_joystick(receiver);
	} else {
		_playerInput[1] = None;
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
	_player[0] = Keyboard; //tempo
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

void Input::detect_input(Input *receiver, const SEvent &event)
{
}

void Input::define_player(Input *receiver)
{
}

bool Input::IsKeyDown(irr::EKEY_CODE keyCode)
{
	return KeyIsDown[keyCode];
}
