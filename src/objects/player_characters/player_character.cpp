#include "player_character.h"

objects::PlayerCharacter::~PlayerCharacter()
{


}

std::vector<int> objects::PlayerCharacter::attack()
{

	return std::vector<int>();
}

void objects::PlayerCharacter::getDamage(std::vector<int> incomingDamageAndPositions)
{


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
