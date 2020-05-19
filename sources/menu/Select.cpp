/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Select
*/

#include "global.hpp"
#include "Select.hpp"
#include "LoadingException.hpp"

Select::Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
    _selectTab = {{"waluigi", true}, {"mario", true}, {"lakitu", true}, {"koopa", true}, {"dr_peach", false}};
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[0].first), "preview1"));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[1].first), "preview2"));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[2].first), "preview3"));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[3].first), "preview4"));
    _previews[0]->setPosition({17, 0, 245});
    _previews[1]->setPosition({-28, 0, 225});
    _previews[2]->setPosition({-79, 0, 205});
    _previews[3]->setPosition({-127, 0, 185});
    for (auto &i : _previews) {
        i->setOrientation(side::east);
    }
}

void Select::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
	if (!_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["play"] = _driver->getTexture("resources/images/buttons/play.png");
	if (!_textures["play"])
		throw LoadingException("could not load texture : resources/images/buttons/play.png");
    _textures["changeSkin1"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (!_textures["changeSkin1"])
		throw LoadingException("could not load texture : resources/images/buttons/skin1.png");
    _textures["changeSkin2"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (!_textures["changeSkin2"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
	_textures["changeSkin3"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (!_textures["changeSkin3"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
    _textures["changeSkin4"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (!_textures["changeSkin4"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
    _textures["ia"] = _driver->getTexture("resources/images/buttons/ia.png");
	if (!_textures["ia"])
		throw LoadingException("could not load texture : resources/images/buttons/ia.png");
    _textures["ia_grey"] = _driver->getTexture("resources/images/buttons/ia2.png");
	if (!_textures["ia_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/ia2.png");
    _textures["p"] = _driver->getTexture("resources/images/buttons/p.png");
	if (!_textures["p"])
		throw LoadingException("could not load texture : resources/images/buttons/p.png");
    _textures["p_grey"] = _driver->getTexture("resources/images/buttons/p2.png");
	if (!_textures["p_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/p_grey.png");
    _textures["x"] = _driver->getTexture("resources/images/buttons/switch.png");
	if (!_textures["x"])
		throw LoadingException("could not load texture : resources/images/buttons/switch.png");
}

void Select::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (!_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));

    _buttons["play"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SELECT_PLAY, L"");
	if (!_buttons["play"])
		throw LoadingException("could not add button : play");
	_buttons["play"]->setImage(_textures["play"]);
    _buttons["play"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 850));

    _buttons["changeSkin1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_1, L"");
	if (!_buttons["changeSkin1"])
		throw LoadingException("could not add button : changeSkin1");
	_buttons["changeSkin1"]->setImage(_textures["changeSkin1"]);
    _buttons["changeSkin1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 650));

    _buttons["changeSkin2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_2, L"");
	if (!_buttons["changeSkin2"])
		throw LoadingException("could not add button : changeSkin2");
    _buttons["changeSkin2"]->setImage(_textures["changeSkin2"]);
    _buttons["changeSkin2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 650));

    _buttons["changeSkin3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_3, L"");
	if (!_buttons["changeSkin3"])
		throw LoadingException("could not add button : changeSkin3");
	_buttons["changeSkin3"]->setImage(_textures["changeSkin3"]);
    _buttons["changeSkin3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 650));

    _buttons["changeSkin4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_4, L"");
	if (!_buttons["changeSkin4"])
		throw LoadingException("could not add button : changeSkin4");
    _buttons["changeSkin4"]->setImage(_textures["changeSkin4"]);
    _buttons["changeSkin4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 650));

    _buttons["ia1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_1, L"");
	if (!_buttons["ia1"])
		throw LoadingException("could not add button : ia1");
    _buttons["ia1"]->setImage(_textures["ia"]);
    _buttons["ia1"]->setRelativePosition(irr::core::position2d<irr::s32>(368, 750));

    _buttons["ia2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_2, L"");
	if (!_buttons["ia2"])
		throw LoadingException("could not add button : ia2");
    _buttons["ia2"]->setImage(_textures["ia"]);
    _buttons["ia2"]->setRelativePosition(irr::core::position2d<irr::s32>(768, 750));

    _buttons["ia3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_3, L"");
	if (!_buttons["ia3"])
		throw LoadingException("could not add button : ia3");
    _buttons["ia3"]->setImage(_textures["ia"]);
    _buttons["ia3"]->setRelativePosition(irr::core::position2d<irr::s32>(1168, 750));

    _buttons["ia4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_IA_4, L"");
	if (!_buttons["ia4"])
		throw LoadingException("could not add button : ia4");
    _buttons["ia4"]->setImage(_textures["ia"]);
    _buttons["ia4"]->setRelativePosition(irr::core::position2d<irr::s32>(1568, 750));

    _buttons["p1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_1, L"");
	if (!_buttons["p1"])
		throw LoadingException("could not add button : p1");
    _buttons["p1"]->setImage(_textures["p"]);
    _buttons["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 750));

    _buttons["p2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_2, L"");
	if (!_buttons["p2"])
		throw LoadingException("could not add button : p2");
    _buttons["p2"]->setImage(_textures["p"]);
    _buttons["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 750));

    _buttons["p3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_3, L"");
	if (!_buttons["p3"])
		throw LoadingException("could not add button : p3");
    _buttons["p3"]->setImage(_textures["p"]);
    _buttons["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 750));

    _buttons["p4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 47, 47), nullptr, GUI_ID_P_4, L"");
	if (!_buttons["p4"])
		throw LoadingException("could not add button : p4");
    _buttons["p4"]->setImage(_textures["p"]);
    _buttons["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));

    _buttons["x1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_1, L"");
	if (!_buttons["x1"])
		throw LoadingException("could not add button : x1");
    _buttons["x1"]->setImage(_textures["x"]);
    _buttons["x1"]->setRelativePosition(irr::core::position2d<irr::s32>(290, 763));

    _buttons["x2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_2, L"");
	if (!_buttons["x2"])
		throw LoadingException("could not add button : x2");
    _buttons["x2"]->setImage(_textures["x"]);
    _buttons["x2"]->setRelativePosition(irr::core::position2d<irr::s32>(690, 763));

    _buttons["x3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_3, L"");
	if (!_buttons["x3"])
		throw LoadingException("could not add button : x3");
    _buttons["x3"]->setImage(_textures["x"]);
    _buttons["x3"]->setRelativePosition(irr::core::position2d<irr::s32>(1090, 763));

    _buttons["x4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_4, L"");
	if (!_buttons["x4"])
		throw LoadingException("could not add button : x4");
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
    if (_nbRole[role][0] == 0) {
        _nbRole[role][0] = 1;
        _nbRole[role][1] = 0;
    } else {
        _nbRole[role][0] = 0;
        _nbRole[role][1] = 1;
    }
}

void Select::run()
{
    _images["p1"]->setImage(_textures[_selectRole[0][0][_nbRole[0][0]]]);
    _images["ia1"]->setImage(_textures[_selectRole[0][1][_nbRole[0][1]]]);
    _images["p2"]->setImage(_textures[_selectRole[0][0][_nbRole[1][0]]]);
    _images["ia2"]->setImage(_textures[_selectRole[0][1][_nbRole[1][1]]]);
    _images["p3"]->setImage(_textures[_selectRole[0][0][_nbRole[2][0]]]);
    _images["ia3"]->setImage(_textures[_selectRole[0][1][_nbRole[2][1]]]);
    _images["ia4"]->setImage(_textures[_selectRole[0][1][_nbRole[3][1]]]);
    _images["p4"]->setImage(_textures[_selectRole[0][0][_nbRole[3][0]]]);
}

std::vector<Character *> Select::getPreviews()
{
    return _previews;
}

std::map<std::string, irr::gui::IGUIButton *> Select::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Select::getImages()
{
	return _images;
}

std::vector<std::vector<std::vector<std::string>>> Select::getSelectRole()
{
    return _selectRole;
}

std::vector<std::vector<int>> Select::getNbRole()
{
    return _nbRole;
}

Character *Select::getPreview(int preview) const
{
    return _previews.at(preview);
}