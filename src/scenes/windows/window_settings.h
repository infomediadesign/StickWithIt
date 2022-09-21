#pragma once

#include "window.h"

namespace window
{
	class WindowSettings : public Window
	{
	public:

		WindowSettings(std::shared_ptr<gs::GameState>& gamestate);
		~WindowSettings();

		void Update() override;
		void Draw() const override;

	private:

		const Texture2D texture_options_ = LoadTexture("assets/graphics/ui/options.png");
	};
}