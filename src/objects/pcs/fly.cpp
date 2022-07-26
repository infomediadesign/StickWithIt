#include "fly.h"

objects::Fly::Fly()
{
	std::cout << "Scarecrow called!" << std::endl;

	// Default max data
	_initLives = 10;
	_initMovePoints = 2;
	_initActionPoints = 2;

	// Default data
	_lives = _initLives;
	_movePoints = _initMovePoints;
	_actionPoints = _initActionPoints;
	_attackDamage = 5;
	_isAlive = true;
	_canFly = true;
	_isActive = false;
	_position = { 0, 0 };
	_activeWeapon = eNoWeapon;

	// Default sprite data 
	_texture = LoadTextureFromImage(textures::FLY);
	_textureColumns = 11;
	_textureRows = 13;
	_textureWidth = 1056;
	_textureHeight = 1248;
	_wantedSpeed = 6;
	_textureOffset = { 48 - game::HALF_TILE_SIZE, 58 - game::HALF_TILE_SIZE }; // The position of objects feet - distance from tile corner to tile mid
	_framesPerRow = {
		6, 6, 6, 6,
		6, 6, 6, 6,
		9, 10, 11, 11,
		11, 11
	};

	// Animation player to tell object what animation to play
	_animationPlayer = std::make_unique<handlers::AnimationPlayer>(&_position, &_texture, _textureColumns, _textureRows, _textureWidth, _textureHeight,
		&_wantedSpeed, _textureOffset, _framesPerRow);
}

objects::Fly::~Fly()
{
	std::cout << "Scarecrow deleted!" << std::endl;
}
