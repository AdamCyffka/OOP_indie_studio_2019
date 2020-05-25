/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#include "MyEventReceiver.hpp"

bool MyEventReceiver::clicks(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
            	_core.getMusicEngine()->add2D("resources/sfx/click.mp3", false, false, true, irrklang::ESM_AUTO_DETECT);
            	switch (id) {
                    case IMenu::GUI_ID_QUIT_BUTTON:
                        _window->closeDevice();
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
                        _core.setLState(Core::menuMain);
                        return true;
                    case IMenu::GUI_ID_OPTIONS_BUTTON:
                        _core.setLState(Core::menuOptions);
                        return true;
                    case IMenu::GUI_ID_NEW_BUTTON:
                        _core.setLState(Core::menuSelect);
                        return true;
                    case IMenu::GUI_ID_CREDITS_BUTTON:
                        _core.setLState(Core::menuCredits);
                        return true;
                    case IMenu::GUI_ID_HELP_BUTTON:
                        _core.setLState(Core::menuHelp);
                        return true;
                    case IMenu::GUI_ID_INTRO_BUTTON:
                        _core.getIntro()->init();
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
						_core.setGState(Core::game);
						_core.hideLayers();
						_core.getGame()->init();
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
