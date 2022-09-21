#pragma once

#include "enemy.h"

namespace actor
{
	class Boar : public Enemy
	{
	public:

		Boar(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}