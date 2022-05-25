#pragma once

#include <raylib.h>
#include <vector>

#include <iostream>
#include <map>
#include <memory>
#include "actor.h"

namespace game::core {
	class Tilesetter {
	public:
		Tilesetter();

		//draws tilemap of specific level
		void drawTilemap(int level);

		//exchanges tile on specific coordinate
		void exchangeTile(Texture2D tileID, Vector2 position);

	private:
		//the tileset
		std::unique_ptr<Texture> tileset;

		//vector out of Rectangles that contain the tiles positions on the tileset
		std::vector<Rectangle> tiles;

		//map out of levels
		//every level contains a vector of integers (that triggers dependant tile to be drawn)
		std::map<std::string, std::vector<int>> levels;

		
		const int amountOfTilesX = 21;
		const int amountOfTilesY = 13;
	};
}
