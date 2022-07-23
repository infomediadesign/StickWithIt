#pragma once

#include "../config.h"
#include "../extras/headers.h"
#include "../extras/typedefs.h"


namespace handlers {
	class AnimationPlayer {
	public:
		AnimationPlayer(type::Position* position, std::shared_ptr<Texture2D>& texture, int& textureColumns, int& textureRows, int& textureWidth, int& textureHeight,
			int& wantedSpeed, type::Position& textureOffset, type::VectorInt& framesPerRow);

		~AnimationPlayer();

		// Draws the current animation
		void Animate();

		// changes the current animation to wanted animation
		void SetCurrentAnimation(int animation);

		// Getter and Setter
		bool GetIsAnimationOver();

		// Call this in constructor of scarecrow
		void SetIsObjectScareCrow(bool isObjectScarecrow);

		void MakeTransparent(); void MakeUnTransparent();
		void SetWantedSpeed(int wantedSpeed);

		// Lists all possible animations (scarecrow has 1 death and 8 attack animations more)
		enum eAnimations {
			eIdleUp, eIdleDown, eIdleRight, eIdleLeft,
			eWalkUp, eWalkDown, eWalkRight, eWalkLeft,
			eAttackUp, eAttackDown, eAttackRight, eAttackLeft,
			eDeath1, eDeath2,
			eAttackUp2, eAttackDown2, eAttackRight2, eAttackLeft2,
			eAttackUp3, eAttackDown3, eAttackRight3, eAttackLeft3
		};

	private:
		// Generic sprite data
		type::Position* _position = nullptr;
		std::shared_ptr<Texture2D> _texture = nullptr;
		int _textureColumns = 0;
		int _textureRows = 0;
		int _textureWidth = 0;
		int _textureHeight = 0;
		int _wantedSpeed = 0;
		type::Position _textureOffset = {};
		type::VectorInt _framesPerRow = {};

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