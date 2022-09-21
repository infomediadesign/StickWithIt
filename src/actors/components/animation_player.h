#pragma once

#include <iostream>

#include "sprite.h"
#include "../state.h"
#include "config.h"

namespace component
{
	class AnimationPlayer
	{
	public:

		AnimationPlayer(const std::shared_ptr<Sprite> sprite, std::shared_ptr<actor::State>& state, bool& is_active);
		~AnimationPlayer();

		void Update(bool is_preparing);
		void Draw(int x, int y) const;

		void StartFlickering(int damage);

		// Uncancelable animations like attack have to fully play before we can input a new state
		bool GetIsAnimationOver() const;

	private:

		Texture2D symbol_select = LoadTexture("assets/graphics/ui/symbol_select.png");

		const std::shared_ptr<Sprite> sprite_;

		std::shared_ptr<actor::State>& state_;

		int current_frame_		= 0;
		int speed_iterator_		= 0;
		int current_animation_	= actor::State::IDLE_DOWN;

		const int speed_up_while_active = 3;

		bool& is_active_;
		bool is_alive_ = true;
		bool is_animation_over = false;

		void EndFlickering();
		void Flicker();

		// Handle flickering when entity is hit
		bool is_flickering_				= false;
		bool is_blank_					= false;
		int damage_taken_				= 0;
		int frame_counter_				= 0;
		int flicker_counter_			= 0;
		const int max_flickers_			= 5;
		const int min_damage_position	= 16;
		int damage_position				= min_damage_position;
		
		Color color_ = WHITE;
	};
}
