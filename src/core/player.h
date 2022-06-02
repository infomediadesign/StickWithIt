#pragma once

#include "actor.h"

namespace game::core {
	class Player : game::core::Actor{
	public:


	private:
        std::shared_ptr<game::core::Sprite> sprite_;

	};
}