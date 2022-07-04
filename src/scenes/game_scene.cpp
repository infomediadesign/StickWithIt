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

	//damage progress for playercharacters + swtich to menu when player is dead
	if (playerObjects[0]->getIsAlive())
	{

		for (int currentPlayer = 0; currentPlayer < numberOfPlayerCharacters; currentPlayer++)
		{

			playerObjects[currentPlayer]->getDamage({ 1, 0, 1, 0, 0 });

			std::cout << playerObjects[currentPlayer]->getLives() << std::endl;

			if (currentPlayer > 0)
			{
				
				if (playerObjects[currentPlayer]->getLives() <= 0)
				{

					playerObjects.erase(playerObjects.begin() + currentPlayer);
				}
			}
		}
	}

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
	if (IsKeyPressed(KEY_F2) || !playerObjects[0]->getIsAlive()) {
		return eMenuScene;
	}
	else
	{
		return 0;
	}
}

void scenes::GameScene::addHelper()
{

	//...

	//playerObjects.push_back(chosen character)
	//umberOfPlayerCharacters++;
}
