#include <raylib.h>

#include "actor.h"

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
    std::shared_ptr<Vector2> velocity = std::make_shared<Vector2>();

    if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
    {
        velocity->y -= 32;
    }
    if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
    {
        velocity->y += 32;
    }
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
    {
        velocity->x -= 32;
    }
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
    {
        velocity->x += 32;
    }

    this->sprite_->pos_x += velocity->x;
    this->sprite_->pos_y += velocity->y;
}
