#pragma once

#include <raylib.h>
#include <vector>

#include <iostream>
#include <map>
#include <memory>

namespace game::core {
	class Tilesetter {
	public:
		Tilesetter();

		//draws tilemap of specific level
		void drawTilemap(int level);

		//exchanges tile on specific coordinate
		void exchangeTile(Texture2D tileID, Vector2 position);

	private:
		//vector out of tilesets (Images)
		std::map<std::string, std::shared_ptr<Texture2D>> tilesetSource;

		//vector out of vectors that contain x and y data of texture to crop into tile
		std::vector<Rectangle> tiles;

		//map out of levels
		//every level contains a vector of integers (that triggers dependant tile to be drawn)
		std::map<std::string, std::vector<int>> levels;
		
		const int amountOfTilesX = 21;
		const int amountOfTilesY = 13;

		//TODO const int playerwidth + height
	};
}
