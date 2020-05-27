/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <irrlicht.h>
#include "CharacterException.hpp"
#include "modelInfos.hpp"
#include "side.hpp"
#include "EnumCheck.hpp"

using namespace irr;
class Character {
    public:
        Character(scene::ISceneManager *sManager, video::IVideoDriver *driver, modelInfos_t model,
        int travelTime = 1000, side orientation = side::north);
        ~Character();

        enum state {
            idle,
            running,
            dying,
            dead,
            victory
        };

        using stateCheck = EnumCheck<state, state::idle, state::running, state::dying, state::dead, state::victory>;

        //setters
        void setSize(f32 size);
        void setPosition(core::vector3df position);
        void setState(Character::state state);
        void setVisibility(bool visibility);
        void setOrientation(side side);
        void setAnimationSpeed(f32 animationSpeed);
        void setTravelTime(u32 travelTime);

        //getters
        float getSize() const;
        core::vector3df getPosition() const;
        Character::state getState() const;
        bool getVisibility() const;
        side getOrientation() const;
        f32 getAnimationSpeed() const;
        u32 getTravelTime() const;
        std::string getModelName() const;

        //methods
        bool moveTo(core::vector3df position, u32 travelTime = 0);
        void changeModel(modelInfos_t model);
    protected:
    private:
        //attributes
            //irr
        scene::ISceneManager *_sManager;
        video::IVideoDriver *_driver;
        scene::IAnimatedMeshSceneNode *_mesh;
            //non irr
        Character::state _state;
        side _orientation;
        modelInfos_t _model;
        int _travelTime;

        //methods
        side getOrientationFromPath(core::vector3df posA, core::vector3df posB);
};

#endif /* !CHARACTER_HPP_ */
