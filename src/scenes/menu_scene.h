#pragma once

#include "scene.h"
#include "button.h"

#include "windows/settings_window.h"
#include "windows/skilltree_window.h"


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

	private:
		std::unique_ptr<scenes::windows::SettingsWindow> _settingsWindow = std::make_unique<scenes::windows::SettingsWindow>();
		bool _isSettingsWindowOpen = false;

		std::unique_ptr<scenes::windows::SkilltreeWindow> _skilltreeWindow = std::make_unique<scenes::windows::SkilltreeWindow>();
		bool _isSkilltreeWindowOpen = false;

		std::vector<Button*> buttons;
		int active_button = 0;

		Texture2D titlescreenTexture;
	};
}