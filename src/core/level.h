#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include <memory>

namespace game::core {
	class Level {
	public:
		Level();
		std::map<std::string, std::vector<int>> getLevelTilemaps();
		void setLevelTilemaps(std::string level, std::map<std::vector<float>, int> tileLocation, float playerPositionX, float playerPositionY);

	private:
		std::map<std::string, std::vector<int>> tilemaps;
	};
}