#include "object.h"

objects::Object::Object(Texture2D texture, int spritesheetWidth, int spritesheetHeight, Vector2 offset, int columns, int rows, int playbackSpeed,
	int lives, int attackDamage, int movePoints, Vector2 position, Vector2 futurePosition, AnimationHandler* animationHandler)
	: mTexture(texture), mSpritesheetWidth(spritesheetWidth), mSpritesheetHeight(spritesheetHeight), mOffset(offset), mColumns(columns), mRows(rows), mPlaybackSpeed(playbackSpeed),
	mLives(lives), mAttackDamage(attackDamage), mMovePoints(movePoints), mPosition(position), mFuturePosition(futurePosition), mAnimationHandler(animationHandler)
{


}

objects::Object::~Object()
{

	delete mAnimationHandler;

	UnloadTexture(mTexture);

	std::cout << "Object deleted.";
}


void objects::Object::getDamage(std::tuple<int, Vector2> incomingDamageAndPositions)
{

	mLives -= std::get<0>(incomingDamageAndPositions);

	if (mLives < 0)
	{
		delete this;
	}
}

int objects::Object::getLives()
{

	return mLives;
}


void objects::Object::setLives(int lives)
{

	mLives = lives;
}


int objects::Object::getMovePoints()
{

	return mMovePoints;
}


void objects::Object::setMovePoints(int movePoints)
{

	mMovePoints = movePoints;
}

bool objects::Object::checkWouldCollide(std::vector<Vector2> positionsOfColliders, Vector2 futurePosition)
{

	//if future position would be on a tile 
	for (int i = 0; i < positionsOfColliders.size(); i++)
	{

		if (positionsOfColliders[i].x == futurePosition.x && positionsOfColliders[i].y == futurePosition.y)
		{

			std::cout << "Es gab eine Kollision." << std::endl;
			return true;
		}
	}

	std::cout << "Es gab keine Kollision." << std::endl;

	return false;
}

