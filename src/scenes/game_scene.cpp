#include "game_scene.h"


scenes::GameScene::GameScene() 
{
	std::cout << "Game scene called!" << std::endl;
}


scenes::GameScene::~GameScene()
{ 
	std::cout << "Game scene deleted!" << std::endl; 
}


// Update current scene here
void scenes::GameScene::Update()
{

}


// Draw current scene here
void scenes::GameScene::Draw()
{
	_levelDrawer->DrawGround();
	{

	}
	_levelDrawer->DrawAir();

	//Draw UI here...
}


// If specific condition happens, change scene
int scenes::GameScene::ChangeScene()
{
	// Go to menu after player has died (or F2 is pressed for now)
	if (IsKeyPressed(KEY_F2))
		return eMenuScene;

	return 0;
}
