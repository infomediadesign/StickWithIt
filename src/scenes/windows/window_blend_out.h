#pragma once

#include "window.h"

namespace window
{
	class WindowBlendOut : public Window
	{
	public:

		WindowBlendOut(std::shared_ptr<gs::GameState>& gamestate);
		~WindowBlendOut();

		void Update() override;
		void Draw() const override;
		int BausSpecial() override;

	private:

		Color color_ = { 0, 0, 0, 0 };
	};
}