#include "pathfinder.h"

#include <list>

component::Pathfinder::Pathfinder(std::shared_ptr<level::Map>& map, int& x, int& y)
	:
	map_(map),
	x_(x),
	y_(y)
{
}

std::pair<int, int> component::Pathfinder::FindPath(std::pair<int, int> destination, bool can_fly)
{
	int position_index_start = y_ * game::TILES_WIDTH + x_;
	int position_index_end = destination.second * game::TILES_WIDTH + destination.first;

	// If we are next to our destination skip all the pathfinding
	if (position_index_start + 1 == position_index_end ||
		position_index_start - 1 == position_index_end ||
		position_index_start + game::TILES_WIDTH == position_index_end ||
		position_index_start - game::TILES_WIDTH == position_index_end)
	{
		return { x_, y_ };
	}

	std::shared_ptr<level::Map::Tile> tile_start = map_->GetMap()[position_index_start];
	std::shared_ptr<level::Map::Tile> tile_end = map_->GetMap()[position_index_end];
	std::shared_ptr<level::Map::Tile> tile_current = nullptr;

	tile_start->cost_start_ = 0;
	tile_start->cost_end_ = sqrtf(static_cast<float>(
		(tile_start->x_ - tile_end->x_) * (tile_start->x_ - tile_end->x_) +
		(tile_start->y_ - tile_end->y_) * (tile_start->y_ - tile_end->y_)));

	std::list<std::shared_ptr<level::Map::Tile>> open_list;
	open_list.push_back(tile_start);


	while (!open_list.empty() && tile_current != tile_end)
	{
		open_list.sort([](std::shared_ptr<level::Map::Tile> tile1, std::shared_ptr<level::Map::Tile> tile2)
			{return tile1->cost_end_ < tile2->cost_end_; });

		// Remove all visited tiles from list
		while (!open_list.empty() && open_list.front()->is_visited_ == true)
		{
			open_list.pop_front();
		}

		// If theres no path
		if (open_list.empty())
		{
			break;
		}

		tile_current = open_list.front();
		tile_current->is_visited_ = true;

		// If we would change the path to a more quicker path, update neighbours to change their parent to the current path
		float possibly_lower_goal_to_start = tile_current->cost_start_ + 1;
		for (auto& neighbour : tile_current->neighbours_)
		{
		// Push traversable neighbour tiles into open list but differentiate between flying and walking enemies
			if (can_fly &&
				!neighbour->is_visited_ &&
				(!neighbour->is_blocked || neighbour == tile_end))
			{
				open_list.push_back(neighbour);
			}
			else if (!neighbour->is_obstacle_ &&
				!neighbour->is_visited_ &&
				(!neighbour->is_blocked || neighbour == tile_end))
			{
				open_list.push_back(neighbour);
			}

			// possibly update cost to start and parent
			if (possibly_lower_goal_to_start < neighbour->cost_start_)
			{
				neighbour->parent_ = tile_current;
				neighbour->cost_start_ = possibly_lower_goal_to_start;
			}

			neighbour->cost_end_ = sqrtf(static_cast<float>(
				(neighbour->x_ - tile_end->x_) * (neighbour->x_ - tile_end->x_) +
				(neighbour->y_ - tile_end->y_) * (neighbour->y_ - tile_end->y_)));
		}
	}

	std::pair<int, int> position;

	// If we found a path: return the position of the next tile in the destinations direction
	if (tile_current == tile_end)
	{
		while (tile_current->parent_->parent_ != nullptr)
		{
			tile_current = tile_current->parent_;
		}

		position = { tile_current->x_, tile_current->y_ };
	}
	//If we have not found a path let the enemy hold its ground
	else
	{
		position = { x_, y_ };
	}

	ResetMap();

	return position;
}

void component::Pathfinder::ResetMap()
{
	// Reset map manipulations
	for (auto& tile : map_->GetMap())
	{
		tile->is_visited_ = false;
		tile->cost_start_ = INFINITY;
		tile->cost_end_ = INFINITY;
		tile->parent_ = nullptr;
	}
}
