// virtual class for all game objects to be found in the game
// general functions like move() or stats like lives

#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

namespace objects
{

	class Object
	{

	public:

		Object(Texture2D texture, int lives, int damage, int movePoints);

		virtual ~Object() = 0;

		//position for enemy will be all border-tiles
		//position for helper will be a manually chosen tile
		//position for player depends on ritual tile
		virtual bool spawn(Vector2 position) = 0;

		//moves dependant on input in playerObject
		//calls pathfinding method in nonPlayerObject
		//calls checkCollision before actually move object
		//moves depending on input and collision feedback
		virtual void move(std::set<Vector2> positionsOfColliders) = 0;

		virtual int attack() = 0;

		//state machine, animate different rectangle, speed modifyable by iterating float. If x = 1 play frame y, then x += 0.2
		//If x = 2 play frame z. If last frame, reset frame iterator
		void animate();

		void getDamage(int incomingDamage);

		int getLives(); void setLives(int lives);

		int getMovePoints(); void setMovePoints(int movementPoints);

	protected:

		//@TODO
		//Ein Vektor mit allen Positionen, es wird die eigene dabei natürlich ignoriert, mit default keyword arbeiten?
		virtual void checkCollision(std::set<Vector2> positionsOfColliders, Vector2 futurePosition);

		Vector2 mPosition = {0.0, 0.0};
		Vector2 mFuturePosition = {0.0, 0.0};

		Texture2D mTexture;

		int mLives;
		int mAttackDamage;
		int mMovePoints;
	};
}