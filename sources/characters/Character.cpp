/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(scene::ISceneManager *sManager, modelInfos_t model, std::string name, int movementSpeed)
: _sManager(sManager), _model(model), _name(name), _movementSpeed(movementSpeed)
{
    _mesh = _sManager->addAnimatedMeshSceneNode(_sManager->getMesh(_model.filename.c_str())); 
    setPosition(core::vector3df{0, 0, 0});
    setSize(_model.size);
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
        case Character::state::dying:
            _mesh->setFrameLoop(_model.dyingLoop.first, _model.idleLoop.second);
            break;
        case Character::state::dead:
            std::cout <<"j'suis mort" << std::endl;
            break;
        default:
            break;
    }
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
    return _mesh->getAbsolutePosition();
}

Character::state Character::getState() const
{
    return _state;
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
void Character::moveTo(core::vector3df position, int speed = -1)
{
    scene::ISceneNodeAnimator *animation = _sManager->createFlyStraightAnimator(getPosition(), position, (speed != -1) ? speed : _movementSpeed, true);
    if (animation) {
        if (_mesh) {
            _mesh->addAnimator(animation);
            animation->drop();
        } else {
            animation->drop();
            throw CharacterException("Mesh \"" + _name + "\" not found");
        }
    } else {
        throw CharacterException("Cannot create a fly straight animator from the scene manager");
    }
}
