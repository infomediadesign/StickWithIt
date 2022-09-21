#include "window_next_level.h"

window::WindowNextLevel::WindowNextLevel(std::shared_ptr<gs::GameState>& gamestate, const int& current_level)
	:
	Window(gamestate),
	current_level_(current_level)
{
}

window::WindowNextLevel::~WindowNextLevel()
{
}

void window::WindowNextLevel::Update()
{
	if (color_background_.a > speed_ && color_font_.a > speed_)
	{
		if (frames_ > pause_)
		{
			color_background_.a -= speed_;
			color_font_.a -= speed_;
		}

		frames_++;
	}
	else
	{
		is_active_ = false;
	}
}

void window::WindowNextLevel::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, color_background_);
	DrawTextEx(gamestate_->GetFont(), TextFormat("Level %i", current_level_ + 1) , {250.0f, 120.0f}, 50, 0, color_font_);
	DrawTextEx(gamestate_->GetFont(), "-- Preperation Phase --" , {210.0f, 180.0f}, 20, 0, color_font_);
}
