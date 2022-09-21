#include "window.h"

window::Window::Window(std::shared_ptr<gs::GameState>& gamestate)
	:
	gamestate_(gamestate)
{
}

window::Window::~Window()
{
	UnloadTexture(exit_button_);
}

bool window::Window::GetIsActive() const
{
	return is_active_;
}

void window::Window::SetIsActive(bool status)
{
	is_active_ = status;
}
