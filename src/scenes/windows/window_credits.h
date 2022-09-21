#pragma once

#include "window.h"

namespace window
{
	class WindowCredits : public Window
	{
	public:

		WindowCredits(std::shared_ptr<gs::GameState>& gamestate);
		~WindowCredits();

		void Update() override;
		void Draw() const override;

	private:


	};
}