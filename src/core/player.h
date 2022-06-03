#pragma once

#include "raylib.h"
#include "actor.h"

namespace game::core {
	class Player : public game::core::Actor{
	public:
		//construct player and give sprite
		Player() = delete;
		Player(std::shared_ptr<game::core::Sprite> sprite);
		~Player() override;

		//handle movement
		void move() override;

		//handle placement when entering new level
		void placeOnMap() override;

	private:
		//if player-object has been placed this turns true and preperation phase will end
		bool playerIsPlaced = false;

		//set the number of tiles a player can move before enemy-turn starts
		bool movementPoints = 10;
	};
}