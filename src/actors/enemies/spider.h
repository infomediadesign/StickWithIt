#pragma once

#include "enemy.h"

namespace actor
{
	class Spider : public Enemy
	{
	public:

		Spider(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}