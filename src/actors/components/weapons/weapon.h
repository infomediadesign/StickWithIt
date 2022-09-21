#pragma once

#include <iostream>
#include <vector>
#include <raylib.h>

#include "config.h"

namespace weapon
{
	class Weapon
	{
	public:

		Weapon(Texture2D texture, 
			std::vector<std::pair<int, int>> pattern_up,
			std::vector<std::pair<int, int>> pattern_down,
			std::vector<std::pair<int, int>> pattern_right,
			std::vector<std::pair<int, int>> pattern_left);

		~Weapon();

		void Draw() const;
		std::vector<std::pair<int, int>> GetPattern(int direction) const;

		enum
		{
			UP,
			DOWN,
			RIGHT,
			LEFT
		};

	protected:

		//PATTERN
		std::vector<std::pair<int, int>> pattern_up_;
		std::vector<std::pair<int, int>> pattern_down_;
		std::vector<std::pair<int, int>> pattern_right_;
		std::vector<std::pair<int, int>> pattern_left_;

		Texture2D texture_;
	};
}