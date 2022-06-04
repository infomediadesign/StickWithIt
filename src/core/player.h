#pragma once

#include <iostream>

#include "actor.h"
#include "sprite_animated.h"

namespace game::core {
	class Player : public game::core::Actor {
	public:
		Player();

		~Player() override;

		void handleMovement();

		//player specific
		int getMovementPoints() override;
		void setMovementPoints(int movementPoints) override;
		bool getIsPlayerPlaced() override;
		void setIsPlayerPlaced(bool isPlayerPlaced) override;

	private:
		//if player-object has been placed this turns true and preperation phase will end
		bool _isPlayerPlaced = false;

		//set the number of tiles a player can move before enemy-turn starts
		int _movementPoints = 10;
	};
}
