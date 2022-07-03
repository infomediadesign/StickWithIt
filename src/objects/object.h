// virtual class for all game objects to be found in the game
// general functions like move() or stats like lives

#pragma once

#include <raylib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>

#include "../handlers/animation_handler.h"

namespace objects
{

	class Object
	{

	public:

		// pure virtual class must have defined destructor
		virtual ~Object() = 0;

		//position for enemy will be all border-tiles
		//position for player and helpers depends on ritual tile
		virtual void spawn(Vector2 position) = 0;

		//moves dependant on input in playerObject
		//calls pathfinding method in nonPlayerObject
		//calls checkCollision before actually move object (repeat as long as checkCollision() == true);
		//moves depending on input and collision 
		virtual void move(std::vector<Vector2> positionsOfColliders) = 0;

		virtual std::tuple<int, std::vector<Vector2>> attack() = 0;

		//if hp = 0: player dies -> menu, helper dies -> respawn in x turns, enemy -> just dead lol
		virtual void getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions);

		int getLives(); void setLives(int lives);

		int getMovePoints(); void setMovePoints(int movementPoints);

	protected:

		//// checks if future position of an object would collide
		bool checkWouldCollide(std::vector<Vector2> positionsOfColliders, Vector2 futurePosition);

		// sprite details
		Texture2D mTexture{};
		int mSpritesheetWidth{};
		int mSpritesheetHeight{};
		Vector2 mOffset{};
		int mColumns{};
		int mRows{};
		int mPlaybackSpeed{};

		// basic stats
		int mLives{};
		int mAttackDamage{};
		int mMovePoints{};

		// initial position
		Vector2 mPosition{};
		Vector2 mFuturePosition{};

		// animation handler
		AnimationHandler* mAnimationHandler{};
	};
}