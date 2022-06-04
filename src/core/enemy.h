#pragma once

#include "actor.h"

namespace game::core {
	class Enemy : public game::core::Actor {
	public:
		Enemy() = delete;
		Enemy(std::shared_ptr<game::core::Sprite> sprite, int enemySpriteHeight, int enemySpriteWidth);
		~Enemy() override;

		void handleMovement(int level) override;

		void placeEnemyAtRandomLocation() override;

	private:
		int _enemySpriteHight = 0;
		int _enemySpriteWidth = 0;
	};
}