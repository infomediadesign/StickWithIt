#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>

namespace objects
{

	class Object
	{

	public:

		Object(Texture2D texture, Vector2 position, int lives, int damage, int movePoints);

		virtual ~Object() = 0;

		//position for enemy will be all border-tiles
		//position for helper will be a manually chosen tile
		//position for player depends on ritual tile
		virtual bool spawn(Vector2 position) = 0;

		//moves dependant on input in playerObject
		//calls pathfinding method in nonPlayerObject
		//calls checkCollision before actually move object
		//moves depending on input and collision feedback
		virtual void move() = 0;

		virtual int attack() = 0;

		virtual void getDamage(int incomingDamage) = 0;

		int getLives(); void setLives(int lives);

		int getMovePoints(); void setMovePoints(int movementPoints);

	protected:

		//@TODO
		virtual void checkCollision() = 0;

		virtual void animate() = 0;

		Vector2 mPosition;

		Texture2D mTexture;

		int mLives;
		int mAttackDamage;
		int mMovePoints;
	};
}