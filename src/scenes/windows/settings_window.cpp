#include "settings_window.h"

scenes::windows::SettingsWindow::SettingsWindow()
{
}

scenes::windows::SettingsWindow::~SettingsWindow()
{
	UnloadTexture(OptionTexture);
	UnloadTexture(FullscreenTexture);
	UnloadTexture(SoundTexture);
	UnloadTexture(KeyTexture);
	UnloadTexture(F_Texture);
	UnloadTexture(M_Texture);
}

void scenes::windows::SettingsWindow::Update()
{	
	if (IsKeyPressed(KEY_F)) {
		ToggleFullscreen();
	}
}

void scenes::windows::SettingsWindow::Draw()
{
	DrawTexture(OptionTexture, 172, 41, WHITE);
	DrawTexture(FullscreenTexture, 234, 150, WHITE);
	DrawTexture(SoundTexture, 234, 204, WHITE);
	DrawTexture(KeyTexture, 375, 196, WHITE);
	DrawTexture(F_Texture, 385, 158, WHITE);
	DrawTexture(M_Texture, 385, 203, WHITE);
}