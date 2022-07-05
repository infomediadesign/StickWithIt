#include "scarecrow.h"

objects::Scarecrow::Scarecrow()
{

	mTexture = LoadTexture("assets/graphics/player/scarecrow_animations.png");
	mSpritesheetWidth = 729;
	mSpritesheetHeight = 639;
	mColumns = 9;
	mRows = 8;
	mPlaybackSpeed = 8;
	mPosition = { 128, 128 };
	mFuturePosition = { 0, 0 };
	mOffset = { 40 , 47 };
	mActualFramesPerRow = {
		9, 9, 9, 9,
		5, 5, 5, 5
	};
	mCurrentAnimation = AnimationHandler::Animation::eIdleDown;
	
	mLives = 10;
	mAttackDamage = 1;
	mMovePoints = 10;
	mCanFly = false;
	mActionPoints = 10;
	mActiveWeapon = Weapons::eScythe;

	mAnimationHandler = new AnimationHandler(mTexture, mSpritesheetWidth, mSpritesheetHeight, mColumns, mRows, 
		mPlaybackSpeed, mPosition, mOffset, mActualFramesPerRow, mCurrentAnimation);

	std::cout << "Scarecrow called.";
}

objects::Scarecrow::~Scarecrow()
{

	std::cout << "Scarecrow deleted." << std::endl;
}

void objects::Scarecrow::spawn(Vector2 position)
{


}

void objects::Scarecrow::move(std::vector<Vector2> positionsOfColliders)
{

	Vector2 velocity = { 0, 0 };

	if (IsKeyPressed(KEY_W))
	{
		velocity.x = 0;
		velocity.y = 32;
	}
	else if (IsKeyPressed(KEY_S))
	{
		velocity.x = 0;
		velocity.y = - 32;
	}
	else if (IsKeyPressed(KEY_D))
	{
		velocity.x = 32;
		velocity.y = 0;
	}
	else if (IsKeyPressed(KEY_A))
	{
		velocity.x = - 32;
		velocity.y = 0;
	}

	mFuturePosition.x += velocity.x;
	mFuturePosition.y += velocity.y;

	if (!checkWouldCollide(mFuturePosition)) 
	{
		if (IsKeyPressed(KEY_W))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eWalkUp);
		}
		else if (IsKeyPressed(KEY_S))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eWalkDown);
		}
		else if (IsKeyPressed(KEY_D))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eWalkRight);
		}
		else if (IsKeyPressed(KEY_A))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eWalkLeft);
		}

		mPosition.x = mFuturePosition.x;
		mPosition.y = mFuturePosition.y;
	}

	mAnimationHandler->animate(mPosition);
}

std::vector<int> objects::Scarecrow::attack()
{
	
	switch (mActiveWeapon)
	{
	case Weapons::eScythe:
		if (IsKeyPressed(KEY_UP))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eAttackUp);
			return { mAttackDamage, static_cast<int>(mPosition.x) -32, static_cast<int>(mPosition.y) + 32, 
			static_cast<int>(mPosition.x), static_cast<int>(mPosition.y) + 32,
			static_cast<int>(mPosition.x) + 32, static_cast<int>(mPosition.y) + 32 };
		}
		else if (IsKeyPressed(KEY_DOWN))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eAttackDown);
			return { mAttackDamage, static_cast<int>(mPosition.x) - 32, static_cast<int>(mPosition.y) - 32,
			static_cast<int>(mPosition.x), static_cast<int>(mPosition.y) - 32,
			static_cast<int>(mPosition.x) + 32, static_cast<int>(mPosition.y) - 32 };
		}
		else if (IsKeyPressed(KEY_RIGHT))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eAttackRight);
			return { mAttackDamage, static_cast<int>(mPosition.x) + 32, static_cast<int>(mPosition.y) + 32,
			static_cast<int>(mPosition.x) + 32, static_cast<int>(mPosition.y),
			static_cast<int>(mPosition.x) + 32, static_cast<int>(mPosition.y) - 32 };
		}
		else if (IsKeyPressed(KEY_LEFT))
		{
			mAnimationHandler->changeAnimation(AnimationHandler::Animation::eAttackLeft);
			return { mAttackDamage, static_cast<int>(mPosition.x) - 32, static_cast<int>(mPosition.y) + 32,
			static_cast<int>(mPosition.x) - 32, static_cast<int>(mPosition.y),
			static_cast<int>(mPosition.x) - 32, static_cast<int>(mPosition.y) - 32 };
		}
		else
		{
			return {0};
		}
		break;

	case Weapons::eSpade:
		break;

	case Weapons::eHoe:
		break;
	}
}



void objects::Scarecrow::getDamage(std::vector<int> incomingDamageAndPositions)
{

	//-2 so we get only 1 position, or 2,3,4... dependant on positions (index 1 and 2 (or 3 and 4, 5 or 6) passed
	if (incomingDamageAndPositions.size() > 1)
	{

		for (int i = 0; i < incomingDamageAndPositions.size() - 2; i += 2)
		{

			if (mPosition.x == incomingDamageAndPositions[i + 1] && mPosition.y == incomingDamageAndPositions[i + 2])
			{

				mLives -= incomingDamageAndPositions[0];
			}
		}
	}

	if (mLives <= 0)
	{

		isAlive = false;
	}
}
