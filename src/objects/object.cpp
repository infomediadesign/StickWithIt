#include "object.h"

objects::Object::~Object()
{

	delete mAnimationHandler;

	UnloadTexture(mTexture);
}


void objects::Object::getDamage(std::vector<int> incomingDamageAndPositions)
{


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

int objects::Object::getWeapon()
{
	return mActiveWeapon;
}

void objects::Object::setWeapon(int weapon)
{

	mActiveWeapon = weapon;
}

bool objects::Object::checkWouldCollide(Vector2 futurePosition)
{
	return false;
}
