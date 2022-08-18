#include "menu_scene.h"


scenes::MenuScene::MenuScene() 
{
	std::cout << "Menu scene called!" << std::endl;
}


scenes::MenuScene::~MenuScene() {
	std::cout << "Menu scene deleted!" << std::endl; }


void scenes::MenuScene::Update()
{
	if (_isSkilltreeWindowOpen)
		_skilltreeWindow->Update();


	if (_isSettingsWindowOpen)
		_settingsWindow->Update();


	if (IsKeyPressed(KEY_LEFT_CONTROL) && _isSkilltreeWindowOpen == false)
		_isSettingsWindowOpen = !_isSettingsWindowOpen;

	if (IsKeyPressed(KEY_RIGHT_CONTROL) && _isSettingsWindowOpen == false)
		_isSkilltreeWindowOpen = !_isSkilltreeWindowOpen;
}


void scenes::MenuScene::Draw()
{
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

	return 0;
}
