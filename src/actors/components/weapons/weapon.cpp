#include "weapon.h"

weapon::Weapon::Weapon(Texture2D texture, 
	std::vector<std::pair<int, int>> pattern_up, 
	std::vector<std::pair<int, int>> pattern_down, 
	std::vector<std::pair<int, int>> pattern_right, 
	std::vector<std::pair<int, int>> pattern_left)
	:
	texture_(texture),
	pattern_up_(pattern_up),
	pattern_down_(pattern_down),
	pattern_right_(pattern_right),
	pattern_left_(pattern_left)
{
}

weapon::Weapon::~Weapon()
{
	UnloadTexture(texture_);
}

void weapon::Weapon::Draw() const
{
	DrawTexture(texture_, game::SCREEN_WIDTH - 65, game::SCREEN_HEIGHT - 58, WHITE);
}

std::vector<std::pair<int, int>> weapon::Weapon::GetPattern(int direction) const
{
	switch (direction)
	{
	case UP:
		return pattern_up_;
		break;
	case DOWN:
		return pattern_down_;
		break;
	case RIGHT:
		return pattern_right_;
		break;
	case LEFT:
		return pattern_left_;
		break;

	default:
		std::cout << "invalid direction, return direction UP";
		return pattern_up_;
	}
}
