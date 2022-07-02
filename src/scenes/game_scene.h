#pragma once

#include "scene.h"

//handlers

#include "../handlers/level_drawer.h"

namespace scenes
{

	class GameScene : public Scene
	{

	public:

		GameScene();

		~GameScene() override;

		virtual void Update() override;

		virtual void Draw() override;

		virtual int changeScene() override;

	private:

		int level = 1;

		std::unique_ptr<handlers::LevelDrawer> levelDrawer = std::make_unique<handlers::LevelDrawer>();

		//Ein set, das s�mtliche Positionen vonn allen kollidierbaren Tiles(und Spielern) enth�lt
		//std::set<Vector2> colidablePositions;
	};
}