#pragma once

#include <iostream>
#include <vector>

#include "level_handler.h"

namespace level
{
	class Map
	{
	public:

		Map(const int& current_level);

		void Draw() const;
		void ResetMap();

		struct Tile
		{
			Tile(int x, int y)
				:
				x_(x),
				y_(y)
			{
			}

			int x_ = 0;
			int y_ = 0;

			float cost_start_ = INFINITY;
			float cost_end_ = INFINITY;

			bool is_obstacle_ = false;
			bool is_visited_ = false;
			bool is_enemy_ground_spawn = false;
			bool is_enemy_air_spawn = false;
			bool is_ritual = false;
			bool is_blocked = false;

			std::shared_ptr<Tile> parent_ = nullptr;

			std::vector<std::shared_ptr<Tile>> neighbours_{};
		};

		std::vector<std::shared_ptr<Tile>>& GetMap();
		const std::unique_ptr<LevelHandler>& GetLevelHandler();

	private:

		// The map full of Tiles
		std::vector<std::shared_ptr<Tile>> map_ {};

		std::unique_ptr<LevelHandler> level_handler_;
	};
}