#include "tilesetter.h"


game::core::Tilesetter::Tilesetter() {
	
	//build levels here
	levels.insert(std::pair<std::string, std::vector<int>>("level1", {
		41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41,
		41, 41, 41, 1, 1, 1, 1, 1, 41, 41, 41, 45, 51, 52, 53, 41, 41, 41, 41, 41, 41,
		41, 41, 1, 1, 1, 1, 1, 1, 1, 41, 41, 46, 61, 62, 63, 45, 41, 1, 1, 41, 41,
		41, 1, 1, 1, 1, 1, 1, 1, 1, 3, 7, 41, 41, 46, 46, 41, 1, 1, 1, 1, 41,
		41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 41,
		41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 41,
		41, 1, 1, 1, 1, 1, 41, 41, 41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 41, 41,
		41, 41, 1, 1, 1, 41, 51, 52, 53, 41, 1, 1, 1, 1, 1, 1, 1, 1, 1, 41, 41,
		41, 41, 41, 41, 41, 45, 61, 62, 63, 45, 1, 1, 1, 1, 1, 1, 1, 1, 41, 41, 41,
		41, 41, 64, 65, 45, 41, 46, 45, 41, 41, 1, 1, 1, 1, 1, 41, 41, 46, 46, 41, 41,
		41, 41, 45, 45, 46, 41, 41, 41, 41, 41, 41, 1, 1, 1, 41, 41, 64, 65, 45, 41, 41,
		41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 45, 41, 41, 41, 41,
	}));

	levels.insert(std::pair<std::string, std::vector<int>>("level2", {
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
	}));

	//load tilesets here
	tileset = std::make_unique<Texture>(LoadTexture("assets/graphics/tilesets/tileset1.png"));

	//evaluate all the rectangles the tileset will be cropped into and give them tilePlace
	int id = 1;
	for (int y = 0; y < tileset_height; y++)
	{
		for (int x = 0; x < tileset_width; x++)
		{
			tiles.insert(std::pair<int, Rectangle>(id, { static_cast<float>(x * 32), static_cast<float>(y * 32), 32.0, 32.0 }));
			id++;
		}
	}

	id = 1;
	for (int y = 0; y < amountOfTilesY; y++)
	{
		for (int x = 0; x < amountOfTilesX; x++)
		{
			tilePlace.insert(std::pair<std::vector<float>, float>({ static_cast<float>(x * 32), static_cast<float>(y * 32) }, id));
			id++;
		}
	}
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


void game::core::Tilesetter::exchangeTile(Vector2 playerPosition, int level) {


	//kontrolliere, ob das Tile an der Spielerposition ein Weizenteil ist, wenn ja, dann ersetze es durch ein kaputtes Weizenteil
	if (level == 1)
	{
		if (levels.at("level1")[tilePlace.find({ playerPosition.x - 18, playerPosition.y + 32 })->second] < 10)
		{
			levels.at("level1")[tilePlace.find({ playerPosition.x - 18, playerPosition.y + 32})->second] = 11;
		}
	}

	if (level == 2)
	{
		if (levels.at("level2")[tilePlace.find({ playerPosition.x - 18, playerPosition.y + 32 })->second] < 10)
		{
			levels.at("level2")[tilePlace.find({ playerPosition.x - 18, playerPosition.y + 32 })->second] = 11;
		}
	}
}
