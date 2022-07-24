#pragma once

#include "scene.h"
#include "../objects/objects.h"
#include "../handlers/level_handler.h"


namespace scenes 
{
	class GameScene : public Scene 
	{
	public:

		GameScene();
		~GameScene();

		void Update() override;
		void Draw() override;
		int ChangeScene() override;


	private:

		int _currentLevel = 0;
		void NextLevel();
		void NextLevel(int level);


		std::unique_ptr<objects::PC> _activePlayer = {};
		void SwitchActivePlayer();


		std::vector<std::shared_ptr<objects::PC>> _players = {};
		std::vector<std::shared_ptr<objects::NPC>> _enemies = {};


		// A collision layer includes all obstacles and objects
		type::Vec_Ptr_Position _collisionLayerGround = {};
		type::Vec_Ptr_Position _collisionLayerSky = {};


		std::unique_ptr<handlers::LevelHandler> _levelDrawer = std::make_unique<handlers::LevelHandler>(&_currentLevel);
	};
}