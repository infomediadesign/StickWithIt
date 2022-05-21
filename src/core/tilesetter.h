#pragma once

#include <raylib.h>
#include <vector>

#include <iostream>
#include <map>

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
		//std::map<int, std::shared_ptr<Texture2D>> tiles;
		std::map<int, Texture2D> tiles;

		//Vector with ID's -> here the tilemap gets manually built
		//for example "level1", {13, 31, 12, 35, 31}
		//For the length of map every ID(tile) gets drawn to correct position
		std::map<std::string, std::vector<int>> tilemaps;
	};
}
