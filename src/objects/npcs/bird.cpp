#include "bird.h"

objects::Bird::Bird()
{
std::cout << "Bird called!" << std::endl;

// Default data
_lives = 10;
_movePoints = 2;
_attackDamage = 2;
_isAlive = true;
_canFly = true;
_position = { 0, 0 };

// Default sprite data 
_texture = LoadTextureFromImage(textures::BIRD);
_textureColumns = 8;
_textureRows = 13;
_textureWidth = 768;
_textureHeight = 1248;
_wantedSpeed = 8;
_textureOffset = { 40 - game::HALF_TILE_SIZE, 48 - game::HALF_TILE_SIZE }; // The position of objects feet - distance from tile corner to tile mid
_framesPerRow = {
	8, 8, 8, 8,
	8, 8, 8, 8,
	8, 8, 8, 8,
	8
};

// Animation player to tell object what animation to play
_animationPlayer = std::make_unique<handlers::AnimationPlayer>(&_position, &_texture, _textureColumns, _textureRows, _textureWidth, _textureHeight,
	&_wantedSpeed, _textureOffset, _framesPerRow);

// Pathfinder object to find path in Walk();
_pathfinder = nullptr;
}

objects::Bird::~Bird() {
	std::cout << "Bird deleted!" << std::endl;
}