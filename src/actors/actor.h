#pragma once

#include <iostream>

#include "components/all_components.h"
#include "state.h"
#include "../levels/map.h"
#include "../gamestate.h"

namespace actor
{
	class Actor
	{
	public:

		Actor(int max_hp, int max_move_points, int max_action_points, int attack_damage, bool can_fly, bool is_active, bool is_prepering,
			std::shared_ptr<component::AnimationPlayer> animation_player, std::shared_ptr<level::Map>& map, std::shared_ptr<gs::GameState>& gamestate);

		virtual ~Actor() {}

		virtual void Draw() const;

		// So the animation plays even though we might not want to update our actors
		void UpdateAnimation();

		virtual void Update() = 0;
		virtual void Spawn() = 0;

		bool GetIsPreparing() const;		void SetIsPreparing(bool status);
		bool GetIsActive() const;			void SetIsActive(bool status);
		bool GetIsAlive() const;
		bool GetIsAnimationOver() const;

		int GetHP() const; void SetHP(int hp);
		int GetMovePoints() const;
		int GetActionPoints() const;
		std::pair<int, int> GetPosition() const;

	protected:

		// Default properties
		const int max_hp_;

		// This could change when updating skilltree
		int max_move_points_;
		int max_action_points_;
		int attack_damage_;

		int hp_				= max_hp_;		
		int compare_hp_		= max_hp_;
		int move_points_	= max_move_points_;	
		int action_points_	= max_action_points_;

		int x_ = 0;
		int y_ = 0;

		bool can_fly_;
		bool is_active_;
		bool is_prepering_;
		bool is_alive_ = true;

		// Default state of current object: Idle down
		std::shared_ptr<State> state_ = std::make_shared<State>();

		// Animate and draw sprite
		std::shared_ptr<component::AnimationPlayer> animation_player_;

		// Map of game scene
		std::shared_ptr<level::Map>& map_;

		std::shared_ptr<gs::GameState>& gamestate_;
	};
}