#include "gameScene.h"

scenes::GameScene::GameScene()
{

	std::cout << "GameScene called." << std::endl;
}

scenes::GameScene::~GameScene()
{

	std::cout << "GameScene deleted." << std::endl;
}

void scenes::GameScene::Update()
{

	levelDrawer->drawLevel(level);
	levelDrawer->exchangeTile({ 128, 128 });
}

void scenes::GameScene::Draw()
{

	BeginDrawing();

	ClearBackground(WHITE);
	//draw below here

	DrawText("Willkommen in der Gameszene", 20, 20, 40, SKYBLUE);

	EndDrawing();
}

int scenes::GameScene::changeScene()
{
	if (IsKeyPressed(KEY_F2)) {
		return eMenuScene;
	}
	else
	{
		return 0;
	}
}