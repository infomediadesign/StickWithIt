#pragma once

#include "window.h"

namespace window
{
	class WindowNextLevel : public Window
	{
	public:

		WindowNextLevel(std::shared_ptr<gs::GameState>& gamestate, const int& current_level);
		~WindowNextLevel();

		void Update() override;
		void Draw() const override;

	private:

		const int& current_level_;

		const int pause_	= 80;

		int frames_			= 0;
		int speed_			= 4;

		Color color_background_ = BLACK;
		Color color_font_ = WHITE;
	};
}