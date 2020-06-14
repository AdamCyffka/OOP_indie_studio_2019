/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** LoadMap
*/

#ifndef LOADMAP_HPP_
#define LOADMAP_HPP_

#include <irrlicht.h>
#include "Map.hpp"
#include "LoadingException.hpp"

class LoadMap {
    public:
        LoadMap(irr::gui::IGUIEnvironment *env, irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr);
        ~LoadMap() = default;
        void run();
		void loadGameMap(float x, float y, float z);
		void emptyGameMap(float x, float y, float z);
        Map *getMap();
		std::map<int, std::map<int, irr::scene::ISceneNode *>> getVisualMap();

	protected:
    private:

    	Map *_map;
		std::map<int, std::map<int, irr::scene::ISceneNode *>> _visualMap;

		irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
};

#endif /* !LOADMAP_HPP_ */