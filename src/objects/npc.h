#pragma once

#include "object.h"
#include "../handlers/pathfinder.h"


namespace objects
{
	class NPC : public Object
	{
	public:

		virtual ~NPC() = 0;


		// If an object is in reach of another enemy object, it attacks...
		type::Pair_Damage_Vec_Position Attack() override;


		void Spawn(type::Vec_Position spawnLayer, type::Vec_Ptr_Position collisionPositions) override;


		// Walk dependant on input or the path found, take collisions into account
		void Move(type::Vec_Ptr_Position collisionLayer) override;


	protected:

		// Pathfinder object to find path in Walk();
		std::unique_ptr<handlers::Pathfinder> _pathfinder = {};
	};
}