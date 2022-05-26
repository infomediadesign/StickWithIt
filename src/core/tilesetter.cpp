#include "tilesetter.h"


game::core::Tilesetter::Tilesetter() {
	
	//build levels here
	levels.insert(std::pair<std::string, std::vector<int>>("level1", {
		41, 42, 41, 42, 41, 44, 46, 43, 44, 41, 41, 41, 41, 41, 41, 41, 44, 41, 42, 46, 43,
			41, 45, 43, 42, 44, 44, 42, 43, 42, 43, 43, 45, 41, 42, 43, 43, 42, 43, 43, 44, 43,
			42, 43, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 42, 46, 43,
			43, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 44, 43,
			43, 41, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 43, 43, 
			41, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 46, 43,
			45, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 45, 43,
			41, 42, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 42, 43, 43,
			41, 44, 43, 41, 42, 43, 42, 46, 42, 41, 42, 45, 42, 43, 41, 44, 43, 41, 42, 43, 43,
			41, 42, 43, 51, 52, 53, 42, 43, 43, 44, 41, 42, 46, 44, 46, 43, 43, 45, 42, 43, 43,
			44, 46, 42, 61, 62, 63, 43, 41, 44, 41, 44, 43, 41, 42, 41, 42, 43, 41, 42, 43, 43,
			41, 44, 43, 41, 42, 43, 42, 46, 42, 41, 42, 45, 42, 43, 41, 44, 43, 41, 42, 43, 43,
			41, 44, 43, 41, 42, 43, 42, 46, 42, 41, 42, 45, 42, 43, 41, 44, 43, 41, 42, 43, 43
		}));

	levels.insert(std::pair<std::string, std::vector<int>>("level2", {
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,20,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,20,		1,4,3,2,1,		2,5,6,2,1,1,

		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,20,1,4,		1,4,3,2,1,		2,5,6,17,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,

		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,20,		2,5,6,2,1,1
		}));

	//load tilesets here
	tileset = std::make_unique<Texture>(LoadTexture("assets/graphics/tilesets/tileset1.png"));

	//evaluate all the rectangles the tileset will be cropped into and give them ids
	int id = 1;
	for (int y = 0; y < tileset_height; y++)
	{
		for (int x = 0; x < tileset_width; x++)
		{
			tiles.insert(std::pair<int, Rectangle>(id, { float(x * 32), float(y * 32), 32.0, 32.0 }));
			id++;
		}
	}

	//for (int i = 0; i < tileset_width * tileset_height; i++)
	//{
	//	ids.push_back({ tiles.find(i)->second.x, tiles.find(i)->second.y});
	//}
}

void game::core::Tilesetter::drawTilemap(int level) {
	int xPlacedTile = 0;

	switch (level)
	{
		case 1:
		{
			//draw tilemap of level 1 here
			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					DrawTextureRec(*tileset, tiles.find(levels.find("level1")->second[xPlacedTile])->second, {float(x) * 32 - 16, float(y) * 32 - 14}, WHITE);
					xPlacedTile++;
				}
			}
			break;
		}
		case 2:
		{
			//draw tilemap of level 2 here
			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					DrawTextureRec(*tileset, tiles.find(levels.find("level2")->second[xPlacedTile])->second, { float(x) * 32 - 16, float(y) * 32 - 14 }, WHITE);
					xPlacedTile++;
				}
			}
			break;
		}
	}
}

//to be implemented after prototype phase //TODO
//if Rectangle(x, y) == Playerposition.x +? && Playerposition.y, 
//dann schau welche Zahl sich an der Position befindet und wechsel Tile, sofern Weizen zu kaputtes Feld tile
void game::core::Tilesetter::exchangeTile(Vector2 playerPosition) {
	if (true)
	{
		//find id of the tile the players staying on and compare if its a wheat tile
		
	}
}
