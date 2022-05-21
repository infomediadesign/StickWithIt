#include "tilesetter.h"

game::core::Tilesetter::Tilesetter() {
	
	//add tilesets here
	tilesets.insert(std::pair<std::string, std::shared_ptr<Image>>("wheat", std::make_shared<Image>(LoadImage("assets/graphics/tilesets/tileset1.png"))));

	//Crop Image to tile, give ID, convert to Texture2D and add to map 
	int ID = 0;
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			tiles.insert(std::pair<int, Texture2D>(ID, LoadTextureFromImage(ImageFromImage(*tilesets.find("wheat")->second, { float(x) * 32, float(y) * 32, 32, 32}))));
		}
	}
}

void game::core::Tilesetter::drawTilemap(int level) {
	switch (level)
	{
		case 1:
		{
			//build tilemap of level 1 here
			for (int i = 0; i < tiles.size(); i++)
			{
				DrawTexture(tiles.find(i)->second, i * 32, 0, WHITE);
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