#pragma once

#include <raylib.h>

#include "enemy.h"
#include "sprite_animated.h"

namespace game::core {
	class Boar : public Enemy {
	public:
		Boar();
		~Boar() override;

		void handleMovement(int level) override;

	private:

	};
}