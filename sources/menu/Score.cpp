/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Score
*/

#include "IEntity.hpp"
#include "Score.hpp"
#include "LoadingException.hpp"
#include "MenuException.hpp"

Score::Score(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::vector<Character *> previews)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;
    _previews = previews;
    _ranking = {0, 1, 2, 3};

    loadTextures();
    loadButtons();
}

void Score::updateRanking(std::vector<std::pair<int, int>> ranking)
{
    if (ranking.size() != 4)
        throw MenuException("Given ranking has a wrong number of players");

    for (int i = 0; i < 4; i++) {
        std::string modelName = _previews[ranking.at(i).first]->getModelInfos().name;
        _images[modelName] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find(modelName) != _images.end() && !_images[modelName])
            throw LoadingException("could not add image : " + modelName);
        _images[modelName]->setImage(_textures[modelName]);
        _images[modelName]->setRelativePosition(irr::core::position2d<irr::s32>(128, 160 * (i + 1)));

        _images[modelName + "_stars_bg"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 175, 50));
        if (_images.find(modelName + "_stars_bg") != _images.end() && !_images[modelName + "_stars_bg"])
            throw LoadingException("could not add image : " + modelName + "_stars_bg");
        _images[modelName + "_stars_bg"]->setImage(_textures["slot"]);
        _images[modelName + "_stars_bg"]->setRelativePosition(irr::core::position2d<irr::s32>(256 + 25, 190 + 160 * i));

        for (int j = 0; j < 3; j++) {
            std::string imageName = modelName + "_star" + std::to_string(j);
            _images[imageName] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 480, 480));
            if (_images.find(imageName) != _images.end() && !_images[imageName])
                throw LoadingException("could not add image : " + imageName);
            _images[imageName]->setImage(_textures[(j >= ranking.at(i).second) ? "grey_star" : "star"]);
            _images[imageName]->setRelativePosition(irr::core::position2d<irr::s32>(256 + 50 * (j + 1), 200 + 160 * (i)));
        }

        _ranking[i] = ranking.at(i).first;
    }
}

void Score::loadTextures()
{
    _textures["back"] = _driver->getTexture("resources/images/buttons/back.png");
	if (_textures.find("back") == _textures.end() || !_textures["back"])
		throw LoadingException("could not load texture : resources/images/buttons/back.png");
    _textures["slot"] = _driver->getTexture("resources/images/buttons/blueslot.png");
    if (_textures.find("slot") == _textures.end() || !_textures["slot"])
		throw LoadingException("could not load texture : resources/images/buttons/blueslot.png");
    _textures["mario"] = _driver->getTexture("resources/images/characters/MK8_Icon_Mario.png");
	if (_textures.find("mario") == _textures.end() || !_textures["mario"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Mario.png");
    _textures["koopa"] = _driver->getTexture("resources/images/characters/MK8_Icon_Koopa_Troopa.png");
	if (_textures.find("koopa") == _textures.end() || !_textures["koopa"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Koopa_Troopa.png");
    _textures["lakitu"] = _driver->getTexture("resources/images/characters/MK8_Icon_Lakitu.png");
	if (_textures.find("lakitu") == _textures.end() || !_textures["lakitu"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Lakitu.png");
    _textures["dr_peach"] = _driver->getTexture("resources/images/characters/MK8_Icon_Peach.png");
	if (_textures.find("dr_peach") == _textures.end() || !_textures["dr_peach"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Peach.png");
    _textures["waluigi"] = _driver->getTexture("resources/images/characters/MK8_Icon_Waluigi.png");
	if (_textures.find("waluigi") == _textures.end() || !_textures["waluigi"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Waluigi.png");
    _textures["yellow_toad"] = _driver->getTexture("resources/images/characters/MK8_Icon_Toad_Yellow.png");
	if (_textures.find("yellow_toad") == _textures.end() || !_textures["yellow_toad"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Toad_Yellow.png");
    _textures["blue_toad"] = _driver->getTexture("resources/images/characters/MK8_Icon_Toad_Bleu.png");
	if (_textures.find("blue_toad") == _textures.end() || !_textures["blue_toad"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Toad_Bleu.png");
    _textures["green_toad"] = _driver->getTexture("resources/images/characters/MK8_Icon_Toad_Green.png");
	if (_textures.find("green_toad") == _textures.end() || !_textures["green_toad"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Toad_Green.png");
    _textures["red_toad"] = _driver->getTexture("resources/images/characters/MK8_Icon_Toad_Red.png");
	if (_textures.find("red_toad") == _textures.end() || !_textures["red_toad"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Toad_Red.png");
    _textures["luigi"] = _driver->getTexture("resources/images/characters/MK8_Icon_Luigi.png");
	if (_textures.find("luigi") == _textures.end() || !_textures["luigi"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Luigi.png");
    _textures["luigi_fire"] = _driver->getTexture("resources/images/characters/MK8_Icon_Luigi_Fire.png");
	if (_textures.find("luigi_fire") == _textures.end() || !_textures["luigi_fire"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Luigi_Fire.png");
    _textures["dry_bones"] = _driver->getTexture("resources/images/characters/MK8_Icon_DryBones.png");
	if (_textures.find("dry_bones") == _textures.end() || !_textures["dry_bones"])
		throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_DryBones.png");
    _textures["grey_star"] = _driver->getTexture("resources/images/starGrey.png");
	if (_textures.find("grey_star") == _textures.end() || !_textures["grey_star"])
		throw LoadingException("could not load texture : resources/images/starGrey.png");
    _textures["star"] = _driver->getTexture("resources/images/star.png");
	if (_textures.find("star") == _textures.end() || !_textures["star"])
		throw LoadingException("could not load texture : resources/images/star.png");
}

void Score::loadButtons()
{
    _buttons["back"] = _env->addButton(irr::core::rect<irr::s32>(0, 0, 215, 47), nullptr, GUI_ID_OPTION_RETURN, L"");
	if (_buttons.find("back") == _buttons.end() || !_buttons["back"])
		throw LoadingException("could not add button : back");
    _buttons["back"]->setImage(_textures["back"]);
    _buttons["back"]->setRelativePosition(irr::core::position2d<irr::s32>(800, 925));
}

void Score::spawnEntities()
{
    _previews[_ranking.at(0)]->setPosition({130.0f, 371.0f, 1020.0f});
    _previews[_ranking.at(1)]->setPosition({210.0f, 331.0f, 1025.0f});
    _previews[_ranking.at(2)]->setPosition({207.0f, 325.0f, 988.8f});
    _previews[_ranking.at(3)]->setPosition({244.0f, 319.0f, 982.0f});
    for (auto &i : _previews) {
        i->setOrientation(side::north);
        i->setState(Character::state::idle);
    }
    _previews[_ranking.at(0)]->setState(Character::state::victory);
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