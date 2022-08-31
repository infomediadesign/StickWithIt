#include "settings_window.h"

scenes::windows::SettingsWindow::SettingsWindow()
	: SettingTexture(LoadTexture("assets/graphics/ui/Options/options_menu_sheet.png"))
{
}

scenes::windows::SettingsWindow::~SettingsWindow()
{
	UnloadTexture(SettingTexture);
}

void scenes::windows::SettingsWindow::Update()
{	
	if (IsKeyPressed(KEY_F)) {
		ToggleFullscreen();
	}
}

void scenes::windows::SettingsWindow::Draw()
{
	DrawTexture(SettingTexture, 172, 41, WHITE);
}