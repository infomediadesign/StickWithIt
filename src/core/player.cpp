#include "player.h"

game::core::Player::Player(std::shared_ptr<game::core::Sprite> sprite)
	: Actor(sprite)
{
	TraceLog(LOG_INFO, "game::core::Player constructor called");
}

game::core::Player::~Player()
{
	TraceLog(LOG_INFO, "game::core::Player destructor called");
}

void game::core::Player::move() {

}

void game::core::Player::placeOnMap() {

}