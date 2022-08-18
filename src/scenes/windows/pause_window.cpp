#include "pause_window.h"

scenes::windows::PauseWindow::PauseWindow()
{
}

scenes::windows::PauseWindow::~PauseWindow()
{
}

void scenes::windows::PauseWindow::Update()
{
	if (IsKeyPressed(KEY_S))
		_isSettingsWindowActive = !_isSettingsWindowActive;

	if (_isSettingsWindowActive)
		_settingsWindow->Update();
}

void scenes::windows::PauseWindow::Draw()
{
	if (_isSettingsWindowActive)
		_settingsWindow->Draw();

	else
	{
		DrawText("Settings", 60, 50, 20, BLACK);
		DrawText("Exit to menu", 60, 75, 20, BLACK);
		DrawText("Resume", 60, 100, 20, BLACK);
	}
}
