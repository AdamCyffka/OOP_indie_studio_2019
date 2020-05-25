/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CameraTravelManager
*/

#include "CameraTravelManager.hpp"
#include "CameraTravelException.hpp"

CameraTravelManager::CameraTravelManager(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr)
: _smgr(smgr), _camera(camera)
{
    std::cout << "Camera travel manager created" << std::endl;
}

CameraTravelManager::~CameraTravelManager()
{
    std::cout << "Camera travel manager deleted" << std::endl;
}

ACameraTravel *CameraTravelManager::getTravel(travel travel) const
{
    if (_travels.find(travel) != _travels.end())
        return _travels.at(travel);
    else
        return nullptr;
}

void CameraTravelManager::doTravel(travel travel)
{
    switch (travel) {
        case travel::intro:
            if (auto travel = getTravel(intro)) {
                travel->start();
            } else {
                _travels[intro] = new CircleCameraTravel(_camera, _smgr,
                {0.0f, 100.0f, 0.0f}, {0.0f, 50.0f, 0.0f}, 500.0f, 0.00035f);
                if (auto travel = getTravel(intro))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: intro");
            }
            break;
        case travel::introToMenu:
            if (auto travel = getTravel(introToMenu)) {
                travel->start();
            } else {
                _travels[introToMenu] = new StraightCameraTravel(_camera, _smgr,
                _camera->getPosition(), {-179.2f, 55.8f, -36.1f}, {-111.0f, 45.0f, -24.0f}, u32(2000));
                if (auto travel = getTravel(introToMenu))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: introToMenu");
            }
            break;
        case travel::menuToSelect:
            if (auto travel = getTravel(menuToSelect)) {
                travel->start();
            } else {
                _travels[menuToSelect] = new StraightCameraTravel(_camera, _smgr,
                {-179.2f, 55.8f, -36.1f}, {-94.3f, 44.1f, 294.3f}, {-70.0f, 21.0f, 232.0f}, u32(2000));
                if (auto travel = getTravel(menuToSelect))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: menuToSelect");
            }
            break;
        case travel::selectToMenu:
            if (auto travel = getTravel(selectToMenu)) {
                travel->start();
            } else {
                _travels[selectToMenu] = new StraightCameraTravel(_camera, _smgr,
                {-94.3f, 44.1f, 294.3f}, {-179.2f, 55.8f, -36.1f}, {-111.0f, 45.0f, -24.0f}, u32(2000));
                if (auto travel = getTravel(selectToMenu))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: selectToMenu");
            }
            break;
        case travel::selectToGame:
            if (auto travel = getTravel(selectToGame)) {
                travel->start();
            } else {
                _travels[selectToGame] = new StraightCameraTravel(_camera, _smgr,
                    {-94.3f, 44.1f, 294.3f}, {-539.4f, 453.6f, 710.3f}, {-516.3f, 333.2f, 710.5f}, u32(2000));
                if (auto travel = getTravel(selectToGame))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: selectToGame");
            }
            break;
        case travel::gameToScore:
            if (auto travel = getTravel(gameToScore)) {
                travel->start();
            } else {
                _travels[gameToScore] = new StraightCameraTravel(_camera, _smgr,
                    {-539.4f, 453.6f, 710.3f}, {203.6f, 392.4f, 828.7f}, {117.5f, 325.1f, 1012.1f}, u32(2000));
                if (auto travel = getTravel(gameToScore))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: gameToScore");
            }
            break;
        case travel::scoreToMenu:
            if (auto travel = getTravel(scoreToMenu)) {
                travel->start();
            } else {
                _travels[scoreToMenu] = new StraightCameraTravel(_camera, _smgr,
                    {203.6f, 392.4f, 828.7f}, {-179.2f, 55.8f, -36.1f}, {-111.0f, 45.0f, -24.0f}, u32(2000));
                if (auto travel = getTravel(scoreToMenu))
                    travel->start();
                else
                    throw CameraTravelException("Camera travel manager can't access to camera travel for: scoreToMenu");
            }
            break;
        default:
            break;
    }
}