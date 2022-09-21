#include "button.h"

ui::Button::Button(const char* texture_path, int x, int y, bool is_active)
	: 
	texture_(LoadTexture(texture_path)),
	x_(x),
	y_(y),
	is_active_(is_active)
{
}

ui::Button::~Button()
{
	UnloadTexture(texture_);
}

void ui::Button::Draw() const
{
	if (is_active_)
	{
		DrawTexture(texture_, x_, y_, WHITE);
	}
	else
	{
		DrawTexture(texture_, x_, y_, DARKGRAY);
	}
}

bool ui::Button::GetIsActive() const
{
	return is_active_;
}

void ui::Button::SetIsActive(bool status)
{
	is_active_ = status;
}
