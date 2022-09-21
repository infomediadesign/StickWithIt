#include "player.h"

actor::Player::Player(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active,
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
		true,
		animation_player,
		map,
		gamestate
	)
{
}

void actor::Player::Draw() const
{
	Actor::Draw();
}

void actor::Player::Update()
{
	if (hp_ > 0)
	{
		Move();

		SwapWeapon();

		// Prevent animation cancelling
		if (animation_player_->GetIsAnimationOver())
		{
			// If the animation of dead object has played delete it in game_scene
			if (state_->GetState() == State::DEATH_1 || state_->GetState() == State::DEATH_2)
			{
				is_alive_ = false;
			}
		}
	}
	else
	{
		if (animation_player_->GetIsAnimationOver())
		{
			is_alive_ = false;
		}
	}
}

void actor::Player::Spawn()
{
	// Look for spawn tiles
	for (auto& pos : map_->GetLevelHandler()->PositionsOfTiletype(level::LevelHandler::SPAWN_PLAYER))
	{
		int tile = pos.second * game::TILES_WIDTH + pos.first;

		// If a spawntile is traversable, spawn player on it
		if (!map_->GetMap()[tile]->is_blocked)
		{
			map_->GetMap()[tile]->is_blocked = true;
			x_ = pos.first;
			y_ = pos.second;
			break;
		}
	}

	state_->SetState(State::IDLE_DOWN);
}

void actor::Player::Move()
{
	if (is_active_ && move_points_ > 0 && hp_ > 0 && animation_player_->GetIsAnimationOver())
	{
		std::pair<int, int> position = { x_, y_ };

		int direction = 0;

		// Handle movement
		if (IsKeyPressed(KEY_W) && y_ > 0)
		{
			position.second--;
			direction = State::WALK_UP;
		}
		else if (IsKeyPressed(KEY_S) && y_ < game::TILES_HEIGHT - 1)
		{
			position.second++;
			direction = State::WALK_DOWN;
		}
		else if (IsKeyPressed(KEY_D) && x_ < game::TILES_WIDTH - 1)
		{
			position.first++;
			direction = State::WALK_RIGHT;
		}
		else if (IsKeyPressed(KEY_A) && x_ > 0)
		{
			position.first--;
			direction = State::WALK_LEFT;
		}

		int tile = position.second * game::TILES_WIDTH + position.first;

		// always move when actor can fly but only move ground-actors when theres no collision
		if ((can_fly_ || (!map_->GetMap()[tile]->is_obstacle_ && !can_fly_)) 
			&& !map_->GetMap()[tile]->is_blocked &&
			(position.first != x_ || position.second != y_))
		{
			// Set the tile we stayed on to unblocked
			int current_tile = y_ * game::TILES_WIDTH + x_;
			map_->GetMap()[current_tile]->is_blocked = false;

			// Move
			x_ = position.first;
			y_ = position.second;

			// Set the tile we are staying on to blocked
			map_->GetMap()[tile]->is_blocked = true;

			// If we are in the preperation phase enable moving infinitly
			if (!is_prepering_)
			{
				move_points_--;
			}

			// Set state
			switch (direction)
			{
			case State::WALK_UP:
				state_->SetState(State::WALK_UP);
				break;
			case State::WALK_DOWN:
				state_->SetState(State::WALK_DOWN);
				break;
			case State::WALK_RIGHT:
				state_->SetState(State::WALK_RIGHT);
				break;
			case State::WALK_LEFT:
				state_->SetState(State::WALK_LEFT);
				break;
			}

			// Destroy wheat on the place we moved to when it's not preperation phase
			if (!is_prepering_ && !can_fly_)
			{
				map_->GetLevelHandler()->DestroyWheat(position);
			}
		}
	}
}

std::pair<int, std::vector<std::pair<int, int>>> actor::Player::Attack()
{
	if (hp_ > 0)
	{
		if (is_active_ && hp_ > 0 && action_points_ > 0 && animation_player_->GetIsAnimationOver() &&
			(IsKeyPressed(KEY_UP) ||
				IsKeyPressed(KEY_DOWN) ||
				IsKeyPressed(KEY_RIGHT) ||
				IsKeyPressed(KEY_LEFT)))
		{
			std::pair<int, int> position{};

			if (IsKeyPressed(KEY_UP))
			{
				position = { x_ + 0, y_ - 1 };
				state_->SetState(State::ATTACK_UP);
			}
			if (IsKeyPressed(KEY_DOWN))
			{
				position = { x_ + 0, y_ + 1 };
				state_->SetState(State::ATTACK_DOWN);
			}
			if (IsKeyPressed(KEY_RIGHT))
			{
				position = { x_ + 1, y_ - 0 };
				state_->SetState(State::ATTACK_RIGHT);
			}
			if (IsKeyPressed(KEY_LEFT))
			{
				position = { x_ - 1, y_ - 0 };
				state_->SetState(State::ATTACK_LEFT);
			}

			// if we have attacked, reduce action points
			if (position.first != 0 && position.second != 0)
			{
				action_points_--;
			}

			// Destroy wheat on position of atttack
			map_->GetLevelHandler()->DestroyWheat(position);

			return { attack_damage_, {{position}} };
		}
	}

	return std::pair<int, std::vector<std::pair<int, int>>>();
}

void actor::Player::GetDamage(std::pair<int, std::pair<int, int>> attack)
{
	if (x_ == attack.second.first && y_ == attack.second.second)
	{
		hp_ -= attack.first;
	}

	if (hp_ <= 0)
	{
		state_->SetState(State::DEATH_1);

		int position_index = y_ * game::TILES_WIDTH + x_;

		map_->GetMap()[position_index]->is_blocked = false;
	}
}

void actor::Player::ResetStats()
{
	move_points_ = max_move_points_;
	action_points_ = max_action_points_;
}
