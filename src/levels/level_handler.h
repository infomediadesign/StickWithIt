#pragma once

#include <iostream>

#include "levels.h"

namespace level
{
	class LevelHandler
	{
	public:
		
		LevelHandler(const int& current_level);
		~LevelHandler();

		void DrawLevel() const;

		enum TileTypes
		{
			WHEAT,
			SPAWN_PLAYER,
			SPAWN_ENEMY_GROUND,
			SPAWN_ENEMY_AIR,
			COLLISION,
			RITUAL_MID
		};

		const std::vector<std::pair<int, int>>& PositionsOfTiletype(TileTypes tile_type) const;

		const int GetNumberOfRounds() const;
		const int GetEnemiesPerRound() const;

		void DestroyWheat(std::pair<int, int> position);

	private:

		const int& current_level_;

		std::vector<std::unique_ptr<level::Level>> levels_;

		// Stores the data of the tileset used for drawing the map
		Texture2D tileset_ = LoadTexture("assets/graphics/tileset/tileset.png");

		const int TILESET_WIDTH_	= 14;
		const int TILESET_HEIGHT_	= 20;

		std::vector<std::pair<float, float>> positions_of_tiles_in_tileset_;
	};
}