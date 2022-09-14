#pragma once

#include "scene.h"
#include "../objects/objects.h"
#include "../handlers/level_handler.h"

#include "windows/pause_window.h"

#include <fstream>

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
		int _turns = 0;
		int _turnsPerLevel = 10;
		int _currentSkillpoints = 0;

		std::unique_ptr<scenes::windows::PauseWindow> _pauseWindow = std::make_unique<scenes::windows::PauseWindow>();
		bool _isPauseWindowOpen = false;


		int _currentLevel = 0;
		int _maxLevels = 4;
		int _ritualLives = 10;
		void NextLevel();
		void NextLevel(int level);


		bool _isPreperationPhase = true;
		bool _hasPreperationPhaseJustEnded = false;
		bool _isPlayerTurn = true;


		void SwitchActivePlayer();
		int _activePlayerIndex = eScarecrow;


		std::shared_ptr<objects::PC> _activePlayer = {};
		std::vector<std::shared_ptr<objects::PC>> _players = {};
		std::vector<std::shared_ptr<objects::NPC>> _enemies = {};
		std::vector<std::shared_ptr<objects::Object>> _deadObjects = {};



		type::Vec_Ptr_Position _collisionsObjects = {};
		type::Vec_Ptr_Position _playersPositions = {};
		type::Vec_Position _enemyDestinations = {};
		type::Vec_Position _allCollisionsSky = {};
		type::Vec_Position _allCollisionsGround = {};


		void ResetPlayersStats();
		void ResetEnemiesStats();


		void AddObject(int object);
		enum
		{
			eScarecrow,
			eFly,

			eBird,
			eMushroom,
			eBat
		};


		std::unique_ptr<handlers::LevelHandler> _levelHandler = std::make_unique<handlers::LevelHandler>(&_currentLevel);

		Texture2D _stats = LoadTexture("assets/graphics/ui/stats.png");
	};
}