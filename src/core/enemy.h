#pragma once

#include "actor.h"

namespace game::core {
	class Enemy : public game::core::Actor {
	public:
		Enemy() = delete;
		Enemy(std::shared_ptr<game::core::Sprite> sprite);

		void handleMovement(int level) override;

	private:
		int _hitpoints = 0;
		int _attackDamage = 0;
		int _movementPoints = 0;
	};
}