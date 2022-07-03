#include "game_scene.h"

scenes::GameScene::GameScene()
{

	std::cout << "GameScene called." << std::endl;

	playerObjects.push_back(std::make_unique<objects::Scarecrow>());
}

scenes::GameScene::~GameScene()
{

	std::cout << "GameScene deleted." << std::endl;
}

void scenes::GameScene::Update()
{
	int uselessvariable = 0;

	std::tuple<int, std::vector<Vector2>> attackfield = { 1, {{0, 0}, {20, 20}} };

	//playerObjects[0]->getDamage(attackfield);

	//if (playerObjects[0]->getIsAlive() == false)
	//{
	//	std::cout << "actor has died";
	//	std::cin >> uselessvariable;
	//}

	std::cout << playerObjects[0]->getLives() << std::endl;

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