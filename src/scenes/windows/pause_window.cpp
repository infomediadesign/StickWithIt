#include "pause_window.h"
#include "../game_scene.h"
#include "../button.h"
#include "../menu_scene.h"


scenes::windows::PauseWindow::PauseWindow()
{
	auto* button1 = new Button(LoadTexture("assets/graphics/ui/resume_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_resume_button.png"),
		45,
		90,
		true);

	auto* button2 = new Button(LoadTexture("assets/graphics/ui/options_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_options_button.png"),
		45,
		150,
		false);

	auto* button3 = new Button(LoadTexture("assets/graphics/ui/exit_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_exit_button.png"),
		45,
		210,
		false);

	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
}

scenes::windows::PauseWindow::~PauseWindow()
{
}

void scenes::windows::PauseWindow::Update()
{
	if (_isSettingsWindowActive == false)
	{
		if (IsKeyPressed(KEY_DOWN)) {
			buttons[active_button]->active = false;
			if (active_button < buttons.size() - 1)
				active_button++;
			else active_button = 0;

			buttons[active_button]->active = true;
		}

		if (IsKeyPressed(KEY_UP)) {
			buttons[active_button]->active = false;
			if (active_button == 0)
				active_button = buttons.size() - 1;
			else active_button--;

			buttons[active_button]->active = true;
		}
	}

	if (IsKeyPressed(KEY_S))
		_isSettingsWindowActive = !_isSettingsWindowActive;

	if (_isSettingsWindowActive)
		_settingsWindow->Update();

	if (IsKeyPressed(KEY_ENTER)) {
		if (active_button == 0) {

			std::cout << "Button Nr. " << active_button << " eins..." << std::endl;
			_isCurrentlyOpen = false;
		}
		if (active_button == 1) {
			_isSettingsWindowActive = !_isSettingsWindowActive;
			std::cout << "Button Nr. " << active_button << " eins..." << std::endl;
		}
		if (active_button == 2) {
			std::cout << "Button Nr. " << active_button << " eins..." << std::endl;
			SetExitKey(KEY_ENTER);
		}
	}
}

void scenes::windows::PauseWindow::Draw()
{
	if (_isSettingsWindowActive)
		_settingsWindow->Draw();

	else
	{
		for (auto& button : buttons) {
			DrawTexture(button->getTexture(), button->pos_x, button->pos_y, WHITE);
			if (active_button == 2) {
				DrawText("You are trapped, hit it twice", 70, 260, 20, WHITE);
			}
		}
	}
}

bool scenes::windows::PauseWindow::GetIsCurrentlyOpen()
{
	return _isCurrentlyOpen;
}

void scenes::windows::PauseWindow::SetISCurrentlyOpen(bool open)
{
	_isCurrentlyOpen = open;
}
