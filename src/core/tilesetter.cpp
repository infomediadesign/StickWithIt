#include "tilesetter.h"

game::core::Tilesetter::Tilesetter() {
	
	//add tilesets here
	tilesetSource.insert(std::pair<std::string, std::shared_ptr<Texture2D>>("wheat", std::make_shared<Texture2D>(LoadTexture("assets/graphics/tilesets/tileset1.png"))));

	//evualuate the position of all tiles the tileset has
	for (int y = 0; y < 7; y++) // 7 = tileset_width
	{
		for (int x = 0; x < 10; x++) // 10 = tileset_height
		{
			tiles.push_back({ float(x * 32), float(y * 32), 32.0, 32.0 });
		}
	}

	//build levels here
	levels.insert(std::pair<std::string, std::vector<int>>("level1", {
		1,3,2,1,5,		2,5,2,1,4,		1,52,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,20,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,

		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1,
		2,1,5,2,10,		2,4,4,1,2,		5,2,1,9,8,		2,5,6,4,2,1,
		1,3,2,1,5,		2,5,2,1,4,		1,4,3,2,1,		2,5,6,2,1,1
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
}

void game::core::Tilesetter::drawTilemap(int level) {
	int positionInTilemap = 0;

	switch (level)
	{
		case 1:
		{
			//draw tilemap of level 1 here
			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					DrawTextureRec(*tilesetSource.find("wheat")->second, tiles[levels.find("level1")->second[positionInTilemap]], {float(x) * 32 - 16, float(y) * 32 - 14}, WHITE);
					positionInTilemap++;
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
					DrawTextureRec(*tilesetSource.find("wheat")->second, tiles[levels.find("level2")->second[positionInTilemap]], { float(x) * 32 - 16, float(y) * 32 - 14 }, WHITE);
					positionInTilemap++;
				}
			}
			break;
		}
	}
}

void game::core::Tilesetter::exchangeTile(Texture2D tile, Vector2 position) {

}
