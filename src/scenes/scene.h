#pragma once

#include <iostream>

#include "../gamestate.h"
#include "windows/windows.h"

namespace scene
{
	class Scene
	{
	public:

		Scene(std::shared_ptr<gs::GameState>& gamestate);
		virtual ~Scene() {}

		virtual void Update() = 0;
		virtual void Draw() = 0;

		virtual int ChangeScene() const = 0;

		// Enum for all possible scenes (+ exit game)
		enum
		{
			EXIT_GAME = 1,
			MENU_SCENE,
			GAME_SCENE
		};

	protected:

		// To show specific window
		std::unique_ptr<window::Window> window_active_;

		// To update settings etc.
		std::shared_ptr<gs::GameState> gamestate_;
	};
}