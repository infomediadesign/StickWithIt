#include "virtual_player_character.h"

objects::VirtualPlayerCharacter::~VirtualPlayerCharacter() {
}

void objects::VirtualPlayerCharacter::Attack()
{
	// sets positionsofattacks
	// sets attackdamage

	// make algorithm out of this
	if (_animationPlayer->GetIsAnimationOver())
	{
		if (IsKeyPressed(KEY_UP))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp);
				_positionsOfAttacks = { {_position.first + 0, _position.second - 1} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp);
				_positionsOfAttacks = { {_position.first + 0, _position.second - 1}, {_position.first + 0, _position.second - 2} , {_position.first - 1, _position.second - 2} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp2);
				_positionsOfAttacks = { {_position.first + 0, _position.second - 1}, {_position.first - 1, _position.second - 2} , {_position.first + 0, _position.second - 3} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackUp3);
				_positionsOfAttacks = { {_position.first - 1, _position.second - 1}, {_position.first + 0, _position.second - 1} , {_position.first + 1, _position.second - 1} };
				_damageOfAttack = _attackDamage;
			}
			_hasAttacked = true;
		}
		if (IsKeyPressed(KEY_DOWN))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown);
				_positionsOfAttacks = { {_position.first + 0, _position.second + 1} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown);
				_positionsOfAttacks = { {_position.first + 0, _position.second + 1}, {_position.first + 0, _position.second + 2} , {_position.first + 1, _position.second + 2} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown2);
				_positionsOfAttacks = { {_position.first + 0, _position.second + 1}, {_position.first + 1, _position.second + 2} , {_position.first + 0, _position.second + 3} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackDown3);
				_positionsOfAttacks = { {_position.first + 1, _position.second + 1}, {_position.first + 0, _position.second + 1} , {_position.first - 1, _position.second + 1} };
				_damageOfAttack = _attackDamage;
			}
			_hasAttacked = true;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight);
				_positionsOfAttacks = { {_position.first + 1, _position.second + 0} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight);
				_positionsOfAttacks = { {_position.first + 1, _position.second + 0}, {_position.first + 2, _position.second + 0} , {_position.first + 2, _position.second - 1} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight2);
				_positionsOfAttacks = { {_position.first + 1, _position.second + 0}, {_position.first + 2, _position.second - 1} , {_position.first + 3, _position.second + 0} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackRight3);
				_positionsOfAttacks = { {_position.first + 1, _position.second - 1}, {_position.first + 1, _position.second + 0} , {_position.first + 1, _position.second + 1} };
				_damageOfAttack = _attackDamage;
			}
			_hasAttacked = true;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			if (_activeWeapon == eNoWeapon) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				_positionsOfAttacks = { {_position.first - 1, _position.second + 0} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eScythe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				_positionsOfAttacks = { {_position.first - 1, _position.second + 0}, {_position.first - 2, _position.second + 0} , {_position.first - 2, _position.second + 1} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eShovel) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				_positionsOfAttacks = { {_position.first - 1, _position.second + 0}, {_position.first - 2, _position.second + 1} , {_position.first - 3, _position.second + 0} };
				_damageOfAttack = _attackDamage;
			}
			if (_activeWeapon == eHoe) {
				_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eAttackLeft);
				_positionsOfAttacks = { {_position.first - 1, _position.second + 1}, {_position.first - 1, _position.second + 0} , {_position.first - 1, _position.second - 1} };
				_damageOfAttack = _attackDamage;
			}
			_hasAttacked = true;
		}
	}
}

void objects::VirtualPlayerCharacter::Spawn(type::VectorPositions spawnLayer, type::VectorPositions collisionPositions)
{
	for (auto& possibleSpawn : spawnLayer) {

		bool checkIfPositionIsAvailable = true;

		for (auto& collisionPosition : collisionPositions) {
			if (possibleSpawn == collisionPosition)
				checkIfPositionIsAvailable = false;
		}

		if (checkIfPositionIsAvailable == true)
		{
			_position = possibleSpawn;
			break;
		}
	}
}

void objects::VirtualPlayerCharacter::Move(type::VectorPositions collisionLayer)
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
			if (futurePosition.first < 0 + 1 || futurePosition.first > data::cTilesPerRow - 2)
				futurePosition.first = _position.first;
			if (futurePosition.second < 0 + 1 || futurePosition.second > data::cTilesPerColumn - 2)
				futurePosition.second = _position.second;

			// Check if positition would be on collision
			for (auto& collisionPosition : collisionLayer)
				if (futurePosition == collisionPosition)
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

void objects::VirtualPlayerCharacter::Animate()
{
	if (_isActive == true)
		_animationPlayer->SetWantedSpeed(_wantedSpeed - 2);
	else
		_animationPlayer->SetWantedSpeed(_wantedSpeed);

	_animationPlayer->Animate();
}

bool objects::VirtualPlayerCharacter::GetIsActive() {
	return _isActive;
}

void objects::VirtualPlayerCharacter::SetIsActive(bool isActive) {
	_isActive = isActive;
}

int objects::VirtualPlayerCharacter::GetActionPoints() {
	return _actionPoints;
}

void objects::VirtualPlayerCharacter::SetActionPoints(int actionPoints) {
	_actionPoints = actionPoints;
}

int objects::VirtualPlayerCharacter::GetActiveWeapon() {
	return _activeWeapon;
}

void objects::VirtualPlayerCharacter::SetActiveWeapon(int weapon) {
	_activeWeapon = weapon;
}
