#include "scarecrow.h"

objects::Scarecrow::Scarecrow(Texture2D texture, int lives, int damage, int movePoints, int actionPoints, bool isCurrentObjectSelected)
	: PlayerCharacter(LoadTexture("assets/graphics/player/scarecrow_animation.png"), 10, 1, 10, 10, true)
{


}
