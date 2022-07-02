// virtual class for all game objects to be found in the game
// general functions like move() or stats like lives

#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <set>

#include "../handlers/animation_handler.h"

namespace objects
{

	class Object
	{

	public:

		virtual ~Object();

		//position for enemy will be all border-tiles
		//position for helper will be a manually chosen tile
		//position for player depends on ritual tile
		virtual bool spawn(Vector2 position) = 0;

		//moves dependant on input in playerObject
		//calls pathfinding method in nonPlayerObject
		//calls checkCollision before actually move object (repeat as long as checkCollision() == true);
		//moves depending on input and collision 
		virtual void move(std::set<Vector2> positionsOfColliders) = 0;

		virtual int attack() = 0;

		//state machine, animate different rectangle, speed modifyable by iterating float. If x = 1 play frame y, then x += 0.2
		//If x = 2 play frame z. If last frame, reset frame iterator
		//differentiates between sprites because size, etc.
		virtual void animate() = 0;

		//if hp = 0: player dies -> menu, helper dies -> respawn in x turns, enemy -> just dead lol
		virtual void getDamage(int incomingDamage) = 0;

		int getLives(); void setLives(int lives);

		int getMovePoints(); void setMovePoints(int movementPoints);

	protected:

		// checks if future position of an object would collide
		bool checkWillCollide(std::set<Vector2> positionsOfColliders, Vector2 futurePosition);

		// sprite details
		Texture2D mTexture;
		int mColumns;
		int mRows;
		int mPlaybackSpeed;
		Vector2 mOffset;

		// animation handler
		AnimationHandler* mAnimationHandler;

		// basic stats
		int mLives;
		int mAttackDamage;
		int mMovePoints;

		// initial position
		Vector2 mPosition = { 0.0, 0.0 };
		Vector2 mFuturePosition = { 0.0, 0.0 };
	};
}