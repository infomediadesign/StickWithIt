#include "window_pause.h"

window::WindowPause::WindowPause(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_resume.png", 50, 80, true));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_options.png", 50, 130, false));
	buttons_.push_back(std::make_unique<ui::Button>("assets/graphics/ui/button_exit.png", 50, 180, false));
}

window::WindowPause::~WindowPause()
{

}

void window::WindowPause::Update()
{
	if (settings_ != nullptr && settings_->GetIsActive())
	{
		settings_->Update();
	}
	else
	{
		if (IsKeyPressed(KEY_UP) && button_active_ > 0)
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

		if (IsKeyPressed(KEY_ENTER))
		{
			switch (button_active_)
			{
			case 0:
				is_active_ = false;
				break;
			case 1:
				settings_ = std::make_unique<window::WindowSettings>(gamestate_);
				break;
			case 2:
				exit_ = true;
				break;
			}
		}

		if (IsKeyPressed(KEY_ESCAPE))
		{
			is_active_ = false;
		}
	}
}

void window::WindowPause::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_WIDTH, { 0, 0, 0, 180 });

	DrawTexture(exit_button_, game::SCREEN_WIDTH - 60, 20, WHITE);

	if (settings_ != nullptr && settings_->GetIsActive())
	{
		settings_->Draw();
	}
	else
	{
		for (auto& button : buttons_)
		{
			button->Draw();
		}
	}
}

int window::WindowPause::BausSpecial()
{
	if (exit_)
	{
		return 1;
	}

	return 0;
}
