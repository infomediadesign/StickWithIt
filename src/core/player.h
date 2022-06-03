#pragma once

#include "raylib.h"
#include "actor.h"

namespace game::core {
	class Player : public game::core::Actor{
	public:
		Player() = delete;

		Player(std::shared_ptr<game::core::Sprite> sprite);

		//prevent slicing
		Player(const game::core::Player& actor) = delete;
		Player& operator=(const Player&) = delete;

	private:
		std::shared_ptr<game::core::Sprite> sprite_;
	};
}