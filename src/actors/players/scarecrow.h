#pragma once

#include "player.h"
#include "../components/weapons/weapons.h"

namespace actor
{
	class Scarecrow : public Player
	{
	public:

		Scarecrow(std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

		void SwapWeapon() override;

		void Draw() const override;

		void GetDamage(std::pair<int, std::pair<int, int>> attack) override;

		std::pair<int, std::vector<std::pair<int, int>>> Attack() override;
		enum
		{
			SCYTHE,
			PITCHFORK,
			SHOVEL,

			MAX_WEAPONS = 3
		};

	private:

		std::unique_ptr<weapon::Weapon> active_weapon_ = std::make_unique<weapon::Scythe>();

		void EvaluateBoosts();
		int EvaluateAttackBoost();

		int active_weapon_index_ = SCYTHE;
	};
}