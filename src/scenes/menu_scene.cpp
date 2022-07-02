#include "menu_scene.h"

scenes::MenuScene::MenuScene()
{

	std::cout << "MenuScene called." << std::endl;
}

scenes::MenuScene::~MenuScene()
{

	std::cout << "MenuScene deleted." << std::endl;
}

void scenes::MenuScene::Update()
{


}

void scenes::MenuScene::Draw()
{

	BeginDrawing();

	ClearBackground(WHITE);
	//draw below here

	DrawText("Willkommen in der Menueszene", 20, 20, 40, DARKPURPLE);

	EndDrawing();
}

int scenes::MenuScene::changeScene()
{
	if (IsKeyPressed(KEY_F1)) {
		return eGameScene;
	}
	else
	{
		return 0;
	}
}