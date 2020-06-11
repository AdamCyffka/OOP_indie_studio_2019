/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include "Character.hpp"
#include "Game.hpp"
#include "LoadingException.hpp"
#include "MenuException.hpp"

Game::Game(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, std::vector<Character *> previews)
{
    _driver = driver;
    _env = env;
    _smgr = smgr;
    _previews = previews;

    loadTextures();
    loadButtons();
    run();
}

void Game::loadTextures()
{
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
    _textures["dry_bones"] = _driver->getTexture("resources/images/characters/MK8_Icon_DryBones.png");
    if (_textures.find("dry_bones") == _textures.end() || !_textures["dry_bones"])
        throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_DryBones.png");
    _textures["luigi"] = _driver->getTexture("resources/images/characters/MK8_Icon_Luigi.png");
    if (_textures.find("luigi") == _textures.end() || !_textures["luigi"])
        throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Luigi.png");
    _textures["luigi_fire"] = _driver->getTexture("resources/images/characters/MK8_Icon_Luigi_Fire.png");
    if (_textures.find("luigi_fire") == _textures.end() || !_textures["luigi_fire"])
        throw LoadingException("could not load texture : resources/images/characters/MK8_Icon_Luigi_Fire.png");
    _textures["grey_star"] = _driver->getTexture("resources/images/starGrey.png");
    if (_textures.find("grey_star") == _textures.end() || !_textures["grey_star"])
        throw LoadingException("could not load texture : resources/images/starGrey.png");
    _textures["star"] = _driver->getTexture("resources/images/star.png");
    if (_textures.find("star") == _textures.end() || !_textures["star"])
        throw LoadingException("could not load texture : resources/images/star.png");
}

void Game::loadButtons()
{
    printUpLeft();
    printUpRight();
    printDownLeft();
    printDownRight();
}

void Game::printStars(std::vector<IEntity *> entities)
{
    for (auto it : entities)
    {
    }

    for (auto it : entities)
    {
        _images["test"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("test") != _images.end() && !_images["test"])
            throw LoadingException("could not add image : test");
        _images["test"]->setImage(_textures["star"]);
        _images["test"]->setRelativePosition(irr::core::position2d<irr::s32>(500, 500));

        _images["test2"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("test2") != _images.end() && !_images["test2"])
            throw LoadingException("could not add image : test");
        _images["test2"]->setImage(_textures["star"]);
        _images["test2"]->setRelativePosition(irr::core::position2d<irr::s32>(1000, 1000));
    }
}

void Game::printUpLeft()
{
    if (_previews[0]->getModelInfos().name == "dr_peach")
    {
        _images["dr_peach"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dr_peach") != _images.end() && !_images["dr_peach"])
            throw LoadingException("could not add image : dr_peach");
        _images["dr_peach"]->setImage(_textures["dr_peach"]);
        _images["dr_peach"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "koopa")
    {
        _images["koopa"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("koopa") != _images.end() && !_images["koopa"])
            throw LoadingException("could not add image : koopa");
        _images["koopa"]->setImage(_textures["koopa"]);
        _images["koopa"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "lakitu")
    {
        _images["lakitu"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("lakitu") != _images.end() && !_images["lakitu"])
            throw LoadingException("could not add image : lakitu");
        _images["lakitu"]->setImage(_textures["lakitu"]);
        _images["lakitu"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "mario")
    {
        _images["mario"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("mario") != _images.end() && !_images["mario"])
            throw LoadingException("could not add image : Mario");
        _images["mario"]->setImage(_textures["mario"]);
        _images["mario"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "waluigi")
    {
        _images["waluigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("waluigi") != _images.end() && !_images["waluigi"])
            throw LoadingException("could not add image : waluigi");
        _images["waluigi"]->setImage(_textures["waluigi"]);
        _images["waluigi"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "green_toad")
    {
        _images["green_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("green_toad") != _images.end() && !_images["green_toad"])
            throw LoadingException("could not add image : green_toad");
        _images["green_toad"]->setImage(_textures["green_toad"]);
        _images["green_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "blue_toad")
    {
        _images["blue_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("blue_toad") != _images.end() && !_images["blue_toad"])
            throw LoadingException("could not add image : blue_toad");
        _images["blue_toad"]->setImage(_textures["blue_toad"]);
        _images["blue_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "yellow_toad")
    {
        _images["yellow_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("yellow_toad") != _images.end() && !_images["yellow_toad"])
            throw LoadingException("could not add image : yellow_toad");
        _images["yellow_toad"]->setImage(_textures["yellow_toad"]);
        _images["yellow_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "dry_bones")
    {
        _images["dry_bones"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dry_bones") != _images.end() && !_images["dry_bones"])
            throw LoadingException("could not add image : dry_bones");
        _images["dry_bones"]->setImage(_textures["dry_bones"]);
        _images["dry_bones"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "red_toad")
    {
        _images["red_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("red_toad") != _images.end() && !_images["red_toad"])
            throw LoadingException("could not add image : red_toad");
        _images["red_toad"]->setImage(_textures["red_toad"]);
        _images["red_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "luigi")
    {
        _images["luigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi") != _images.end() && !_images["luigi"])
            throw LoadingException("could not add image : luigi");
        _images["luigi"]->setImage(_textures["luigi"]);
        _images["luigi"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
    else if (_previews[0]->getModelInfos().name == "luigi_fire")
    {
        _images["luigi_fire"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi_fire") != _images.end() && !_images["luigi_fire"])
            throw LoadingException("could not add image : luigi_fire");
        _images["luigi_fire"]->setImage(_textures["luigi_fire"]);
        _images["luigi_fire"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 0));
    }
}

void Game::printDownLeft()
{
    if (_previews[2]->getModelInfos().name == "dr_peach")
    {
        _images["dr_peach"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dr_peach") != _images.end() && !_images["dr_peach"])
            throw LoadingException("could not add image : dr_peach");
        _images["dr_peach"]->setImage(_textures["dr_peach"]);
        _images["dr_peach"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "koopa")
    {
        _images["koopa"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("koopa") != _images.end() && !_images["koopa"])
            throw LoadingException("could not add image : koopa");
        _images["koopa"]->setImage(_textures["koopa"]);
        _images["koopa"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "lakitu")
    {
        _images["lakitu"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("lakitu") != _images.end() && !_images["lakitu"])
            throw LoadingException("could not add image : lakitu");
        _images["lakitu"]->setImage(_textures["lakitu"]);
        _images["lakitu"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "mario")
    {
        _images["mario"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("mario") != _images.end() && !_images["mario"])
            throw LoadingException("could not add image : Mario");
        _images["mario"]->setImage(_textures["mario"]);
        _images["mario"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "waluigi")
    {
        _images["waluigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("waluigi") != _images.end() && !_images["waluigi"])
            throw LoadingException("could not add image : waluigi");
        _images["waluigi"]->setImage(_textures["waluigi"]);
        _images["waluigi"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "green_toad")
    {
        _images["green_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("green_toad") != _images.end() && !_images["green_toad"])
            throw LoadingException("could not add image : green_toad");
        _images["green_toad"]->setImage(_textures["green_toad"]);
        _images["green_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "blue_toad")
    {
        _images["blue_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("blue_toad") != _images.end() && !_images["blue_toad"])
            throw LoadingException("could not add image : blue_toad");
        _images["blue_toad"]->setImage(_textures["blue_toad"]);
        _images["blue_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "yellow_toad")
    {
        _images["yellow_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("yellow_toad") != _images.end() && !_images["yellow_toad"])
            throw LoadingException("could not add image : yellow_toad");
        _images["yellow_toad"]->setImage(_textures["yellow_toad"]);
        _images["yellow_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "dry_bones")
    {
        _images["dry_bones"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dry_bones") != _images.end() && !_images["dry_bones"])
            throw LoadingException("could not add image : dry_bones");
        _images["dry_bones"]->setImage(_textures["dry_bones"]);
        _images["dry_bones"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "red_toad")
    {
        _images["red_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("red_toad") != _images.end() && !_images["red_toad"])
            throw LoadingException("could not add image : red_toad");
        _images["red_toad"]->setImage(_textures["red_toad"]);
        _images["red_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "luigi")
    {
        _images["luigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi") != _images.end() && !_images["luigi"])
            throw LoadingException("could not add image : luigi");
        _images["luigi"]->setImage(_textures["luigi"]);
        _images["luigi"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
    else if (_previews[2]->getModelInfos().name == "luigi_fire")
    {
        _images["luigi_fire"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi_fire") != _images.end() && !_images["luigi_fire"])
            throw LoadingException("could not add image : luigi_fire");
        _images["luigi_fire"]->setImage(_textures["luigi_fire"]);
        _images["luigi_fire"]->setRelativePosition(irr::core::position2d<irr::s32>(0, 953));
    }
}

void Game::printUpRight()
{
    if (_previews[1]->getModelInfos().name == "dr_peach")
    {
        _images["dr_peach"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dr_peach") != _images.end() && !_images["dr_peach"])
            throw LoadingException("could not add image : dr_peach");
        _images["dr_peach"]->setImage(_textures["dr_peach"]);
        _images["dr_peach"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "koopa")
    {
        _images["koopa"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("koopa") != _images.end() && !_images["koopa"])
            throw LoadingException("could not add image : koopa");
        _images["koopa"]->setImage(_textures["koopa"]);
        _images["koopa"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "lakitu")
    {
        _images["lakitu"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("lakitu") != _images.end() && !_images["lakitu"])
            throw LoadingException("could not add image : lakitu");
        _images["lakitu"]->setImage(_textures["lakitu"]);
        _images["lakitu"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "mario")
    {
        _images["mario"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("mario") != _images.end() && !_images["mario"])
            throw LoadingException("could not add image : Mario");
        _images["mario"]->setImage(_textures["mario"]);
        _images["mario"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "waluigi")
    {
        _images["waluigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("waluigi") != _images.end() && !_images["waluigi"])
            throw LoadingException("could not add image : waluigi");
        _images["waluigi"]->setImage(_textures["waluigi"]);
        _images["waluigi"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "green_toad")
    {
        _images["green_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("green_toad") != _images.end() && !_images["green_toad"])
            throw LoadingException("could not add image : green_toad");
        _images["green_toad"]->setImage(_textures["green_toad"]);
        _images["green_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "blue_toad")
    {
        _images["blue_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("blue_toad") != _images.end() && !_images["blue_toad"])
            throw LoadingException("could not add image : blue_toad");
        _images["blue_toad"]->setImage(_textures["blue_toad"]);
        _images["blue_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "yellow_toad")
    {
        _images["yellow_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("yellow_toad") != _images.end() && !_images["yellow_toad"])
            throw LoadingException("could not add image : yellow_toad");
        _images["yellow_toad"]->setImage(_textures["yellow_toad"]);
        _images["yellow_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "dry_bones")
    {
        _images["dry_bones"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dry_bones") != _images.end() && !_images["dry_bones"])
            throw LoadingException("could not add image : dry_bones");
        _images["dry_bones"]->setImage(_textures["dry_bones"]);
        _images["dry_bones"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "red_toad")
    {
        _images["red_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("red_toad") != _images.end() && !_images["red_toad"])
            throw LoadingException("could not add image : red_toad");
        _images["red_toad"]->setImage(_textures["red_toad"]);
        _images["red_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "luigi")
    {
        _images["luigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi") != _images.end() && !_images["luigi"])
            throw LoadingException("could not add image : luigi");
        _images["luigi"]->setImage(_textures["luigi"]);
        _images["luigi"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
    else if (_previews[1]->getModelInfos().name == "luigi_fire")
    {
        _images["luigi_fire"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi_fire") != _images.end() && !_images["luigi_fire"])
            throw LoadingException("could not add image : luigi_fire");
        _images["luigi_fire"]->setImage(_textures["luigi_fire"]);
        _images["luigi_fire"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 0));
    }
}

void Game::printDownRight()
{
    if (_previews[3]->getModelInfos().name == "dr_peach")
    {
        _images["dr_peach"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dr_peach") != _images.end() && !_images["dr_peach"])
            throw LoadingException("could not add image : dr_peach");
        _images["dr_peach"]->setImage(_textures["dr_peach"]);
        _images["dr_peach"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "koopa")
    {
        _images["koopa"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("koopa") != _images.end() && !_images["koopa"])
            throw LoadingException("could not add image : koopa");
        _images["koopa"]->setImage(_textures["koopa"]);
        _images["koopa"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "lakitu")
    {
        _images["lakitu"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("lakitu") != _images.end() && !_images["lakitu"])
            throw LoadingException("could not add image : lakitu");
        _images["lakitu"]->setImage(_textures["lakitu"]);
        _images["lakitu"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "mario")
    {
        _images["mario"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("mario") != _images.end() && !_images["mario"])
            throw LoadingException("could not add image : Mario");
        _images["mario"]->setImage(_textures["mario"]);
        _images["mario"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "waluigi")
    {
        _images["waluigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("waluigi") != _images.end() && !_images["waluigi"])
            throw LoadingException("could not add image : waluigi");
        _images["waluigi"]->setImage(_textures["waluigi"]);
        _images["waluigi"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "green_toad")
    {
        _images["green_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("green_toad") != _images.end() && !_images["green_toad"])
            throw LoadingException("could not add image : green_toad");
        _images["green_toad"]->setImage(_textures["green_toad"]);
        _images["green_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "blue_toad")
    {
        _images["blue_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("blue_toad") != _images.end() && !_images["blue_toad"])
            throw LoadingException("could not add image : blue_toad");
        _images["blue_toad"]->setImage(_textures["blue_toad"]);
        _images["blue_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "yellow_toad")
    {
        _images["yellow_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("yellow_toad") != _images.end() && !_images["yellow_toad"])
            throw LoadingException("could not add image : yellow_toad");
        _images["yellow_toad"]->setImage(_textures["yellow_toad"]);
        _images["yellow_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "dry_bones")
    {
        _images["dry_bones"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("dry_bones") != _images.end() && !_images["dry_bones"])
            throw LoadingException("could not add image : dry_bones");
        _images["dry_bones"]->setImage(_textures["dry_bones"]);
        _images["dry_bones"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "red_toad")
    {
        _images["red_toad"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("red_toad") != _images.end() && !_images["red_toad"])
            throw LoadingException("could not add image : red_toad");
        _images["red_toad"]->setImage(_textures["red_toad"]);
        _images["red_toad"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "luigi")
    {
        _images["luigi"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi") != _images.end() && !_images["luigi"])
            throw LoadingException("could not add image : luigi");
        _images["luigi"]->setImage(_textures["luigi"]);
        _images["luigi"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
    else if (_previews[3]->getModelInfos().name == "luigi_fire")
    {
        _images["luigi_fire"] = _env->addImage(irr::core::rect<irr::s32>(0, 0, 128, 128));
        if (_images.find("luigi_fire") != _images.end() && !_images["luigi_fire"])
            throw LoadingException("could not add image : luigi_fire");
        _images["luigi_fire"]->setImage(_textures["luigi_fire"]);
        _images["luigi_fire"]->setRelativePosition(irr::core::position2d<irr::s32>(1793, 953));
    }
}

void Game::run()
{
}

std::map<std::string, irr::gui::IGUIButton *> Game::getButtons()
{
    return _buttons;
}

std::map<std::string, irr::gui::IGUIImage *> Game::getImages()
{
    return _images;
}

std::map<std::string, irr::gui::IGUICheckBox *> Game::getCheckBox()
{
    return _checkBox;
}