#pragma once

#include "../../extras/headers.h"
#include "../virtual_object.h"

namespace objects {
	class VirtualPlayerCharacter : public VirtualObject {
	public:
		virtual ~VirtualPlayerCharacter() = 0;

		// If an object is in reach of another enemy object, it attacks...
		// For each helper the same but not for scarecrow
		void Attack() override;

		void Spawn(type::VectorPositions spawnLayer, type::VectorPositions collisionPositions) override;

		// Walk dependant on input or the path found, take collisions into account
		void Move(type::VectorPositions collisionLayer) override;

		// Animate object depending on movement and action
		void Animate() override;

		// Getter and Setter
		bool GetIsActive(); void SetIsActive(bool isActive);
		int GetActionPoints(); void SetActionPoints(int actionPoints);
		int GetActiveWeapon(); void SetActiveWeapon(int weapon);

		// Lists all weapons
		enum eWeapons
		{
			eNoWeapon,
			eScythe,
			eShovel,
			eHoe
		};

	protected:
		// Additional player object data
		int _activeWeapon = 0;
		int _actionPoints = 0;
		bool _isActive = false;
	};
}