#include "settings_window.h"

scenes::windows::SettingsWindow::SettingsWindow()
{
}

scenes::windows::SettingsWindow::~SettingsWindow()
{
}

void scenes::windows::SettingsWindow::Update()
{
}

void scenes::windows::SettingsWindow::Draw()
{
	DrawText("Sound", 60, 50, 20, BLACK);
	DrawText("Fullscreen", 60, 75, 20, BLACK);
}
