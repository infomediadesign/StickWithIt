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

		virtual void Update() override;

		virtual void Draw() override;

		virtual int changeScene() override;

	private:

	};
}