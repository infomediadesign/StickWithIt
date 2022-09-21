#include "animation_player.h"

component::AnimationPlayer::AnimationPlayer(const std::shared_ptr<Sprite> sprite, std::shared_ptr<actor::State>& state, bool& is_active)
	:
	sprite_(sprite),
	state_(state),
	is_active_(is_active)
{
}

component::AnimationPlayer::~AnimationPlayer()
{
	UnloadTexture(symbol_select);
}

void component::AnimationPlayer::Update(bool is_preparing)
{
	// If the animation got changed mid-animation, start new animation at frame 0
	if (state_->GetState() != current_animation_)
	{
		current_animation_ = state_->GetState();
		current_frame_ = 0;

		// Uncancable animations here
		{
			if (current_animation_ == actor::State::ATTACK_UP ||
				current_animation_ == actor::State::ATTACK_DOWN ||
				current_animation_ == actor::State::ATTACK_RIGHT ||
				current_animation_ == actor::State::ATTACK_LEFT ||
				current_animation_ == actor::State::ATTACK_PITCHFORK_UP ||
				current_animation_ == actor::State::ATTACK_PITCHFORK_DOWN ||
				current_animation_ == actor::State::ATTACK_PITCHFORK_RIGHT ||
				current_animation_ == actor::State::ATTACK_PITCHFORK_LEFT ||
				current_animation_ == actor::State::ATTACK_SHOVEL_UP ||
				current_animation_ == actor::State::ATTACK_SHOVEL_DOWN ||
				current_animation_ == actor::State::ATTACK_SHOVEL_RIGHT ||
				current_animation_ == actor::State::ATTACK_SHOVEL_LEFT ||
				current_animation_ == actor::State::DEATH_1 ||
				current_animation_ == actor::State::DEATH_2)
			{
				is_animation_over = false;
			}
		}
	}

	// Change color if it's preparation phase
	if (is_preparing)
	{
		color_ = { 255, 255, 255, 140 };
	}
	else
	{
		color_ = WHITE;
	}

	// Change actors speed if active
	if (speed_iterator_ > sprite_->wanted_speed_ - speed_up_while_active && is_active_)
	{
		current_frame_++;
		speed_iterator_ = 0;
	}
	else if (speed_iterator_ > sprite_->wanted_speed_)
	{
		current_frame_++;
		speed_iterator_ = 0;
	}

	speed_iterator_++;

	 //If we have reached the last frame of the current animation change state and reset frame
	if (current_frame_ == sprite_->frames_per_row_[current_animation_] - 1)
	{
		switch (current_animation_)
		{
		case actor::State::ATTACK_UP:
			state_->SetState(actor::State::IDLE_UP);
			break;
		case actor::State::ATTACK_DOWN:
			state_->SetState(actor::State::IDLE_DOWN);
			break;
		case actor::State::ATTACK_RIGHT:
			state_->SetState(actor::State::IDLE_RIGHT);
			break;
		case actor::State::ATTACK_LEFT:
			state_->SetState(actor::State::IDLE_LEFT);
			break;

		case actor::State::ATTACK_PITCHFORK_UP:
			state_->SetState(actor::State::IDLE_UP);
			break;
		case actor::State::ATTACK_PITCHFORK_DOWN:
			state_->SetState(actor::State::IDLE_DOWN);
			break;
		case actor::State::ATTACK_PITCHFORK_RIGHT:
			state_->SetState(actor::State::IDLE_RIGHT);
			break;
		case actor::State::ATTACK_PITCHFORK_LEFT:
			state_->SetState(actor::State::IDLE_LEFT);
			break;

		case actor::State::ATTACK_SHOVEL_UP:
			state_->SetState(actor::State::IDLE_UP);
			break;
		case actor::State::ATTACK_SHOVEL_DOWN:
			state_->SetState(actor::State::IDLE_DOWN);
			break;
		case actor::State::ATTACK_SHOVEL_RIGHT:
			state_->SetState(actor::State::IDLE_RIGHT);
			break;
		case actor::State::ATTACK_SHOVEL_LEFT:
			state_->SetState(actor::State::IDLE_LEFT);
			break;

		case actor::State::WALK_UP:
			state_->SetState(actor::State::IDLE_UP);
			break;
		case actor::State::WALK_DOWN:
			state_->SetState(actor::State::IDLE_DOWN);
			break;
		case actor::State::WALK_RIGHT:
			state_->SetState(actor::State::IDLE_RIGHT);
			break;
		case actor::State::WALK_LEFT:
			state_->SetState(actor::State::IDLE_LEFT);
			break;

		case actor::State::DEATH_1:
			is_alive_ = false;
			break;
		// Keep playing last frame of Death 2
		case actor::State::DEATH_2:
			current_frame_ = sprite_->frames_per_row_[current_animation_] - 1;
			speed_iterator_ = 0;
			is_animation_over = true;
			break;
		}

		if (current_animation_ != actor::State::DEATH_2)
		{
			current_frame_ = 0;
			is_animation_over = true;
		}
	}

	Flicker();
}

void component::AnimationPlayer::Draw(int x, int y) const
{
	// Stop drawing character if hes dead
	if (is_alive_)
	{
		// Draw sprite
		DrawTextureRec(
			sprite_->texture_,
			{
				static_cast<float>(current_frame_ * sprite_->texture_width_ / sprite_->texture_collumns_),
				static_cast<float>(current_animation_ * sprite_->texture_height_ / sprite_->texture_rows_),
				static_cast<float>(sprite_->texture_width_ / sprite_->texture_collumns_),
				static_cast<float>(sprite_->texture_height_ / sprite_->texture_rows_),
			},
			{
				static_cast<float>(x * game::TILE_SIZE - sprite_->texture_offset_.first),
				static_cast<float>(y * game::TILE_SIZE - sprite_->texture_offset_.second)
			},
			color_
		);

		// Draw the active symbol
		if (is_active_)
		{
			DrawTexture(symbol_select, x * game::TILE_SIZE + 11, y * game::TILE_SIZE - 26, color_);
		}

		// Draw flickering
		if (is_flickering_)
		{
			DrawText(TextFormat("%i", damage_taken_),
				x * game::TILE_SIZE + game::TILE_SIZE / 2 - 4,
				y * game::TILE_SIZE - damage_position,
				14,
				RED);
		}
	}
}

void component::AnimationPlayer::StartFlickering(int damage)
{
	is_flickering_ = true;
	damage_taken_ = damage;
}

bool component::AnimationPlayer::GetIsAnimationOver() const
{
	return is_animation_over;
}

void component::AnimationPlayer::EndFlickering()
{
	is_flickering_ = false;
	damage_taken_ = 0;
	damage_position = 0;
	flicker_counter_ = 0;
	damage_position = min_damage_position;
}

void component::AnimationPlayer::Flicker()
{
	if (is_flickering_)
	{
		// Every third frame make the damage count rise
		if (frame_counter_ % 4 == 0)
		{
			damage_position++;
		}

		// Every 5th frame we flicker and every other 5th frame we change color back to normal
		if (frame_counter_ % 4 == 0 && !is_blank_)
		{
			color_ = BLANK;
			is_blank_ = true;
		}
		else if (frame_counter_ % 4 == 0 && is_blank_)
		{
			color_ = WHITE;
			is_blank_ = false;
			flicker_counter_++;
		}

		frame_counter_++;

		// Reset
		if (flicker_counter_ > max_flickers_)
		{
			EndFlickering();
		}
	}
}
