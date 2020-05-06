/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(scene::ISceneManager *sManager, modelInfos_t model, std::string name, int movementSpeed, side orientation)
: _sManager(sManager), _model(model), _name(name), _movementSpeed(movementSpeed), _orientation(orientation)
{
    _mesh = _sManager->addAnimatedMeshSceneNode(_sManager->getMesh(_model.filename.c_str())); 
    setPosition(core::vector3df{0, 0, 0});
    setSize(_model.size);
    setAnimationSpeed(15);
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
            _mesh->setFrameLoop(_model.movingLoop.first, _model.idleLoop.second);
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

void Character::setMovementSpeed(int movementSpeed)
{
    _movementSpeed = movementSpeed;
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

int Character::getMovementSpeed() const
{
    return _movementSpeed;
}

//methods
side Character::getOrientationFromPath(core::vector3df posA, core::vector3df posB)
{
    if (posA.Y == posB.Y && posA.X != posB.X)
        return (posA.X > posB.X) ? side::west : side::east;
    else if (posA.X == posB.X && posA.Y != posB.Y)
        return (posA.Y > posB.Y) ? side::south : side::north;
    else
        return _orientation;
}

bool Character::moveTo(core::vector3df position, int speed)
{
    core::vector3df currentPosition = getPosition();
    scene::ISceneNodeAnimator *animation = _sManager->createFlyStraightAnimator(currentPosition, position, (speed != -1) ? speed : _movementSpeed, true);
    
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
