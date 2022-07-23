#include "virtual_object.h"

objects::VirtualObject::~VirtualObject() {
	UnloadTexture(*_texture);
}

void objects::VirtualObject::GetDamage(int damage, type::VectorPositions positions)
{
}

void objects::VirtualObject::Animate() {
	_animationPlayer->Animate();
}

bool objects::VirtualObject::GetHasAttacked()
{
	return _hasAttacked;
}

void objects::VirtualObject::SetHasAttacked(bool hasAttacked) {
	_hasAttacked = hasAttacked;
}

bool objects::VirtualObject::GetHasMoved() {
	return _hasMoved;
}

void objects::VirtualObject::SetHasMoved(bool hasMoved) {
	_hasMoved = hasMoved;
}

int objects::VirtualObject::GetLives() {
	return _lives;
}

void objects::VirtualObject::SetLives(int lives) {
	_lives = lives;
}

int objects::VirtualObject::GetMovePoints() {
	return _movePoints;
}

void objects::VirtualObject::SetMovePoints(int movePoints) {
	_movePoints = movePoints;
}

bool objects::VirtualObject::GetIsAlive() {
	return _isAlive;
}

void objects::VirtualObject::SetIsAlive(bool isAlive) {
	_isAlive = isAlive;
}

bool objects::VirtualObject::GetCanFly() {
	return _canFly;
}

void objects::VirtualObject::setCanFly(bool canFly) {
	_canFly = canFly;
}

type::VectorPositions objects::VirtualObject::GetPositionsOfAttacks()
{
	return _positionsOfAttacks;
}

int objects::VirtualObject::GetDamageOfAttack()
{
	return _damageOfAttack;
}

type::Position* objects::VirtualObject::GetPosition() {
	return &_position;
}

void objects::VirtualObject::SetPosition(type::Position position) {
	_position = position;
}
