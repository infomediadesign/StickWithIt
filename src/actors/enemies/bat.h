#pragma once

#include "enemy.h"

namespace actor
{
	class Bat : public Enemy
	{
	public:

		Bat(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}