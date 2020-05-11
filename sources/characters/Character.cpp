/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(scene::ISceneManager *sManager, video::IVideoDriver *driver, modelInfos_t model, std::string name, int travelingTime, side orientation)
: _sManager(sManager), _driver(driver), _model(model), _name(name), _travelingTime(travelingTime), _orientation(orientation)
{
    _mesh = _sManager->addAnimatedMeshSceneNode(_sManager->getMesh(_model.filename.c_str()));
    _mesh->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    for (std::size_t i = 0; i < _model.textures.size(); i++) {
        video::ITexture *texture = _driver->getTexture(_model.textures[i].c_str());
        if (texture && _mesh) {
            _driver->removeTexture(texture);
            texture = _driver->getTexture(_model.textures[i].c_str());
            _mesh->getMaterial(i).setTexture(0, texture);
        }
    }
    std::cout << name <<" : j'ai " << std::to_string(_mesh->getMaterialCount()) << " materials"<< std::endl;
    setOrientation(orientation);
    setPosition(core::vector3df{0, 0, 0});
    setSize(_model.size);
    setAnimationSpeed(30);
    setState(Character::state::idle);
}

Character::~Character()
{
    _mesh->drop();
}

//setters
void Character::setSize(int size)
{
    _mesh->setScale(core::vector3df(size, size, size));
}

void Character::setPosition(core::vector3df position)
{
    _mesh->setPosition(position);
}

void Character::setState(Character::state state)
{
    switch (state) {
        case Character::state::idle:
            _mesh->setFrameLoop(_model.idleLoop.first, _model.idleLoop.second);
            break;
        case Character::state::moving:
            _mesh->setFrameLoop(_model.movingLoop.first, _model.movingLoop.second);
            break;
        case Character::state::dying:
            _mesh->setFrameLoop(_model.dyingLoop.first, _model.dyingLoop.second);
            break;
        case Character::state::dead:
            _mesh->setFrameLoop(_model.deadLoop.first, _model.deadLoop.second);
            break;
        case Character::state::victory:
            _mesh->setFrameLoop(_model.victoryLoop.first, _model.victoryLoop.second);
            break;
        default:
            break;
    }
    _state = state;
}

void Character::setOrientation(side orientation)
{
    switch (orientation) {
        case side::north:
            _mesh->setRotation(core::vector3df(0, 0, 0));
            break;
        case side::south:
            _mesh->setRotation(core::vector3df(0, 180, 0));
            break;
        case side::east:
            _mesh->setRotation(core::vector3df(0, 90, 0));
            break;
        case side::west:
            _mesh->setRotation(core::vector3df(0, -90, 0));
            break;
        default:
            break;
    }
    _orientation = orientation;
}

void Character::setAnimationSpeed(int animationSpeed)
{
    _mesh->setAnimationSpeed(animationSpeed);
}

void Character::setTravelingTime(int travelingTime)
{
    _travelingTime = travelingTime;
}

//getters
int Character::getSize() const
{
    return _model.size;
}

core::vector3df Character::getPosition() const
{
    return _mesh->getPosition();
}

Character::state Character::getState() const
{
    return _state;
}

side Character::getOrientation() const
{
    return _orientation;
}

int Character::getAnimationSpeed() const
{
    return _mesh->getAnimationSpeed();
}

int Character::getTravelingTime() const
{
    return _travelingTime;
}

//methods
side Character::getOrientationFromPath(core::vector3df posA, core::vector3df posB)
{
    if (posA.Z == posB.Z && posA.X != posB.X)
        return (posA.X > posB.X) ? side::east : side::west;
    else if (posA.X == posB.X && posA.Z != posB.Z)
        return (posA.Z > posB.Z) ? side::north : side::south;
    else
        return _orientation;
}

bool Character::moveTo(core::vector3df position, int travelingTime)
{
    core::vector3df currentPosition = getPosition();
    scene::ISceneNodeAnimator *animation = _sManager->createFlyStraightAnimator(currentPosition, position, (travelingTime != 0) ? travelingTime : _travelingTime, false);
    
    if (animation) {
        if (_mesh) {
            setState(Character::state::moving);
            setOrientation(getOrientationFromPath(currentPosition, position));
            _mesh->addAnimator(animation);

            animation->drop();
        } else {
            animation->drop();
            throw CharacterException("Mesh \"" + _name + "\" not found");
        }
    } else {
        throw CharacterException("Cannot create a fly straight animator from the scene manager");
    }
    return true;
}
