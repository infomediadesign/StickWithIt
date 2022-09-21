#pragma once

#include "../actor.h"
#include "../components/pathfinder.h"

namespace actor
{
	class Enemy : public Actor
	{
	public:

		Enemy(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active,
			std::shared_ptr<component::AnimationPlayer> animation_player, std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

		virtual ~Enemy() {}

		void Update() override;
		void Spawn() override;

		// Move returns true if the enemy has entered a ritual tile -> state: DEATH
		int Move(std::vector<std::pair<int, int>> position_players);

		// For each enemy: for each player: attack(player_position) and return attack_damage if there is one
		// Player->GetDamage(enemy->Attack(player->x_, player->y_))
		std::pair<int, std::pair<int, int>> Attack(int x, int y) const;
		// For each player
		void GetDamage(std::pair<int, std::vector<std::pair<int, int>>> attack);

		std::unique_ptr<component::Pathfinder> pathfinder_;
	};
}