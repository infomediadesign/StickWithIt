#include "upgrade.h"

st::Upgrade::Upgrade(const char* texture_path_, int x, int y, int strength, int move_points, int action_points, int cost, bool is_unlocked)
	:
	texture_(LoadTexture(texture_path_)),
	x_(x),
	y_(y),
	strength_(strength),
	move_points_(move_points),
	action_points_(action_points),
	cost_(cost),
	is_unlocked_(is_unlocked)
{
}

st::Upgrade::~Upgrade()
{
	UnloadTexture(texture_);
}

void st::Upgrade::Draw() const
{
	if (is_active_)
	{
		DrawTexture(texture_, x_, y_, WHITE);
	}
	else
	{
		DrawTexture(texture_, x_, y_, DARKGRAY);
	}
}

bool st::Upgrade::GetIsUnlocked() const
{
	return is_unlocked_;
}

void st::Upgrade::SetIsUnlocked(bool status)
{
	is_unlocked_ = status;
}

bool st::Upgrade::GetIsActive() const
{
	return is_active_;
}

void st::Upgrade::SetIsActive(bool status)
{
	is_active_ = status;
}

const std::pair<int, int> st::Upgrade::GetPosition() const
{
	return { x_, y_ };
}

int st::Upgrade::GetStrength() const
{
	return strength_;
}

int st::Upgrade::GetMovePoints() const
{
	return move_points_;
}

int st::Upgrade::GetActionPoints() const
{
	return action_points_;
}

int st::Upgrade::GetCost() const
{
	return cost_;
}
