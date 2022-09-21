#include "window_credits.h"

window::WindowCredits::WindowCredits(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowCredits::~WindowCredits()
{
}

void window::WindowCredits::Update()
{
	if (IsKeyPressed(KEY_ESCAPE))
	{
		is_active_ = false;
	}
}

void window::WindowCredits::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, { 0, 0, 0, 220 });

	DrawTexture(exit_button_, game::SCREEN_WIDTH - 60, 20, WHITE);

	DrawTextEx(gamestate_->GetFont(), "Stick With It", { 70.0f, 60.0f }, 30.0f, 0.0f, WHITE);
	DrawTextEx(gamestate_->GetFont(), "Programming:", { 70.0f, 130.0f }, 20.0f, 0, WHITE);		DrawTextEx(gamestate_->GetFont(), "Levin Theil", { 220.0f, 130.0f }, 20.0f, 0.0f, GRAY);
	DrawTextEx(gamestate_->GetFont(), "Design:", { 70.0f, 160.0f }, 20.0f, 0, WHITE);			DrawTextEx(gamestate_->GetFont(), "Moritz Kromer", { 220.0f, 160.0f }, 20.0f, 0.0f, RED);
	DrawTextEx(gamestate_->GetFont(), "Management:", { 70.0f, 190.0f }, 20.0f, 0, WHITE);		DrawTextEx(gamestate_->GetFont(), "Silas Schuerger", { 220.0f, 190.0f }, 20.0f, 0.0f, GOLD);
	DrawTextEx(gamestate_->GetFont(), "Art:", { 70.0f, 220.0f }, 20.0f, 0, WHITE);				DrawTextEx(gamestate_->GetFont(), "Tina Kroschel", { 220.0f, 220.0f }, 20.0f, 0.0f, PINK);
	DrawTextEx(gamestate_->GetFont(), "Production:", { 70.0f, 250.0f }, 20.0f, 0, WHITE);		DrawTextEx(gamestate_->GetFont(), "Sarah Scharf", { 220.0f, 250.0f }, 20.0f, 0.0f, DARKGREEN);
}
