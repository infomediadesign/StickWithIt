#pragma once

#include "scene.h"


namespace scenes 
{
	class MenuScene : public Scene 
	{
	public:
		MenuScene();
		~MenuScene();

		void Update() override;
		void Draw() override;
		int ChangeScene() override;
	};
}