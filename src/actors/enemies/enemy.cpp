#include "enemy.h"

#include <list>
#include <math.h>

actor::Enemy::Enemy(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active,
	std::shared_ptr<component::AnimationPlayer> animation_player, std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate)
	:
	Actor(
		max_hp,
		max_move_points,
		max_action_points,
		attack_damage,
		can_fly,
		is_active,
		//is prepering
		false,
		animation_player,
		map,
		gamestate
	),
	pathfinder_(std::make_unique<component::Pathfinder>(map_, x_, y_))
{
}

void actor::Enemy::Update()
{
	if (hp_ <= 0 && animation_player_->GetIsAnimationOver())
	{
		is_alive_ = false;
	}
}

void actor::Enemy::Spawn()
{
	int tile = 0;

	// pos of spawn tile
	std::pair<int, int> position{};

	// Look for spawn tiles
	if (can_fly_)
	{
		// Get us a random spawnable tile
		do 
		{
			int temp_pos = GetRandomValue(0, static_cast<int>(map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::SPAWN_ENEMY_AIR).size() - 1));

			position = map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::SPAWN_ENEMY_AIR)[temp_pos];

			tile = position.second * game::TILES_WIDTH + position.first;
		} while (map_->GetMap()[tile]->is_blocked);
	}
	else
	{
		// Get us a random spawnable AND traversable tile
		do
		{
			int temp_pos = GetRandomValue(0, static_cast<int>(map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::SPAWN_ENEMY_GROUND).size() - 1));

			position = map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::SPAWN_ENEMY_GROUND)[temp_pos];

			tile = position.second * game::TILES_WIDTH + position.first;
		} while (map_->GetMap()[tile]->is_blocked);
	}

	// Mark the spawn tile as blocked
	map_->GetMap()[tile]->is_blocked = true;

	// Move position of enemy to spawn
	x_ = position.first;
	y_ = position.second;

	if (x_ == 0)
	{
		state_->SetState(State::IDLE_RIGHT);
	}
	else if (x_ == game::TILES_WIDTH - 1)
	{
		state_->SetState(State::IDLE_LEFT);
	}
	else if (y_ == 0)
	{
		state_->SetState(State::IDLE_DOWN);
	}
	else if (y_ == game::TILES_HEIGHT - 1)
	{
		state_->SetState(State::IDLE_UP);
	}
}

int actor::Enemy::Move(std::vector<std::pair<int, int>> position_players)
{
	if (is_alive_)
	{
		std::vector<std::pair<int, int>> possible_destinations;

		for (auto& pos : position_players)
		{
			possible_destinations.push_back(pos);
		}
		for (auto& pos : map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::RITUAL_MID))
		{
			possible_destinations.push_back(pos);
		}

		std::pair<int, int> destination;
		float distance_to_destination = INFINITY;

		// Go trough every possible destination and evaluate the nearest
		for (auto& pos : possible_destinations)
		{
			float distance = sqrtf(static_cast<float>((x_ - pos.first) * (x_ - pos.first) + (y_ - pos.second) * (y_ - pos.second)));

			if (distance < distance_to_destination)
			{
				distance_to_destination = distance;
				destination = pos;
			}
		}

		destination = pathfinder_->FindPath(destination, can_fly_);

		int position_index = y_ * game::TILES_WIDTH + x_;
		int future_position_index = destination.second * game::TILES_WIDTH + destination.first;

		// Remove collision of tile the enemy moved from..
		map_->GetMap()[position_index]->is_blocked = false;

		std::pair<int, int> temp_position = { x_, y_ };

		x_ = destination.first;
		y_ = destination.second;

		if (!can_fly_)
		{
			map_->GetLevelHandler()->DestroyWheat({ x_, y_ });
		}

		// ..and add it to the tile the enemy is now standing on
		map_->GetMap()[future_position_index]->is_blocked = true;

		// If the enemy is standing on a ritual tile: BLOW UP! and damage scarecrow
		if (map_->GetMap()[future_position_index]->is_ritual)
		{
			hp_ = 0;
			state_->SetState(State::DEATH_1);
			map_->GetMap()[future_position_index]->is_blocked = false;
			return attack_damage_;
		}
		else
		{
			if (y_ < temp_position.second)
			{
				state_->SetState(State::WALK_UP);
			}
			else if (y_ > temp_position.second)
			{
				state_->SetState(State::WALK_DOWN);
			}
			else if (x_ > temp_position.first)
			{
				state_->SetState(State::WALK_RIGHT);
			}
			else if (y_ < temp_position.second)
			{
				state_->SetState(State::WALK_LEFT);
			}
		}
	}

	return false;
}

std::pair<int, std::pair<int, int>> actor::Enemy::Attack(int x, int y) const
{
	if (hp_ > 0)
	{
		bool hit = false;

		if (x_ == x + 0 && y_ == y + 1)
		{
			state_->SetState(State::ATTACK_UP);
			hit = true;
		}
		else if (x_ == x + 0 && y_ == y - 1)
		{
			state_->SetState(State::ATTACK_DOWN);
			hit = true;
		}
		else if (x_ == x - 1 && y_ == y + 0)
		{
			state_->SetState(State::ATTACK_RIGHT);
			hit = true;
		}
		else if (x_ == x + 1 && y_ == y + 0)
		{
			state_->SetState(State::ATTACK_LEFT);
			hit = true;
		}

		if (hit)
		{
			return { attack_damage_, {x, y} };
		}
	}

	return std::pair<int, std::pair<int, int>>();
}

void actor::Enemy::GetDamage(std::pair<int, std::vector<std::pair<int, int>>> attack)
{
	// For each attacked tile
	for (auto& pos : attack.second)
	{
		// If enemy is on one of the attacked tiles - damage it!
		if (x_ == pos.first && y_ == pos.second)
		{
			hp_ -= attack.first;
		}
	}

	if (hp_ <= 0)
	{
		int position_index = y_ * game::TILES_WIDTH + x_;
		map_->GetMap()[position_index]->is_blocked = false;
		state_->SetState(State::DEATH_1);
	}
}
