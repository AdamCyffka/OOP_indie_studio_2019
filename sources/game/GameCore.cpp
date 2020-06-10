/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Player
*/

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include "GameCore.hpp"
#include "Core.hpp"
#include "hitbox.hpp"
#include "MyEventReceiver.hpp"
#include "GameCoreException.hpp"

GameCore::GameCore(Core *core)
{
	_core = core;
	_isInit = false;
	_isPaused = false;
	_isWaiting = false;
	_map = _core->getMap();
	_loadMap = _core->getLoadMap();
	_bomber = new Bomber(_map, _loadMap, this);
	_spawnAreas[1] = irr::core::vector3df{-450.0f, 308.0f, 780.0f};
	_spawnAreas[2] = irr::core::vector3df{-450.0f, 308.0f, 620.0f};
	_spawnAreas[3] = irr::core::vector3df{-550.0f, 308.0f, 780.0f};
	_spawnAreas[4] = irr::core::vector3df{-550.0f, 308.0f, 620.0f};
}

void GameCore::reset()
{
	for (auto it : _entities) {
		it->getCharacter()->removeAnimators();
	}
	_map->generateMap();
	_loadMap->emptyGameMap(-440.0, 308.0, 790.0);
	_loadMap->loadGameMap(-440.0, 308.0, 790.0);
	_powerUps.clear();
	_entities.clear();
	_isPaused = false;
	_isInit = false;
}

void GameCore::nextRound()
{
	_isWaiting = true;
	for (auto it : _entities) {
		it->getCharacter()->removeAnimators();
	}
	spawnPlayers();
	boost::this_thread::sleep_for(boost::chrono::seconds(3));
	spawnPlayers();
	_map->generateMap();
	_powerUps.clear();
	_loadMap->emptyGameMap(-440.0, 308.0, 790.0);
	_loadMap->loadGameMap(-440.0, 308.0, 790.0);
	_isWaiting = false;
}

void GameCore::init(const std::vector<Character *> characters, const std::vector<EntityType::EntityType> entityTypes, std::vector<EntityType::ControlType> controlTypes)
{
	for (int i = 1; i <= 4; ++i) {
		IEntity *entity;
		if (entityTypes.at(i - 1) == EntityType::EntityType::AI) {
			entity = new AI(characters.at(i - 1), i, _map, _core->getDriver(), _core->getSmgr(), _entities, _bomber);
			entity->setInput(Key_mouvement::Ia);
			if (controlTypes.at(i - 1) == EntityType::ControlType::NoDevice)
				_core->getInput()->setDevice(i, No_device);
		}
		else {
			entity = new Player(characters.at(i - 1), _core->getInput()->getPlayerInputs().at(i), i, _map, _core->getDriver(), _core->getSmgr(), this, _bomber);
			entity->setInput(Key_mouvement::None);
			if (controlTypes.at(i - 1) == EntityType::ControlType::Keyboard)
				_core->getInput()->setDevice(i, Controller);
			else if (controlTypes.at(i - 1) == EntityType::ControlType::Controller) {
				_core->getInput()->setJoystick(_core->getWindow());
				_core->getInput()->setDevice(i, Keyboard);
			}
		}
		_entities.push_back(entity);
	}
	spawnPlayers();
	_bomber->setEntities(_entities);
	boost::thread thr = boost::thread(boost::bind(&GameCore::nextRound, this));
	_isInit = true;
}

void GameCore::run()
{
	if (_isPaused || _isWaiting)
		return;
	if (gameOver())
	{
		_core->getMusicEngine()->stop("resources/music/game.mp3", false);
		_core->getMusicEngine()->add2D("resources/music/end.mp3", false, false, true, irrklang::ESM_AUTO_DETECT, true);
		_core->setGState(Core::menu);
		_core->setLState(Core::menuScore);
		_core->getCameraTravelManager()->doTravel(CameraTravelManager::travel::gameToScore);
		_core->getScore()->updateRanking(getRanking());
        _core->getScore()->spawnEntities();
		reset();
		return;
	}
	if (getRemainingEntities() == 1) {
		std::cout << "IL EN RESTE QU'UN" << std::endl;
		for (auto it : _entities)
			if (it->isAlive())
				it->setWinNumber(it->getWinNumber() + 1);
		if (!gameOver())
			boost::thread thr = boost::thread(boost::bind(&GameCore::nextRound, this));
		return;
	}
	auto inputs = _core->getInput()->getPlayerInputs();
	for (int i = 1; i <= 4; ++i) {
		if (_entities.at(i - 1)->getInput() == Key_mouvement::Ia) {
			static_cast<AI*>(_entities.at(i - 1))->run(inputs.at(i), _entities);
		} else
			_entities.at(i - 1)->run(inputs.at(i));
		SelectPowerUp(_entities.at(i - 1), isPowerUpsTaken(_powerUps, _map, _entities.at(i - 1)));
	}
}

void GameCore::SelectPowerUp(IEntity *entity, int id)
{
	switch (id) {
		case 1:
			entity->setBombAmount(-1);
			break;
		case 2:
			entity->setBombAmount(5);
			break;
		case 3:
			entity->setBombPass(true);
			break;
		case 4:
			entity->setBombAmount(1);
			break;
		case 5:
			entity->setFirePower(-1);
			break;
		case 6:
			entity->setFirePower(4);
			break;
		case 7:
			entity->setFirePower(1);
			break;
		case 8:
			entity->setSpeed(-1);
			break;
		case 9:
			entity->setSpeed(1);
			break;
		case 10:
			entity->setWallPass(true);
			break;
		case 0:
			break;
	}
}

void GameCore::addPowerUps(irr::core::vector3df &pos)
{
    u32 random = std::rand() % 100;

//	_powerUps.push_back(new BombDown(_core->getSmgr(), pos));
	if (random > 25)
		return;
    else if (random >= 0 && random < 2)
        _powerUps.push_back(new BombDown(_core->getSmgr(), pos)); //segfault(ou pas)
    else if (random >= 2 && random <= 8)
        _powerUps.push_back(new BombUp(_core->getSmgr(), pos)); //fonctionne
    else if (random > 8 && random <= 10)
        _powerUps.push_back(new FireDown(_core->getSmgr(), pos)); //fonctionne
    else if (random > 10 && random <= 16)
        _powerUps.push_back(new FireUp(_core->getSmgr(), pos)); //segfault (ou pas ?)
	else if (random > 16 && random <= 18)
        _powerUps.push_back(new SpeedDown(_core->getSmgr(), pos)); //fonctionne
	else if (random > 18 && random <= 24)
        _powerUps.push_back(new SpeedUp(_core->getSmgr(), pos)); //fonctionne
    else
	{
		random = std::rand() % 100;
		if (random >= 0 && random < 25)
		    _powerUps.push_back(new BombFull(_core->getSmgr(), pos)); //fonctionne
		else if (random >= 25 && random < 50)
	        _powerUps.push_back(new FireFull(_core->getSmgr(), pos)); //fonctionne
		else if (random >= 50 && random < 75)
	        _powerUps.push_back(new BombPass(_core->getSmgr(), pos)); //segfault (ou pas)
		else
	        _powerUps.push_back(new WallPass(_core->getSmgr(), pos));
	}
}

void GameCore::spawnPlayers()
{
	int count = 1;

	for (auto it : _entities) {
		it->getCharacter()->setPosition(_spawnAreas[count]);
		it->getCharacter()->setVisibility(true);
		it->getCharacter()->setState(Character::state::idle);
		it->setIsAlive(true);
		++count;
	}
}

bool GameCore::gameOver()
{
	for (auto it : _entities) {
		if (it->getWinNumber() >= 3)
			return (true);
	}
	return false;
}

int GameCore::getRemainingEntities()
{
	int count = 0;
	for (auto it : _entities) {
		if (it->isAlive()) {
			count++;
		}
	}
	return count;
}

std::vector<std::pair<int, int>> GameCore::getRanking()
{
	std::vector<std::pair<int, int>> ranking;
	for (auto entity : _entities) {
		if (entity->getWinNumber() == 3)
			ranking.push_back({entity->getEntityNumber() - 1, 3});
	}
	for (auto entity : _entities) {
		if (entity->getWinNumber() == 2)
			ranking.push_back({entity->getEntityNumber() - 1, 2});
	}
	for (auto entity : _entities) {
		if (entity->getWinNumber() == 1)
			ranking.push_back({entity->getEntityNumber() - 1, 1});
	}
	for (auto entity : _entities) {
		if (entity->getWinNumber() == 0)
			ranking.push_back({entity->getEntityNumber() - 1, 0});
	}
	return ranking;
}

std::vector<IEntity *> GameCore::getEntities() const
{
	return _entities;
}

void GameCore::setPause(bool state)
{
	_isPaused = state;
}

bool GameCore::isInit() const
{
	return _isInit;
}

bool GameCore::nextBlockHasBomb(std::pair<int, int> pos, bool powerUp)
{
	return _map->getBombMap()[pos.first][pos.second] == bomb && !powerUp;
}

bool GameCore::nextBlockHasWall(std::pair<int, int> pos)
{
	return _map->getMap()[pos.first][pos.second] == unbreakable;
}

bool GameCore::nextBlockHasBlock(std::pair<int, int> pos, bool powerUp)
{
	return _map->getMap()[pos.first][pos.second] == breakable && !powerUp;
}

Bomber *GameCore::getBomber()
{
	return _bomber;
}

Core *GameCore::getCore()
{
	return _core;
}