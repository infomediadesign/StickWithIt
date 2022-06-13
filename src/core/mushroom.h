#pragma once

#include <raylib.h>

#include "enemy.h"
#include "sprite_animated.h"

namespace game::core {
	class Mushroom : public Enemy {
	public:
		Mushroom();
		~Mushroom() override;

		void handleMovement(int level) override;

	private:

	};
}
