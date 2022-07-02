// Description: draws levels and exchanges tiles

#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>

namespace handlers {
	class LevelDrawer {
	public:

		LevelDrawer();

		~LevelDrawer();

		void drawLevel(int level);

		void exchangeTile(Vector2 position);

		//@TODO
		//std::set<Vector2> returnCollisionLayer(int level);

		//Vector2 returnStartingPointsEnemy(int level);

		//Vector2 returnStartingPointPlayer(int level);

	private:

		void returnTexture(int level);

		void returnLevelData(int level);

		void returnGridByID();

		int compareLevel = 0;

		Texture2D levelTexture;

		std::vector<int> levelData;

		std::map<int, Rectangle> gridIDs;
	};
}