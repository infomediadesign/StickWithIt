#pragma once

#include "raylib.h"
#include <vector>


class Button {
public:
    Texture2D texture_active;
    Texture2D texture_inactive;

    int pos_x;
    int pos_y;

    Button(Texture2D texture_active, Texture2D texture_inactive, int pos_x, int pos_y, bool active);

    ~Button();

    bool active;
    Texture2D getTexture();
};
