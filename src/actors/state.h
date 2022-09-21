#pragma once

namespace actor
{
	class State
	{
	public:

		void Update();

		// Gettser / Setters
		int GetState() const; void SetState(int state);

		enum
		{
			IDLE_UP,
			IDLE_DOWN,
			IDLE_RIGHT,
			IDLE_LEFT,

			WALK_UP,
			WALK_DOWN,
			WALK_RIGHT,
			WALK_LEFT,

			ATTACK_UP,
			ATTACK_DOWN,
			ATTACK_RIGHT,
			ATTACK_LEFT,

			DEATH_1,
			DEATH_2,

			ATTACK_SHOVEL_UP,
			ATTACK_SHOVEL_DOWN,
			ATTACK_SHOVEL_RIGHT,
			ATTACK_SHOVEL_LEFT,

			ATTACK_PITCHFORK_UP,
			ATTACK_PITCHFORK_DOWN,
			ATTACK_PITCHFORK_RIGHT,
			ATTACK_PITCHFORK_LEFT
		};

	private:

		int state_current_ = IDLE_DOWN;
	};
}