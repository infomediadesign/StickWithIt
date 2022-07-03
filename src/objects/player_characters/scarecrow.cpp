#include "scarecrow.h"

objects::Scarecrow::Scarecrow()
{

	mTexture = LoadTexture("assets/graphics/player/scarecrow_animations.png");
	mSpritesheetWidth = 729;
	mSpritesheetHeight = 639;
	mColumns = 8;
	mRows = 9;
	mPlaybackSpeed = 5;
	mPosition = { 0, 0 };
	mFuturePosition = { 0, 0 };
	mOffset = { 40, 47 };
	
	mLives = 10;
	mAttackDamage = 1;
	mMovePoints = 10;
	mActionPoints = 10;

	mAnimationHandler = new AnimationHandler(mTexture, mSpritesheetWidth, mSpritesheetHeight, mColumns, mRows, mPlaybackSpeed, mPosition, mOffset);

	std::cout << "Scarecrow called.";
}

objects::Scarecrow::~Scarecrow()
{


}

void objects::Scarecrow::spawn(Vector2 position)
{


}

void objects::Scarecrow::move(std::vector<Vector2> positionsOfColliders)
{


}

std::tuple<int, std::vector<Vector2>> objects::Scarecrow::attack()
{
	return std::tuple<int, std::vector<Vector2>>();
}

void objects::Scarecrow::getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions)
{

	for (int i = 0; i < std::get<1>(incomingDamageAndPositions).size(); i++)
	{
		
		if (mPosition.x == std::get<1>(incomingDamageAndPositions)[i].x && mPosition.y == std::get<1>(incomingDamageAndPositions)[i].y)
		{

			mLives -= std::get<0>(incomingDamageAndPositions);
		}
	}

	if (mLives < 0)
	{

		std::cout << "Scarecrow has died." << std::endl;

		isAlive = false;

		delete this;
	}
}
