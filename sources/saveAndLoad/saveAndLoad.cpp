/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** save
*/

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/filesystem.hpp>
#include "saveAndLoad.hpp"

namespace pt = boost::property_tree;

void saveMap(Core &core, pt::ptree *root)
{
    std::map<int, std::map<int, blockState>> map = core.getMap()->getMap();
    pt::ptree map_node;

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        pt::ptree line_node;
        std::string lineInString = "";
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            lineInString += std::to_string(map[i][j]);
        }
        line_node.put("", lineInString);
        map_node.push_back(std::make_pair("", line_node));
    }
    root->add_child("map", map_node);
}

void saveBombMap(Core &core, pt::ptree *root)
{
    std::map<int, std::map<int, bombState>> bombMap = core.getMap()->getBombMap();
    pt::ptree map_node;

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        pt::ptree line_node;
        std::string lineInString = "";
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            lineInString += std::to_string(bombMap[i][j]);
        }
        line_node.put("", lineInString);
        map_node.push_back(std::make_pair("", line_node));
    }
    root->add_child("bombMap", map_node);
}

void savePlayerMap(Core &core, pt::ptree *root)
{
    std::map<int, std::map<int, playerState>> playerMap = core.getMap()->getPlayerMap();
    pt::ptree map_node;

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        pt::ptree line_node;
        std::string lineInString = "";
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            lineInString += std::to_string(playerMap[i][j]);
        }
        line_node.put("", lineInString);
        map_node.push_back(std::make_pair("", line_node));
    }
    root->add_child("playerMap", map_node);
}

void savePlayer(int playerNB, Core &core, pt::ptree *root)
{
    std::vector<IEntity *> entities = core.getGame()->getEntities();
    IEntity *entity = entities[playerNB];
    pt::ptree player;

    player.put("isAlive", entity->isAlive());
    player.put("firePower", entity->getFirePower());
    player.put("bombAmount", entity->getBombAmount());
    player.put("speed", entity->getSpeed());
    player.put("wallPass", entity->getWallPass());
    player.put("bombPass", entity->getBombPass());
    player.put("entityNumber", entity->getEntityNumber());
    player.put("score", entity->getScore());
    player.put("winNumber", entity->getWinNumber());

    Character *character = entity->getCharacter();
    pt::ptree character_node;
    character_node.put("size", character->getSize());
    character_node.put("state", character->getState());
    character_node.put("visibility", character->getVisibility());
    character_node.put("orientation", character->getOrientation());
    character_node.put("animationSpeed", character->getAnimationSpeed());
    character_node.put("travelTime", character->getTravelTime());
    character_node.put("modelName", character->getModelName());

    pt::ptree positions_node;
    pt::ptree position_node;
    core::vector3df position = character->getPosition();

    position_node.put("", position.X);
    positions_node.push_back(std::make_pair("", position_node));
    position_node.put("", position.Y);
    positions_node.push_back(std::make_pair("", position_node));
    position_node.put("", position.Z);
    positions_node.push_back(std::make_pair("", position_node));

    character_node.add_child("position", positions_node);
    player.add_child("character", character_node);
    root->add_child("player" + std::to_string(playerNB), player);
}

void saveGame(int slot, Core &core, CameraTravelManager *cameraTravelManager)
{
    pt::ptree root;

    savePlayer(0, core, &root);
    savePlayer(1, core, &root);
    savePlayer(2, core, &root);
    savePlayer(3, core, &root);
    saveMap(core, &root);
    saveBombMap(core, &root);
    savePlayerMap(core, &root);

    //Write save in save file
    pt::write_json("save" + std::to_string(slot) + ".json", root);
    return;

    //Others elements for load
    cameraTravelManager->doTravel(CameraTravelManager::travel::selectToGame);
    core.setGState(Core::game);
    core.hideLayers();
    core.getGame()->init();
}