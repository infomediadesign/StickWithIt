#include "sprite.h"

component::Sprite::Sprite(const char* texture_path, int wanted_speed, int texture_collumns, int texture_rows, int texture_width, int texture_height, 
	std::pair<int, int> texture_offset, std::vector<int> frames_per_row)
	:
	texture_(LoadTexture(texture_path)),
	wanted_speed_(wanted_speed),
	texture_collumns_(texture_collumns),
	texture_rows_(texture_rows),
	texture_width_(texture_width),
	texture_height_(texture_height),
	texture_offset_(texture_offset),
	frames_per_row_(frames_per_row)
{
}

component::Sprite::~Sprite()
{
	UnloadTexture(texture_);
}
