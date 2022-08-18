#pragma once

#include "../scene.h"


namespace scenes::windows
{
	class SettingsWindow : public scenes::Scene
	{
	public:
		SettingsWindow();
		~SettingsWindow();

		void Update() override;
		void Draw() override;
	};
}