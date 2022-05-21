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
		void exchangeTile(Texture2D tile, Vector2 position);

	private:
		//vector with tilesets (Texture2Ds)
		std::map<std::string, std::shared_ptr<Texture2D>> tilesets;

		//vector with vectors with tiles
		std::vector<std::vector<Texture2D>> tilemaps;
	};
}
