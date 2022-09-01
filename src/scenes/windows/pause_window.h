#pragma once

#include "../scene.h"
#include "../button.h"
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
		bool GetIsCurrentlyOpen();
		void SetISCurrentlyOpen(bool);

	private:

		std::unique_ptr<scenes::windows::SettingsWindow> _settingsWindow = std::make_unique<scenes::windows::SettingsWindow>();
		bool _isSettingsWindowActive = false;

		bool _isCurrentlyOpen = true;

		std::vector<Button*> buttons;
		int active_button = 0;
	};
}