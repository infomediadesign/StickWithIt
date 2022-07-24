#include "level_handler.h"

handlers::LevelHandler::LevelHandler(int* currentLevel) {
	_currentLevel = currentLevel;

	// Give every tile of tilesheet an ID and link it with it's position
	int id = 1;
	for (int y = 0; y < game::TILESHEET_TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILESHEET_TILES_PER_ROW; x++)
		{
			// 0 = no tile, 1 = first tile on tileset, start with id 1
			// E.g. second tile on tileset would be: id=2 with position { 64, 0 }
			_IDWithPosition.insert(std::pair<int, type::Position>(id, { x * game::TILE_SIZE, y * game::TILE_SIZE }));
			id++;
		}
	}
}

handlers::LevelHandler::~LevelHandler() {
	UnloadTexture(_texture);
}

type::Vec_Ptr_Position handlers::LevelHandler::GetCollisionsGround()
{
	type::Vec_Ptr_Position collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][eCollisionLayer][iterator] == eCollisionTiles
				|| _vecDataAllLevel[*_currentLevel][eCollisionLayer][iterator] == eCollisionOnlyGroundTile)
				collisionPositions.push_back({ &x, &y });

			iterator++;
		}
	}
	return collisionPositions;
}

type::Vec_Ptr_Position handlers::LevelHandler::GetCollisionsSky()
{
	type::Vec_Ptr_Position collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_COLUMN; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][eCollisionLayer][iterator] == eCollisionTiles)
				collisionPositions.push_back({ &x, &y });

			iterator++;
		}
	}
	return collisionPositions;
}

type::Vec_Position handlers::LevelHandler::GetSpawnsGround()
{
	type::Vec_Position spawnGroundPositions = {};
	int iterator = 0;

	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_COLUMN; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][eSpawnLayer][iterator] == eSpawnGroundTile)
				spawnGroundPositions.push_back({ x, y });

			iterator++;
		}
	}
	return spawnGroundPositions;
}

type::Vec_Position handlers::LevelHandler::GetSpawnsSky()
{
	type::Vec_Position spawnSkyPositions = {};
	int iterator = 0;

	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_COLUMN; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][eSpawnLayer][iterator] == eSpawnSkyTile)
				spawnSkyPositions.push_back({ x, y });

			iterator++;
		}
	}
	return spawnSkyPositions;
}

type::Vec_Position handlers::LevelHandler::GetSpawnsPC()
{
	type::Vec_Position ritualPositions = {};
	int iterator = 0;

	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_COLUMN; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][eSpawnLayer][iterator] == eRitualTile)
				ritualPositions.push_back({ x, y });

			iterator++;
		}
	}
	return ritualPositions;
}

void handlers::LevelHandler::DrawAnyLayer(int layer)
{
	int iterator = 0;
	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_COLUMN; x++)
		{
			// If tile is not 0: draw it
			if (_vecDataAllLevel[*_currentLevel][layer][iterator] != 0)
			{
				DrawTextureRec(_texture,
					{ static_cast<float>(_IDWithPosition.at(_vecDataAllLevel[*_currentLevel][layer][iterator]).first),
					static_cast<float>(_IDWithPosition.at(_vecDataAllLevel[*_currentLevel][layer][iterator]).second),
					static_cast<float>(game::TILE_SIZE),
					static_cast<float>(game::TILE_SIZE) },
					{ static_cast<float>(x) * game::TILE_SIZE,
					static_cast<float>(y) * game::TILE_SIZE }, WHITE);
			}
			iterator++;
		}
	}
}

int handlers::LevelHandler::GetNumberOfWheat()
{
	int wheatCount = 0;
	for (int tile : _vecDataAllLevel[*_currentLevel][eGroundLayer])
	{
		if (tile == eWheat1Tile
			|| tile == eWheat2Tile
			|| tile == eWheat3Tile)
		{
			wheatCount++;
		}
	}
	return wheatCount;
}

void handlers::LevelHandler::DestroyWheat(type::Position position)
{
	if (position.first > 0 && position.first < game::TILES_PER_ROW
		&& position.second > 0 && position.second < game::TILES_PER_COLUMN)
	{
		int positionToIndex = position.first + position.second * game::TILES_PER_ROW;

		if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat1Tile)
			_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eWheat2Tile;

		else if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat2Tile)
			_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eWheat3Tile;

		else if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat3Tile)
			_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eFieldTile;
	}
}

void handlers::LevelHandler::DestroyWheat(type::Vec_Position positions)
{
	for (auto& position : positions)
	{
		if (position.first > 0 && position.first < game::TILES_PER_ROW
			&& position.second > 0 && position.second < game::TILES_PER_COLUMN)
		{
			int positionToIndex = position.first + position.second * game::TILES_PER_ROW;

			if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat1Tile)
				_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eWheat2Tile;

			else if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat2Tile)
				_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eWheat3Tile;

			else if (_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] == eWheat3Tile)
				_vecDataAllLevel[*_currentLevel][eGroundLayer][positionToIndex] = eFieldTile;
		}
	}
}

void handlers::LevelHandler::DrawGround()
{
	DrawAnyLayer(eGroundLayer);
	DrawAnyLayer(eSpawnLayer);
	DrawAnyLayer(eCollisionLayer);
}

void handlers::LevelHandler::DrawAir()
{
	DrawAnyLayer(eSkyLayer);
}