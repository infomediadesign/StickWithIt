#pragma once

#include <raylib.h>
#include <vector>
#include <iostream>
#include <map>
#include <memory>

#include "actor.h"
#include "level.h"

namespace game::core {
	class Tilesetter {
	public:
		Tilesetter();

		//draws tilemap of specific level
		void drawTilemap(int specificLevel);

		//if the tile the player stands on is a wheat-tile, it gets exchanged to a destroyed-wheat-tile
		void exchangeTile(Vector2 playerPosition, int specificLevel);

		//get number of wheat tiles
		int getNumberOfWheat(int level);

	private:
		//the tileset
		std::unique_ptr<Texture> tileset;

		//vector out of Rectangles that contain the tiles positions on the tileset
		std::map<int, Rectangle> tiles;

		//give every tile a number dependant on place
		std::map<std::vector<float>, int> tileLocation;

		//level object that stores the tilemap of all levels
		Level tilemaps;
	};
}
