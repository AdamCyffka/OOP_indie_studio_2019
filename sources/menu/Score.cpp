/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Score
*/

#include "IEntity.hpp"
#include "Score.hpp"
#include "LoadingException.hpp"

Score::Score(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::vector<Character *> previews)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;
    _previews = previews;

    loadTextures();
    loadButtons();
}

void Score::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("back") != _textures.end() && !_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
}

void Score::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("back") != _buttons.end() && !_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));
}

void Score::run()
{
}

void Score::spawnEntities()
{
    _previews[0]->setPosition({244.0f, 319.0f, 982.0f});
    _previews[1]->setPosition({207.0f, 325.0f, 988.8f});
    _previews[2]->setPosition({210.0f, 331.0f, 1025.0f});
    _previews[3]->setPosition({130.0f, 371.0f, 1020.0f});
    _previews[3]->setState(Character::state::victory);
    for (auto &i : _previews)
        i->setOrientation(side::north);
}

std::vector<Character *> Score::getPreviews()
{
    return _previews;
}

std::map<std::string, irr::gui::IGUIButton *> Score::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Score::getImages()
{
	return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Score::getCheckBox()
{
  return _checkBox;
}