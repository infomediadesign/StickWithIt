#include "level_handler.h"
#include "config.h"

level::LevelHandler::LevelHandler(const int& current_level)
	:
	current_level_(current_level)
{
	// Fill the 'tiles_and_their_positions_on_tileset_'-vector
	for (int y = 0; y < TILESET_HEIGHT_; y++)
	{
		for (int x = 0; x < TILESET_WIDTH_; x++)
		{
			positions_of_tiles_in_tileset_.push_back({ static_cast<float>(game::TILE_SIZE) * x, static_cast<float>(game::TILE_SIZE) * y });
		}
	}

	// Fill our levels
	levels_.push_back(std::make_unique<level::Level1>(5, 5));
	levels_.push_back(std::make_unique<level::Level2>(6, 6));
	levels_.push_back(std::make_unique<level::Level3>(7, 7));
	levels_.push_back(std::make_unique<level::Level4>(8, 8));
}

level::LevelHandler::~LevelHandler()
{
	UnloadTexture(tileset_);
}

void level::LevelHandler::DrawLevel() const
{
	std::vector<std::vector<int>> tilemap_current = levels_[current_level_]->GetTilemap();

	// Draw each layer - one after the other
	for (int layer = 0; layer < level::Level::VISIBLE_LAYERS; layer++)
	{
		// Iterator for each tile of our tilemap layer
		int tile = 0;

		for (float y = 0; y < game::TILES_HEIGHT; y++)
		{
			for (float x = 0; x < game::TILES_WIDTH; x++)
			{
				// If we have an empty tile, skip it!
				if (tilemap_current[layer][tile] != 0)
				{
					// Draw a specific rectangle of our tileset depending on the current tile of tilemap
					int tile_in_tileset = tilemap_current[layer][tile] - 1;				// - 1 because tile with id = 1 is at index = 0

					DrawTextureRec(
						tileset_,
						{
							positions_of_tiles_in_tileset_[tile_in_tileset].first,
							positions_of_tiles_in_tileset_[tile_in_tileset].second,
							static_cast<float>(game::TILE_SIZE),
							static_cast<float>(game::TILE_SIZE)
						},
						{
							static_cast<float>(game::TILE_SIZE) * x,
							static_cast<float>(game::TILE_SIZE) * y
						},
						WHITE
						);
				}

				tile++;
			}
		}
	}
}

const std::vector<std::pair<int, int>>& level::LevelHandler::PositionsOfTiletype(TileTypes tile_type) const
{
	switch (tile_type)
	{
	case WHEAT:
		return levels_[current_level_]->GetWheat();
		break;
	case SPAWN_PLAYER:
		return levels_[current_level_]->GetSpawnPlayer();
		break;
	case SPAWN_ENEMY_GROUND:
		return levels_[current_level_]->GetSpawnEnemyGround();
		break;
	case SPAWN_ENEMY_AIR:
		return levels_[current_level_]->GetSpawnEnemyAir();
		break;
	case COLLISION:
		return levels_[current_level_]->GetCollisions();
		break;
	case RITUAL_MID:
		return levels_[current_level_]->GetRitualMid();
		break;

	default:
		std::cout << "invalid tiletype, returned wheat" << std::endl;
		return levels_[current_level_]->GetWheat();
	}
}

const int level::LevelHandler::GetNumberOfRounds() const
{
	return levels_[current_level_]->GetNumberOfRounds();
}

const int level::LevelHandler::GetEnemiesPerRound() const
{
	return levels_[current_level_]->GetEnemiesPerRound();
}

void level::LevelHandler::DestroyWheat(std::pair<int, int> position)
{
	levels_[current_level_]->DestroyWheat(position);
}
