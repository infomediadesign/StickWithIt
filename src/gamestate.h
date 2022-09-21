#pragma once

#include <raylib.h>

namespace gs
{
	class GameState
	{
	public:

		GameState();
		~GameState();

		Font GetFont() const;

		int GetWheatThisRun() const; void SetWheatThisRun(int wheat);
		int GetWheatOverall() const; void SetWheatOverall(int wheat);

		bool GetUpgradeStatus(int tree, int upgrade) const; void SetUpgradeStatus(int tree, int upgrade, bool status);

		bool GetMusicPause() const; void SetMusicPause(bool status);

		enum
		{
			SCYTHE,
			PITCHFORK,
			SHOVEL
		};

		enum
		{
			UPGRADE_MID,
			UPGRADE_LEFT_1,
			UPGRADE_LEFT_2,
			UPGRADE_RIGHT_1,
			UPGRADE_RIGHT_2
		};

	private:

		// Sound
		bool is_mute_ = false;

		Font font_pixel_musketeer = LoadFont("assets/graphics/ui/pixel_musketeer.otf");

		// Save skillpoints
		int wheat_this_run_ = 0;
		int wheat_overall_ = 0;

		// Save bought upgrades and use them in Scarecrow.cpp
		bool pitchfork_1	= false;
		bool pitchfork_2	= false;
		bool pitchfork_3	= false;
		bool pitchfork_4	= false;
		bool pitchfork_5	= false;

		bool scythe_1		= false;
		bool scythe_2		= false;
		bool scythe_3		= false;
		bool scythe_4		= false;
		bool scythe_5		= false;

		bool shovel_1		= false;
		bool shovel_2		= false;
		bool shovel_3		= false;
		bool shovel_4		= false;
		bool shovel_5		= false;
	};
}