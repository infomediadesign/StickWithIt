#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>

namespace scenes
{

	class Scene
	{

	public:

		virtual ~Scene() = 0;

		virtual void Update() = 0;

		virtual void Draw() = 0;

		virtual int changeScene() = 0;

	protected:

		enum eScenes
		{
			eMenuScene = 1,
			eGameScene = 2
		};
	};
}