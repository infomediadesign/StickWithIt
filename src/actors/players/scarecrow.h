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

		Texture2D button_swap_weapon = LoadTexture("assets/graphics/ui/button_swap_weapon.png");

		void EvaluateBoosts();
		int EvaluateAttackBoost();

		int damage_scythe_ = 0;
		int damage_pitchfork_ = 0;
		int damage_shovel = 3;

		int active_weapon_index_ = SCYTHE;
	};
}