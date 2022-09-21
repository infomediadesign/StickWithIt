#pragma once

#include <vector>

#include "../../levels/map.h"

namespace component
{
	class Pathfinder
	{
	public:

		Pathfinder(std::shared_ptr<level::Map>& map, int& x, int& y);

		std::pair<int, int> FindPath(std::pair<int, int> destination, bool can_fly);

	private:

		void ResetMap();

		std::shared_ptr<level::Map>& map_;

		int& x_;
		int& y_;
	};
}