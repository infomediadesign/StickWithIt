#include "tilesetter.h"

game::core::Tilesetter::Tilesetter() {
	
	//add tilesets here
	tilesetSource.insert(std::pair<std::string, std::shared_ptr<Image>>("wheat", std::make_shared<Image>(LoadImage("assets/graphics/tilesets/tileset1.png"))));

	//Crop Image to tiles, give IDs, convert to Texture2Ds and add to map 
	int ID = 0;
	for (int y = 0; y < 7; y++) // 7 = tilesetwidth
	{
		for (int x = 0; x < 10; x++) // 10 = tilesetheight
		{
			tiles.insert(std::pair<int, std::shared_ptr<Texture2D>>(ID, 
				std::make_shared<Texture2D>(LoadTextureFromImage(ImageFromImage(*tilesetSource.find("wheat")->second, { float(x) * 32, float(y) * 32, 32, 32})))));
			ID++;
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
			//draw tilemap of level(level) here
			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					DrawTexture(*tiles.find(levels.find("level1")->second[positionInTilemap])->second, x * 32 - 16, y * 32 - 14, WHITE);
					positionInTilemap++;
				}
			}
			break;
		}
		case 2:
		{
			//draw tilemap of level(level) here
			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					DrawTexture(*tiles.find(levels.find("level2")->second[positionInTilemap])->second, x * 32 - 16, y * 32 - 14, WHITE);
					positionInTilemap++;
				}
			}
			break;
		}
	}
}

void game::core::Tilesetter::exchangeTile(Texture2D tile, Vector2 position) {

}
