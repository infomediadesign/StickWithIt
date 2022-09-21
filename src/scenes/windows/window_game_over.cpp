#include "window_game_over.h"

window::WindowGameOver::WindowGameOver(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowGameOver::~WindowGameOver()
{
}

void window::WindowGameOver::Update()
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

void window::WindowGameOver::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, color_background_);

	DrawTexture(exit_button_, game::SCREEN_WIDTH - 60, 20, color_font_);

	DrawTextEx(gamestate_->GetFont(), "GAME OVER", { 204.0f, 125.0f }, 50, 0, color_font_);

	DrawTextEx(gamestate_->GetFont(), TextFormat("Wheat collected: %i", gamestate_->GetWheatThisRun()), {246.0f, 190.0f}, 20, 0, color_font_);
}
