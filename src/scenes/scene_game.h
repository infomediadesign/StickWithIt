#pragma once

#include "scene.h"
#include "../actors/spawner.h"

namespace scene
{
	class GameScene : public Scene
	{
	public:

		GameScene(std::shared_ptr<gs::GameState>& gamestate);
		~GameScene();

		void Update() override;
		void Draw() override;

		int ChangeScene() const override;

	private:

		void NextLevel();
		void UpdatePreperationPhase();
		void UpdatePlayerPhase();
		void UpdateEnemyPhase();

		void SwitchPlayer() const;
		void DrawUI() const;

		Texture2D stats_			= LoadTexture("assets/graphics/ui/stats.png");
		Texture2D button_exit_		= LoadTexture("assets/graphics/ui/button_escape_2.png");
		Texture2D button_end_turn	= LoadTexture("assets/graphics/ui/button_end_turn.png");
		Texture2D button_end_prep	= LoadTexture("assets/graphics/ui/button_end_prep.png");

		const int max_level_		= 4;

		int level_current_			= 0;
		int round_current_			= 0;

		// Condition to play next level but only after all enemies have played their animation
		bool fade_out_done			= false;
		bool exit_					= false;

		// Condition to get "game won" window and return back to menu
		bool game_won_				= false;
		bool preperation_phase_		= true;
		bool player_phase_			= true;

		// Contains and draws all level + manages it
		std::shared_ptr<level::Map> map_ = std::make_shared<level::Map>(level_current_);

		// Can spawn any entity we want
		std::unique_ptr<actor::Spawner> spawner_ = std::make_unique<actor::Spawner>(gamestate_);

		// Contains all players
		std::vector<std::shared_ptr<actor::Player>> players_ {};
		// Contains all enemies
		std::vector<std::shared_ptr<actor::Enemy>> enemies_{};
	};
}