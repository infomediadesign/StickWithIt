#include "player.h"

game::core::Player::Player(std::shared_ptr<game::core::Sprite> sprite)
	: Actor(sprite)
{
	TraceLog(LOG_INFO, "game::core::Player constructor called");
}