#include "game_scene.h"


scenes::GameScene::GameScene() 
{
	std::cout << "Game scene called!" << std::endl;

	AddObject(eScarecrow);
	AddObject(eFly);
	AddObject(eBird);
	AddObject(eMushroom);

	_activePlayer = _players[eScarecrow];

	_playersPositions.push_back(&_levelHandler->GetSpawnsPC()[3]);
}


scenes::GameScene::~GameScene()
{ 
	std::cout << "Game scene deleted!" << std::endl; 
}


// Update current scene here
void scenes::GameScene::Update()
{
	if (_isPlayerTurn)
	{
		// switch to fighting phase
		if (IsKeyPressed(KEY_ENTER))
		{
			_isPreperationPhase = false;
			_hasPreperationPhaseJustEnded = true;
			ResetEnemiesStats();
		}

		// handle movement of players
		if (_activePlayer->GetCanFly())
			_activePlayer->Move(_levelHandler->GetCollisionsSky(), _collisionsObjects);
		else
			if (_activePlayer->Move(_levelHandler->GetCollisionsGround(), _collisionsObjects))
				_levelHandler->DestroyWheat(*_activePlayer->GetPosition());

		if (_isPreperationPhase == false)
		{
			// Destroy the wheat tile of every ground player when entering the preperation phase
			if (_hasPreperationPhaseJustEnded)
			{
				for (auto& player : _players)
				{
					if (player->GetCanFly() == false)
					{
						_levelHandler->DestroyWheat(*player->GetPosition());
					}
					_hasPreperationPhaseJustEnded = false;
				}
			}

			// Destroy the wheat the player attacks
			_levelHandler->DestroyWheat(_activePlayer->Attack().second);
		}

		int sumOfMoveAndActionPoints = 0;
		for (auto& player : _players)
		{
			sumOfMoveAndActionPoints += player->GetMovePoints() + player->GetActionPoints();
		}
		if (sumOfMoveAndActionPoints == 0 || IsKeyPressed(KEY_BACKSPACE))
		{
			_isPlayerTurn = false;
		}

		// switch through players
		SwitchActivePlayer();
	}
	else
	{
		type::Vec_Position allCollisions = _levelHandler->GetSpawnsPC();
		for (auto& player : _players)
			allCollisions.push_back(*player->GetPosition());

		for (auto& enemy : _enemies)
		{
			if (enemy->GetCanFly())
				enemy->Move(allCollisions, _levelHandler->GetCollisionsSky());
			else
			{
				enemy->Move(allCollisions, _levelHandler->GetCollisionsGround());
				_levelHandler->DestroyWheat(*enemy->GetPosition());
			}
		}

		ResetPlayersStats();
		_isPlayerTurn = true;
	}
}


// Draw current scene here
void scenes::GameScene::Draw()
{
	_levelHandler->DrawGround();
	{
		for (auto& player : _players)
		{
			player->Animate();
		}

		for (auto& enemy : _enemies)
		{
			enemy->Animate();
		}
	}
	_levelHandler->DrawAir();

	//Draw UI here...
	DrawText(TextFormat("Wheat: %i", _levelHandler->GetNumberOfWheat()), 40, 40, 20, BLACK);
	DrawText(TextFormat("Lives: %i", _activePlayer->GetLives()), 40, 65, 20, BLACK);
	DrawText(TextFormat("Moves: %i", _activePlayer->GetMovePoints()), 40, 90, 20, BLACK);
	DrawText(TextFormat("Actions: %i", _activePlayer->GetActionPoints()), 40, 115, 20, BLACK);
	DrawFPS(5, game::SCREEN_HEIGHT - 20);
}


// If specific condition happens, change scene
int scenes::GameScene::ChangeScene()
{
	// Go to menu after player has died (or F2 is pressed for now)
	if (IsKeyPressed(KEY_F2))
		return eMenuScene;

	return 0;
}


void scenes::GameScene::NextLevel()
{
	_currentLevel++;
	_collisionsObjects = {};
	_isPreperationPhase = true;
	_hasPreperationPhaseJustEnded = false;
	for (auto& pos : _levelHandler->GetSpawnsPC())
		_playersPositions.push_back(&pos);
}


void scenes::GameScene::NextLevel(int level)
{
	_currentLevel = level;
	_collisionsObjects = {};
	_isPreperationPhase = true;
	_hasPreperationPhaseJustEnded = false;
	for (auto& pos : _levelHandler->GetSpawnsPC())
		_playersPositions.push_back(&pos);
}


void scenes::GameScene::SwitchActivePlayer()
{
	if (IsKeyPressed(KEY_Q))
	{
		_activePlayer->SetIsActive(false);
		_activePlayerIndex--;

		if (_activePlayerIndex < 0)
		{
			// @TODO change this to 4th helper
			_activePlayerIndex = eFly;
		}
		_activePlayer = _players[_activePlayerIndex];
		_activePlayer->SetIsActive(true);
	}
	if (IsKeyPressed(KEY_E))
	{
		_activePlayer->SetIsActive(false);
		_activePlayerIndex++;

		if (_activePlayerIndex > 1)
		{
			// @TODO change this to 4th helper
			_activePlayerIndex = eScarecrow;
		}
		_activePlayer = _players[_activePlayerIndex];
		_activePlayer->SetIsActive(true);
	}
}


void scenes::GameScene::ResetPlayersStats()
{
	for (auto& player : _players)
	{
		player->SetMovePoints(player->GetInitMovePoints());
		player->SetActionPoints(player->GetActionPoints());
	}
}

void scenes::GameScene::ResetEnemiesStats()
{
	for (auto& enemy : _enemies)
	{
		enemy->SetMovePoints(enemy->GetInitMovePoints());
	}
}

void scenes::GameScene::AddObject(int object)
{
	switch (object)
	{
	case eScarecrow:
		_players.push_back(std::make_shared<objects::Scarecrow>());
		_players.back()->Spawn(_levelHandler->GetSpawnsPC(), _levelHandler->GetCollisionsGround(), _collisionsObjects);
		_players.back()->SetIsPreperationPhase(&_isPreperationPhase);
		_collisionsObjects.push_back(_players.back()->GetPosition());
		_playersPositions.push_back(_players.back()->GetPosition());
		break;

	case eFly:
		_players.push_back(std::make_shared<objects::Fly>());
		_players.back()->Spawn(_levelHandler->GetSpawnsPC(), _levelHandler->GetCollisionsSky(), _collisionsObjects);
		_players.back()->SetIsPreperationPhase(&_isPreperationPhase);
		_collisionsObjects.push_back(_players.back()->GetPosition());
		_playersPositions.push_back(_players.back()->GetPosition());
		break;



	case eBird:
		_enemies.push_back(std::make_unique<objects::Bird>());
		_enemies.back()->Spawn(_levelHandler->GetSpawnsSky(), _levelHandler->GetCollisionsSky(), _collisionsObjects);
		_enemies.back()->SetIsPreperationPhase(&_isPreperationPhase);
		_collisionsObjects.push_back(_enemies.back()->GetPosition());
		break;

	case eMushroom:
		_enemies.push_back(std::make_unique<objects::Mushroom>());
		_enemies.back()->Spawn(_levelHandler->GetSpawnsGround(), _levelHandler->GetCollisionsGround(), _collisionsObjects);
		_enemies.back()->SetIsPreperationPhase(&_isPreperationPhase);
		_collisionsObjects.push_back(_enemies.back()->GetPosition());
		break;
	}
}
