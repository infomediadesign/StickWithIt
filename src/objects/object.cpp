#include "object.h"

objects::Object::~Object()
{

	delete mAnimationHandler;

	UnloadTexture(mTexture);

	std::cout << "Object deleted.";
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


bool objects::Object::checkWillCollide(std::set<Vector2> positionsOfColliders, Vector2 futurePosition)
{

	//if future position would be on a tile 
	if (positionsOfColliders.find(futurePosition) == positionsOfColliders.end())
	{
		return false;
	}
	else
	{
		return true;
	}
}
