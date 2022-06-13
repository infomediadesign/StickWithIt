#include "Mushroom.h"

#include "information.h"
#include "sprite_animated.h"

#include <iostream>

game::core::Mushroom::Mushroom()
    : Enemy(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>
        (mushroomTexturePath), mushroomFrameWidth, mushroomFrameHeight, mushroomRow, mushroomSteps, mushroomSpeed, mushroomStartpositionX, mushroomStartpositionY), mushroomFrameHeight, mushroomFrameWidth)
{
    TraceLog(LOG_INFO, "game::core::Mushroom constructor called");
}

game::core::Mushroom::~Mushroom() {
    TraceLog(LOG_INFO, "game::core::Mushroom destructor called");
}

void game::core::Mushroom::handleMovement(int level)
{

}