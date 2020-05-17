/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#include "Enum.hpp"
#include "MyEventReceiver.hpp"

bool MyEventReceiver::clicks(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_GUI_EVENT) {
        irr::s32 id = event.GUIEvent.Caller->getID();
        switch (event.GUIEvent.EventType) {
            case irr::gui::EGET_BUTTON_CLICKED:
            	_core.getMusicEngine()->add2D("resources/sfx/click.mp3", false, true, true, irrklang::ESM_AUTO_DETECT, true);
// 				sound effect example below
//            	_core.getMusicEngine()->enableSoundEffect("resources/sfx/click.mp3", musicNs::echo, true);
//				_core.getMusicEngine()->enableSoundEffect("resources/sfx/click.mp3", musicNs::wavesReverb, true);
				_core.getMusicEngine()->setPause("resources/sfx/click.mp3", false, true);
            	switch (id) {
                    case GUI_ID_QUIT_BUTTON:
                        _window->closeDevice();
                        return true;
                    case GUI_ID_SKIN_1:
                        _core.getSelect()->incSkin(0);
                        return true;
                    case GUI_ID_SKIN_2:
                        _core.getSelect()->incSkin(1);
                        return true;
                    case GUI_ID_SKIN_3:
                        _core.getSelect()->incSkin(2);
                        return true;
                    case GUI_ID_SKIN_4:
                        _core.getSelect()->incSkin(3);
                        return true;
                    case GUI_ID_X_1:
                        _core.getSelect()->changeRole(0);
                        return true;
                    case GUI_ID_X_2:
                        _core.getSelect()->changeRole(1);
                        return true;
                    case GUI_ID_X_3:
                        _core.getSelect()->changeRole(2);
                        return true;
                    case GUI_ID_X_4:
                        _core.getSelect()->changeRole(3);
                        return true;
                    case GUI_ID_OPTION_RETURN:
                        _core.setState(Core::menuMain);
                        return true;
                    case GUI_ID_OPTIONS_BUTTON:
                        _core.setState(Core::menuOptions);
                        return true;
                    case GUI_ID_NEW_BUTTON:
                        _core.setState(Core::menuSelect);
                        return true;
                    case GUI_ID_CREDITS_BUTTON:
                        _core.setState(Core::menuCredits);
                        return true;
                    case GUI_ID_HELP_BUTTON:
                        _core.setState(Core::menuHelp);
                        return true;
                    case GUI_ID_INTRO_BUTTON:
                        _core.setState(Core::menuMain);
                        return true;
	                case GUI_ID_OPTION_PLUS_MUSIC_BUTTON:
						_core.getMusicEngine()->musicUp();
						return true;
					case GUI_ID_OPTION_MINUS_MUSIC_BUTTON:
						_core.getMusicEngine()->musicDown();
						return true;
					case GUI_ID_OPTION_PLUS_GENERAL_BUTTON:
						_core.getMusicEngine()->masterUp();
						return true;
					case GUI_ID_OPTION_MINUS_GENERAL_BUTTON:
						_core.getMusicEngine()->masterDown();
						return true;
					case GUI_ID_OPTION_PLUS_SFX_BUTTON:
						_core.getMusicEngine()->sfxUp();
						return true;
					case GUI_ID_OPTION_MINUS_SFX_BUTTON:
						_core.getMusicEngine()->sfxDown();
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
