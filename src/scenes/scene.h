#pragma once

#include "../extras/headers.h"
#include "../extras/typedefs.h"

namespace scenes 
{
	class Scene 
	{
	public:
		virtual ~Scene() = 0;

		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual int ChangeScene();

		enum {
			eMenuScene = 1,
			eGameScene = 2
		};
	};
}