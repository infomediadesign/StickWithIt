#pragma once

#include "../levels/map.h"
#include "actors.h"

namespace actor
{
	class Spawner
	{
	public:

		Spawner(std::shared_ptr<gs::GameState>& gamestate);

		enum
		{
			BAT,
			BIRD,
			BOAR,
			MUSHROOM,
			SPIDER,

			FLY,
			SCARECROW,

			MAX_ENEMIES = 5
		};

		std::shared_ptr<Player> SpawnPlayer(int entity, std::shared_ptr<level::Map>& map) const;
		std::shared_ptr<Enemy> SpawnEnemy(int entity, std::shared_ptr<level::Map>& map) const;

		std::vector<std::shared_ptr<Enemy>> SpawnWave(int number_of_enemies, std::shared_ptr<level::Map>& map);

		std::shared_ptr<gs::GameState>& gamestate_;
	};
}