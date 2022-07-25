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


		void SwitchActivePlayer();
		std::shared_ptr<objects::PC> _activePlayer = {};
		std::vector<std::shared_ptr<objects::PC>> _players = {};
		std::vector<std::unique_ptr<objects::NPC>> _enemies = {};


		type::Vec_Ptr_Position _collisionsObjects = {};


		void AddObject(int object);
		enum
		{
			eScarecrow,
			eFly,

			eBird,
			eMushroom
		};


		std::unique_ptr<handlers::LevelHandler> _levelHandler = std::make_unique<handlers::LevelHandler>(&_currentLevel);
	};
}