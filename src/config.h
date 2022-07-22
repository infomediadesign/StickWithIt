#pragma once

#include "extras/headers.h"

namespace game {
    inline constexpr const char* PROJECT_NAME = "Stick With It";
    inline constexpr const char* PROJECT_VERSION = "0.1";
    inline const Image ICON = LoadImage("assets/graphics/extras/icon.png");

    inline constexpr const int SCREEN_WIDTH = 640;
    inline constexpr const int SCREEN_HEIGHT = 360;
    inline constexpr const int FRAMERATE = 60;

    inline constexpr const int TILE_SIZE = 32;
    inline constexpr const int HALF_TILE_SIZE = 16;

    inline constexpr const int TILES_PER_ROW = 20;
    inline constexpr const int TILES_PER_COLUMN = 12;

    // Must be adjusted to biggest tilesheet
    inline constexpr const int TILESHEET_TILES_PER_ROW = 10;
    inline constexpr const int TILESHEET_TILES_PER_COLUMN = 2;
}