#include "button.h"

Texture2D Button::getTexture() {
    if (active)
        return this->texture_active;

    return this->texture_inactive;
}

Button::Button(Texture2D texture_active, Texture2D texture_inactive, int pos_x, int pos_y, bool active)
    : texture_active(texture_active), texture_inactive(texture_inactive), pos_x(pos_x), pos_y(pos_y), active(active) {
}

Button::~Button() {
    UnloadTexture(this->texture_active);
    UnloadTexture(this->texture_inactive);
}