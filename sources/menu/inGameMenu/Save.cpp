/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Save
*/

#include "Save.hpp"

Save::Save(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
}

void Save::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/b.png");
    _textures["slot"] = _driver->getTexture("resources/images/buttons/slot.png");
}

void Save::loadButtons()
{
    _buttons["slot1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_SAVE_SLOT_1, L"save 1");
    _buttons["slot1"]->setImage(_textures["slot"]);
    _buttons["slot1"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 250));

    _buttons["slot2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_SAVE_SLOT_2, L"save 2");
    _buttons["slot2"]->setImage(_textures["slot"]);
    _buttons["slot2"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 350));

    _buttons["slot3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_SAVE_SLOT_3, L"save 3");
    _buttons["slot3"]->setImage(_textures["slot"]);
    _buttons["slot3"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 450));

    _buttons["slot4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 350, 50), nullptr, GUI_ID_SAVE_SLOT_4, L"save 4");
    _buttons["slot4"]->setImage(_textures["slot"]);
    _buttons["slot4"]->setRelativePosition(irr::core::position2d<irr::s32>(780, 550));

    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SAVE_BACKTOPAUSE, L"");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(852, 800));
}

std::vector<Character *> Save::getPreviews()
{
    return {};
}

std::map<std::string, irr::gui::IGUIButton *> Save::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Save::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Save::getCheckBox()
{
    return _checkBox;
}