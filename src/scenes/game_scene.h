#pragma once

#include "scene.h"


namespace scenes 
{
	class GameScene : public Scene 
	{
	public:
		GameScene();
		~GameScene();

		void Update() override;
		void Draw() override;
		int ChangeScene() override;

	private:

	};
}