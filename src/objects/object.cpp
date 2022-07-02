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

