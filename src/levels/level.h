#pragma once

#include <raylib.h>
#include <vector>

#include "config.h"

namespace level
{
	class Level
	{
	public:

		Level(int number_of_rounds, int enemies_per_round, std::vector<std::vector<int>> tilemap);

		enum Layer
		{
			GROUND_LAYER,
			DECOR_LAYER,
			SPAWN_LAYER,
			COLLISION_LAYER,

			VISIBLE_LAYERS = 2,
			INVISIBLE_LAYERs = 2
		};

		enum Tiletype
		{
			WHEAT = 56,
			WHEAT_DESTROYED = 8,
			SPAWN_PLAYER = 182,
			RITUAL = 182,
			RITUAL_MID = 182,
			SPAWN_ENEMY_GROUND = 190,
			SPAWN_ENEMY_FLYING = 146,
			COLLISION = 190
		};

		const std::vector<std::vector<int>>& GetTilemap();

		const std::vector<std::pair<int, int>>& GetWheat() const;
		const std::vector<std::pair<int, int>>& GetSpawnPlayer() const;
		const std::vector<std::pair<int, int>>& GetRitualMid() const;
		const std::vector<std::pair<int, int>>& GetSpawnEnemyGround() const;
		const std::vector<std::pair<int, int>>& GetSpawnEnemyAir() const;
		const std::vector<std::pair<int, int>>& GetCollisions() const;

		const int GetNumberOfRounds() const;
		const int GetEnemiesPerRound() const;

		void DestroyWheat(std::pair<int, int> position);

	private:

		const int number_of_rounds_;
		const int enemies_per_round_;

		std::vector<std::vector<int>> tilemap_;

		std::vector<std::pair<int, int>> positions_wheat_;
		std::vector<std::pair<int, int>> positions_spawn_player_;
		std::vector<std::pair<int, int>> positions_ritual_mid_;
		std::vector<std::pair<int, int>> positions_spawn_enemy_ground_;
		std::vector<std::pair<int, int>> positions_spawn_enemy_air_;
		std::vector<std::pair<int, int>> positions_collisions_;
	};
}