#include "scarecrow.h"

objects::Scarecrow::Scarecrow()
{
	std::cout << "Scarecrow called!" << std::endl;

	// Default data
	_lives = 10;
	_movePoints = 10;
	_actionPoints = 10;
	_attackDamage = 5;
	_isAlive = true;
	_canFly = false;
	_isActive = true;
	_position = { 0, 0 };
	_activeWeapon = eScythe;

	// Default sprite data 
	_texture = LoadTextureFromImage(textures::SCARECROW);
	_textureColumns = 25;
	_textureRows = 14;
	_textureWidth = 2000;
	_textureHeight = 1120;
	_wantedSpeed = 6;
	_textureOffset = { 40 - game::HALF_TILE_SIZE, 45 - game::HALF_TILE_SIZE }; // The position of objects feet - distance from tile corner to tile mid
	_framesPerRow = {
		15, 15, 15, 15,
		9, 9, 9, 9,
		5, 5, 5, 5,
		16, 25
	};

	// Animation player to tell object what animation to play
	_animationPlayer = std::make_unique<handlers::AnimationPlayer>(&_position, &_texture, _textureColumns, _textureRows, _textureWidth, _textureHeight,
		&_wantedSpeed, _textureOffset, _framesPerRow);
}

objects::Scarecrow::~Scarecrow() {
	std::cout << "Scarecrow deleted!" << std::endl;
}
