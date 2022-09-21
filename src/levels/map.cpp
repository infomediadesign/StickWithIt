#include "map.h"

level::Map::Map(const int& current_level)
	:
	level_handler_(std::make_unique<LevelHandler>(current_level))
{
	for (int y = 0; y < game::TILES_HEIGHT; y++)
	{
		for (int x = 0; x < game::TILES_WIDTH; x++)
		{
			map_.push_back(std::make_shared<Tile>(x, y));
		}
	}

	// Fill up neighbours of each tile
	for (auto& tile : map_)
	{
		int tileUp = tile->y_ * game::TILES_WIDTH + tile->x_ - game::TILES_WIDTH;
		int tileDown = tile->y_ * game::TILES_WIDTH + tile->x_ + game::TILES_WIDTH;
		int tileRight = tile->y_ * game::TILES_WIDTH + tile->x_ - 1;
		int tileLeft = tile->y_ * game::TILES_WIDTH + tile->x_ + 1;

		if (tile->y_ > 0)
		{
			tile->neighbours_.push_back(map_[tileUp]);
		}
		if (tile->y_ < game::TILES_HEIGHT - 1)
		{
			tile->neighbours_.push_back(map_[tileDown]);
		}
		if (tile->x_ > 0)
		{
			tile->neighbours_.push_back(map_[tileRight]);
		}
		if (tile->x_ < game::TILES_WIDTH - 1)
		{
			tile->neighbours_.push_back(map_[tileLeft]);
		}
	}

	ResetMap();
}

void level::Map::Draw() const
{
	level_handler_->DrawLevel();
}

// Delete old map and setup every tiles properties
// Gets also called in constructor
void level::Map::ResetMap()
{
	// Delete all properties
	for (auto& tile : map_)
	{
		tile->is_obstacle_ = false;
		tile->is_ritual = false;
	}

	// Set collisions
	for (auto& tile : level_handler_->PositionsOfTiletype(LevelHandler::COLLISION))
	{
		int tile_position = tile.second * game::TILES_WIDTH + tile.first;

		map_[tile_position]->is_obstacle_ = true;
	}

	// Set ritual tiles
	for (auto& tile : level_handler_->PositionsOfTiletype(LevelHandler::SPAWN_PLAYER))
	{
		int tile_position = tile.second * game::TILES_WIDTH + tile.first;

		map_[tile_position]->is_ritual = true;
	}
}

const std::unique_ptr<level::LevelHandler>& level::Map::GetLevelHandler()
{
	return level_handler_;
}

std::vector<std::shared_ptr<level::Map::Tile>>& level::Map::GetMap()
{
	return map_;
}
