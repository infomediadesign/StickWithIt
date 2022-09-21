#pragma once

#include "enemy.h"

namespace actor
{
	class Bird : public Enemy
	{
	public:

		Bird(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}