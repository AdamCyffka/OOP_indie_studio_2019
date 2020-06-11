/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#include "MyEventReceiver.hpp"

MyEventReceiver::MyEventReceiver(irr::IrrlichtDevice *window, Core &core, CameraTravelManager *cameraTravelManager) : _window(window), _core(core), _cameraTravelManager(cameraTravelManager),
	_keyDown{false}
{
}

bool MyEventReceiver::clicks(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_GUI_EVENT) {
		irr::s32 id = event.GUIEvent.Caller->getID();
		switch (event.GUIEvent.EventType) {
		case irr::gui::EGET_BUTTON_CLICKED:
			_core.getMusicEngine()->add2D("resources/sfx/click.mp3", false, false, true, irrklang::ESM_AUTO_DETECT, true);
			switch (id) {
				case IMenu::GUI_ID_QUIT_BUTTON:
					_window->closeDevice();
					//_core.start();
					return true;
				case IMenu::GUI_ID_SKIN_1:
					_core.getSelect()->incSkin(0);
					return true;
				case IMenu::GUI_ID_SKIN_2:
					_core.getSelect()->incSkin(1);
					return true;
				case IMenu::GUI_ID_SKIN_3:
					_core.getSelect()->incSkin(2);
					return true;
				case IMenu::GUI_ID_SKIN_4:
					_core.getSelect()->incSkin(3);
					return true;
				case IMenu::GUI_ID_X_1:
					_core.getSelect()->changeRole(0);
					return true;
				case IMenu::GUI_ID_X_2:
					_core.getSelect()->changeRole(1);
					return true;
				case IMenu::GUI_ID_X_3:
					_core.getSelect()->changeRole(2);
					return true;
				case IMenu::GUI_ID_X_4:
					_core.getSelect()->changeRole(3);
					return true;
				case IMenu::GUI_ID_OPTION_RETURN:
					if (_core.getLState() == Core::layerMenuState::menuSelect)
						_cameraTravelManager->doTravel(CameraTravelManager::travel::selectToMenu);
					else if (_core.getLState() == Core::layerMenuState::menuScore) {
						_cameraTravelManager->doTravel(CameraTravelManager::travel::scoreToMenu);
						_core.getMusicEngine()->add2D("resources/music/menu.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
						_core.getMusicEngine()->stop("resources/music/end.mp3", false);
					}
					_core.setLState(Core::menuMain);
					return true;
				case IMenu::GUI_ID_SOUNDS_BUTTON:
					_core.setLState(Core::menuSounds);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_BUTTON:
					_core.setLState(Core::menuGameSettings);
					return true;
				case IMenu::GUI_ID_CONTROLS_BUTTON:
					_core.setLState(Core::menuControls);
					return true;
				case IMenu::GUI_ID_NEW_BUTTON:
					_cameraTravelManager->doTravel(CameraTravelManager::travel::menuToSelect);
					_core.setLState(Core::menuSelect);
					_core.getSelect()->spawnEntities();
					return true;
				case IMenu::GUI_ID_CREDITS_BUTTON:
					_core.setLState(Core::menuCredits);
					return true;
				case IMenu::GUI_ID_HELP_BUTTON:
					_core.setLState(Core::menuHelp);
					return true;
				case IMenu::GUI_ID_INTRO_BUTTON:
					_core.getMusicEngine()->stop("resources/music/intro.mp3", false);
					_core.getMusicEngine()->add2D("resources/music/menu.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
					_cameraTravelManager->doTravel(CameraTravelManager::travel::introToMenu);
					_core.setLState(Core::menuMain);
					return true;
				case IMenu::GUI_ID_OPTION_PLUS_MUSIC_BUTTON:
					_core.getMusicEngine()->musicUp();
					return true;
				case IMenu::GUI_ID_OPTION_MINUS_MUSIC_BUTTON:
					_core.getMusicEngine()->musicDown();
					return true;
				case IMenu::GUI_ID_OPTION_PLUS_GENERAL_BUTTON:
					_core.getMusicEngine()->masterUp();
					return true;
				case IMenu::GUI_ID_OPTION_MINUS_GENERAL_BUTTON:
					_core.getMusicEngine()->masterDown();
					return true;
				case IMenu::GUI_ID_OPTION_PLUS_SFX_BUTTON:
					_core.getMusicEngine()->sfxUp();
					return true;
				case IMenu::GUI_ID_OPTION_MINUS_SFX_BUTTON:
					_core.getMusicEngine()->sfxDown();
					return true;
				case IMenu::GUI_ID_SELECT_PLAY:
					_core.getGame()->loadButtons();
					_core.setLGState(Core::gameGame);
					_core.getMusicEngine()->stop("resources/music/menu.mp3", false);
					_core.getMusicEngine()->add2D("resources/music/game.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
					_cameraTravelManager->doTravel(CameraTravelManager::travel::selectToGame);
					_core.getGameCore()->reset();
					_core.setGState(Core::game);
					_core.getGameCore()->init(_core.getSelect()->getPreviews(), _core.getSelect()->getEntityTypes(), _core.getControls()->getEntityType());
					return true;
				case IMenu::GUI_ID_SAVE_SLOT_1:
					saveGame(1, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_SAVE_SLOT_2:
					saveGame(2, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_SAVE_SLOT_3:
					saveGame(3, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_SAVE_SLOT_4:
					saveGame(4, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_LOAD_BUTTON:
					_core.setLState(Core::menuLoad);
					return true;
				case IMenu::GUI_ID_LOAD_SLOT_1:
					loadGame(1, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_LOAD_SLOT_2:
					loadGame(2, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_LOAD_SLOT_3:
					loadGame(3, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_LOAD_SLOT_4:
					loadGame(4, _core, _cameraTravelManager);
					return true;
				case IMenu::GUI_ID_RESUME_BUTTON:
					_core.setLGState(Core::gameGame);
					return true;
				case IMenu::GUI_ID_SAVE_BUTTON:
					_core.setLGState(Core::gameSave);
					return true;
				case IMenu::GUI_ID_SAVE_BACKTOPAUSE:
					_core.setLGState(Core::gamePause);
					return true;
				case IMenu::GUI_ID_PAUSE_RETURN:
					_core.setLGState(Core::gamePause);
					return true;
				case IMenu::GUI_ID_PAUSE_SOUNDS:
					_core.setLGState(Core::gameSounds);
					return true;
				case IMenu::GUI_ID_PAUSE_CONTROLS:
					_core.setLGState(Core::gameControls);
					return true;
				case IMenu::GUI_ID_PAUSE_MENU:
					_core.getMusicEngine()->stop("resources/music/game.mp3", false);
					_core.getMusicEngine()->add2D("resources/music/menu.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
					_cameraTravelManager->doTravel(CameraTravelManager::travel::pauseToMenu);
					_core.getGameCore()->reset();
					_core.setGState(Core::menu);
					_core.setLState(Core::menuMain);
					return true;
				case IMenu::GUI_ID_CONTROLS_SWITCH_1:
					_core.getControls()->changeOption(0);
					return true;
				case IMenu::GUI_ID_CONTROLS_SWITCH_2:
					_core.getControls()->changeOption(1);
					return true;
				case IMenu::GUI_ID_CONTROLS_SWITCH_3:
					_core.getControls()->changeOption(2);
					return true;
				case IMenu::GUI_ID_CONTROLS_SWITCH_4:
					_core.getControls()->changeOption(3);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_MINUS_FIRE_POWER:
					_core.getGameSettings()->setFirePower(-1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_PLUS_FIRE_POWER:
					_core.getGameSettings()->setFirePower(1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_MINUS_BOMB_AMOUNT:
					_core.getGameSettings()->setBombAmount(-1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_PLUS_BOMB_AMOUNT:
					_core.getGameSettings()->setBombAmount(1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_MINUS_SPEED:
					_core.getGameSettings()->setSpeed(-1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_PLUS_SPEED:
					_core.getGameSettings()->setSpeed(1);
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_WALLPASS:
					_core.getGameSettings()->setWallPass(!_core.getGameSettings()->isWallPass());
					return true;
				case IMenu::GUI_ID_GAMESETTINGS_BOMBPASS:
					_core.getGameSettings()->setBombPass(!_core.getGameSettings()->isBombPass());
					return true;
				default:
					break;
				}
			}
		}
	return false;
}

bool MyEventReceiver::OnEvent(const irr::SEvent &event)
{
	if (clicks(event))
		return true;
	if (_core.getInput() && _core.getInput()->inputEvent(event))
		return true;
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.Key == KEY_ESCAPE && event.KeyInput.PressedDown == false && _core.getGState() == Core::game)
			_core.setLGState(_core.getLGState() == Core::gameGame ? Core::gamePause : Core::gameGame);
		_keyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		return true;
	}
	return false;
}

bool MyEventReceiver::keyHasBeenPressed(irr::EKEY_CODE keyCode) const
{
	return _keyPressed[keyCode];
}

bool MyEventReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
	return _keyDown[keyCode];
}