#pragma once

#include "object.h"


namespace objects
{
	class PC : public Object 
	{
	public:

		virtual ~PC() = 0;


		// If an object is in reach of another enemy object, it attacks...
		// For each helper the same but not for scarecrow
		type::Pair_Damage_Vec_Position Attack() override;


		void Spawn(type::Vec_Position spawnLayer, type::Vec_Ptr_Position collisionPositions) override;


		// Walk dependant on input or the path found, take collisions into account
		void Move(type::Vec_Ptr_Position collisionLayer) override;


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
		bool _speedIsAdjusted = false;
	};
}