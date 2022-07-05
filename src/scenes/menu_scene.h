#pragma once

#include "scene.h"

//handlers

namespace scenes
{

	class MenuScene : public Scene
	{

	public:

		MenuScene();

		~MenuScene() override;

		void Update() override;

		void Draw() override;

		int changeScene() override;

	private:

	};
}