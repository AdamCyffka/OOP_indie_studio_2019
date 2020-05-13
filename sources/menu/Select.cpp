/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Select
*/

#include "Select.hpp"

Select::Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
    selectTab = {
        {"dry_bones", "luigi", "mario", "waluigi"},
        {"dry_bones", "luigi", "mario", "waluigi"},
        {"dry_bones", "luigi", "mario", "waluigi"},
        {"dry_bones", "luigi", "mario", "waluigi"}
    };
}

void Select::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
    _textures["play"] = _driver->getTexture("resources/images/buttons/play.png");
    _textures["changeSkin1"] = _driver->getTexture("resources/images/buttons/skin.png");
    _textures["changeSkin2"] = _driver->getTexture("resources/images/buttons/skin.png");
    _textures["changeSkin3"] = _driver->getTexture("resources/images/buttons/skin.png");
    _textures["changeSkin4"] = _driver->getTexture("resources/images/buttons/skin.png");
    _textures["ia"] = _driver->getTexture("resources/images/buttons/ia.png");
    _textures["ia_grey"] = _driver->getTexture("resources/images/buttons/ia2.png");
    _textures["p"] = _driver->getTexture("resources/images/buttons/p.png");
    _textures["p_grey"] = _driver->getTexture("resources/images/buttons/p2.png");
    _textures["x"] = _driver->getTexture("resources/images/buttons/switch.png");
}

void Select::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));

    _buttons["play"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SELECT_PLAY, L"");
    _buttons["play"]->setImage(_textures["play"]);
    _buttons["play"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 850));

    _buttons["changeSkin1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_1, L"");
    _buttons["changeSkin1"]->setImage(_textures["changeSkin1"]);
    _buttons["changeSkin1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 650));

    _buttons["changeSkin2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_2, L"");
    _buttons["changeSkin2"]->setImage(_textures["changeSkin2"]);
    _buttons["changeSkin2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 650));

    _buttons["changeSkin3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_3, L"");
    _buttons["changeSkin3"]->setImage(_textures["changeSkin3"]);
    _buttons["changeSkin3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 650));

    _buttons["changeSkin4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_4, L"");
    _buttons["changeSkin4"]->setImage(_textures["changeSkin4"]);
    _buttons["changeSkin4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 650));

    _buttons["ia1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_1, L"");
    _buttons["ia1"]->setImage(_textures["ia"]);
    _buttons["ia1"]->setRelativePosition(irr::core::position2d<irr::s32>(368, 750));

    _buttons["ia2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_2, L"");
    _buttons["ia2"]->setImage(_textures["ia"]);
    _buttons["ia2"]->setRelativePosition(irr::core::position2d<irr::s32>(768, 750));

    _buttons["ia3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_3, L"");
    _buttons["ia3"]->setImage(_textures["ia"]);
    _buttons["ia3"]->setRelativePosition(irr::core::position2d<irr::s32>(1168, 750));

    _buttons["ia4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_4, L"");
    _buttons["ia4"]->setImage(_textures["ia"]);
    _buttons["ia4"]->setRelativePosition(irr::core::position2d<irr::s32>(1568, 750));

    _buttons["p1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_1, L"");
    _buttons["p1"]->setImage(_textures["p"]);
    _buttons["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 750));

    _buttons["p2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_2, L"");
    _buttons["p2"]->setImage(_textures["p"]);
    _buttons["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 750));

    _buttons["p3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_3, L"");
    _buttons["p3"]->setImage(_textures["p"]);
    _buttons["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 750));

    _buttons["p4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_4, L"");
    _buttons["p4"]->setImage(_textures["p"]);
    _buttons["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));

    _buttons["p4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_4, L"");
    _buttons["p4"]->setImage(_textures["p"]);
    _buttons["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));

    _buttons["x1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_1, L"");
    _buttons["x1"]->setImage(_textures["x"]);
    _buttons["x1"]->setRelativePosition(irr::core::position2d<irr::s32>(290, 763));

    _buttons["x2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_2, L"");
    _buttons["x2"]->setImage(_textures["x"]);
    _buttons["x2"]->setRelativePosition(irr::core::position2d<irr::s32>(690, 763));

    _buttons["x3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_3, L"");
    _buttons["x3"]->setImage(_textures["x"]);
    _buttons["x3"]->setRelativePosition(irr::core::position2d<irr::s32>(1090, 763));

    _buttons["x4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_4, L"");
    _buttons["x4"]->setImage(_textures["x"]);
    _buttons["x4"]->setRelativePosition(irr::core::position2d<irr::s32>(1490, 763));
}

void Select::incSkin(int skin)
{
    if (nbSkin[skin] < 6)
        nbSkin[skin]++;
    else
        nbSkin[skin] = 0;
}

void Select::changeRole(int role)
{
    if (nbRole[role][0] == 0) {
        nbRole[role][0] = 1;
        nbRole[role][1] = 0;
    } else {
        nbRole[role][0] = 0;
        nbRole[role][1] = 1;
    }
}

std::map<std::string, irr::gui::IGUIButton *> Select::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::video::ITexture *> Select::getTextures()
{
    return _textures;
}

std::vector<std::vector<std::vector<std::string>>> Select::getSelectRole()
{
    return selectRole;
}

std::vector<std::vector<int>> Select::getNbRole()
{
    return nbRole;
}

irr::video::ITexture *Select::getSkin(int skin)
{
    return _textures[selectTab[skin][nbSkin[skin]]];
}