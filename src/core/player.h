#pragma once

#include "raylib.h"
#include "actor.h"

namespace game::core {
	class Player : game::core::Actor{
	public:
		Player(std::shared_ptr<game::core::Sprite> sprite);
	private:

	};
}