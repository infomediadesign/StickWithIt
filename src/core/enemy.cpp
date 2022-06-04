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

    int coinflipBorder = rand() % 4 + 1;

	switch (coinflipBorder)
	{
	case 1:
	{
		sprite_->pos_x = 0;
		sprite_->pos_y = (rand() % (640 - _enemySpriteHight)) + 0;
	}
	case 2:
	{
		sprite_->pos_x = 640 - _enemySpriteWidth;
		sprite_->pos_y = (rand() % (640 - _enemySpriteHight)) + 0;
	}
	case 3:
	{
		sprite_->pos_x = (rand() % (640 - _enemySpriteWidth)) + 0;
		sprite_->pos_y = 0;
	}
	case 4:
	{
		sprite_->pos_x = (rand() % (640 - _enemySpriteWidth)) + 0;
		sprite_->pos_y = 360 - _enemySpriteHight;
	}
	}
}