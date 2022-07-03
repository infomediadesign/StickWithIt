#include "animation_handler.h"

objects::AnimationHandler::AnimationHandler(Texture2D texture, int spritesheetWidth, int spritesheetHeight, int columns, int rows, int playbackSpeed, Vector2 actorPosition, Vector2 offset)
	: mTexture(texture), mSpriteSheetWidth(spritesheetWidth), mSpriteSheetHeight(spritesheetHeight), mColumns(columns), mRows(rows), 
	mPlaybackSpeed(playbackSpeed), mPosition(actorPosition), mOffset(offset)
{


}

void objects::AnimationHandler::setPosition(Vector2 position)
{

	mPosition = position;
}


void objects::AnimationHandler::animate(Vector2 position, int animation)
{


}
