#include "player_character.h"

objects::PlayerCharacter::PlayerCharacter(Texture2D texture, int spritesheetWidth, int spritesheetHeight, Vector2 offset, int columns, int rows, int playbackSpeed,
	int lives, int attackDamage, int movePoints, Vector2 position, Vector2 futurePosition, AnimationHandler* animationHandler, int actionPoints)
	: Object(texture, spritesheetWidth, spritesheetHeight, offset, columns, rows, playbackSpeed, lives, attackDamage, movePoints, position, futurePosition, animationHandler),
	mActionPoints(actionPoints)
{


}

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
