#include "enemy.h"

game::core::Enemy::Enemy(std::shared_ptr<game::core::Sprite> sprite)
	: Actor(sprite)
{
}

void game::core::Enemy::handleMovement(int level) {
	//A* implementation here, then modify in derived classes by changing some values
}