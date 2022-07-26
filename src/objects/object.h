#pragma once

#include "../extras/headers.h"
#include "../extras/typedefs.h"
#include "../extras/textures.h"
#include "../handlers/animation_player.h"
#include "../config.h"


namespace objects 
{
	class Object 
	{
	public:

		virtual ~Object() = 0;


		// Determines where the objects can spawn
		// For player objects it's always same order but non player objects will spawn randomly
		virtual void Spawn(type::Vec_Position spawnLayer, type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects) = 0;


		// If an object is in reach of another enemy object, it attacks...
		virtual type::Pair_Damage_Vec_Position Attack() = 0;


		// ...and every enemy object checks if it is in the attacks range and if so it gets damaged
		void GetDamage(type::Pair_Damage_Vec_Position damageAndPositions);


		// Animate object depending on movement and action
		virtual void Animate();


		// Walk dependant on input or the path found, take collisions into account
		virtual bool Move(type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects) = 0;


		// Getters and Setters
		int GetLives();	void SetLives(int lives);
		int GetMovePoints(); void SetMovePoints(int movePoints);
		bool GetIsAlive(); void SetIsAlive(bool isAlive);
		bool GetCanFly(); void setCanFly(bool canFly);
		type::Position* GetPosition(); void SetPosition(type::Position position);
		void SetIsPreperationPhase(bool* isPreperationPhase);


	protected:

		// Default data
		int _lives = {};
		int _movePoints = {};
		int _attackDamage = {};
		bool _isAlive = true;
		bool _canFly = false;
		type::Position _position = {};


		// Default sprite data 
		Texture2D _texture = {};
		int _textureColumns = {};
		int _textureRows = {};
		int _textureWidth = {};
		int _textureHeight = {};
		int _wantedSpeed = {};							// The higher the slower the animation
		type::Position _textureOffset = {};
		type::Vec_Int _framesPerRow = {};


		bool* _isPreperationPhase = {};


		// Animation player to tell object what animation to play
		std::unique_ptr<handlers::AnimationPlayer> _animationPlayer = {};
	};
}