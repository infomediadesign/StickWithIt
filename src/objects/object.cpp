#include "object.h"

objects::Object::Object(Texture2D texture, int lives, int attackDamage, int movePoints)
	: mTexture(texture), mLives(lives), mAttackDamage(attackDamage), mMovePoints(movePoints)
{


}

objects::Object::~Object()
{

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
