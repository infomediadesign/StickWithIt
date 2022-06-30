#include "levelDrawer.h"

handlers::LevelDrawer::LevelDrawer()
	: levelTexture(LoadTexture("assets/graphics/other/logo.png")) // preload placeholder to be unloaded so tilemap of random level can be loaded safely
{

	std::cout << "LevelDrawer called." << std::endl;
}

handlers::LevelDrawer::~LevelDrawer()
{

	std::cout << "LevelDrawer deleted." << std::endl;
}

void handlers::LevelDrawer::drawLevel(int level) {

	//update tilemap
	if (compareLevel == level - 1) {
		returnTexture(level);
		returnLevelData(level);
		returnGridByID();
		compareLevel++;
	}

	int i = 0;

	//draw tilemap
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			DrawTextureRec(levelTexture, gridIDs.at(levelData.at(i)), { static_cast<float>(x * 32), static_cast<float>(y * 32) }, WHITE);
			i++;
		}
	}
}

void handlers::LevelDrawer::exchangeTile(Vector2 position)
{

	if (levelData[static_cast<int64_t>(position.x / 32 + position.y * 20 / 32)] <= 9)
	{
		levelData[static_cast<int64_t>(position.x / 32 + position.y * 20 / 32)] = 11;
	}
}

bool handlers::LevelDrawer::checkCollision(Vector2 position)
{

	//@TODO
	return false;
}

void handlers::LevelDrawer::returnTexture(int level)
{

	switch (level)
	{
	case 1:
		UnloadTexture(levelTexture);
		levelTexture = LoadTexture("assets/graphics/tilesets/tileset1.png");
		break;
	case 2:
		UnloadTexture(levelTexture);
		levelTexture = LoadTexture("assets/graphics/tilesets/tileset1.png");
		break;
	}
}

void handlers::LevelDrawer::returnLevelData(int level)
{

	switch (level)
	{
	case 1:
		levelData = { 42, 42, 41, 42, 41, 44, 46, 43, 44, 41, 41, 41, 41, 41, 41, 41, 44, 41, 42, 46,
			41, 45, 43, 42, 44, 44, 42, 43, 42, 43, 43, 45, 41, 42, 43, 43, 42, 43, 43, 44,
			42, 43, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 42, 46,
			43, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 44,
			43, 41, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 43,
			41, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 46,
			45, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 45,
			41, 42, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 42, 43,
			41, 44, 43, 41, 42, 43, 42, 46, 42, 41, 42, 45, 42, 43, 41, 44, 43, 41, 42, 43,
			41, 42, 43, 51, 52, 53, 42, 43, 43, 44, 41, 42, 46, 44, 46, 43, 43, 45, 42, 43,
			44, 46, 42, 61, 62, 63, 43, 41, 44, 1, 1, 43, 41, 42, 41, 42, 43, 41, 42, 43,
			44, 46, 42, 61, 62, 63, 43, 41, 44, 1, 1, 43, 41, 42, 41, 42, 43, 41, 42, 43 };
		break;
	case 2:
		levelData = { 41, 42, 41, 1, 1, 44, 46, 43, 44, 41, 41, 41, 41, 41, 41, 41, 44, 41, 42, 46,
			41, 45, 43, 42, 44, 44, 42, 43, 42, 43, 43, 45, 41, 42, 43, 43, 42, 43, 43, 44,
			42, 43, 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 42, 46,
			43, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 44,
			43, 41, 5, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 4, 42, 43,
			41, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 46,
			45, 42, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 42, 45,
			41, 42, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 42, 43,
			41, 44, 43, 41, 42, 43, 42, 46, 42, 41, 42, 45, 42, 43, 41, 44, 43, 41, 42, 43,
			41, 42, 43, 51, 52, 53, 42, 43, 43, 44, 41, 42, 46, 44, 46, 43, 43, 45, 42, 43,
			44, 46, 42, 61, 62, 63, 43, 41, 44, 41, 44, 43, 41, 42, 41, 42, 43, 41, 42, 43,
			44, 46, 42, 61, 62, 63, 43, 41, 44, 1, 1, 43, 41, 42, 41, 42, 43, 41, 42, 43 };
		break;
	}
}

void handlers::LevelDrawer::returnGridByID()
{

	int id = 1;

	// change x and y depending on tilesheet size
	for (int y = 0; y < 7; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			gridIDs.insert(std::pair<int, Rectangle>(id, { static_cast<float>(x * 32), static_cast<float>(y * 32), static_cast<float>(32), static_cast<float>(32) }));
			id++;
		}
	}
}