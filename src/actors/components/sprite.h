#pragma once

#include <raylib.h>
#include <vector>

namespace component
{
	class Sprite
	{
	public:

		Sprite(const char* texture_path, int wanted_speed, int texture_collumns, int texture_rows, int texture_width, int texture_height,
			std::pair<int, int> texture_offset, std::vector<int> frames_per_row);
		virtual ~Sprite();

		const Texture2D texture_;

		const int wanted_speed_;
		const int texture_collumns_;
		const int texture_rows_;
		const int texture_width_;
		const int texture_height_;

		std::pair<int, int> texture_offset_;

		std::vector<int> frames_per_row_;
	};
}