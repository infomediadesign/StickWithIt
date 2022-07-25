#include "object.h"


objects::Object::~Object()
{
	UnloadTexture(_texture);
}

void objects::Object::GetDamage(type::Pair_Damage_Vec_Position damageAndPositions)
{

}


void objects::Object::Animate() 
{
	_animationPlayer->Animate();
}


bool objects::Object::GetHasAttacked()
{
	return _hasAttacked;
}


void objects::Object::SetHasAttacked(bool hasAttacked) {
	_hasAttacked = hasAttacked;
}


bool objects::Object::GetHasMoved() {
	return _hasMoved;
}


void objects::Object::SetHasMoved(bool hasMoved) {
	_hasMoved = hasMoved;
}


int objects::Object::GetLives() {
	return _lives;
}


void objects::Object::SetLives(int lives) {
	_lives = lives;
}


int objects::Object::GetMovePoints() {
	return _movePoints;
}


void objects::Object::SetMovePoints(int movePoints) {
	_movePoints = movePoints;
}


bool objects::Object::GetIsAlive() {
	return _isAlive;
}


void objects::Object::SetIsAlive(bool isAlive) {
	_isAlive = isAlive;
}


bool objects::Object::GetCanFly() {
	return _canFly;
}


void objects::Object::setCanFly(bool canFly) {
	_canFly = canFly;
}


type::Position* objects::Object::GetPosition() {
	return &_position;
}


void objects::Object::SetPosition(type::Position position) {
	_position = position;
}

void objects::Object::SetIsPreperationPhase(bool* isPreperationPhase){
	_isPreperationPhase = isPreperationPhase;
}
