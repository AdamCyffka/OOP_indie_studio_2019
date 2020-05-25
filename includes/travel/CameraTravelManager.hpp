/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** CameraTravelManager
*/

#ifndef CAMERATRAVELMANAGER_HPP_
#define CAMERATRAVELMANAGER_HPP_

#include <map>
#include "ACameraTravel.hpp"
#include "CircleCameraTravel.hpp"
#include "StraightCameraTravel.hpp"

class CameraTravelManager {
    public:
        CameraTravelManager(scene::ICameraSceneNode *camera, scene::ISceneManager *smgr);
        ~CameraTravelManager();

        enum travel {
            intro,
            introToMenu,
            menuToSelect,
            selectToMenu,
            selectToGame,
            gameToScore
        };

        ACameraTravel *getTravel(travel travel) const;
        void doTravel(travel travel);
    protected:
    private:
        scene::ISceneManager *_smgr;
        scene::ICameraSceneNode *_camera;
        std::map<travel, ACameraTravel *> _travels;
};

#endif /* !CAMERATRAVELMANAGER_HPP_ */
