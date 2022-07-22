#pragma once

#include "../extras/headers.h"
#include "../extras/typedefs.h"

namespace scenes {
	class Scene {
	public:
		// ChangeScene() will later determinate what scene to change to when specific thing happens in scene
		virtual ~Scene() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		virtual int ChangeScene() = 0;

		// Use enums to differentiate between the scenes
		enum {
			eMenuScene = 1,
			eGameScene = 2
		};
	};
}