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
#include "global.hpp"

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
    //ADDING ELEMENTS FOR PLAYER HERE

    Character *character = entity->getCharacter();
    pt::ptree character_node;
    character_node.put("size", character->getSize());
    character_node.put("state", character->getState());
    character_node.put("visibility", character->getVisibility());
    character_node.put("orientation", character->getOrientation());
    character_node.put("animationSpeed", character->getAnimationSpeed());
    character_node.put("travelTime", character->getTravelTime());
    //ADDING ELEMENTS FOR CHARACTER HERE

    //ALL CONDITIONS TO SAVE THE MODEL
    character_node.put("modelName", character->getModelInfos().name);

    //SAVE POSITIONS OF THE PLAYER
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

    //Write save in save file
    pt::write_json("save" + std::to_string(slot) + ".json", root);
    return;

    //Others elements for load
    cameraTravelManager->doTravel(CameraTravelManager::travel::selectToGame);
    core.setGState(Core::game);
	core.hideGameLayers();
	core.getGame()->init(core.getSelect()->getPreviews(), core.getInput()->getPlayerInput(), core.getSelect()->getEntityTypes());
}

//END SAVE GAME

//LOAD GAME

void loadMap(Core &core, pt::ptree *root)
{
    std::vector<std::string> map;
    std::map<int, std::map<int, blockState>> &_map = core.getMap()->getMap();

    for (pt::ptree::value_type &line : root->get_child("map"))
    {
        if (line.second.data().size() != 17)
            throw saveAndLoadException("Invalid map's size");
        map.push_back(line.second.data());
    }
    if (map.size() != 11)
        throw saveAndLoadException("Invalid map's size");
    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            blockState block = blockState(map[i - 1][j - 1] - '0');
            if (!blockStateCheck::is_value(block))
                throw saveAndLoadException("Invalid Enum value");
            _map[i][j] = block;
        }
    }
}

void loadBombMap(Core &core, pt::ptree *root)
{
    std::vector<std::string> map;
    std::map<int, std::map<int, bombState>> &_map = core.getMap()->getBombMap();

    for (pt::ptree::value_type &line : root->get_child("bombMap"))
    {
        if (line.second.data().size() != 17)
            throw saveAndLoadException("Invalid map's size");
        map.push_back(line.second.data());
    }
    if (map.size() != 11)
        throw saveAndLoadException("Invalid map's size");
    for (int i = 1; i < MAP_HEIGHT + 1; ++i)
    {
        for (int j = 1; j < MAP_WIDTH + 1; ++j)
        {
            bombState block = bombState(map[i - 1][j - 1] - '0');
            if (!bombStateCheck::is_value(block))
                throw saveAndLoadException("Invalid Enum value");
            _map[i][j] = block;
        }
    }
}

void setPlayerValues(int playerNB, Core &core, pt::ptree *root)
{
    std::vector<IEntity *> entities = core.getGame()->getEntities();
    const std::vector<Character *> &characters = core.getSelect()->getPreviews();
    IEntity *entity = entities[playerNB];
    IEntity *entitySaved = nullptr;
    std::string path = "player" + std::to_string(playerNB) + ".";

    Key_mouvement input = (Key_mouvement)root->get<int>(path + "input");
    if (!Key_mouvementCheck::is_value(input))
        throw saveAndLoadException("Invalid Enum value");
    if (input == Key_mouvement::Ia)
        entity = new AI(characters[playerNB], playerNB + 1, core.getMap());
    else
        entity = new Player(characters[playerNB], input, playerNB + 1, core.getMap(), core.getGame());
    entity->setIsAlive(root->get<bool>(path + "isAlive", 0));
    entity->setBombPass(root->get<bool>(path + "bombPass", 0));
    entity->setWallPass(root->get<bool>(path + "wallPass", 0));
    entity->setScore(root->get<int>(path + "score", 0));
    entity->setEntityNumber(root->get<int>(path + "entityNumber", 0));
    entity->setSpeed(root->get<int>(path + "speed", 0));
    entity->setBombAmount(root->get<int>(path + "bombAmount", 0));
    entity->setFirePower(root->get<int>(path + "firePower", 0));
    entity->setWinNumber(root->get<int>(path + "winNumber", 0));
    //ADDING ELEMNTS TO LOAD HERE FOR PLAYER
}

void setCharacterValues(int playerNB, Core &core, pt::ptree *root)
{
    std::vector<IEntity *> entities = core.getGame()->getEntities();
    Character *character = entities[playerNB]->getCharacter();
    std::string path = "player" + std::to_string(playerNB) + ".character.";

    try
    {
        character->changeModel(g_modelInfos.at(root->get<std::string>(path + "modelName", "")));
    }
    catch (std::exception const &msg)
    {
        std::cerr << msg.what() << std::endl;
        return;
    }

    character->setSize(root->get<f32>(path + "size", 0));
    character->setVisibility(root->get<bool>(path + "visibility", 0));
    character->setAnimationSpeed(root->get<f32>(path + "animationSpeed", 0));
    character->setTravelTime(root->get<u32>(path + "travelTime", 0));

    side orientation = (side)root->get<int>(path + "orientation", 0);
    if (!sideCheck::is_value(orientation))
        throw saveAndLoadException("Invalid Enum value");
    character->setOrientation(orientation);

    Character::state state = (Character::state)root->get<int>(path + "state", 0);
    if (!Character::stateCheck::is_value(state))
        throw saveAndLoadException("Invalid Enum value");
    character->setState(state);

    std::vector<int> positions;
    for (pt::ptree::value_type &line : root->get_child(path + "position"))
        positions.push_back(std::stoi(line.second.data()));
    if (positions.size() != 3)
        throw saveAndLoadException("Invalid player's position");
    character->setPosition(core::vector3df(positions[0], positions[1], positions[2]));
    //ADDING ELEMNTS TO LOAD HERE FOR CHARACTER
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
        throw saveAndLoadException("Invalid Player");
        return;
    }
}

void checkSkins(Core &core, pt::ptree *root)
{
    std::vector<std::string> players;
    players.push_back(root->get<std::string>("player0.character.modelName", ""));
    players.push_back(root->get<std::string>("player1.character.modelName", ""));
    players.push_back(root->get<std::string>("player2.character.modelName", ""));
    players.push_back(root->get<std::string>("player3.character.modelName", ""));

    for (auto player: players)
    {
        if (player.compare("") == 0)
            throw saveAndLoadException("Invalid player's model");
        if (player.compare("mario") != 0 && player.compare("waluigi") != 0 && player.compare("luigi") != 0 && player.compare("dr_peach") != 0 && player.compare("dry_bones") != 0 && player.compare("lakitu") != 0 && player.compare("koopa") != 0
        && player.compare("red_toad") != 0 && player.compare("yellow_toad") != 0 && player.compare("green_toad") != 0 && player.compare("blue_toad") != 0)
            throw saveAndLoadException("Invalid player's model");
    }
    if (players[0].compare(players[1]) == 0 || players[0].compare(players[2]) == 0 || players[0].compare(players[3]) == 0 || players[1].compare(players[2]) == 0 || players[1].compare(players[3]) == 0 || players[2].compare(players[3]) == 0)
    {
        throw saveAndLoadException("Two times the same model");
    }
}

void loadGame(int slot, Core &core, CameraTravelManager *cameraTravelManager)
{
    //INIT GAME JUST IN CASE
    core.getGame()->init(core.getSelect()->getPreviews(), core.getInput()->getPlayerInput(), core.getSelect()->getEntityTypes());

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
    try
    {
        //only for the error handling
        checkSkins(core, &root);

        loadPlayer(0, core, &root);
        loadPlayer(1, core, &root);
        loadPlayer(2, core, &root);
        loadPlayer(3, core, &root);
        loadMap(core, &root);
        loadBombMap(core, &root);
    }
    catch (std::exception const &msg)
    {
        core.getGame()->reset();
        std::cerr << msg.what() << std::endl;
        return;
    }
    //Empty the map to load the one frome the save
    core.getLoadMap()->emptyGameMap(-440, 308, 790);
    core.getLoadMap()->loadGameMap(-440, 308, 790);
    //End of load now start the game
    std::cout << "Save correct" << std::endl;
    core.getMusicEngine()->stop("resources/music/menu.mp3", false);
    core.getMusicEngine()->add2D("resources/music/game.mp3", true, false, true, irrklang::ESM_AUTO_DETECT);
    cameraTravelManager->doTravel(CameraTravelManager::travel::selectToGame);
    core.setGState(Core::game);
    core.hideGameLayers();
    return;

    //Others elements for load
}

//END LOAD GAME