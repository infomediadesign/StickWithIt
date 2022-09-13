#include "npc.h"

objects::NPC::~NPC() {
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
	else if (_position.first == game::SCREEN_WIDTH - 1)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleLeft);
	else if (_position.second == 0)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleDown);
	else if (_position.second == game::SCREEN_HEIGHT - 1)
		_animationPlayer->SetCurrentAnimation(handlers::AnimationPlayer::eIdleUp);
}

bool objects::NPC::Move(type::Vec_Position posDestinations, type::Vec_Position posCollisions)
{
	// This will ERROR when the path is shorter than the movePoints
	type::Vec_Position path = _pathfinder->FindPath(_position, posDestinations, posCollisions);

	// Make the path long enough so we wont get out of vector range
	while (path.size() < _movePoints)
	{
		path.push_back(_position);
	}
	_position = path.back();

	return false;
}
