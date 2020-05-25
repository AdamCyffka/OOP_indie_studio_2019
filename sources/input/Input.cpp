/*
** EPITECH PROJECT, 2020
** Input.cpp
** File description:
** Event
*/

#include "Input.hpp"

using namespace irr;

bool Input::IsKeyPressed(Input receiver)
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

bool Input::IsKeyDown(EKEY_CODE keyCode) const {
		return KeyIsDown[keyCode];
}

void Input::player_one(Input receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver.GetJoystickStatePone();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1) {
			_playerInput[1] = Up;
		} else if (moveVertical == -1) {
			_playerInput[1] = Down;
		} else if (moveHorizontal == 1) {
			_playerInput[1] = Right;
		} else if (moveHorizontal == -1) {
			_playerInput[1] = Left;
		} else {
			_playerInput[1] = None;
		}
	}

	if (receiver.IsKeyDown(irr::KEY_KEY_Z)) {
        _playerInput[1] = Up;
    } else if(receiver.IsKeyDown(irr::KEY_KEY_S)) {
        _playerInput[1] = Down;
    } else if(receiver.IsKeyDown(irr::KEY_KEY_Q)) {
        _playerInput[1] = Left;
    } else if(receiver.IsKeyDown(irr::KEY_KEY_D)) {
        _playerInput[1] = Right;
	} else if(receiver.IsKeyDown(irr::KEY_SPACE)) {
        _playerInput[1] = Bomb;
    } else {
		_playerInput[1] = None;
	}
}

void Input::player_two(Input receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver.GetJoystickStatePtwo();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1) {
			_playerInput[2] = Up;
		} else if (moveVertical == -1) {
			_playerInput[2] = Down;
		} else if (moveHorizontal == 1) {
			_playerInput[2] = Right;
		} else if (moveHorizontal == -1) {
			_playerInput[2] = Left;
		} else {
			_playerInput[2] = None;
		}
	}

	if (receiver.IsKeyDown(irr::KEY_UP)) {
        _playerInput[2] = Up;
    } else if (receiver.IsKeyDown(irr::KEY_DOWN)) {
        _playerInput[2] = Down;
    } else if (receiver.IsKeyDown(irr::KEY_LEFT)) { 
        _playerInput[2] = Left;
    } else if (receiver.IsKeyDown(irr::KEY_RIGHT)) { 
        _playerInput[2] = Right;
	} else if (receiver.IsKeyDown(irr::KEY_ACCEPT)) {
		_playerInput[2] = Bomb;
    } else {
		_playerInput[2] = None;
	}
}

void Input::player_three(Input receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver.GetJoystickStatePthree();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1) {
			_playerInput[3] = Up;
		} else if (moveVertical == -1) {
			_playerInput[3] = Down;
		} else if (moveHorizontal == 1) {
			_playerInput[3] = Right;
		} else if (moveHorizontal == -1) {
			_playerInput[3] = Left;
		} else {
			_playerInput[3] = None;
		}
	}

	if (receiver.IsKeyDown(irr::KEY_KEY_Y)) {
        _playerInput[3] = Up;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_H)) {
        _playerInput[3] = Down;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_J)) { 
        _playerInput[3] = Left;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_G)) { 
        _playerInput[3] = Right;
	} else if (receiver.IsKeyDown(irr::KEY_KEY_B)) {
		_playerInput[3] = Bomb;
    } else {
		_playerInput[3] = None;
	}
}

void Input::player_four(Input receiver)
{
	core::array<SJoystickInfo> joystickInfo;
	f32 moveHorizontal = 0.f;
	f32 moveVertical = 0.f;
	const SEvent::SJoystickEvent &joystickData = receiver.GetJoystickStatePfour();
	const f32 DEAD_ZONE = 0.05f;

	if (joystickInfo.size() == 0)
	{
	
		moveHorizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
		if(fabs(moveHorizontal) < DEAD_ZONE)
			moveHorizontal = 0.f;

		moveVertical = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;
		if(fabs(moveVertical) < DEAD_ZONE)
			moveVertical = 0.f;
		if (moveVertical == 1) {
			_playerInput[4] = Up;
		} else if (moveVertical == -1) {
			_playerInput[4] = Down;
		} else if (moveHorizontal == 1) {
			_playerInput[4] = Right;
		} else if (moveHorizontal == -1) {
			_playerInput[4] = Left;
		} else {
			_playerInput[4] = None;
		}
	}

	if (receiver.IsKeyDown(irr::KEY_KEY_Y)) {
        _playerInput[4] = Up;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_H)) {
        _playerInput[4] = Down;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_J)) { 
        _playerInput[4] = Left;
    } else if (receiver.IsKeyDown(irr::KEY_KEY_G)) { 
        _playerInput[4] = Right;
	} else if (receiver.IsKeyDown(irr::KEY_KEY_B)) {
		_playerInput[4] = Bomb;
    } else {
		_playerInput[4] = None;
	}	
}

void Input::keyBoard (Input receiver)
{

		
}


bool Input::OnEvent(const SEvent& event) 
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
    return false;
}


std::map<int, Key_mouvement> Input::getPlayerInput()
{
    return (_playerInput);
}

Input::Input()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
    	KeyIsDown[i] = false;
	_playerInput[1] = None;
	_playerInput[2] = None;
	_keyIsPressed = false;
}

Input::~Input()
{

}

	

