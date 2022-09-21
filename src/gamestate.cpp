#include "gamestate.h"

gs::GameState::GameState()
{
}

gs::GameState::~GameState()
{
}

Font gs::GameState::GetFont() const
{
	return font_pixel_musketeer;
}

int gs::GameState::GetWheatThisRun() const
{
	return wheat_this_run_;
}

void gs::GameState::SetWheatThisRun(int wheat)
{
	wheat_this_run_ = wheat;
}

int gs::GameState::GetWheatOverall() const
{
	return wheat_overall_;
}

void gs::GameState::SetWheatOverall(int wheat)
{
	wheat_overall_ = wheat;
}

bool gs::GameState::GetUpgradeStatus(int tree, int upgrade) const
{
	switch (tree)
	{
	case SCYTHE:
		switch (upgrade)
		{
		case UPGRADE_MID:
			return scythe_1;
			break;
		case UPGRADE_LEFT_1:
			return scythe_2;
			break;
		case UPGRADE_LEFT_2:
			return scythe_3;
			break;
		case UPGRADE_RIGHT_1:
			return scythe_4;
			break;
		case UPGRADE_RIGHT_2:
			return scythe_5;
			break;
		}
		break;

	case PITCHFORK:
		switch (upgrade)
		{
		case UPGRADE_MID:
			return pitchfork_1;
			break;
		case UPGRADE_LEFT_1:
			return pitchfork_2;
			break;
		case UPGRADE_LEFT_2:
			return pitchfork_3;
			break;
		case UPGRADE_RIGHT_1:
			return pitchfork_4;
			break;
		case UPGRADE_RIGHT_2:
			return pitchfork_5;
			break;
		}
		break;

	case SHOVEL:
		switch (upgrade)
		{
		case UPGRADE_MID:
			return shovel_1;
			break;
		case UPGRADE_LEFT_1:
			return shovel_2;
			break;
		case UPGRADE_LEFT_2:
			return shovel_3;
			break;
		case UPGRADE_RIGHT_1:
			return shovel_4;
			break;
		case UPGRADE_RIGHT_2:
			return shovel_5;
			break;
		}
		break;
	}

	return false;
}

void gs::GameState::SetUpgradeStatus(int tree, int upgrade, bool status)
{
	if (status == true)
	{
		switch (tree)
		{
		case SCYTHE:
			switch (upgrade)
			{
			case UPGRADE_MID:
				scythe_1 = true;
				break;
			case UPGRADE_LEFT_1:
				scythe_2 = true;
				break;
			case UPGRADE_LEFT_2:
				scythe_3 = true;
				break;
			case UPGRADE_RIGHT_1:
				scythe_4 = true;
				break;
			case UPGRADE_RIGHT_2:
				scythe_5 = true;
				break;
			}
			break;

		case PITCHFORK:
			switch (upgrade)
			{
			case UPGRADE_MID:
				pitchfork_1 = true;
				break;
			case UPGRADE_LEFT_1:
				pitchfork_2 = true;
				break;
			case UPGRADE_LEFT_2:
				pitchfork_3 = true;
				break;
			case UPGRADE_RIGHT_1:
				pitchfork_4 = true;
				break;
			case UPGRADE_RIGHT_2:
				pitchfork_5 = true;
				break;
			}
			break;

		case SHOVEL:
			switch (upgrade)
			{
			case UPGRADE_MID:
				shovel_1 = true;
				break;
			case UPGRADE_LEFT_1:
				shovel_2 = true;
				break;
			case UPGRADE_LEFT_2:
				shovel_3 = true;
				break;
			case UPGRADE_RIGHT_1:
				shovel_4 = true;
				break;
			case UPGRADE_RIGHT_2:
				shovel_5 = true;
				break;
			}
			break;
		}
	}
}

bool gs::GameState::GetMusicPause() const
{
	return is_mute_;
}

void gs::GameState::SetMusicPause(bool status)
{
	is_mute_ = status;
}
