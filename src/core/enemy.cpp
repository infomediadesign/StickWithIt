#include "enemy.h"

#include "information.h"
#include "sprite_animated.h"

#include <random>
#include <iostream>

game::core::Enemy::Enemy(std::shared_ptr<game::core::Sprite> sprite, int enemySpriteHeight, int enemySpriteWidth)
    : Actor(sprite), _enemySpriteHight(enemySpriteHeight), _enemySpriteWidth(enemySpriteWidth)
{
}

game::core::Enemy::~Enemy() {
}

void game::core::Enemy::handleMovement(int level)
{

}

void game::core::Enemy::placeEnemyAtRandomLocation() {

	int coinflipBorder = rand() & 3;

	switch (coinflipBorder)
	{
	case 0:
	{
		sprite_->pos_x = 0;
		sprite_->pos_y = (rand() & 360 + _enemySpriteHight) - _enemySpriteHight;
		break;
	}
	case 1:
	{
		sprite_->pos_x = (rand() & 640 + _enemySpriteWidth) - _enemySpriteWidth;
		sprite_->pos_y = 0;
		break;
	}
	case 2:
	{
		sprite_->pos_x = 640 - _enemySpriteWidth;
		sprite_->pos_y = (rand() & 360 + _enemySpriteHight) - _enemySpriteHight;
		break;
	}
	case 3:
	{
		sprite_->pos_x = (rand() & 640 + _enemySpriteWidth) - _enemySpriteWidth;
		sprite_->pos_y = 360 - _enemySpriteHight;
		break;
	}
	}
}