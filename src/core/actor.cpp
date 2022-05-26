#include <raylib.h>

#include "actor.h"
#include "information.h"

game::core::Actor::Actor(std::shared_ptr<game::core::Sprite> sprite) : sprite_(std::move(sprite)){
    TraceLog(LOG_INFO, "game::core::Actor constructor called");
}

game::core::Actor::~Actor() {
    TraceLog(LOG_INFO, "game::core::Actor destructor called");
}

const std::shared_ptr<game::core::Sprite> &game::core::Actor::sprite() const {
    return this->sprite_;
}

void game::core::Actor::sprite(std::shared_ptr<game::core::Sprite> sprite) {
    this->sprite_ = std::move(sprite);
}

void game::core::Actor::playerMovement() {
    Vector2 velocity = {0, 0};

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
    if (this->sprite_->pos_x + velocity.x < 0 || this->sprite_->pos_x + velocity.x > game_width - 32)
    {
        velocity.x = 0;
    }
    if (this->sprite_->pos_y + velocity.y < -16 || this->sprite_->pos_y + velocity.y > game_height - 16)
    {
        velocity.y = 0;
    }

    //move sprite
    this->sprite_->pos_x += velocity.x;
    this->sprite_->pos_y += velocity.y;
}

Vector2 game::core::Actor::getActorPosition() {
    return { static_cast<float>(this->sprite_->pos_x), static_cast<float>(this->sprite_->pos_y) };
}