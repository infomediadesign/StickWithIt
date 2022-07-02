//this class will draw the objects texture and provide functionality of an animation player

#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

namespace objects
{

	class AnimationHandler
	{

	public:

		AnimationHandler(Texture2D texture, int spritesheetWidth, int spritesheetHeight, int columns, int rows, int playbackSpeed, Vector2 actorPosition, Vector2 offset);

		void animate(int animation);

		enum Animation
		{

			eDeath,

			eIdleUp,
			eIdleDown,
			eIdleRight,
			eIdleLeft,

			eWalkUp,
			eWalkDown,
			eWalkRight,
			eWalkLeft,

			eAttackUp,
			eAttackDown,
			eAttackRight,
			eAttackLeft
		};

	private:

		bool mAnimationCompleted = false;

		Vector2 mActorPosition;

		Texture2D mTexture;
		int mSpriteSheetWidth;
		int mSpriteSheetHeight;
		int mColumns;
		int mRows;
		int mPlaybackSpeed;
		Vector2 mOffset;
	};
}