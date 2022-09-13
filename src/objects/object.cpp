#include "object.h"


objects::Object::~Object()
{
	UnloadTexture(_texture);
}

type::Pair_Damage_Vec_Position objects::Object::Attack()
{
	return type::Pair_Damage_Vec_Position();
}

type::Pair_Damage_Vec_Position objects::Object::Attack(int animation)
{
	if (animation == 0)
	{
		_animationPlayer->SetCurrentAnimation(9);
		return { {_attackDamage},{{_position.first + 0, _position.second + 1}} };
	}

	if (animation == 1)
	{
		_animationPlayer->SetCurrentAnimation(8);
		return { {_attackDamage},{{_position.first + 0, _position.second - 1}} };
	}

	if (animation == 2)
	{
		_animationPlayer->SetCurrentAnimation(10);
		return { {_attackDamage},{{_position.first + 1, _position.second + 0}} };
	}

	if (animation == 3)
	{
		_animationPlayer->SetCurrentAnimation(11);
		return { {_attackDamage},{{_position.first - 1, _position.second + 0}} };
	}
}

void objects::Object::GetDamage(type::Pair_Damage_Vec_Position damageAndPositions)
{
	for (auto& position : damageAndPositions.second)
	{
		if (_position == position)
		{
			_lives -= damageAndPositions.first;
		}
	}
}


void objects::Object::Animate() 
{
	_animationPlayer->Animate();
}

void objects::Object::AnimateDeath()
{
	_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eDeath1);
	_animationPlayer->AnimateDeath();
}

bool objects::Object::Move(type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects)
{
	return false;
}

bool objects::Object::Move(type::Vec_Position posDestinations, type::Vec_Position posCollisions)
{
	return false;
}


int objects::Object::GetLives() {
	return _lives;
}


void objects::Object::SetLives(int lives) {
	_lives = lives;
}

int objects::Object::GetInitLives(){
	return _initLives;
}


int objects::Object::GetMovePoints() {
	return _movePoints;
}


void objects::Object::SetMovePoints(int movePoints) {
	_movePoints = movePoints;
}

int objects::Object::GetInitMovePoints(){
	return _initMovePoints;
}

int objects::Object::GetAttackDamage()
{
	return _attackDamage;
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
