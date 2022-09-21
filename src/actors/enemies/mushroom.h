#pragma once

#include "enemy.h"

namespace actor
{
	class Mushroom : public Enemy
	{
	public:

		Mushroom(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}