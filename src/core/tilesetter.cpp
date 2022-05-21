#include "tilesetter.h"

game::core::Tilesetter::Tilesetter() {
	
	//add tilesets here
	tilesets.insert(std::pair<std::string, std::shared_ptr<Texture2D>>("tilesetWheat", std::make_shared<Texture2D>(LoadTexture("assets/graphics/tilesets/tileset1.png"))));

	//split tilemap into tiles and give them IDs

}

void game::core::Tilesetter::drawTilemap(int level) {
	switch (level)
	{
		case 1:
		{
			DrawTextureRec(*tilesets.find("tilesetWheat")->second, { 0, 0, 32, 32 }, { 0, 0 }, WHITE);
			DrawText("hello", 0, 0, 12, GREEN);
			break;
		}
		case 2:
		{

			break;
		}
	}
}

void game::core::Tilesetter::exchangeTile(Texture2D tile, Vector2 position) {

}