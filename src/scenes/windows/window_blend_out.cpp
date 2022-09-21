#include "window_blend_out.h"

window::WindowBlendOut::WindowBlendOut(std::shared_ptr<gs::GameState>& gamestate)
	:
	Window(gamestate)
{
}

window::WindowBlendOut::~WindowBlendOut()
{
}

void window::WindowBlendOut::Update()
{
	if (color_.a <= 255 - 3)
	{
		color_.a += 3;
	}
	else
	{
		is_active_ = false;
	}
}

void window::WindowBlendOut::Draw() const
{
	DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, color_);
}

int window::WindowBlendOut::BausSpecial()
{
	if (color_.a == 255 && !is_active_)
	{
		DrawRectangle(0, 0, game::SCREEN_WIDTH, game::SCREEN_HEIGHT, BLACK);
	}

	return 0;
}
