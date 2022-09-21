#pragma once

#include "window.h"

#include <iostream>
#include <vector>

#include "window_settings.h"
#include "../button.h"

namespace window
{
	class WindowPause : public Window
	{
	public:

		WindowPause(std::shared_ptr<gs::GameState>& gamestate);
		~WindowPause();

		void Update() override;
		void Draw() const override;

		int BausSpecial() override;

	private:
		
		// Windows
		std::unique_ptr<WindowSettings> settings_ = nullptr;

		// Vector for all buttons
		std::vector<std::unique_ptr<ui::Button>> buttons_;
		int button_active_ = 0;

		bool exit_ = false;
	};
}