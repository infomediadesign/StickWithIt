#pragma once

#include <iostream>
#include <raylib.h>

namespace st
{
	class Upgrade
	{
	public:

		Upgrade(const char* texture_path_, int x, int y, int strength, int move_points, int action_points, int cost, bool is_unlocked);
		~Upgrade();

		void Draw() const;

		bool GetIsUnlocked() const; void SetIsUnlocked(bool status);
		bool GetIsActive() const; void SetIsActive(bool status);

		const std::pair<int, int> GetPosition() const;

		int GetStrength() const;
		int GetMovePoints() const;
		int GetActionPoints() const;
		int GetCost() const;

	private:

		const Texture2D texture_;

		const int x_;
		const int y_;
		const int cost_;
		const int strength_;
		const int move_points_;
		const int action_points_;

		bool is_active_ = false;
		bool is_unlocked_;
	};
}
