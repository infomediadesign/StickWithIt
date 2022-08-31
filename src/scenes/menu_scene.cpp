#include "menu_scene.h"


scenes::MenuScene::MenuScene() 
	: titlescreenTexture(LoadTexture("assets/graphics/backgrounds/menu_background.png"))
{
	std::cout << "Menu scene called!" << std::endl;
}


scenes::MenuScene::~MenuScene() {
	std::cout << "Menu scene deleted!" << std::endl; 
	UnloadTexture(titlescreenTexture);
}


void scenes::MenuScene::Update()
{
	if (_isSkilltreeWindowOpen)
		_skilltreeWindow->Update();

	if (_isSettingsWindowOpen)
		_settingsWindow->Update();


	if (IsKeyPressed(KEY_F2) && _isSettingsWindowOpen == false)
		_isSkilltreeWindowOpen = !_isSkilltreeWindowOpen;

	if (IsKeyPressed(KEY_F3) && _isSkilltreeWindowOpen == false)
		_isSettingsWindowOpen = !_isSettingsWindowOpen;
}


void scenes::MenuScene::Draw()
{
	DrawTexture(titlescreenTexture, 0, 0, WHITE);

	DrawText("F1 to start game", 10, 10, 10, WHITE);
	DrawText("F2 to open skilltree", 10, 25, 10, WHITE);
	DrawText("F3 to open settings", 10, 40, 10, WHITE);
	DrawText("F4 to exit game", 10, 54, 10, WHITE);

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
	if (IsKeyPressed(KEY_F1))
		return eGameScene;

	if (IsKeyPressed(KEY_F4))
		return -1;

	return 0;
}
