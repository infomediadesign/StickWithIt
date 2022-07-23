#pragma once

#include "../extras/constants.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"

#include "../handlers/animation_player.h"

namespace objects {
	class VirtualObject {
	public:
		virtual ~VirtualObject() = 0;

		// Determines where the objects can spawn
		// For player objects it's always same order but non player objects will spawn randomly
		virtual void Spawn(type::VectorPositions spawnLayer, type::VectorPositions collisionPositions) = 0;

		// If an object is in reach of another enemy object, it attacks...
		virtual void Attack() = 0;

		// ...and every enemy object checks if it is in the attacks range and if so it gets damaged
		void GetDamage(int damage, type::VectorPositions positions);

		// Animate object depending on movement and action
		virtual void Animate();

		// Walk dependant on input or the path found, take collisions into account
		virtual void Move(type::VectorPositions collisionLayer) = 0;

		// Getters and Setters
		bool GetHasAttacked(); void SetHasAttacked(bool hasAttacked);
		bool GetHasMoved(); void SetHasMoved(bool hasMoved);
		int GetLives();	void SetLives(int lives);
		int GetMovePoints(); void SetMovePoints(int movePoints);
		bool GetIsAlive(); void SetIsAlive(bool isAlive);
		bool GetCanFly(); void setCanFly(bool canFly);
		type::VectorPositions GetPositionsOfAttacks();
		int GetDamageOfAttack();
		type::Position* GetPosition(); void SetPosition(type::Position position);

	protected:
		// Default data
		int _lives = 0;
		int _movePoints = 0;
		int _attackDamage = 0;
		bool _isAlive = true;
		bool _canFly = false;
		bool _hasMoved = false;
		bool _hasAttacked = false;
		type::Position _position = {};
		type::VectorPositions _positionsOfAttacks = {};
		int _damageOfAttack = {};

		// Default sprite data 
		std::shared_ptr<Texture2D> _texture = nullptr;
		int _textureColumns = 0;
		int _textureRows = 0;
		int _textureWidth = 0;
		int _textureHeight = 0;
		int _wantedSpeed = 0;								// The higher the slower the animation
		type::Position _textureOffset = {};
		type::VectorInt _framesPerRow = {};

		// Animation player to tell object what animation to play
		std::unique_ptr<handlers::AnimationPlayer> _animationPlayer = nullptr;
	};
}