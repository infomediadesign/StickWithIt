#include "animation_handler.h"


objects::AnimationHandler::AnimationHandler(Texture2D texture, int spritesheetWidth, int spritesheetHeight, int columns, int rows, int playbackSpeed, 
	Vector2 position, Vector2 offset, std::vector<int> actualFramesPerRow, int currentAnimation)
	: mTexture(texture), mSpriteSheetWidth(spritesheetWidth), mSpriteSheetHeight(spritesheetHeight), mColumns(columns), mRows(rows),
	mPlaybackSpeed(playbackSpeed), mPosition(position), mOffset(offset), mActualFramesPerRow(actualFramesPerRow), mCurrentAnimation(currentAnimation)
{
}

bool objects::AnimationHandler::isAnimationCompleted()
{
	
	return mIsAnimationCompleted;
}

void objects::AnimationHandler::animate(Vector2 position)
{

	//plays next frame depending on speed
	if (mStandartPlaybackSpeed == mPlaybackSpeed)
	{
		mCurrentFrame++;
		mStandartPlaybackSpeed = 1;
	}

	switch (mCurrentAnimation)
	{
	case eIdleDown:

		DrawTextureRec(mTexture,
			{
			static_cast<float>(mCurrentFrame) * mSpriteSheetWidth / mColumns,
			static_cast<float>(mSpriteSheetHeight) / mRows,
			static_cast<float>(mSpriteSheetWidth) / mColumns - 1, //-1 pixel so we dont actually start with first pixel of following frame
			static_cast<float>(mSpriteSheetHeight) / mRows - 1
			},
		{
		mPosition.x - mOffset.x + mHalfTileSize, mPosition.y - mOffset.y + mHalfTileSize
		},
			WHITE);

		if (mCurrentFrame == mActualFramesPerRow[0] - 1)
		{

			mIsAnimationCompleted = true;
		}

		break;

	}

	mStandartPlaybackSpeed++;
}

void objects::AnimationHandler::changeAnimation(int animation)
{

	mCurrentAnimation = animation;
}
