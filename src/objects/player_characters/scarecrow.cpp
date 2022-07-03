#include "scarecrow.h"

objects::Scarecrow::Scarecrow()
	: PlayerCharacter(
		LoadTexture("assets/graphics/player/scarecrow_animation.png"),
		729,
		639,
		{ 40, 47 },
		8,
		9,
		5,
		20,
		1,
		10,
		{ 0, 0 },
		{ 0, 0 },
		new AnimationHandler(mTexture, mSpritesheetWidth, mSpritesheetHeight, mColumns, mRows, mPlaybackSpeed, mPosition, mOffset),
		10
		)
{


}

objects::Scarecrow::~Scarecrow()
{


}

bool objects::Scarecrow::spawn(Vector2 position)
{

	return false;
}

void objects::Scarecrow::move(std::vector<Vector2> positionsOfColliders)
{


}

std::tuple<int, std::vector<Vector2>> objects::Scarecrow::attack()
{


}

void objects::Scarecrow::getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions)
{

	mLives -= std::get<0>(incomingDamageAndPositions);

	//for tuple length look, if position == any Vector2 of incomingPosition

	if (mLives < 0)
	{

		std::cout << "Scarecrow has died." << std::endl;

		isAlive = false;

		delete this;
	}
}
