#pragma once

#include "../actor.h"

namespace actor
{
	class Player : public Actor
	{
	public:

		Player(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active,
			std::shared_ptr<component::AnimationPlayer> animation_player, std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

		virtual ~Player() {}

		virtual void Draw() const;

		void Update() override;
		void Spawn() override;

		void Move();

		virtual std::pair<int, std::vector<std::pair<int, int>>> Attack();
		virtual void GetDamage(std::pair<int, std::pair<int, int>> attack);

		void ResetStats();

		// Exclusive for every players that can hold items (for now only scarecrow though)
		virtual void SwapWeapon() {};
	};
}