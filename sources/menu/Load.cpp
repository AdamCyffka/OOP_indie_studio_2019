/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Load
*/

#include "Load.hpp"
#include "LoadingException.hpp"

Load::Load(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Load::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    if (_textures.find("back") == _textures.end() || !_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["slot"] = _driver->getTexture("resources/images/buttons/slot.png");
    if (_textures.find("slot") == _textures.end() || !_textures["slot"])
		throw LoadingException("could not load texture : resources/images/buttons/slot.png");
}

void Load::loadButtons()
{
    _buttons["slot1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_LOAD_SLOT_1, L"load 1");
    _buttons["slot1"]->setImage(_textures["slot"]);
    _buttons["slot1"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 250));

    _buttons["slot2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_LOAD_SLOT_2, L"load 2");
    _buttons["slot2"]->setImage(_textures["slot"]);
    _buttons["slot2"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 350));

    _buttons["slot3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_LOAD_SLOT_3, L"load 3");
    _buttons["slot3"]->setImage(_textures["slot"]);
    _buttons["slot3"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 450));

    _buttons["slot4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_LOAD_SLOT_4, L"load 4");
    _buttons["slot4"]->setImage(_textures["slot"]);
    _buttons["slot4"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 550));

    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
}

std::vector<Character *> Load::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Load::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Load::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Load::getCheckBox()
{
    return _checkBox;
}