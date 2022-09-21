#include "scarecrow.h"

actor::Scarecrow::Scarecrow(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate)
	:
	Player(
		//max_hp
		10,
		//max_move_points
		10,
		//max_action_points
		3,
		//attack_damage
		10,
		//can_fly
		false,
		//is_active
		true,
		//animation_player
		std::make_shared<component::AnimationPlayer>(
			std::make_shared<component::Sprite>(
				//texture
				"assets/graphics/players/scarecrow_animations.png",
				//wanted_speed
				7,
				//texture_collumns
				25,
				//texture_rows
				14,
				//texture_width
				2000,
				//texture_height
				1120,
				//texture_offset
				std::pair<int, int>
				{
					40 - game::TILE_SIZE / 2,
					46 - game::TILE_SIZE / 2
				},
				//frames_per_row
				std::vector<int>
				{
					15, 15, 15, 15,
					9, 9, 9, 9,
					5, 5, 5, 5,
					16, 25,
					9, 9, 9, 9,
					6, 6, 7, 7
				}
				),
			//state
			state_,
			//is_active_
			is_active_
			),
		//map
		map,
		gamestate
	)
{
	EvaluateBoosts();
}

void actor::Scarecrow::SwapWeapon()
{
	if (IsKeyPressed(KEY_F) && is_active_)
	{
		active_weapon_index_++;

		if (active_weapon_index_ == MAX_WEAPONS)
		{
			active_weapon_index_ = SCYTHE;
		}

		switch (active_weapon_index_)
		{
		case SCYTHE:
			active_weapon_ = std::make_unique<weapon::Scythe>();
			break;
		case PITCHFORK:
			active_weapon_ = std::make_unique<weapon::Pitchfork>();
			break;
		case SHOVEL:
			active_weapon_ = std::make_unique<weapon::Shovel>();
			break;
		}
	}

	// @TODO hier stats anpassen von gamestate
}

void actor::Scarecrow::Draw() const
{
	actor::Actor::Draw();

	if (is_active_)
	{
		active_weapon_->Draw();
	}
}

void actor::Scarecrow::GetDamage(std::pair<int, std::pair<int, int>> attack)
{
	if (x_ == attack.second.first && y_ == attack.second.second)
	{
		hp_ -= attack.first;
	}

	if (hp_ <= 0)
	{
		if (GetRandomValue(0, 1) == 1)
		{
			state_->SetState(State::DEATH_2);
		}
		else
		{
			state_->SetState(State::DEATH_1);
		}
	}
}

std::pair<int, std::vector<std::pair<int, int>>> actor::Scarecrow::Attack()
{
	if (is_active_ && hp_ > 0 && action_points_ > 0 && animation_player_->GetIsAnimationOver() &&
		(IsKeyPressed(KEY_UP) ||
		IsKeyPressed(KEY_DOWN) ||
		IsKeyPressed(KEY_RIGHT) ||
		IsKeyPressed(KEY_LEFT)))
	{
		bool has_attacked = false;
		int direction = 0;

		if (IsKeyPressed(KEY_UP))
		{
			has_attacked = true;
			direction = weapon::Weapon::UP;

			switch (active_weapon_index_)
			{
			case SCYTHE:
				state_->SetState(State::ATTACK_UP);
				break;
			case PITCHFORK:
				state_->SetState(State::ATTACK_PITCHFORK_UP);
				break;
			case SHOVEL:
				state_->SetState(State::ATTACK_SHOVEL_UP);
				break;
			}
		}
		if (IsKeyPressed(KEY_DOWN))
		{
			has_attacked = true;
			direction = weapon::Weapon::DOWN;

			switch (active_weapon_index_)
			{
			case SCYTHE:
				state_->SetState(State::ATTACK_DOWN);
				break;
			case PITCHFORK:
				state_->SetState(State::ATTACK_PITCHFORK_DOWN);
				break;
			case SHOVEL:
				state_->SetState(State::ATTACK_SHOVEL_DOWN);
				break;
			}
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			has_attacked = true;
			direction = weapon::Weapon::RIGHT;

			switch (active_weapon_index_)
			{
			case SCYTHE:
				state_->SetState(State::ATTACK_RIGHT);
				break;
			case PITCHFORK:
				state_->SetState(State::ATTACK_PITCHFORK_RIGHT);
				break;
			case SHOVEL:
				state_->SetState(State::ATTACK_SHOVEL_RIGHT);
				break;
			}
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			has_attacked = true;
			direction = weapon::Weapon::LEFT;

			switch (active_weapon_index_)
			{
			case SCYTHE:
				state_->SetState(State::ATTACK_LEFT);
				break;
			case PITCHFORK:
				state_->SetState(State::ATTACK_PITCHFORK_LEFT);
				break;
			case SHOVEL:
				state_->SetState(State::ATTACK_SHOVEL_LEFT);
				break;
			}
		}

		if (has_attacked)
		{
			action_points_--;
		}

		 //Destroy wheat of every position of atttack (if its even on the map)
		for (auto& pattern_pos : active_weapon_->GetPattern(direction))
		{
			std::pair<int, int> position = { x_ + pattern_pos.first, y_ + pattern_pos.second };

			if (has_attacked && 
				position.first >= 0 &&
				position.first < game::TILES_WIDTH && 
				position.second >= 0 && 
				position.second < game::TILES_HEIGHT)
			{
				map_->GetLevelHandler()->DestroyWheat(position);
			}
		}

		std::vector<std::pair<int, int>> positions;

		for (auto& pos : active_weapon_->GetPattern(direction))
		{
			positions.push_back({ x_ + pos.first, y_ + pos.second });
		}

		return { attack_damage_ + EvaluateAttackBoost(), positions};
	}

	return std::pair<int, std::vector<std::pair<int, int>>>();
}

void actor::Scarecrow::EvaluateBoosts()
{
	// PITCHFORK
	if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_MID))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_1))
	{
		max_move_points_	+= 3;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_2))
	{
		max_move_points_	+= 1;
		max_action_points_	+= 1;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_1))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_2))
	{
		max_move_points_	+= 2;
		max_action_points_	+= 2;
	}

	// SCYTHE
	if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_MID))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_1))
	{
		max_move_points_	+= 3;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_2))
	{
		max_move_points_	+= 1;
		max_action_points_	+= 1;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_1))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_2))
	{
		max_move_points_	+= 2;
		max_action_points_	+= 2;
	}

	// SHOVEL
	if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_MID))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_1))
	{
		max_move_points_	+= 3;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_2))
	{
		max_move_points_	+= 1;
		max_action_points_	+= 1;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_1))
	{
		max_move_points_	+= 0;
		max_action_points_	+= 0;
	}
	if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_2))
	{
		max_move_points_	+= 2;
		max_action_points_	+= 1;
	}

	move_points_ = max_move_points_;
	action_points_ = max_action_points_;
}

int actor::Scarecrow::EvaluateAttackBoost()
{
	int attack_boost = 0;

	switch (active_weapon_index_)
	{
	case SCYTHE:
		if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_MID))
		{
			attack_damage_ += 3;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_1))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_LEFT_2))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_1))
		{
			attack_damage_ += 4;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SCYTHE, gs::GameState::UPGRADE_RIGHT_2))
		{
			attack_damage_ += 2;
		}
		break;

	case PITCHFORK:
		if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_MID))
		{
			attack_damage_ += 3;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_1))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_LEFT_2))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_1))
		{
			attack_damage_ += 4;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::PITCHFORK, gs::GameState::UPGRADE_RIGHT_2))
		{
			attack_damage_ += 2;
		}
		break;

	case SHOVEL:
		if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_MID))
		{
			attack_damage_ += 3;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_1))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_LEFT_2))
		{
			attack_damage_ += 0;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_1))
		{
			attack_damage_ += 4;
		}
		if (gamestate_->GetUpgradeStatus(gs::GameState::SHOVEL, gs::GameState::UPGRADE_RIGHT_2))
		{
			attack_damage_ += 2;
		}
		break;
	}

	return attack_boost;
}
