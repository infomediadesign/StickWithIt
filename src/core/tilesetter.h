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
		std::map<std::string, std::shared_ptr<Image>> tilesetSource;

		//map with tiles(converted to Texture2D) described by IDs
		std::map<int, std::shared_ptr<Texture2D>> tiles;

		//map out of levels
		//every level contains a vector of integers (ids, that triggers dependant tiles to be drawn)
		std::map<std::string, std::vector<int>> levels;
		
		const int amountOfTilesX = 21;
		const int amountOfTilesY = 13;

		//TODO const int playerwidth + height
	};
}
