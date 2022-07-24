#pragma once

#include "../config.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"


namespace handlers 
{
	class AnimationPlayer 
	{
	public:

		AnimationPlayer(type::Position* position, Texture2D* texture, int textureColumns, int textureRows, int textureWidth, int textureHeight,
			int* wantedSpeed, type::Position textureOffset, type::Vec_Int framesPerRow);
		~AnimationPlayer();


		// Draws the current animation
		void Animate();


		// changes the current animation to wanted animation
		void SetCurrentAnimation(int animation);


		// Getter and Setter
		bool GetIsAnimationOver();



		// Call this in constructor of scarecrow
		// This enables the animation player to keep playing the last frame of scarecrows death
		void SetIsObjectScareCrow(bool isObjectScarecrow);


		void MakeTransparent(); void MakeUntransparent();


		// Lists all possible animations (scarecrow has 1 death and 8 attack animations more)
		enum animations
		{
			eIdleUp, eIdleDown, eIdleRight, eIdleLeft,
			eWalkUp, eWalkDown, eWalkRight, eWalkLeft,
			eAttackUp, eAttackDown, eAttackRight, eAttackLeft,
			eDeath1, eDeath2,
			eAttackUp2, eAttackDown2, eAttackRight2, eAttackLeft2,
			eAttackUp3, eAttackDown3, eAttackRight3, eAttackLeft3
		};


	private:

		// Generic sprite data
		// This will change in the lifetime of an object
		type::Position* _position = {};
		int* _wantedSpeed = {};
		// This wont't change
		Texture2D* _texture = {};
		int _textureColumns = {};
		int _textureRows = {};
		int _textureWidth = {};
		int _textureHeight = {};
		type::Position _textureOffset = {};
		type::Vec_Int _framesPerRow = {};


		// Holds data of current animation state
		int _currentAnimation = eIdleDown;
		int _currentFrame = 0;
		float _speedIterator = 0;
		int _standartSpeed = 100;
		int _numberOfFramesToNotCancel = 0;
		bool _isAnimationOver = true;
		bool _isObjectScarecrow = false;
		Color _color = { 255, 255, 255, 255 };
	};
}