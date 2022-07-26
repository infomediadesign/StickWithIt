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

bool objects::NPC::Move(type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects, type::Vec_Ptr_Position playersPositions, type::Vec_Position ritualPositions)
{
	// This looks for the closest player character or ritual
	std::pair<int, type::Position> distanceToPositionPlusDestination = { 100, {0,0} };

	for (auto& pos : playersPositions)
	{
		if (static_cast<int>(sqrt((_position.first - pos->first) * (_position.first - pos->first) + (_position.second - pos->second) * (_position.second - pos->second)) < distanceToPositionPlusDestination.first))
		{
		distanceToPositionPlusDestination.first = static_cast<int>(sqrt((_position.first - pos->first) * (_position.first - pos->first) + (_position.second - pos->second) * (_position.second - pos->second)));
		distanceToPositionPlusDestination.second = *pos;
		}
	}

	for (auto& pos :ritualPositions)
		if (static_cast<int>(sqrt((_position.first - pos.first) * (_position.first - pos.first) + (_position.second - pos.second) * (_position.second - pos.second)) < distanceToPositionPlusDestination.first))
		{
			distanceToPositionPlusDestination.first = static_cast<int>(sqrt((_position.first - pos.first) * (_position.first - pos.first) + (_position.second - pos.second) * (_position.second - pos.second)));
			distanceToPositionPlusDestination.second = pos;
		}

	std::cout << distanceToPositionPlusDestination.second.first << " " << distanceToPositionPlusDestination.second.second << " " << distanceToPositionPlusDestination.first << std::endl;

	return false;
}
