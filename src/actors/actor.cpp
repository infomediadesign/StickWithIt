#include "actor.h"

actor::Actor::Actor(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active, bool is_prepering,
	std::shared_ptr<component::AnimationPlayer> animation_player, std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate)
	:
	max_hp_(max_hp),
	max_move_points_(max_move_points),
	max_action_points_(max_action_points),
	attack_damage_(attack_damage),
	can_fly_(can_fly),
	is_active_(is_active),
	is_prepering_(is_prepering),
	animation_player_(animation_player),
	map_(map),
	gamestate_(gamestate)
{
}

void actor::Actor::Draw() const
{
	animation_player_->Draw(x_, y_);
}

void actor::Actor::UpdateAnimation()
{
	if (compare_hp_ != hp_)
	{
		animation_player_->StartFlickering(compare_hp_ - hp_);
		compare_hp_ = hp_;
	}
	animation_player_->Update(is_prepering_);
}

bool actor::Actor::GetIsPreparing() const
{
	return is_prepering_;
}

void actor::Actor::SetIsPreparing(bool status)
{
	if (status == false && !can_fly_)
	{
		map_->GetLevelHandler()->DestroyWheat({ x_, y_ });
	}

	is_prepering_ = status;
}

bool actor::Actor::GetIsActive() const
{
	return is_active_;
}

void actor::Actor::SetIsActive(bool status)
{
	is_active_ = status;
}

bool actor::Actor::GetIsAlive() const
{
	return is_alive_;
}

bool actor::Actor::GetIsAnimationOver() const
{
	return animation_player_->GetIsAnimationOver();
}

int actor::Actor::GetHP() const
{
	return hp_;
}

void actor::Actor::SetHP(int hp)
{
	hp_ = hp;
}

int actor::Actor::GetMovePoints() const
{
	return move_points_;
}

int actor::Actor::GetActionPoints() const
{
	return action_points_;
}

std::pair<int, int> actor::Actor::GetPosition() const
{
	return { x_, y_ };
}
