#include "scene_menu.h"

scene::MenuScene::MenuScene(std::shared_ptr<gs::GameState>& gamestate)
	: Scene(gamestate)
{
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_start.png", 50, 50, true));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_skilltree.png", 50, 100, false));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_options.png", 50, 150, false));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_credits.png", 50, 200, false));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_exit.png", 50, 250, false));
}

scene::MenuScene::~MenuScene()
{
}

void scene::MenuScene::Update()
{
	// Update a window if there is one AND it's active
	if (window_active_ != nullptr && window_active_->GetIsActive())
	{
		window_active_->Update();
	}
	else
	{
		// Handle input of scene
		if (IsKeyPressed(KEY_ENTER))
		{
			// Open different windows depenant of active button
			switch (button_active_)
			{
			case START:
				window_active_ = std::make_unique<window::WindowBlendOut>(gamestate_);
				launching_into_game_ = true;
				break;
			case SKILLTREE:
				window_active_ = std::make_unique<window::WindowSkilltree>(gamestate_);
				break;
			case OPTIONS:
				window_active_ = std::make_unique<window::WindowSettings>(gamestate_);
				break;
			case CREDITS:
				window_active_ = std::make_unique<window::WindowCredits>(gamestate_);
				break;
			}
		}
		else if (IsKeyPressed(KEY_UP) && button_active_ > 0)
		{
			buttons_[button_active_]->SetIsActive(false);
			button_active_--;
			buttons_[button_active_]->SetIsActive(true);
		}
		else if (IsKeyPressed(KEY_DOWN) && button_active_ < buttons_.size() - 1)
		{
			buttons_[button_active_]->SetIsActive(false);
			button_active_++;
			buttons_[button_active_]->SetIsActive(true);
		}
	}
}

void scene::MenuScene::Draw()
{
	DrawTexture(texture_background_, 0, 0, WHITE);

	// Update a window if there is one AND it's active and we dont launch into game
	if (window_active_ != nullptr && window_active_->GetIsActive() && !launching_into_game_)
	{
		window_active_->Draw();
	}
	// Or draw the standart menu UI
	else
	{
		for (auto& button : buttons_)
		{
			button->Draw();
		}

		if (launching_into_game_)
		{
			window_active_->Draw();
		}
	}
}

int scene::MenuScene::ChangeScene() const
{
	if (launching_into_game_ && !window_active_->GetIsActive())
	{
		return GAME_SCENE;
	}
	if (IsKeyPressed(KEY_ENTER) && button_active_ == EXIT)
	{
		return EXIT_GAME;
	}

	return NULL;
}
