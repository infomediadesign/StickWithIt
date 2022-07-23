#include "mushroom.h"

objects::Mushroom::Mushroom()
{
	std::cout << "Mushroom called!" << std::endl;

	// Default data
	_lives = 10;
	_movePoints = 2;
	_attackDamage = 2;
	_isAlive = true;
	_canFly = false;
	_position = { 0, 0 };

	// Default sprite data 
	_texture = std::make_shared<Texture2D>(LoadTextureFromImage(*data::cTextureMushroom));
	_textureColumns = 8;
	_textureRows = 13;
	_textureWidth = 640;
	_textureHeight = 1040;
	_wantedSpeed = 15;
	_textureOffset = { 40 - data::cHalfTileSize, 48 - data::cHalfTileSize }; // The position of objects feet - distance from tile corner to tile mid
	_framesPerRow = {
		8, 8, 8, 8,
		8, 8, 8, 8,
		8, 8, 8, 8,
		8
	};

	// Animation player to tell object what animation to play
	_animationPlayer = std::make_unique<handlers::AnimationPlayer>(&_position, _texture, _textureColumns, _textureRows, _textureWidth, _textureHeight,
		_wantedSpeed, _textureOffset, _framesPerRow);

	// Pathfinder object to find path in Walk();
	_pathfinder = nullptr;
}

objects::Mushroom::~Mushroom() {
	std::cout << "Mushroom deleted!" << std::endl;
}
