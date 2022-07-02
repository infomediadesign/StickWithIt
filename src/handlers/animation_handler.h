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

		AnimationHandler(Texture2D texture, int columns, int rows, int playbackSpeed, Vector2 offset);

		~AnimationHandler();

		void animate(int animation);

		enum Animation
		{
			eIdle,
			eDeath,

			eWalkUp,
			eWalkDown,
			eWalkRight,
			eWalkLeft,

			eAttackUp,
			eAttackDown,
			eAttackRight,
			eAttackLeft
		};
	};
}