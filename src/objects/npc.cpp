#include "virtual_non_player_character.h"

objects::VirtualNonPlayerCharacter::~VirtualNonPlayerCharacter() {
}

void objects::VirtualNonPlayerCharacter::Attack()
{
}

void objects::VirtualNonPlayerCharacter::Spawn(type::VectorPositions spawnLayer, type::VectorPositions collisionPositions)
{
	unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());

	std::shuffle(spawnLayer.begin(), spawnLayer.end(), std::default_random_engine(seed));

	for (auto& possibleSpawn : spawnLayer) {

		bool checkIfPositionIsAvailable = true;

		// Check if there is no collision on spawnable tile
		for (auto& collisionPosition : collisionPositions) {
			if (collisionPosition == possibleSpawn)
				checkIfPositionIsAvailable = false;
		}

		if (checkIfPositionIsAvailable == true)
		{
			_position = possibleSpawn;
			break;
		}
	}

	// Set animation dependant on where the enemy spawned
	if (_position.first == 0)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleRight);
	else
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleLeft);
	if (_position.second == 0)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleDown);
	else
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleUp);
}

void objects::VirtualNonPlayerCharacter::Move(type::VectorPositions collisionLayer)
{
}
