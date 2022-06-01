#pragma once

#include <raylib.h>
#include <vector>

#include <iostream>
#include <map>
#include <memory>
#include "actor.h"
#include "information.h"

namespace game::core {
	class Tilesetter {
	public:
		Tilesetter();

		//draws tilemap of specific level
		void drawTilemap(int specificLevel);

		//if the tile the player stands on is a wheat-tile, it gets exchanged to a destroyed-wheat-tile
		void exchangeTile(Vector2 playerPosition, int specificLevel);

	private:
		//the tileset
		std::unique_ptr<Texture> tileset;

		//vector out of Rectangles that contain the tiles positions on the tileset
		std::map<int, Rectangle> tiles;

		//give every tile a number dependant on place
		std::map<std::vector<float>, int> tileLocation;

		//map out of levels
		//every level contains a vector of integers (that triggers dependant tile to be drawn)
		std::map<std::string, std::vector<int>> levels;
	};
}
