/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(scene::ISceneManager *sManager, video::IVideoDriver *driver, modelInfos_t model, int travelTime, side orientation)
: _sManager(sManager), _driver(driver), _model(model), _travelTime(travelTime), _orientation(orientation)
{
    _mesh = _sManager->addAnimatedMeshSceneNode(_sManager->getMesh(_model.filename.c_str()));
    if (!_mesh)
        throw CharacterException("Unable to create mesh with model " + _model.filename);
    _mesh->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    for (std::size_t i = 0; i < _model.textures.size(); i++) {
        video::ITexture *texture = _driver->getTexture(_model.textures[i].c_str());
        if (texture && _mesh) {
            _driver->removeTexture(texture);
            texture = _driver->getTexture(_model.textures[i].c_str());
            _mesh->getMaterial(u32(i)).setTexture(0, texture);
        }
    }
    setOrientation(orientation);
    setPosition(core::vector3df{0.0f, 0.0f, 0.0f});
    setSize(_model.size);
    setAnimationSpeed(30);
    setState(Character::state::idle);
}

Character::~Character()
{
    _mesh->drop();
}

//setters
void Character::setSize(f32 size)
{
    _mesh->setScale(core::vector3df(size, size, size));
}

void Character::setPosition(core::vector3df position)
{
    std::cout << "Character::setPosition a été call avec comme param : " << position.X << ", " << position.Y << ", " << position.Z << std::endl;
    _mesh->setPosition(position);
}


void Character::setState(Character::state state)
{
    switch (state) {
        case Character::state::idle:
            _mesh->setFrameLoop(_model.idleLoop.first, _model.idleLoop.second);
            break;
        case Character::state::running:
            _mesh->setFrameLoop(_model.runningLoop.first, _model.runningLoop.second);
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

void Character::setVisibility(bool state)
{
    _mesh->setVisible(state);
}

void Character::setOrientation(side orientation)
{
    switch (orientation) {
        case side::north:
            _mesh->setRotation(core::vector3df(0.0f, 0.0f, 0.0f));
            break;
        case side::south:
            _mesh->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
            break;
        case side::east:
            _mesh->setRotation(core::vector3df(0.0f, 90.0f, 0.0f));
            break;
        case side::west:
            _mesh->setRotation(core::vector3df(0.0f, -90.0f, 0.0f));
            break;
        default:
            break;
    }
    _orientation = orientation;
}

void Character::setAnimationSpeed(f32 animationSpeed)
{
    _mesh->setAnimationSpeed(animationSpeed);
}

void Character::setTravelTime(u32 travelTime)
{
    _travelTime = travelTime;
}

//getters
float Character::getSize() const
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

bool Character::getVisibility() const
{
    return _mesh->isVisible();
}

side Character::getOrientation() const
{
    return _orientation;
}

f32 Character::getAnimationSpeed() const
{
    return _mesh->getAnimationSpeed();
}

u32 Character::getTravelTime() const
{
    return _travelTime;
}

modelInfos_t Character::getModelInfos() const
{
    return _model;
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

void Character::removeAnimators()
{
    _mesh->removeAnimators();
}

bool Character::moveTo(core::vector3df position, u32 travelTime)
{
    core::vector3df currentPosition = getPosition();
    scene::ISceneNodeAnimator *animation = _sManager->createFlyStraightAnimator(currentPosition, position, (travelTime != 0) ? travelTime : _travelTime, false);

    if (animation) {
        if (_mesh) {
            setState(Character::state::running);
            setOrientation(getOrientationFromPath(currentPosition, position));
            _mesh->addAnimator(animation);

            animation->drop();
        } else {
            animation->drop();
            throw CharacterException("Mesh \"" + _model.filename + "\" not found");
        }
    } else {
        throw CharacterException("Cannot create a fly straight animator from the scene manager");
    }
    return true;
}


void Character::changeModel(modelInfos_t model)
{
    side orientation = getOrientation();
    core::vector3df position = getPosition();
    f32 animationSpeed = getAnimationSpeed();
    Character::state state = getState();

    _model = model;
    if (_mesh) {
        _mesh->remove();
        _mesh = nullptr;
    }
    _mesh = _sManager->addAnimatedMeshSceneNode(_sManager->getMesh(_model.filename.c_str()));
    if (!_mesh)
        throw CharacterException("Unable to create mesh with model " + _model.filename);
    _mesh->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    for (std::size_t i = 0; i < _model.textures.size(); i++) {
        video::ITexture *texture = _driver->getTexture(_model.textures[i].c_str());
        if (texture && _mesh) {
            _driver->removeTexture(texture);
            texture = _driver->getTexture(_model.textures[i].c_str());
            _mesh->getMaterial(u32(i)).setTexture(0, texture);
        }
    }
    setOrientation(orientation);
    setPosition(position);
    setSize(_model.size);
    setAnimationSpeed(animationSpeed);
    setState(state);
}