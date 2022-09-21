#pragma once

#include <raylib.h>
#include <iostream>

#include "config.h"
#include "../../gamestate.h"

namespace window
{
	class Window
	{
	public:

		Window(std::shared_ptr<gs::GameState>& gamestate);
		virtual ~Window();

		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual int BausSpecial() { return 0; };

		enum
		{
			ACTIVE,
			INACTIVE,
		};

		bool GetIsActive() const; void SetIsActive(bool status);

	protected:

		Texture2D exit_button_ = LoadTexture("assets/graphics/ui/button_escape.png");

		bool is_active_ = true;

		std::shared_ptr<gs::GameState> gamestate_;
	};
}