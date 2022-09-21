#pragma once

#include "window.h"

namespace window
{
	class WindowGameOver : public Window
	{
	public:

		WindowGameOver(std::shared_ptr<gs::GameState>& gamestate);
		~WindowGameOver();

		void Update() override;
		void Draw() const override;

	private:

		Color color_background_ = { 0, 0, 0, 0 };
		Color color_font_ = { 255, 255, 255, 0 };

		int frames_ = 0;
		int speed_ = 2;
	};
}