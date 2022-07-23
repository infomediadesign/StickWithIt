#pragma once

#include "../../extras/headers.h"
#include "../virtual_object.h"
#include "../../handlers/pathfinder.h"

namespace objects {
	class VirtualNonPlayerCharacter : public VirtualObject {
	public:
		virtual ~VirtualNonPlayerCharacter() = 0;

		// If an object is in reach of another enemy object, it attacks...
		void Attack() override;

		void Spawn(type::VectorPositions spawnLayer, type::VectorPositions collisionPositions) override;

		// Walk dependant on input or the path found, take collisions into account
		void Move(type::VectorPositions collisionLayer) override;

	protected:
		// Pathfinder object to find path in Walk();
		std::unique_ptr<handlers::Pathfinder> _pathfinder = nullptr;
	};
}