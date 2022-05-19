#pragma once
#include <raylib.h>

namespace game::core {
	class Tilesetter {
	public:
		void placeTilemap(int level);
		void exchangeTile(Vector2 position);
	};
}