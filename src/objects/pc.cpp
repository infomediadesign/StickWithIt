#include "pc.h"


objects::PC::~PC() {
}


type::Pair_Damage_Vec_Position objects::PC::Attack()
{
	type::Pair_Damage_Vec_Position damagePlusPositions;

	// make algorithm out of this
	if (_animationPlayer->GetIsAnimationOver())
	{
		if (IsKeyPressed(KEY_UP))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp);
				damagePlusPositions.second = {{_position.first + 0, _position.second - 1}};
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp);
				damagePlusPositions.second = { {_position.first + 0, _position.second - 1}, {_position.first + 0, _position.second - 2} , {_position.first - 1, _position.second - 2} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp2);
				damagePlusPositions.second = { {_position.first + 0, _position.second - 1}, {_position.first - 1, _position.second - 2} , {_position.first + 0, _position.second - 3} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp3);
				damagePlusPositions.second = { {_position.first - 1, _position.second - 1}, {_position.first + 0, _position.second - 1} , {_position.first + 1, _position.second - 1} };
				damagePlusPositions.first = _attackDamage;
			}
			_hasAttacked = true;
			return damagePlusPositions;
		}
		if (IsKeyPressed(KEY_DOWN))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown);
				damagePlusPositions.second = { {_position.first + 0, _position.second + 1} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown);
				damagePlusPositions.second = { {_position.first + 0, _position.second + 1}, {_position.first + 0, _position.second + 2} , {_position.first + 1, _position.second + 2} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown2);
				damagePlusPositions.second = { {_position.first + 0, _position.second + 1}, {_position.first + 1, _position.second + 2} , {_position.first + 0, _position.second + 3} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown3);
				damagePlusPositions.second = { {_position.first + 1, _position.second + 1}, {_position.first + 0, _position.second + 1} , {_position.first - 1, _position.second + 1} };
				damagePlusPositions.first = _attackDamage;
			}
			_hasAttacked = true;
			return damagePlusPositions;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight);
				damagePlusPositions.second = { {_position.first + 1, _position.second + 0} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight);
				damagePlusPositions.second = { {_position.first + 1, _position.second + 0}, {_position.first + 2, _position.second + 0} , {_position.first + 2, _position.second - 1} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight2);
				damagePlusPositions.second = { {_position.first + 1, _position.second + 0}, {_position.first + 2, _position.second - 1} , {_position.first + 3, _position.second + 0} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight3);
				damagePlusPositions.second = { {_position.first + 1, _position.second - 1}, {_position.first + 1, _position.second + 0} , {_position.first + 1, _position.second + 1} };
				damagePlusPositions.first = _attackDamage;
			}
			_hasAttacked = true;
			return damagePlusPositions;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				damagePlusPositions.second = { {_position.first - 1, _position.second + 0} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				damagePlusPositions.second= { {_position.first - 1, _position.second + 0}, {_position.first - 2, _position.second + 0} , {_position.first - 2, _position.second + 1} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				damagePlusPositions.second = { {_position.first - 1, _position.second + 0}, {_position.first - 2, _position.second + 1} , {_position.first - 3, _position.second + 0} };
				damagePlusPositions.first = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				damagePlusPositions.second = { {_position.first - 1, _position.second + 1}, {_position.first - 1, _position.second + 0} , {_position.first - 1, _position.second - 1} };
				damagePlusPositions.first = _attackDamage;
			}
			_hasAttacked = true;
			return damagePlusPositions;
		}
	}
}


void objects::PC::Spawn(type::Vec_Position spawnLayer, type::Vec_Position* collisionPositions)
{
	for (auto& possibleSpawn : spawnLayer) {

		bool checkIfPositionIsAvailable = true;

		for (auto& collisionPosition : *collisionPositions) {
			if (collisionPosition == possibleSpawn)
				checkIfPositionIsAvailable = false;
		}

		if (checkIfPositionIsAvailable == true)
		{
			_position = possibleSpawn;
			break;
		}
	}
}


void objects::PC::Move(type::Vec_Position* collisionLayer)
{
	if (_isActive == true)
	{
		if (_animationPlayer->GetIsAnimationOver() == true)
		{
			type::Position futurePosition = _position;

			if (_movePoints > 0)
			{
				if (IsKeyPressed(KEY_W)) {
					futurePosition.second--;
					_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eWalkUp);
				}
				else if (IsKeyPressed(KEY_S)) {
					futurePosition.second++;
					_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eWalkDown);
				}
				else if (IsKeyPressed(KEY_D)) {
					futurePosition.first++;
					_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eWalkRight);
				}
				else if (IsKeyPressed(KEY_A)) {
					futurePosition.first--;
					_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eWalkLeft);
				}
			}

			// Check if position would be on border
			if (futurePosition.first < 0 + 1 || futurePosition.first > game::TILES_PER_ROW - 2)
				futurePosition.first = _position.first;
			if (futurePosition.second < 0 + 1 || futurePosition.second > game::TILES_PER_COLUMN - 2)
				futurePosition.second = _position.second;

			// Check if positition would be on collision
			for (auto& collisionPosition : *collisionLayer)
				if (collisionPosition == futurePosition)
					futurePosition = _position;

			// If theres neither collision or border, move the object
			if (_position != futurePosition && _movePoints > 0) {
				_position = futurePosition;
				_hasMoved = true;
				_movePoints--;
			}
		}
	}
}


void objects::PC::Animate()
{
	if (_isActive == true && _speedIsAdjusted == false)
	{
		_wantedSpeed += 2;
		_speedIsAdjusted = true;
	}
	else if (_isActive == false && _speedIsAdjusted == true)
	{
		_wantedSpeed -= 2;
		_speedIsAdjusted = false;
	}


	_animationPlayer->Animate();
}


bool objects::PC::GetIsActive() {
	return _isActive;
}


void objects::PC::SetIsActive(bool isActive) {
	_isActive = isActive;
}


int objects::PC::GetActionPoints() {
	return _actionPoints;
}


void objects::PC::SetActionPoints(int actionPoints) {
	_actionPoints = actionPoints;
}


int objects::PC::GetActiveWeapon() {
	return _activeWeapon;
}


void objects::PC::SetActiveWeapon(int weapon) {
	_activeWeapon = weapon;
}
