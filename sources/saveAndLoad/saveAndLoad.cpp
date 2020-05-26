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
#include "EnumCheck.hpp"
#include "saveAndLoadException.hpp"

namespace pt = boost::property_tree;

//SAVE GAME

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
    player.put("input", entity->getInput());

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

//END SAVE GAME

//LOAD GAME

void loadMap(Core &core, pt::ptree *root)
{
    std::vector<std::string> map;
    std::map<int, std::map<int, blockState>> &_map = core.getMap()->getMap();

    for (pt::ptree::value_type &line : root->get_child("map"))
    {
        map.push_back(line.second.data());
    }

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            _map[i][j] = blockState(map[i - 1][j - 1] - '0');
        }
    }
}

void loadBombMap(Core &core, pt::ptree *root)
{
    std::vector<std::string> map;
    std::map<int, std::map<int, bombState>> &_map = core.getMap()->getBombMap();

    for (pt::ptree::value_type &line : root->get_child("bombMap"))
    {
        map.push_back(line.second.data());
    }

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            _map[i][j] = bombState(map[i - 1][j - 1] - '0');
        }
    }
}

void loadPlayerMap(Core &core, pt::ptree *root)
{
    std::vector<std::string> map;
    std::map<int, std::map<int, playerState>> &_map = core.getMap()->getPlayerMap();

    for (pt::ptree::value_type &line : root->get_child("playerMap"))
    {
        map.push_back(line.second.data());
    }

    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            _map[i][j] = playerState(map[i - 1][j - 1] - '0');
        }
    }
}

void setPlayerValues(int playerNB, Core &core, pt::ptree *root)
{
    std::vector<IEntity *> entities = core.getGame()->getEntities();
    const std::vector<Character *> &characters = core.getSelect()->getPreviews();
    IEntity *entity = entities[playerNB];
    IEntity *entitySaved;
    std::string path = "player" + std::to_string(playerNB) + ".";

    Key_mouvement input = (Key_mouvement)root->get<int>(path + "input");
    if (!Key_mouvementCheck::is_value(input))
        throw saveAndLoadException("Invalid Enum value");
    if (input == Key_mouvement::Ia)
        entity = new AI(characters[playerNB], playerNB, core.getMap());
    else
        entity = new Player(characters[playerNB], input, playerNB);
    entity->setIsAlive(root->get<bool>(path + "isAlive", 0));
    entity->setBombPass(root->get<bool>(path + "bombPass", 0));
    entity->setWallPass(root->get<bool>(path + "wallPass", 0));
    entity->setScore(root->get<int>(path + "score", 0));
    entity->setEntityNumber(root->get<int>(path + "entityNumber", 0));
    entity->setSpeed(root->get<int>(path + "speed", 0));
    entity->setBombAmount(root->get<int>(path + "bombAmount", 0));
    entity->setFirePower(root->get<int>(path + "firePower", 0));
    entity->setWinNumber(root->get<int>(path + "winNumber", 0));
}

void setCharacterValues(int playerNB, Core &core, pt::ptree *root)
{
    std::vector<IEntity *> entities = core.getGame()->getEntities();
    Character *character = entities[playerNB]->getCharacter();
    std::string path = "player" + std::to_string(playerNB) + ".character";    
}

void loadPlayer(int playerNB, Core &core, pt::ptree *root)
{
    try
    {
        setPlayerValues(playerNB, core, root);
        setCharacterValues(playerNB, core, root);
    }
    catch (pt::ptree_bad_path)
    {
        std::cerr << "Corrupted save file" << std::endl;
        return;
    }
    catch (std::exception const &msg)
    {
        std::cerr << msg.what() << std::endl;
        return;
    }
    /*
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
    root->add_child("player" + std::to_string(playerNB), player);*/
}

void loadGame(int slot, Core &core, CameraTravelManager *cameraTravelManager)
{
    pt::ptree root;
    try
    {
        pt::read_json("save" + std::to_string(slot) + ".json", root);
    }
    catch (pt::json_parser::json_parser_error)
    {
        std::cerr << "Unable to open save file" << std::endl;
        return;
    }
    loadPlayer(0, core, &root);
    saveGame(slot, core, cameraTravelManager);
    /*loadMap(core, &root);
    loadBombMap(core, &root);
    loadPlayerMap(core, &root);
    core.getLoadMap()->emptyGameMap(-440, 308, 790);
    core.getLoadMap()->loadGameMap(-440, 308, 790);
    cameraTravelManager->doTravel(CameraTravelManager::travel::selectToGame);
    core.setGState(Core::game);
    core.hideLayers();
    core.getGame()->init();

    saveGame(slot, core, cameraTravelManager);*/
    return;

    //Others elements for load
}

//END LOAD GAME