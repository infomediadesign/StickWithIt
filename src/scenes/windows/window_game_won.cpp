#include "window_game_won.h"

window::WindowGameWon::WindowGameWon(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowGameWon::~WindowGameWon()
{
}

void window::WindowGameWon::Update()
{
	// Fade black then stay black
	if (color_background_.a < 255 - speed_)
	{
		color_background_.a += speed_;
		color_font_.a += speed_;
	}
	if (color_background_.a > 255 - speed_)
	{
		color_background_.a = 255;
		color_font_.a = 255;
	}

	if (IsKeyPressed(KEY_ESCAPE))
	{
		is_active_ = false;
	}
}

void window::WindowGameWon::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, color_background_);
	DrawTextEx(gamestate_->GetFont(), "Game Won", { 216.0f, 135.0f }, 50, 0, color_font_);
	DrawTexture(exit_button_, game::SCREEN_WIDTH - 60, 20, color_font_);
}
