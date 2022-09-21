#include "level.h"

#include <iostream>
level::Level::Level(int number_of_rounds, int enemies_per_round, std::vector<std::vector<int>> tilemap)
	:
	number_of_rounds_(number_of_rounds),
	enemies_per_round_(enemies_per_round),
	tilemap_(tilemap)
{

	int tile = 0;

	// If we found a tile of the wanted type, push back it's position
	for (int y = 0; y < game::TILES_HEIGHT; y++)
	{
		for (int x = 0; x < game::TILES_WIDTH; x++)
		{
			if (tilemap_[COLLISION_LAYER][tile] == WHEAT)
			{
				positions_wheat_.push_back({ x, y });
			}

			if (tilemap_[SPAWN_LAYER][tile] == SPAWN_PLAYER)
			{
				positions_spawn_player_.push_back({ x, y });
			}

			if (tilemap_[SPAWN_LAYER][tile] == SPAWN_ENEMY_GROUND)
			{
				positions_spawn_enemy_ground_.push_back({ x, y });
			}

			// Flying enemies can also spawn on ground spawns
			if (tilemap_[SPAWN_LAYER][tile] == SPAWN_ENEMY_FLYING ||
				tilemap_[SPAWN_LAYER][tile] == SPAWN_ENEMY_GROUND)
			{
				positions_spawn_enemy_air_.push_back({ x, y });
			}

			if (tilemap_[COLLISION_LAYER][tile] == COLLISION)
			{
				positions_collisions_.push_back({ x, y });
			}

			if (tilemap_[COLLISION_LAYER][tile] == RITUAL_MID)
			{
				positions_ritual_mid_.push_back({ x, y });
			}

			tile++;
		}
	}
}

const std::vector<std::vector<int>>& level::Level::GetTilemap()
{
	return tilemap_;
}

const std::vector<std::pair<int, int>>& level::Level::GetWheat() const
{
	return positions_wheat_;
}

const std::vector<std::pair<int, int>>& level::Level::GetSpawnPlayer() const
{
	return positions_spawn_player_;
}

const std::vector<std::pair<int, int>>& level::Level::GetRitualMid() const
{
	return positions_ritual_mid_;
}

const std::vector<std::pair<int, int>>& level::Level::GetSpawnEnemyGround() const
{
	return positions_spawn_enemy_ground_;
}

const std::vector<std::pair<int, int>>& level::Level::GetSpawnEnemyAir() const
{
	return positions_spawn_enemy_air_;
}

const std::vector<std::pair<int, int>>& level::Level::GetCollisions() const
{
	return positions_collisions_;
}

const int level::Level::GetNumberOfRounds() const
{
	return number_of_rounds_;
}

const int level::Level::GetEnemiesPerRound() const
{
	return enemies_per_round_;
}

void level::Level::DestroyWheat(std::pair<int, int> position)
{
	// Exchange wheat tiles when flying entities enter it
	int tile = position.second * game::TILES_WIDTH + position.first;

	if (tilemap_[COLLISION_LAYER][tile] == WHEAT)
	{
		tilemap_[GROUND_LAYER][tile] = WHEAT_DESTROYED;
	}
}
