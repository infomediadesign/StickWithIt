#include "window_settings.h"

window::WindowSettings::WindowSettings(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowSettings::~WindowSettings()
{
	UnloadTexture(texture_options_);
}

void window::WindowSettings::Update()
{
	if (IsKeyPressed(KEY_M))
	{
		gamestate_->SetMusicPause(!gamestate_->GetMusicPause());
	}

	if (IsKeyPressed(KEY_F))
	{
		ToggleFullscreen();
	}

	if (IsKeyPressed(KEY_ESCAPE))
	{
		is_active_ = false;
	}
}

void window::WindowSettings::Draw() const
{
	DrawTexture(exit_button_, game::SCREEN_WIDTH - 60, 20, WHITE);
	DrawTexture(texture_options_, 180, 40, WHITE);
}
