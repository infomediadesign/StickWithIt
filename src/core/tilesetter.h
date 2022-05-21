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
		std::map<std::string, std::shared_ptr<Image>> tilesets;

		//map with tiles(converted to Texture2D) described by IDs
		//std::map<int, std::shared_ptr<Texture2D>> tiles;
		std::map<int, Texture2D> tiles;

		//map with vector out of tilemaps
		std::map<std::string, std::vector<Texture2D>> tilemaps;
	};
}
