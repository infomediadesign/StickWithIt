#include "boar.h"
#include "information.h"

#include <iostream>

game::core::Boar::Boar()
    : Enemy(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>
        (), boarFrameWidth, boarFrameHeight, boarRow, boarSteps, boarSpeed, boarStartpositionX, boarStartpositionY))
{
    TraceLog(LOG_INFO, "game::core::Boar constructor called");
}

game::core::Boar::~Boar() {
    TraceLog(LOG_INFO, "game::core::Boar destructor called");
}

void game::core::Boar::handleMovement(int level)
{

}
