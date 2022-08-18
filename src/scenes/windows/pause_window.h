#pragma once

#include "../scene.h"
#include "settings_window.h"


namespace scenes::windows
{
	class PauseWindow : public scenes::Scene
	{
	public:
		PauseWindow();
		~PauseWindow();

		void Update() override;
		void Draw() override;

	private:
		std::unique_ptr<scenes::windows::SettingsWindow> _settingsWindow = std::make_unique<scenes::windows::SettingsWindow>();
		bool _isSettingsWindowActive = false;
	};
}