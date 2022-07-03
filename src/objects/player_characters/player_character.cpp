#include "player_character.h"

objects::PlayerCharacter::~PlayerCharacter()
{


}

void objects::PlayerCharacter::getDamage(std::tuple<int, std::vector<Vector2>> incomingDamageAndPositions)
{

	mLives -= std::get<0>(incomingDamageAndPositions);

	if (mLives < 0)
	{
		std::cout << "Helper has died." << std::endl;
		delete this;
	}
}

int objects::PlayerCharacter::getActionPoints()
{

	return mActionPoints;
}

void objects::PlayerCharacter::setActionPoints(int actionPoints)
{

	mActionPoints = actionPoints;
}

int objects::PlayerCharacter::getIsAlive()
{

	return isAlive;
}
