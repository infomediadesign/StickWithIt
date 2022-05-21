#include "tilesetter.h"

game::core::Tilesetter::Tilesetter() {
	
	//add tilesets here
	tilesetSource.insert(std::pair<std::string, std::shared_ptr<Image>>("wheat", std::make_shared<Image>(LoadImage("assets/graphics/tilesets/tileset1.png"))));

	//Crop Image to tiles, give IDs, convert to Texture2Ds and add to map 
	int ID = 0;
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			ID++;
			tiles.insert(std::pair<int, Texture2D>(ID, 
				LoadTextureFromImage(ImageFromImage(*tilesetSource.find("wheat")->second, { float(x) * 32, float(y) * 32, 32, 32}))));
		}
	}

	//build tilemap for level1
	tilemaps.insert(std::pair<std::string, std::vector<int>>("level1", {1, 3, 1, 1, 1}));
}

void game::core::Tilesetter::drawTilemap(int level) {
	int amountOfTilesX = 20;
	int amountOfTilesY = 13;
	int idOfTile = 0;

	switch (level)
	{
		case 1:
		{
			//draw tilemap of level 1 here
			for (int i = 0; i < tiles.size(); i++)
			{
				DrawTexture(tiles.find(i)->second, i * 32, 0, WHITE);
			}

			for (int y = 0; y < amountOfTilesY; y++)
			{
				for (int x = 0; x < amountOfTilesX; x++)
				{
					
					DrawTexture(tiles.find(tilemaps.find("level1")->second[idOfTile])->second, x * 32, y * 32, WHITE);
					idOfTile++;
				}
			}

			break;
		}
		case 2:
		{
			//build tilemap of level 1 here
			for (int i = 0; i < tiles.size(); i++)
			{
				DrawTexture(tiles.find(i)->second, i * 32, 0, WHITE);
			}
			break;
		}
	}
}

void game::core::Tilesetter::exchangeTile(Texture2D tile, Vector2 position) {

}