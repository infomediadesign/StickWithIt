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
		//if Rectangle(x, y) == Playerposition.x +? && Playerposition.y, 
		//dann schau welche Zahl sich an der Position befindet und wechsel Tile, sofern Weizen zu kaputtes Feld tile
		void exchangeTile();

	private:
		//the tileset
		std::unique_ptr<Texture> tileset;

		//vector out of Rectangles that contain the tiles positions on the tileset
		std::map<int, Rectangle> tiles;

		//map out of levels
		//every level contains a vector of integers (that triggers dependant tile to be drawn)
		std::map<std::string, std::vector<int>> levels;

		
		const int amountOfTilesX = 21;
		const int amountOfTilesY = 13;
	};
}
