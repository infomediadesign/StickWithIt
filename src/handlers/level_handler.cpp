#include "level_handler.h"

handlers::LevelHandler::LevelHandler(int* currentLevel) {
	_currentLevel = currentLevel;

	// Give every tile of tilesheet an ID and link it with it's position
	int id = 1;
	for (int y = 0; y < data::cTilesheetTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesheetTilesPerRow; x++)
		{
			// 0 = no tile, 1 = first tile on tileset, start with id 1
			// E.g. second tile on tileset would be: id=2 with position { 64, 0 }
			_positionsWithIDs.insert(std::pair<int, type::Position>(id, { x * data::cTilesize, y * data::cTilesize }));
			id++;
		}
	}
}

handlers::LevelHandler::~LevelHandler() {
	UnloadTexture(*_texture);
}

type::VectorPositions handlers::LevelHandler::GetCollisionPositions()
{
	type::VectorPositions collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			if (_vecLevelData[*_currentLevel][eCollisionLayer][iterator] == eCollisionTiles
				|| _vecLevelData[*_currentLevel][eCollisionLayer][iterator] == eCollisionOnlyGroundTile)
				collisionPositions.push_back({ x, y });

			iterator++;
		}
	}
	return collisionPositions;
}

type::VectorPositions handlers::LevelHandler::GetCollisionPositionsSkyObjectsOnly()
{
	type::VectorPositions collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			if (_vecLevelData[*_currentLevel][eCollisionLayer][iterator] == eCollisionTiles)
				collisionPositions.push_back({ x, y });

			iterator++;
		}
	}
	return collisionPositions;
}

type::VectorPositions handlers::LevelHandler::GetSpawnsGround()
{
	type::VectorPositions spawnGroundPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			if (_vecLevelData[*_currentLevel][eSpawnLayer][iterator] == eSpawnGroundTile)
				spawnGroundPositions.push_back({ x, y });

			iterator++;
		}
	}
	return spawnGroundPositions;
}

type::VectorPositions handlers::LevelHandler::GetSpawnsSky()
{
	type::VectorPositions spawnSkyPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			if (_vecLevelData[*_currentLevel][eSpawnLayer][iterator] == eSpawnSkyTile)
				spawnSkyPositions.push_back({ x, y });

			iterator++;
		}
	}
	return spawnSkyPositions;
}

type::VectorPositions handlers::LevelHandler::GetRitualPositions()
{
	type::VectorPositions ritualPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			if (_vecLevelData[*_currentLevel][eGroundLayer][iterator] == eRitualTile)
				ritualPositions.push_back({ x, y });

			iterator++;
		}
	}
	return ritualPositions;
}

void handlers::LevelHandler::DrawAnyLayer(int layer)
{
	int iterator = 0;
	for (int y = 0; y < data::cTilesPerColumn; y++) {
		for (int x = 0; x < data::cTilesPerRow; x++)
		{
			// If tile is not 0: draw it
			if (_vecLevelData[*_currentLevel][layer][iterator] != 0)
			{
				DrawTextureRec(*_texture,
					{ static_cast<float>(_positionsWithIDs.at(_vecLevelData[*_currentLevel][layer][iterator]).first),
					static_cast<float>(_positionsWithIDs.at(_vecLevelData[*_currentLevel][layer][iterator]).second),
					static_cast<float>(data::cTilesize),
					static_cast<float>(data::cTilesize) },
					{ static_cast<float>(x) * data::cTilesize,
					static_cast<float>(y) * data::cTilesize }, WHITE);
			}
			iterator++;
		}
	}
}

int handlers::LevelHandler::GetNumberOfWheat()
{
	int wheatCount = 0;
	for (int tile : _vecLevelData[*_currentLevel][eGroundLayer])
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
	if (position.first > 0 && position.first < data::cTilesPerRow
		&& position.second > 0 && position.second < data::cTilesPerColumn)
	{
		int positionToIndex = position.first + position.second * data::cTilesPerRow;

		if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat1Tile)
			_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eWheat2Tile;

		else if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat2Tile)
			_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eWheat3Tile;

		else if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat3Tile)
			_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eFieldTile;
	}
}

void handlers::LevelHandler::DestroyWheat(type::VectorPositions positions)
{
	for (auto& position : positions)
	{
		if (position.first > 0 && position.first < data::cTilesPerRow
			&& position.second > 0 && position.second < data::cTilesPerColumn)
		{
			int positionToIndex = position.first + position.second * data::cTilesPerRow;

			if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat1Tile)
				_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eWheat2Tile;

			else if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat2Tile)
				_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eWheat3Tile;

			else if (_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] == eWheat3Tile)
				_vecLevelData[*_currentLevel][eGroundLayer][positionToIndex] = eFieldTile;
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