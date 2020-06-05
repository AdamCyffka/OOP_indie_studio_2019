/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Select
*/

#include "Select.hpp"
#include "global.hpp"
#include "LoadingException.hpp"

Select::Select(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;

    loadTextures();
    loadButtons();
    _selectTab = {{"mario", 0}, {"luigi", 1}, {"waluigi", 2}, {"red_toad", 3}, {"koopa", -1}, {"yellow_toad", -1}, {"blue_toad", -1}, {"green_toad", -1}, {"dr_peach", -1}, {"dry_bones", -1}, {"lakitu", -1}, {"luigi_fire", -1}};
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[0].first)));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[1].first)));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[2].first)));
    _previews.push_back(new Character(_smgr, _driver, g_modelInfos.at(_selectTab[3].first)));
    _previews[0]->setPosition({17, 0, 245});
    _previews[1]->setPosition({-28, 0, 225});
    _previews[2]->setPosition({-79, 0, 205});
    _previews[3]->setPosition({-127, 0, 185});
    for (auto &i : _previews) {
        i->setVisibility(true);
        i->setOrientation(side::east);
        i->setState(Character::state::idle);
    }
}

void Select::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("back") == _textures.end() || !_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["play"] = _driver->getTexture("resources/images/buttons/play.png");
	if (_textures.find("play") == _textures.end() || !_textures["play"])
		throw LoadingException("could not load texture : resources/images/buttons/play.png");
    _textures["changeSkin1"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (_textures.find("changeSkin1") == _textures.end() || !_textures["changeSkin1"])
		throw LoadingException("could not load texture : resources/images/buttons/skin1.png");
    _textures["changeSkin2"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (_textures.find("changeSkin2") == _textures.end() || !_textures["changeSkin2"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
	_textures["changeSkin3"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (_textures.find("changeSkin3") == _textures.end() || !_textures["changeSkin3"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
    _textures["changeSkin4"] = _driver->getTexture("resources/images/buttons/skin.png");
	if (_textures.find("changeSkin4") == _textures.end() || !_textures["changeSkin4"])
		throw LoadingException("could not load texture : resources/images/buttons/skin.png");
    _textures["ia"] = _driver->getTexture("resources/images/buttons/ia.png");
	if (_textures.find("ia") == _textures.end() || !_textures["ia"])
		throw LoadingException("could not load texture : resources/images/buttons/ia.png");
    _textures["ia_grey"] = _driver->getTexture("resources/images/buttons/ia2.png");
	if (_textures.find("ia_grey") == _textures.end() || !_textures["ia_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/ia2.png");
    _textures["p"] = _driver->getTexture("resources/images/buttons/p.png");
	if (_textures.find("p") == _textures.end() || !_textures["p"])
		throw LoadingException("could not load texture : resources/images/buttons/p.png");
    _textures["p_grey"] = _driver->getTexture("resources/images/buttons/p2.png");
	if (_textures.find("p_grey") == _textures.end() || !_textures["p_grey"])
		throw LoadingException("could not load texture : resources/images/buttons/p_grey.png");
    _textures["x"] = _driver->getTexture("resources/images/buttons/switch.png");
	if (_textures.find("x") == _textures.end() || !_textures["x"])
		throw LoadingException("could not load texture : resources/images/buttons/switch.png");
}

void Select::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));

    _buttons["play"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SELECT_PLAY, L"");
	if (_buttons.find("play") == _buttons.end() || !_buttons["play"])
		throw LoadingException("could not add button : play");
	_buttons["play"]->setImage(_textures["play"]);
    _buttons["play"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 850));

    _buttons["changeSkin1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_1, L"");
	if (_buttons.find("changeSkin1") == _buttons.end() || !_buttons["changeSkin1"])
		throw LoadingException("could not add button : changeSkin1");
	_buttons["changeSkin1"]->setImage(_textures["changeSkin1"]);
    _buttons["changeSkin1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 650));

    _buttons["changeSkin2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_2, L"");
	if (_buttons.find("changeSkin2") == _buttons.end() || !_buttons["changeSkin2"])
		throw LoadingException("could not add button : changeSkin2");
    _buttons["changeSkin2"]->setImage(_textures["changeSkin2"]);
    _buttons["changeSkin2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 650));

    _buttons["changeSkin3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_3, L"");
	if (_buttons.find("changeSkin3") == _buttons.end() || !_buttons["changeSkin3"])
		throw LoadingException("could not add button : changeSkin3");
	_buttons["changeSkin3"]->setImage(_textures["changeSkin3"]);
    _buttons["changeSkin3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 650));

    _buttons["changeSkin4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_SKIN_4, L"");
	if (_buttons.find("changeSkin4") == _buttons.end() || !_buttons["changeSkin4"])
		throw LoadingException("could not add button : changeSkin4");
    _buttons["changeSkin4"]->setImage(_textures["changeSkin4"]);
    _buttons["changeSkin4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 650));

    _images["ia1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("ia1") == _images.end() || !_images["ia1"])
		throw LoadingException("could not add image : ia1");
    _images["ia1"]->setImage(_textures["ia"]);
    _images["ia1"]->setRelativePosition(irr::core::position2d<irr::s32>(368, 750));

    _images["ia2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("ia2") == _images.end() || !_images["ia2"])
		throw LoadingException("could not add image : ia2");
    _images["ia2"]->setImage(_textures["ia"]);
    _images["ia2"]->setRelativePosition(irr::core::position2d<irr::s32>(768, 750));

    _images["ia3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("ia3") == _images.end() || !_images["ia3"])
		throw LoadingException("could not add image : ia3");
    _images["ia3"]->setImage(_textures["ia"]);
    _images["ia3"]->setRelativePosition(irr::core::position2d<irr::s32>(1168, 750));

    _images["ia4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("ia4") == _images.end() || !_images["ia4"])
		throw LoadingException("could not add image : ia4");
    _images["ia4"]->setImage(_textures["ia"]);
    _images["ia4"]->setRelativePosition(irr::core::position2d<irr::s32>(1568, 750));

    _images["p1"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("p1") == _images.end() || !_images["p1"])
		throw LoadingException("could not add image : p1");
    _images["p1"]->setImage(_textures["p"]);
    _images["p1"]->setRelativePosition(irr::core::position2d<irr::s32>(200, 750));

    _images["p2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("p2") == _images.end() || !_images["p2"])
		throw LoadingException("could not add image : p2");
    _images["p2"]->setImage(_textures["p"]);
    _images["p2"]->setRelativePosition(irr::core::position2d<irr::s32>(600, 750));

    _images["p3"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("p3") == _images.end() || !_images["p3"])
		throw LoadingException("could not add image : p3");
    _images["p3"]->setImage(_textures["p"]);
    _images["p3"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 750));

    _images["p4"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 47, 47));
	if (_images.find("p4") == _images.end() || !_images["p4"])
		throw LoadingException("could not add image : p4");
    _images["p4"]->setImage(_textures["p"]);
    _images["p4"]->setRelativePosition(irr::core::position2d<irr::s32>(1400, 750));

    _buttons["x1"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_1, L"");
	if (_buttons.find("x1") == _buttons.end() || !_buttons["x1"])
		throw LoadingException("could not add button : x1");
    _buttons["x1"]->setImage(_textures["x"]);
    _buttons["x1"]->setRelativePosition(irr::core::position2d<irr::s32>(290, 763));

    _buttons["x2"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_2, L"");
	if (_buttons.find("x2") == _buttons.end() || !_buttons["x2"])
		throw LoadingException("could not add button : x2");
    _buttons["x2"]->setImage(_textures["x"]);
    _buttons["x2"]->setRelativePosition(irr::core::position2d<irr::s32>(690, 763));

    _buttons["x3"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_3, L"");
	if (_buttons.find("x3") == _buttons.end() || !_buttons["x3"])
		throw LoadingException("could not add button : x3");
    _buttons["x3"]->setImage(_textures["x"]);
    _buttons["x3"]->setRelativePosition(irr::core::position2d<irr::s32>(1090, 763));

    _buttons["x4"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 30, 30), nullptr, GUI_ID_X_4, L"");
	if (_buttons.find("x4") == _buttons.end() || !_buttons["x4"])
		throw LoadingException("could not add button : x4");
    _buttons["x4"]->setImage(_textures["x"]);
    _buttons["x4"]->setRelativePosition(irr::core::position2d<irr::s32>(1490, 763));
}

void Select::spawnEntities()
{
    _previews[0]->setPosition({17, 0, 245});
    _previews[1]->setPosition({-28, 0, 225});
    _previews[2]->setPosition({-79, 0, 205});
    _previews[3]->setPosition({-127, 0, 185});
    for (auto &i : _previews) {
        i->setVisibility(true);
        i->setOrientation(side::east);
        i->setState(Character::state::idle);
    }
}

int Select::getNextAvailableSkin(size_t start)
{
    for (size_t i = start; i < _selectTab.size(); i++)
        if (_selectTab[i].second == -1)
            return (int)i;
    return getNextAvailableSkin();
}

void Select::incSkin(int skin)
{
    for (size_t i = 0; i < _selectTab.size(); i++) {
        if (_selectTab[i].second == skin) {
            int newSkinIndex = getNextAvailableSkin(i);
            if (newSkinIndex != -1) {
                _previews[skin]->changeModel(g_modelInfos.at(_selectTab[newSkinIndex].first));
                _selectTab[newSkinIndex].second = skin;
                _selectTab[i].second = -1;
            }
            break;
        }
    }
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
    _images["p4"]->setImage(_textures[_selectRole[0][0][_nbRole[3][0]]]);
    _images["ia4"]->setImage(_textures[_selectRole[0][1][_nbRole[3][1]]]);
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

const std::vector<EntityType::EntityType> &Select::getEntityTypes()
{
	_entitiesTypes.clear();

	for (auto it : _nbRole) {
		if (*it.begin() == 1)
			_entitiesTypes.push_back(EntityType::EntityType::AI);
		else
			_entitiesTypes.push_back(EntityType::EntityType::player);
	}
	return _entitiesTypes;
}


std::map<std::string, irr::gui::IGUICheckBox *> Select::getCheckBox()
{
    return _checkBox;
}