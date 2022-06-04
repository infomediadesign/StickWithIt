#include "player.h"
#include "information.h"

game::core::Player::Player()
    : Actor(std::make_unique<game::core::SpriteAnimated>(std::make_shared<game::core::Texture2D>
        (playerTexturePath), playerFrameWidth, playerFrameHeight, playerRow, playerSteps, playerSpeed, playerStartpositionX, playerStartpositionY))
{
    TraceLog(LOG_INFO, "game::core::Player constructor called");
}

game::core::Player::~Player() {
    TraceLog(LOG_INFO, "game::core::Player destructor called");
}

void game::core::Player::handleMovement(int level)
{
    //checks if new level has entered, reset position, reset to preperation phase, reset movement points, increment tempLevel
    if (tempLevel != level)
    {
        sprite_->pos_x = playerStartpositionX;
        sprite_->pos_y = playerStartpositionY;
        _isPlayerPlaced = false;
        _movementPoints = 10;
        tempLevel++;
    }

    //handles transparency at level start
    if (!_isPlayerPlaced)
    {
        int i = 0;

        if (i == 0)
        {
            sprite_->tint = { 255, 255, 255, 150 };
            i++;
        }

        if (i == 1 && IsKeyPressed(KEY_ENTER))
        {
            sprite_->tint = { 255, 255, 255, 255 };
            _isPlayerPlaced = true;
            i++;
        }
    }

    if (_movementPoints > 0)
    {
        Vector2 velocity = { 0, 0 };

        //simple input query
        if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
        {
            velocity.y -= 32;
        }
        if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
        {
            velocity.y += 32;
        }
        if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
        {
            velocity.x -= 32;
        }
        if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
        {
            velocity.x += 32;
        }

        //limit sprite_pos to screen width and height
        if (sprite_->pos_x + velocity.x < 0 || sprite_->pos_x + velocity.x > gameWidth - 32)
        {
            velocity.x = 0;
        }
        if (sprite_->pos_y + velocity.y < -16 || sprite_->pos_y + velocity.y > gameHeight - 16)
        {
            velocity.y = 0;
        }

        //move sprite, prevent diagonal movement
        sprite_->pos_x += velocity.x;
        if (velocity.x == 0)
        {
            sprite_->pos_y += velocity.y;
        }

        //if there is movement, decrease movement points by 1
        if (_isPlayerPlaced && (velocity.x != 0 || velocity.y != 0))
        {
            _movementPoints--;
        }
    }
}

int game::core::Player::getMovementPoints() {
    return _movementPoints;
}

void game::core::Player::setMovementPoints(int movementPoints) {
    _movementPoints = movementPoints;
}

bool game::core::Player::getIsPlayerPlaced() {
    return _isPlayerPlaced;
}

void game::core::Player::setIsPlayerPlaced(bool isPlayerPlaced) {
    _isPlayerPlaced = isPlayerPlaced;
}