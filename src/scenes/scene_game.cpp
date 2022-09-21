#include "scene_game.h"

scene::GameScene::GameScene(std::shared_ptr<gs::GameState>& gamestate)
	: Scene(gamestate)
{
	window_active_ = std::make_unique<window::WindowNextLevel>(gamestate_, level_current_);

	// Reset wheat counter
	gamestate_->SetWheatThisRun(0);

	players_.push_back(spawner_->SpawnPlayer(actor::Spawner::SCARECROW, map_));
	players_.push_back(spawner_->SpawnPlayer(actor::Spawner::FLY, map_));

	for (auto& enemy : spawner_->SpawnWave(map_->GetLevelHandler()->GetEnemiesPerRound(), map_))
	{
		enemies_.push_back(enemy);
	}
}

scene::GameScene::~GameScene()
{
	UnloadTexture(stats_);
	UnloadTexture(button_exit_);
	UnloadTexture(button_end_turn);
	UnloadTexture(button_end_prep);
}

void scene::GameScene::Update()
{
	if (preperation_phase_)
	{
		UpdatePreperationPhase();
	}
	else
	{
		if (player_phase_)
		{
			UpdatePlayerPhase();
		}
		else
		{
			UpdateEnemyPhase();
		}
	}



	// Update window if ones active
	if (window_active_->GetIsActive())
	{
		window_active_->Update();
	}
	// Or Update scene
	else
	{
		SwitchPlayer();

		{
			bool all_enemies_dead = true;
			bool all_enemies_done_with_animation = true;
			for (auto& enemy : enemies_)
			{
				if (!enemy->GetIsAnimationOver())
				{
					all_enemies_done_with_animation = false;
					break;
				}
			}
			for (auto& enemy : enemies_)
			{
				if (enemy->GetIsAlive())
				{
					all_enemies_dead = false;
					break;
				}
			}
			// If all enemies are killed and have played their animation
			if (level_current_ < max_level_ && all_enemies_dead && all_enemies_done_with_animation && round_current_ >= map_->GetLevelHandler()->GetNumberOfRounds() - 1)
			{
				NextLevel();
			}
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			window_active_ = std::make_unique<window::WindowPause>(gamestate_);
		}

		if (IsKeyPressed(KEY_K))
		{
			players_[0]->SetHP(0);
		}


		if (IsKeyPressed(KEY_ENTER))
		{
			if (preperation_phase_)
			{
				preperation_phase_ = false;
				for (auto& player : players_)
				{
					player->SetIsPreparing(!player->GetIsPreparing());
				}
			}
			else
			{
				std::vector<std::pair<int, int>> positions;
				for (auto& player : players_)
				{
					if (player->GetIsAlive())
					{
						positions.push_back(player->GetPosition());
					}
				}

				for (auto& enemy : enemies_)
				{

					// move enemy and damage scarecrow if enemy steps on ritual
					players_[0]->SetHP(players_[0]->GetHP() - enemy->Move(positions));

					// let enemies attack
					for (auto& player : players_)
					{
						if (player->GetIsAlive())
						{
							player->GetDamage(enemy->Attack(player->GetPosition().first, player->GetPosition().second));
						}
					}
				}

				if (round_current_ < map_->GetLevelHandler()->GetNumberOfRounds())
				{
					for (auto& enemy : spawner_->SpawnWave(map_->GetLevelHandler()->GetEnemiesPerRound(), map_))
					{
						enemies_.push_back(enemy);
					}

					round_current_++;
				}

				for (auto& player : players_)
				{
					player->ResetStats();
				}
			}
		}

		std::vector<std::pair<int, std::vector<std::pair<int, int>>>> positions_of_attack;

		// Update entities
		for (auto& player : players_)
		{
			// Enable attacking when not in preperation phase
			if (!preperation_phase_)
			{
				positions_of_attack.push_back(player->Attack());
			}

			player->Update();
		}
		for (auto& enemy : enemies_)
		{
			for (auto& pos : positions_of_attack)
			{
				enemy->GetDamage(pos);
			}

			enemy->Update();
		}
	}

	// Update animation of entities and delete them if dead
	for (auto& player : players_)
	{
		player->UpdateAnimation();
	}
	for (auto& enemy : enemies_)
	{
		enemy->UpdateAnimation();
	}

	if (!players_[0]->GetIsAlive() && players_[0]->GetIsAnimationOver() && !window_active_->GetIsActive() && !game_won_)
	{
		window_active_ = std::make_unique<window::WindowGameOver>(gamestate_);
		game_won_ = true;
	}
}

void scene::GameScene::Draw()
{
	if (level_current_ < max_level_)
	{
		map_->Draw();
	}

	// Draw Entities
	for (auto& enemy : enemies_)
	{
		enemy->Draw();
	}
	for (auto& player : players_)
	{
		player->Draw();
	}

	DrawUI();

	if (window_active_->GetIsActive() || game_won_)
	{
		window_active_->Draw();
	}

	if (window_active_->BausSpecial() == 1)
	{
		std::cout << "yes";
		exit_ = true;
	}
}

int scene::GameScene::ChangeScene() const
{
	// @TODO if scarecrow is dead and escape is pressed
	// if we won the game and escape is pressed (game_won_window will deactivate itself once escape is pressed BUT only after it faded completely balack)
	if ((!window_active_->GetIsActive() && game_won_) || exit_)
	{
		return scene::Scene::MENU_SCENE;
	}

	return 0;
}

void scene::GameScene::NextLevel()
{
	// Fade out
	if (level_current_ < max_level_ - 1 && !fade_out_done)
	{
		window_active_ = std::make_unique<window::WindowBlendOut>(gamestate_);
		fade_out_done = true;
	}
	if ((fade_out_done && !window_active_->GetIsActive()) || level_current_ == max_level_ - 1)
	{
		fade_out_done = false;

		// Update our wheat counter for the skilltree
		gamestate_->SetWheatOverall(static_cast<int>(gamestate_->GetWheatOverall() + map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::WHEAT).size()));
		gamestate_->SetWheatThisRun(static_cast<int>(gamestate_->GetWheatThisRun() + map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::WHEAT).size()));

		level_current_++;
		round_current_ = 0;
		preperation_phase_ = true;

		if (level_current_ < max_level_)
		{
			enemies_.clear();

			for (auto& enemy : spawner_->SpawnWave(map_->GetLevelHandler()->GetEnemiesPerRound(), map_))
			{
				enemies_.push_back(enemy);
			}

			window_active_ = std::make_unique<window::WindowNextLevel>(gamestate_, level_current_);

			map_->ResetMap();

			for (auto& player : players_)
			{
				player->SetIsPreparing(true);
				player->Spawn();
			}
		}
		if (level_current_ == max_level_)
		{
			window_active_ = std::make_unique<window::WindowGameWon>(gamestate_);
			level_current_--;
			game_won_ = true;
		}
	}
}

void scene::GameScene::UpdatePreperationPhase()
{
}

void scene::GameScene::UpdatePlayerPhase()
{
}

void scene::GameScene::UpdateEnemyPhase()
{
}

void scene::GameScene::SwitchPlayer() const
{
	if (!players_[1]->GetIsAlive())
	{
		players_[0]->SetIsActive(true);
	}

	if (IsKeyPressed(KEY_Q) || IsKeyPressed(KEY_E))
	{
		for (auto& player : players_)
		{
			if (players_[1]->GetIsAlive())
			{
				player->SetIsActive(!player->GetIsActive());
			}
		}
	}
}

void scene::GameScene::DrawUI() const
{
	DrawTexture(stats_, 20, 0, WHITE);

	// Draw stats of active player
	for (auto& player : players_)
	{
		if (player->GetIsActive() && (player->GetIsAlive() || player == players_[0]))
		{
			DrawTextEx(gamestate_->GetFont(), TextFormat("%i", player->GetHP()), { 48.0f, 20.0f }, 20, 0, WHITE);
			DrawTextEx(gamestate_->GetFont(), TextFormat("%i", player->GetMovePoints()), { 108.0f, 20.0f }, 20, 0, WHITE);
			DrawTextEx(gamestate_->GetFont(), TextFormat("%i", player->GetActionPoints()), { 164.0f, 20.0f }, 20, 0, WHITE);
		}
	}

	DrawTexture(button_exit_, 560, 15, WHITE);

	if (preperation_phase_)
	{
		DrawTexture(button_end_prep, 340, 15, WHITE);
	}
	else
	{
		DrawTexture(button_end_turn, 422, 15, WHITE);
	}
}
