#pragma once

#include "player.h"

namespace actor
{
	class Fly : public Player
	{
	public:

		Fly(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

	};
}