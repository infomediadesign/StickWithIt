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
	mActualFramesPerRow = {
		9, 9, 9, 9,
		5, 5, 5, 5
	};
	
	mLives = 10;
	mAttackDamage = 1;
	mMovePoints = 10;
	mActionPoints = 10;

	mAnimationHandler = new AnimationHandler(mTexture, mSpritesheetWidth, mSpritesheetHeight, mColumns, mRows, mPlaybackSpeed, mPosition, mOffset, mActualFramesPerRow);

	std::cout << "Scarecrow called.";
}

objects::Scarecrow::~Scarecrow()
{

	std::cout << "Scarecrow deleted.";
}

void objects::Scarecrow::spawn(Vector2 position)
{


}

void objects::Scarecrow::move(std::vector<Vector2> positionsOfColliders)
{


}

std::vector<int> objects::Scarecrow::attack()
{

	return std::vector<int>();
}



void objects::Scarecrow::getDamage(std::vector<int> incomingDamageAndPositions)
{

	//-2 so we get only 1 position, or 2,3,4... dependant on positions (index 1 and 2 (or 3 and 4, 5 or 6) passed
	for (int i = 0; i < incomingDamageAndPositions.size() - 2; i += 2)
	{
		
		if (mPosition.x == incomingDamageAndPositions[i + 1] && mPosition.y == incomingDamageAndPositions[i + 2])
		{

			mLives -= incomingDamageAndPositions[0];
		}
	}

	if (mLives <= 0)
	{

		isAlive = false;
	}
}
