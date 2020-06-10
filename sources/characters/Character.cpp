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
    scene::IAnimatedMesh *mesh = _sManager->getMesh(_model.filename.c_str());
    _meshNode = _sManager->addAnimatedMeshSceneNode(mesh);
    if (!_meshNode)
        throw CharacterException("Unable to create mesh with model " + _model.filename);
    _meshNode->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    for (std::size_t i = 0; i < _model.textures.size(); i++) {
        video::ITexture *texture = _driver->getTexture(_model.textures[i].c_str());
        if (texture && _meshNode) {
            _driver->removeTexture(texture);
            texture = _driver->getTexture(_model.textures[i].c_str());
            _meshNode->getMaterial(u32(i)).setTexture(0, texture);
        } else {
            throw CharacterException("Can't access to texture " + _model.textures[i]);
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
    _meshNode->drop();
}

//setters
void Character::setSize(f32 size)
{
    _meshNode->setScale(core::vector3df(size, size, size));
}

void Character::setPosition(core::vector3df position)
{
    _meshNode->setPosition(position);
}


void Character::setState(Character::state state)
{
    switch (state) {
        case Character::state::idle:
            _meshNode->setFrameLoop(_model.idleLoop.first, _model.idleLoop.second);
            break;
        case Character::state::running:
            _meshNode->setFrameLoop(_model.runningLoop.first, _model.runningLoop.second);
            break;
        case Character::state::dying:
            _meshNode->setFrameLoop(_model.dyingLoop.first, _model.dyingLoop.second);
            break;
        case Character::state::dead:
            _meshNode->setFrameLoop(_model.deadLoop.first, _model.deadLoop.second);
            break;
        case Character::state::victory:
            _meshNode->setFrameLoop(_model.victoryLoop.first, _model.victoryLoop.second);
            break;
        default:
            break;
    }
    _state = state;
}

void Character::setVisibility(bool state)
{
    _meshNode->setVisible(state);
}

void Character::setOrientation(side orientation)
{
    switch (orientation) {
        case side::north:
            _meshNode->setRotation(core::vector3df(0.0f, 0.0f, 0.0f));
            break;
        case side::south:
            _meshNode->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
            break;
        case side::east:
            _meshNode->setRotation(core::vector3df(0.0f, 90.0f, 0.0f));
            break;
        case side::west:
            _meshNode->setRotation(core::vector3df(0.0f, -90.0f, 0.0f));
            break;
        default:
            break;
    }
    _orientation = orientation;
}

void Character::setAnimationSpeed(f32 animationSpeed)
{
    _meshNode->setAnimationSpeed(animationSpeed);
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
    return _meshNode->getPosition();
}

Character::state Character::getState() const
{
    return _state;
}

bool Character::getVisibility() const
{
    return _meshNode->isVisible();
}

side Character::getOrientation() const
{
    return _orientation;
}

f32 Character::getAnimationSpeed() const
{
    return _meshNode->getAnimationSpeed();
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
    _meshNode->removeAnimators();
}

const irr::scene::ISceneNodeAnimatorList &Character::getAnimators()
{
    return _meshNode->getAnimators();
}

void Character::moveTo(core::vector3df position, u32 travelTime)
{
    removeAnimators();
    core::vector3df currentPosition = getPosition();
    scene::ISceneNodeAnimator *animation = _sManager->createFlyStraightAnimator(currentPosition, position, (travelTime != 0) ? travelTime : _travelTime, false);

    if (animation) {
        if (_meshNode) {
            if (_state != Character::state::running)
                setState(Character::state::running);
            setOrientation(getOrientationFromPath(currentPosition, position));
            _meshNode->addAnimator(animation);

            animation->drop();
        } else {
            animation->drop();
            throw CharacterException("Mesh \"" + _model.filename + "\" not found");
        }
    } else {
        throw CharacterException("Cannot create a fly straight animator from the scene manager");
    }
}


void Character::changeModel(modelInfos_t model)
{
    side orientation = getOrientation();
    core::vector3df position = getPosition();
    f32 animationSpeed = getAnimationSpeed();
    Character::state state = getState();

    _model = model;
    if (_meshNode) {
        _meshNode->remove();
        _meshNode = nullptr;
    }
    irr::scene::IAnimatedMesh *mesh = _sManager->getMesh(_model.filename.c_str());
    if (!mesh)
        throw CharacterException("Unable to create mesh with model " + _model.filename);
    _meshNode = _sManager->addAnimatedMeshSceneNode(mesh);
    if (!_meshNode)
        throw CharacterException("Unable to add mesh with model " + _model.filename);
    _meshNode->setMaterialFlag(video::E_MATERIAL_FLAG::EMF_LIGHTING, false);
    for (std::size_t i = 0; i < _model.textures.size(); i++) {
        video::ITexture *texture = _driver->getTexture(_model.textures[i].c_str());
        if (texture && _meshNode) {
            _driver->removeTexture(texture);
            texture = _driver->getTexture(_model.textures[i].c_str());
            _meshNode->getMaterial(u32(i)).setTexture(0, texture);
        } else {
            throw CharacterException("Can't access to texture " + _model.textures[i]);
        }
    }
    setOrientation(orientation);
    setPosition(position);
    setSize(_model.size);
    setAnimationSpeed(animationSpeed);
    setState(state);
}