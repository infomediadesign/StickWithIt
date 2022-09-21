#pragma once

#include "window.h"

namespace window
{
	class WindowGameWon : public Window
	{
	public:

		WindowGameWon(std::shared_ptr<gs::GameState>& gamestate);
		~WindowGameWon();

		void Update() override;
		void Draw() const override;

	private:

		int speed_ = 4;

		Color color_background_ = { 0, 0, 0, 0 };
		Color color_font_ = { 255, 255, 255, 0 };
	};
}