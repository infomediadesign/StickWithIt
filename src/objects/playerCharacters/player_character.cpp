#include "player_character.h"

objects::PlayerCharacter::PlayerCharacter(Texture2D texture, int lives, int damage, int movePoints, 
	int actionPoints, bool isCurrentObjectSelected)
	: Object(texture, lives, damage, movePoints), mActionPoints(actionPoints), 
	mIsCurrentObjectSelected(isCurrentObjectSelected)
{


}

objects::PlayerCharacter::~PlayerCharacter()
{


}

int objects::PlayerCharacter::getActionPoints()
{

	return mActionPoints;
}