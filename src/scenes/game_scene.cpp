#include "game_scene.h"
#include <string>

scenes::GameScene::GameScene() 
{
	std::string skillpointsToString;
	std::ifstream savegameFile("savegame.txt");
	while (std::getline(savegameFile, skillpointsToString))
		_currentSkillpoints = std::stoi(skillpointsToString);

	std::cout << "Game scene called!" << std::endl;

	AddObject(eScarecrow);
	AddObject(eFly);
	AddObject(eBird);
	AddObject(eMushroom);
	AddObject(eBat);

	_activePlayer = _players[eScarecrow];

	_playersPositions.push_back(&_levelHandler->GetSpawnsPC()[3]);
}


scenes::GameScene::~GameScene()
{ 
	std::cout << "Game scene deleted!" << std::endl; 

	UnloadTexture(_stats);
}


// Update current scene here
void scenes::GameScene::Update()
{
	if (_isPauseWindowOpen)
	{
		_pauseWindow->Update();
	}
	else 
	{
		// player turn
		if (_isPlayerTurn)
		{
			// switch to fighting phase
			if (IsKeyPressed(KEY_P))
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
				// Destroy the wheat tile of every ground player when leaving the preperation phase
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


				// If the player decides to attack, destroy wheat and ask every enemy if it was in attack range (and if, damage it)
				type::Pair_Damage_Vec_Position attack = _activePlayer->Attack();
				if (attack.second.empty() == false)
				{
					// Destroy the wheat the player attacks
					_levelHandler->DestroyWheat(attack.second);

					for (auto& enemy : _enemies)
						enemy->GetDamage(attack);
				}
			}

			// If NO pc has move/actionpoints left, we start next turn and reset move/actionpoints
			int sumOfMoveAndActionPoints = 0;
			for (auto& player : _players)
			{
				sumOfMoveAndActionPoints += player->GetMovePoints() + player->GetActionPoints();
			}
			// End turn prematurely
			if (sumOfMoveAndActionPoints == 0 || (IsKeyPressed(KEY_BACKSPACE) && !_isPreperationPhase))
			{
				_isPlayerTurn = false;
			}


			// enable switching through players
			SwitchActivePlayer();


			// if an enemy dies it goes to the "graveyard" and plays its death animation, then disappears
			for (int enemy = 0; enemy < _enemies.size(); enemy++)
			{
				if (_enemies[enemy]->GetLives() <= 0)
				{
					// Delete its collision
					for (int i = 0; i < _collisionsObjects.size(); i++)
						if (_enemies[enemy]->GetPosition() == _collisionsObjects[i])
							_collisionsObjects.erase(std::next(_collisionsObjects.begin(), i));

					_deadObjects.push_back(_enemies[enemy]);
					_enemies.erase(std::next(_enemies.begin(), enemy));
				}
			}
		}
		// enemy turn
		else
		{
			// handle collisions/movement
			type::Vec_Position allCollisions = _levelHandler->GetSpawnsPC();
			for (auto& player : _players)
				allCollisions.push_back(*player->GetPosition());
			for (auto& pos : _levelHandler->GetSpawnsPC())
				allCollisions.push_back(pos);

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

			// When an enemy reaches the ritual, it damages the scarecrows lives
			for (int enemy = 0; enemy < _enemies.size(); enemy++)
			{
				for (auto& pos : _levelHandler->GetSpawnsPC())
				{
					if (*_enemies[enemy]->GetPosition() == pos)
					{
						_players[0]->SetLives(_players[0]->GetLives() - _enemies.at(enemy)->GetAttackDamage());
						_enemies.erase(std::next(_enemies.begin(), enemy));
						break;
					}
				}
			}

			// when an enemy is close to a player, it attacks him and updates attacked players lives
			for (auto& enemy : _enemies)
			{
				for (auto& player : _players)
				{
					if (enemy->GetPosition()->second + 1 == player->GetPosition()->second && enemy->GetPosition()->first + 0 == player->GetPosition()->first)
						player->GetDamage(enemy->Attack(0));

					else if (enemy->GetPosition()->second - 1 == player->GetPosition()->second && enemy->GetPosition()->first + 0 == player->GetPosition()->first)
						player->GetDamage(enemy->Attack(1));

					else if (enemy->GetPosition()->second + 0 == player->GetPosition()->second && enemy->GetPosition()->first + 1 == player->GetPosition()->first)
						player->GetDamage(enemy->Attack(2));

					else if (enemy->GetPosition()->second + 0 == player->GetPosition()->second && enemy->GetPosition()->first - 1 == player->GetPosition()->first)
						player->GetDamage(enemy->Attack(3));

					// only works with 2 players for now
					if (player->GetLives() <= 0 && _players.size() > 1) {
						_deadObjects.push_back(_players[1]);
						_players.pop_back();
					}
				}
			}

			// while we haven't reached a specific number of turns, we will spawn enemies each turn, randomly
			_turns++;
			srand(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));
			if (_turns <= _turnsPerLevel)
			{
				switch (rand() % 3)
				{
				case 0:
					AddObject(eMushroom);
					break;
				case 1:
					AddObject(eBird);
					break;
				case 2:
					AddObject(eBat);
					break;
				}
			}

			// Reset move/attack points and start player turn
			ResetPlayersStats();
			_isPlayerTurn = true;
		}
	}


	// Handle input for game stop (pause/settings opened)
	if (IsKeyPressed(KEY_ESCAPE))
	{
		_pauseWindow->SetISCurrentlyOpen(true);
		_isPauseWindowOpen = true;
	}

	if (_pauseWindow->GetIsCurrentlyOpen() == false)
		_isPauseWindowOpen = false;

	if (_enemies.empty() && _turns >= 5 && _levelHandler->GetNumberOfLevels() > _currentLevel)
		NextLevel();
}


// Draw current scene here
void scenes::GameScene::Draw()
{
	// Draw Ground...
	_levelHandler->DrawGround();
	// ...Then players...
	for (auto& player : _players)
	{
		player->Animate();
	}
	// ...Then enemies...
	if (!_enemies.empty())
		for (auto& enemy : _enemies)
		{
			enemy->Animate();
		}
	// ...Then dead characters...
	for (auto& object : _deadObjects)
	{
		object->AnimateDeath();
	}
	// ...Then treetops etc.
	_levelHandler->DrawAir();

	// Draw ui for current players stats
	DrawTexture(_stats, 20, 0, WHITE);
	DrawText(TextFormat("%i", _activePlayer->GetLives()), 48, 34, 20, WHITE);
	DrawText(TextFormat("%i", _activePlayer->GetMovePoints()), 110, 34, 20, WHITE);
	DrawText(TextFormat("%i", _activePlayer->GetActionPoints()), 162, 34, 20, WHITE);

	// Draw current window (settings/pause) if opened
	if (_isPauseWindowOpen)
	{
		DrawRectangle(0, 0, 640, 360, { 0, 0, 0, 80 });
		_pauseWindow->Draw();
	}
}


// If specific condition happens, change scene
int scenes::GameScene::ChangeScene()
{
	// Go to menu after player has died (or F2 is pressed for now)
	if (_players[0]->GetLives() <= 0 || _currentLevel >= _maxLevels - 1)
	{
		return eMenuScene;
	}

	return 0;
}


void scenes::GameScene::NextLevel()
{
	NextLevel(_currentLevel + 1);
}


void scenes::GameScene::NextLevel(int level)
{
	// Write saved wheat tiles into savegame file
	std::ofstream savegameFile("savegame.txt");
	savegameFile << _levelHandler->GetNumberOfWheat() / 2 + _currentSkillpoints;
	savegameFile.close();

	// Remove all dead objects
	_deadObjects.clear();

	_turns = 0;
	_currentLevel = level;
	_collisionsObjects.clear();
	_isPreperationPhase = true;
	_hasPreperationPhaseJustEnded = false;

	int i = 0;
	for (auto& player : _players) {
		player->SetPosition(_levelHandler->GetSpawnsPC()[i]);
		i++;
	}
}


void scenes::GameScene::SwitchActivePlayer()
{
	if (_players.size() > 1) {
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
	else
	{
		_activePlayer = _players[eScarecrow];
		_activePlayer->SetIsActive(true);
	}
}


void scenes::GameScene::ResetPlayersStats()
{
	for (auto& player : _players)
	{
		player->SetMovePoints(player->GetInitMovePoints());
		player->SetActionPoints(player->GetInitActionPoints());
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
	// Every time we add an object, it has to spawn somewhere where no other character is located, also we need to update the collisions map with every object we add
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

	case eBat:
		_enemies.push_back(std::make_unique<objects::Bat>());
		_enemies.back()->Spawn(_levelHandler->GetSpawnsSky(), _levelHandler->GetCollisionsSky(), _collisionsObjects);
		_enemies.back()->SetIsPreperationPhase(&_isPreperationPhase);
		_collisionsObjects.push_back(_enemies.back()->GetPosition());
		break;
	}
}
