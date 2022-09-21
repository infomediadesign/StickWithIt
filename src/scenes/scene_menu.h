#pragma once

#include "scene.h"

#include <raylib.h>
#include <vector>

#include "button.h"

namespace scene
{
	class MenuScene : public Scene
	{
	public:

		MenuScene(std::shared_ptr<gs::GameState>& gamestate);
		~MenuScene();

		void Update() override;
		void Draw() override;

		int ChangeScene() const override;

	private:

		enum
		{
			START,
			SKILLTREE,
			OPTIONS,
			CREDITS,
			EXIT
		};

		// Background
		const Texture2D texture_background_	= LoadTexture("assets/graphics/backgrounds/menu_background.png");

		// Vector for all buttons
		std::vector<std::unique_ptr<ui::Button>> buttons_;

		int button_active_ = 0;

		bool launching_into_game_ = false;
	};
}