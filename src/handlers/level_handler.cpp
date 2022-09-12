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

type::Vec_Position handlers::LevelHandler::GetCollisionsGround()
{
	type::Vec_Position collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][collisions][iterator] == collisionGround)
			{
				collisionPositions.push_back({ x, y });
			}

			iterator++;
		}
	}
	return collisionPositions;
}

type::Vec_Position handlers::LevelHandler::GetCollisionsSky()
{
	type::Vec_Position collisionPositions = {};
	int iterator = 0;

	// Return ritual positions of current level
	for (int y = 0; y < game::TILES_PER_COLUMN; y++) {
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][collisions][iterator] == collisionAir)
			{
				collisionPositions.push_back({ x, y });
			}

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
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][spawns][iterator] == spawnGroundNPC)
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
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][spawns][iterator] == spawnAirNPC)
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
		for (int x = 0; x < game::TILES_PER_ROW; x++)
		{
			if (_vecDataAllLevel[*_currentLevel][spawns][iterator] == spawnPC)
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
		for (int x = 0; x < game::TILES_PER_ROW; x++)
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
	for (int tile : _vecDataAllLevel[*_currentLevel][ground])
	{
		if (tile == wheat)
		{
			wheatCount++;
		}
	}
	return wheatCount;
}

int handlers::LevelHandler::GetNumberOfLevels()
{
	return _vecDataAllLevel.size();
}

void handlers::LevelHandler::DestroyWheat(type::Position position)
{
	if (position.first > 0 && position.first < game::TILES_PER_ROW
		&& position.second > 0 && position.second < game::TILES_PER_COLUMN)
	{
		int positionToIndex = position.first + position.second * game::TILES_PER_ROW;

		if (_vecDataAllLevel[*_currentLevel][ground][positionToIndex] == wheat)
			_vecDataAllLevel[*_currentLevel][ground][positionToIndex] = destroyedWheat;
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

			if (_vecDataAllLevel[*_currentLevel][ground][positionToIndex] == wheat)
				_vecDataAllLevel[*_currentLevel][ground][positionToIndex] = destroyedWheat;
		}
	}
}

void handlers::LevelHandler::DrawGround()
{
	DrawAnyLayer(ground);
	DrawAnyLayer(decor_ground);
}

void handlers::LevelHandler::DrawAir()
{
	DrawAnyLayer(decor_air);
}