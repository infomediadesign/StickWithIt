#include "menu_scene.h"
#include "button.h"

scenes::MenuScene::MenuScene()
	: titlescreenTexture(LoadTexture("assets/graphics/backgrounds/menu_background.png"))
{
	std::cout << "Titlescreen called." << std::endl;

	auto* button1 = new Button(LoadTexture("assets/graphics/ui/start_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_start_button.png"),
		45,
		70,
		true);

	auto* button2 = new Button(LoadTexture("assets/graphics/ui/skilltree_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_skilltree_button.png"),
		45,
		130,
		false);

	auto* button3 = new Button(LoadTexture("assets/graphics/ui/options_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_options_button.png"),
		45,
		190,
		false);

	auto* button4 = new Button(LoadTexture("assets/graphics/ui/exit_button_sheet.png"),
		LoadTexture("assets/graphics/ui/weiß_exit_button.png"),
		45,
		250,
		false);

	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
}

scenes::MenuScene::~MenuScene()
{
	std::cout << "Titlescreen deleted." << std::endl;
	UnloadTexture(titlescreenTexture);
}

void scenes::MenuScene::Update()
{
	if (_isSettingsWindowOpen == false && _isSkilltreeWindowOpen == false)
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

	if (_isSkilltreeWindowOpen)
		_skilltreeWindow->Update();

	if (_isSettingsWindowOpen)
		_settingsWindow->Update();

	if (IsKeyPressed(KEY_F2) && _isSettingsWindowOpen == false)
		_isSkilltreeWindowOpen = !_isSkilltreeWindowOpen;

	if (IsKeyPressed(KEY_F3) && _isSkilltreeWindowOpen == false)
		_isSettingsWindowOpen = !_isSettingsWindowOpen;

	if (IsKeyPressed(KEY_ENTER)) {
		if (active_button == 1) {
			_isSkilltreeWindowOpen = !_isSkilltreeWindowOpen;
			std::cout << "Button Nr. " << active_button << " eins..." << std::endl;
		}
		if (active_button == 2) {
			_isSettingsWindowOpen = !_isSettingsWindowOpen;
			std::cout << "Button Nr. " << active_button << " eins..." << std::endl;
		}
	}
}

void scenes::MenuScene::Draw()
{
	DrawTexture(titlescreenTexture, 0, 0, WHITE);

	for (auto& button : buttons) {
		DrawTexture(button->getTexture(), button->pos_x, button->pos_y, WHITE);
	}

	if (_isSettingsWindowOpen)
	{
		DrawRectangle(0, 0, 640, 360, { 0, 0, 0, 80 });
		_settingsWindow->Draw();
	}

	if (_isSkilltreeWindowOpen)
	{
		DrawRectangle(0, 0, 640, 360, { 0, 0, 0, 80 });
		_skilltreeWindow->Draw();
	}
}

int scenes::MenuScene::ChangeScene()
{
	if (IsKeyPressed(KEY_ENTER)) {
		std::cout << "Button Nr. " << active_button << " gedrückt..." << std::endl;
		if (active_button == 0) {
			std::cout << "Button Nr. " << active_button << " null..." << std::endl;
			return eGameScene;
		}

		if (active_button == 3) {
			std::cout << "Button Nr. " << active_button << " zwei..." << std::endl;
			return -1;
		}
	}
}