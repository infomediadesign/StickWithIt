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


		void Spawn(type::Vec_Position spawnLayer, type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects) override;


		// Walk dependant on input or the path found, take collisions into account
		bool Move(type::Vec_Position collisionLayer, type::Vec_Ptr_Position collisionsObjects) override;


	protected:

		// Pathfinder object to find path in Walk();
		std::unique_ptr<handlers::Pathfinder> _pathfinder = {};
	};
}