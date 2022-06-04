#include <raylib.h>

#include "actor.h"

game::core::Actor::Actor(std::shared_ptr<game::core::Sprite> sprite) : sprite_(std::move(sprite)) {
}

game::core::Actor::~Actor() {
}

const std::shared_ptr<game::core::Sprite>& game::core::Actor::sprite() const {
    return this->sprite_;
}

void game::core::Actor::sprite(std::shared_ptr<game::core::Sprite> sprite) {
    this->sprite_ = std::move(sprite);
}

int game::core::Actor::getMovementPoints() {
    return 0;
}

void game::core::Actor::setMovementPoints(int movementPoints) {
}

bool game::core::Actor::getIsPlayerPlaced() {
    return 0;
}

void game::core::Actor::setIsPlayerPlaced(bool isPlayerPlaced) {
}