#include "tilesetter.h"
#include "information.h"



game::core::Tilesetter::Tilesetter() {
	//load tileset here
	tileset = std::make_unique<Texture>(LoadTexture("assets/graphics/tilesets/tileset1.png"));

	//evaluate all the rectangles the tileset will be cropped into and give them ids
	int id = 1;
	for (int y = 0; y < tilesetHeight; y++)
	{
		for (int x = 0; x < tilesetWidth; x++)
		{
			tiles.insert(std::pair<int, Rectangle>(id, { static_cast<float>(x * 32), static_cast<float>(y * 32), 32.0, 32.0 }));
			id++;
		}
	}

	//revert the map so you can get ids by inputting dependant coordinate (eg player position)
	id = 1;
	for (int y = 0; y < amountOfTilesY; y++)
	{
		for (int x = 0; x < amountOfTilesX; x++)
		{
			tileLocation.insert(std::pair<std::vector<float>, float>({ static_cast<float>(x * 32), static_cast<float>(y * 32) }, id));
			id++;
		}
	}
}

void game::core::Tilesetter::drawTilemap(int specificLevel) {

	std::string level;
	int xPlacedTile = 0;

	switch (specificLevel)
	{
		case 1:
		{
			level = "level1";
			break;
		}
		case 2:
		{
			level = "level2";
			break;
		}
	}

	for (int y = 0; y < amountOfTilesY; y++)
	{
		for (int x = 0; x < amountOfTilesX; x++)
		{
			DrawTextureRec(*tileset, tiles.find(tilemaps.getLevelTilemaps().find(level)->second[xPlacedTile])->second, {float(x) * 32 - 16, float(y) * 32 - 14}, WHITE);
			xPlacedTile++;
		}
	}
}


void game::core::Tilesetter::exchangeTile(Vector2 actorPosition, int deviationX, int deviationY, int specificLevel) {

	std::string level;

	switch (specificLevel)
	{
	case 1:
	{
		level = "level1";
		break;
	}
	case 2:
	{
		level = "level2";
		break;
	}
	}

	//if the tile the player stands on is of type wheat (0-9) make it of id 11 (destroyed-wheat-tile)
	if (tilemaps.getLevelTilemaps().at(level)[tileLocation.find({ actorPosition.x - deviationX, actorPosition.y + deviationY})->second] < 10)
	{
		tilemaps.setLevelTilemaps(level, tileLocation, actorPosition.x, actorPosition.y, deviationX, deviationY);
	}
}

int game::core::Tilesetter::getNumberOfWheat(int level) {
	int count = 0;
	std::string levelToString;

	switch (level)
	{
	case 1:
	{
		levelToString = "level1";
		break;
	}
	case 2:
	{
		levelToString = "level2";
		break;
	}
	}

	for (int i = 0; i < tilemaps.getLevelTilemaps().at(levelToString).size(); i++)
	{
		if (tilemaps.getLevelTilemaps().at(levelToString)[i] < 10)
		{
			count++;
		}
	}

	return count;
}