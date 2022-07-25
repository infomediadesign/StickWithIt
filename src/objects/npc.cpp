#include "npc.h"

objects::NPC::~NPC() {
}


type::Pair_Damage_Vec_Position objects::NPC::Attack()
{
	return type::Pair_Damage_Vec_Position();
}


void objects::NPC::Spawn(type::Vec_Position spawnLayer, type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects)
{
	unsigned int seed = static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count());

	std::shuffle(spawnLayer.begin(), spawnLayer.end(), std::default_random_engine(seed));

	for (auto& possibleSpawn : spawnLayer) {

		bool checkIfPositionIsAvailable = true;


		for (auto& collisionPosition : collisionLayer)
			if (possibleSpawn == collisionPosition)
				checkIfPositionIsAvailable = false;

		for (auto& collisionPosition : collisionsObjects)
			if (possibleSpawn == *collisionPosition)
				checkIfPositionIsAvailable = false;


		if (checkIfPositionIsAvailable == true)
		{
			_position = possibleSpawn;
			break;
		}
	}

	// Set animation dependant on where the enemy spawned
	if (_position.first == 0)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleRight);
	else if (_position.first == 19)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleLeft);
	if (_position.second == 0)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleDown);
	else if (_position.second == 11)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleUp);
}

void objects::NPC::Move(type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects)
{
}
