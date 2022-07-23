#include "menu_scene.h"


scenes::MenuScene::MenuScene() 
{
	std::cout << "Menu scene called!" << std::endl;
}


scenes::MenuScene::~MenuScene() {
	std::cout << "Menu scene deleted!" << std::endl; }


void scenes::MenuScene::Update()
{

}


void scenes::MenuScene::Draw()
{

}


int scenes::MenuScene::ChangeScene()
{
	if (IsKeyPressed(KEY_F1))
		return eGameScene;

	return 0;
}
