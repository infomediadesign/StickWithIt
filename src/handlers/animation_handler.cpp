#include "animation_handler.h"

objects::AnimationHandler::AnimationHandler(Texture2D texture, int spritesheetWidth, int spritesheetHeight, int columns, int rows, int playbackSpeed,
	Vector2 actorPosition, Vector2 offset, std::vector<int> actualFramesPerRow)
	: mTexture(texture), mSpriteSheetWidth(spritesheetWidth), mSpriteSheetHeight(spritesheetHeight), mColumns(columns), mRows(rows),
	mPlaybackSpeed(playbackSpeed), mPosition(actorPosition), mOffset(offset), mActualFramesPerRow(actualFramesPerRow)
{


}

void objects::AnimationHandler::setPosition(Vector2 position)
{

	mPosition = position;
}

bool objects::AnimationHandler::isAnimationCompleted()
{
	
	return mIsAnimationCompleted;
}


void objects::AnimationHandler::animate(Vector2 position, int animation)
{

	switch (animation)
	{
	case eIdleDown:
		DrawTextureRec(mTexture, 
			{ 
			static_cast<float>(currentFrame) * mSpriteSheetWidth / mColumns, 
			static_cast<float>(currentFrame) * mSpriteSheetHeight / mRows, 
			static_cast<float>(currentFrame + 1) * mSpriteSheetWidth / mColumns 
			static_cast<float>(currentFrame + 1) * mSpriteSheetHeight / mRows,
			});

		currentFrame++;
		if (currentFrame == mActualFramesPerRow[0] - 1)
		{
			mIsAnimationCompleted = true;
		}
		break;
	}
}
